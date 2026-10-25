//
// Created by chelokito on 16/8/26.
//

#ifndef ELEMENTOS_VENTANAJUEGO_H
#define ELEMENTOS_VENTANAJUEGO_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui
{
    class VentanaJuego;
}

QT_END_NAMESPACE

class VentanaJuego : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaJuego(QWidget* parent = nullptr);
    ~VentanaJuego() override;

private:
    Ui::VentanaJuego* ui;
};


#endif //ELEMENTOS_VENTANAJUEGO_H
