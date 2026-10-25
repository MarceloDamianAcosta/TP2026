//
// Created by chelokito on 25/10/26.
//

#ifndef ELEMENTOS_GUARDAR_PARTIDA_H
#define ELEMENTOS_GUARDAR_PARTIDA_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui
{
    class guardar_partida;
}

QT_END_NAMESPACE

class guardar_partida : public QWidget
{
    Q_OBJECT

public:
    explicit guardar_partida(QWidget* parent = nullptr);
    ~guardar_partida() override;

private:
    Ui::guardar_partida* ui;
};


#endif //ELEMENTOS_GUARDAR_PARTIDA_H
