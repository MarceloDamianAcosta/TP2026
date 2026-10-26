//
// Created by chelokito on 25/10/26.
//

#include "nueva.h"
#include "ui_Nueva.h"
#include <QHeaderView>
#include <QProxyStyle>
#include <QStyleOptionHeader>
#include <QPainter>
#include <QSpinBox>

// dibuja centrado el icono de los encabezados que no tienen texto
class IconoCentrado : public QProxyStyle
{
public:
    void drawControl(ControlElement elemento, const QStyleOption* opcion, QPainter* pintor, const QWidget* widget) const override
    {
        auto* encabezado = qstyleoption_cast<const QStyleOptionHeader*>(opcion);
        if (elemento == CE_HeaderLabel && encabezado && encabezado->text.isEmpty())
        {
            int lado = proxy()->pixelMetric(PM_SmallIconSize, opcion, widget);
            QRect lugar = alignedRect(encabezado->direction, Qt::AlignCenter, QSize(lado, lado), encabezado->rect);
            encabezado->icon.paint(pintor, lugar);
            return;
        }
        QProxyStyle::drawControl(elemento, opcion, pintor, widget);
    }
};


Nueva::Nueva(Juego* juego, QWidget* parent) :
    QWidget(parent), ui(new Ui::Nueva), juego(juego)
{
    ui->setupUi(this);
    configuracion = juego->getConfiguracion();
    ui->radioButton->setChecked(configuracion.dificultad == 1);
    ui->radioButton_2->setChecked(configuracion.dificultad == 2);
    ui->radioButton_3->setChecked(configuracion.dificultad == 3);
    ui->spinBox->setValue(configuracion.cantidad);
    armarTabla();
    // sin nombre no se puede jugar
    ui->pushButton->setEnabled(false);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, [this](const QString& nombre) {
        ui->pushButton->setEnabled(!nombre.trimmed().isEmpty());
    });
    connect(ui->pushButton, &QPushButton::clicked, this, &Nueva::jugar);
}

Nueva::~Nueva()
{
    delete ui;
}

void Nueva::armarTabla()
{
    const QString nombres[6] = {"agua", "fuego", "tierra", "barro", "lava", "vapor"};
    auto* estilo = new IconoCentrado;
    estilo->setParent(ui->tablaDanio);
    ui->tablaDanio->horizontalHeader()->setStyle(estilo);
    ui->tablaDanio->verticalHeader()->setStyle(estilo);
    ui->tablaDanio->horizontalHeader()->setIconSize(QSize(32, 32));
    ui->tablaDanio->verticalHeader()->setIconSize(QSize(32, 32));
    ui->tablaDanio->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaDanio->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (int i = agua; i <= vapor; i++)
    {
        auto* columna = new QTableWidgetItem(QIcon(":/iconos/" + nombres[i] + ".svg"), "");
        columna->setToolTip(nombres[i] + " ataca");
        ui->tablaDanio->setHorizontalHeaderItem(i, columna);
        auto* fila = new QTableWidgetItem(QIcon(":/iconos/" + nombres[i] + ".svg"), "");
        fila->setToolTip(nombres[i] + " defiende");
        ui->tablaDanio->setVerticalHeaderItem(i, fila);
    }
    for (int defensor = agua; defensor <= vapor; defensor++)
        for (int atacante = agua; atacante <= vapor; atacante++)
        {
            // los puros se editan con un QSpinBox de 0 a 100
            if (defensor <= tierra && atacante <= tierra)
            {
                auto* spin = new QSpinBox;
                spin->setRange(0, 100);
                spin->setAlignment(Qt::AlignCenter);
                spin->setValue(configuracion.danio[defensor][atacante]);
                connect(spin, &QSpinBox::valueChanged, this, [this, defensor, atacante](int valor) {
                    configuracion.danio[defensor][atacante] = valor;
                    Fabrica::completar(configuracion.danio);
                    mostrarDanio();
                });
                ui->tablaDanio->setCellWidget(defensor, atacante, spin);
            }
            // los compuestos se ven grises y no se editan
            else
            {
                auto* celda = new QTableWidgetItem;
                celda->setTextAlignment(Qt::AlignCenter);
                celda->setFlags(Qt::NoItemFlags);
                ui->tablaDanio->setItem(defensor, atacante, celda);
            }
        }
    mostrarDanio();
}

// actualiza los compuestos, que dependen de los puros
void Nueva::mostrarDanio()
{
    for (int defensor = agua; defensor <= vapor; defensor++)
        for (int atacante = agua; atacante <= vapor; atacante++)
            if (defensor > tierra || atacante > tierra)
                ui->tablaDanio->item(defensor, atacante)->setData(Qt::DisplayRole, configuracion.danio[defensor][atacante]);
}

void Nueva::jugar()
{
    configuracion.dificultad = 1;
    if (ui->radioButton_2->isChecked())
        configuracion.dificultad = 2;
    if (ui->radioButton_3->isChecked())
        configuracion.dificultad = 3;
    configuracion.cantidad = ui->spinBox->value();

    juego->iniciar(ui->lineEdit->text().trimmed().toStdString(), configuracion);
    emit partidaCreada();
    close();
}
