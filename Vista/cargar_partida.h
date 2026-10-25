//
// Created by chelokito on 25/10/26.
//

#ifndef ELEMENTOS_CARGAR_PARTIDA_H
#define ELEMENTOS_CARGAR_PARTIDA_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui
{
    class Cargar_Partida;
}

QT_END_NAMESPACE

class Cargar_Partida : public QWidget
{
    Q_OBJECT

public:
    explicit Cargar_Partida(QWidget* parent = nullptr);
    ~Cargar_Partida() override;

private:
    Ui::Cargar_Partida* ui;
};


#endif //ELEMENTOS_CARGAR_PARTIDA_H
