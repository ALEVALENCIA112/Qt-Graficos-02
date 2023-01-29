#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_actionGuardar_triggered();

    void on_pushButton_clicked();

    //slots de cada spinBox, el parametro de activación es el cambio de valor
    void on_spinBox_nota1_valueChanged(int valor);
    void on_spinBox_nota2_valueChanged(int valor);
    void on_spinBox_nota3_valueChanged(int valor);

protected:
    /*Esta esta funcion miembro (o metodo)
    es la clave para crear dibujos dinamicos*/
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Principal *ui;
    QPixmap lienzo;

    void dibujar();
    int getaltura(int valor);
    float prom;

};
#endif // PRINCIPAL_H
