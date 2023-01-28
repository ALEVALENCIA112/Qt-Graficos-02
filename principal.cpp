#include "principal.h"
#include "ui_principal.h"

#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    lienzo = QPixmap(500,500);
    this->dibujar();

    ui->outCuadro->setPixmap(lienzo);


}

Principal::~Principal()
{
    delete ui;
}

/*funcion miembro para crear graficos dinamicos
  acepta el evento de cambio de algún valor*/
void Principal::paintEvent(QPaintEvent *event)
{
    ui->outCuadro->setPixmap(lienzo);
    // Aceptar el evento
    event;
}

void Principal::dibujar()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x = 0;
    int y = 0;

    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::red);
    pincel.setJoinStyle(Qt::MiterJoin);

    // Establecer el pincel al "pintor"
    painter.setPen(pincel);

    //en la variable creada se almacena el valor ingresado en el spinBox, en este caso el spinBox_nota1
    int nota1 = ui->spinBox_nota1->value();
    //variable creada para almacenar la altura de la barra en base al valor ingresado
    int alto1 = this->getaltura(nota1);

    // Dibujar primera barra
    painter.drawRect(x+50, y+450,100,-alto1);
    /*no se toma la variable "nota1" ya que el tamaño del gráfico no correspondería a
    la escala gráfica, sino que correspondería a la escala de "Qtlabel"*/

    //en ocasiones no es necesarios colocar x+ || y+ sino unicamente los valores

    /*El punto (0 ; 0) u origen de la pantalla se encuentra en la esquina superior izquierda del margen

     * El punto de origen del grafico:  POSICIÖN

        Si el valor es positivo el punto de donde se graficará será:
                                                            para X de izquierda a derecha
                                                            para Y de arriba a abajo

        Si el valor es negativo el punto de donde se graficará será:
                                                            para X de derecha a izquierda
                                                            para Y de abajo a arriba

        Siempre tomando en cuenta el punto de origen

       * En nuestro caso nuetro punto de origen de grafico será (x+50; y+450)

     * Para armar el grafico:   TAMAÑO

     El tamaño dependera de los valores que ubiquemos para los tamaños correspondientes de X & Y (# ; #)

        Si el valor ingresado es positivo entonces el grafico irá: de
                                                                de izquierda a derecha en el caso de X
                                                                de arriba a abajo en el caso de Y

        Si el valor ingresado es negativo entonces el grafico irá: de
                                                                de derecha a izquierda en el caso de X
                                                                de abajo a arriba en el caso de Y

      * Nuestros valores son (100 ; -400)

      * En nuestro caso los valores a los que ira nuestro grafico será:
                                                                desde x+50 hasta 100 (izquierda a derecha)
                                                                desde x+450 hasta -### (abajo a arriba)

    */

    // Crear un objeto color para el relleno
    QColor colorRelleno(190,120,162);
    // Crear otro objeto color para el borde
    QColor colorBorde(78,3,48);

    // Cambiar el color del pincel
    pincel.setColor(colorBorde);

    // Volver a establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Establecer el color al brush (relleno)
    painter.setBrush(colorRelleno);


    /*se realiza el mismo proceso que para graficar la barra 1,unicamente creando
    nuevas variables de almacenamiento y conectandolas de forma correcta*/

    //en la variable creada se almacena el valor ingresado en el spinBox, en este caso el spinBox_nota2 <=== OJO
    int nota2 = ui->spinBox_nota2->value();
    //variable creada para almacenar la altura de la barra en base al valor ingresado
    //tambien se cambia el valor que toma "getaltura()" para que se correspondiente
    int alto2 = this->getaltura(nota2);

    //Para graficar la barra prestar atención que en los datos de POSICIÖN (x+### ; y+###) & TAMAÑO (### ; ###) se encuentren declarados de forma correcta
    // Dibujar segunda barra
    painter.drawRect(x+170, y+450, 100, -alto2);
    /*no se toma la variable "nota2" ya que el tamaño del gráfico no correspondería a
    la escala gráfica, sino que correspondería a la escala de "Qtlabel"*/

    // Creando los colores de la tercera barra
    QColor cRellenoBarra3(253, 253, 115);
    QColor cBordeBarra3(174, 174, 51);

    // Estableciendo colores al puncel y al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    /*se realiza el mismo proceso que para graficar la barra 1,unicamente creando
    nuevas variables de almacenamiento y conectandolas de forma correcta*/

    //en la variable creada se almacena el valor ingresado en el spinBox, en este caso el spinBox_nota3 <=== OJO
    int nota3 = ui->spinBox_nota3->value();
    //variable creada para almacenar la altura de la barra en base al valor ingresado
    //tambien se cambia el valor que toma "getaltura()" para que se correspondiente
    int alto3 = this->getaltura(nota3);

    //Para graficar la barra prestar atención que en los datos de POSICIÖN (x+### ; y+###) & TAMAÑO (### ; ###) se encuentren declarados de forma correcta
    // Dibujar tercera barra
    painter.drawRect(x+290,y+450,100,-alto3);
    /*no se toma la variable "nota3" ya que el tamaño del gráfico no correspondería a
    la escala gráfica, sino que correspondería a la escala de "Qtlabel"*/
}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

void Principal::on_pushButton_clicked(bool checked)
{

}

int Principal::getaltura(int valor)
{
    return 4 * valor;
}


//los slots al cumplir con su parametro ejecutan la función de graficar
void Principal::on_spinBox_nota1_valueChanged(int valor)
{
    dibujar();
}

void Principal::on_spinBox_nota2_valueChanged(int valor)
{
    dibujar();
}

void Principal::on_spinBox_nota3_valueChanged(int valor)
{
    dibujar();
}


