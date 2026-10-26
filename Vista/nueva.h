//
// Created by chelokito on 25/10/26.
//

#ifndef ELEMENTOS_NUEVA_H
#define ELEMENTOS_NUEVA_H

#include <QWidget>
#include "../Modelo/Juego.h"


QT_BEGIN_NAMESPACE

namespace Ui
{
    class Nueva;
}

QT_END_NAMESPACE

class Nueva : public QWidget
{
    Q_OBJECT

public:
    explicit Nueva(Juego* juego, QWidget* parent = nullptr);
    ~Nueva() override;

signals:
    void partidaCreada();

private slots:
    void jugar();

private:
    Ui::Nueva* ui;
    Juego* juego;
    Configuracion configuracion;
    void armarTabla();
    void mostrarDanio();
};


#endif //ELEMENTOS_NUEVA_H
