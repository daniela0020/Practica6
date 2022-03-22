#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "cuerpo.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ofstream fout;

public slots:
    void Actualizar();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    // puntero de mi escena
    QGraphicsScene *scene;

    // temporizador para el pulso
    QTimer *timer;

    //limites
    QGraphicsLineItem *l1;
    QGraphicsLineItem *l2;
    QGraphicsLineItem *l3;
    QGraphicsLineItem *l4;

    //lista de objetos
    QList <cuerpo*> sistema;

    //booleano para controlar la simulación
    bool secuencia;
    unsigned int numCuerpos = 0;
    unsigned int contador = 0;


};
#endif // MAINWINDOW_H
