#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // se agrega la escena
    scene = new QGraphicsScene(-500, -250, 1000, 500);
    ui->graphicsView->setScene(scene);
    // limites de la escena
    l1 = new QGraphicsLineItem(-500,-250,500,-250);
    l2 = new QGraphicsLineItem(-500,250,500,250);
    l3 = new QGraphicsLineItem(-500,-250,-500,250);
    l4 = new QGraphicsLineItem(500,-250,500,250);

    // Se agregan los limites a la escena
   scene->addItem(l1);
   scene->addItem(l2);
   scene->addItem(l3);
   scene->addItem(l4);

   secuencia = false;

   timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()), this, SLOT(Actualizar()));
}

void MainWindow::Actualizar()
//Actualiza las velocidades y posiciones del cuerpo
{
    int j=0,r=0,e=0;
    /*
    QList <cuerpo*>::iterator K = sistema.begin();

    while (K != sistema.end()){
        cout << *K << endl;
        K++;
    }
    */

    fout.open("Posiciones.txt",ios::app); //abre el archivo para escritura
    for (r=0 ; r<5  ; r++)
    {
        for (e=0; e < sistema.length(); e++) {
            for (j=0 ; j < sistema.length() ; j++)
            {
                if(e!=j){
                    sistema.at(e)->aceleracion(sistema[j]->getX(),sistema[j]->getY(),sistema[j]->getMasa(),numCuerpos);

                }
                else if (e < sistema.length()-1) {
                    sistema.at(e)->aceleracion(sistema[j+1]->getX(),sistema[j+1]->getY(),sistema[j+1]->getMasa(),numCuerpos);
                }
                else if (e == sistema.length()-1 && e==j){
                    sistema.at(e)->aceleracion(sistema[e-1]->getX(),sistema[e-1]->getY(),sistema[e-1]->getMasa(),numCuerpos);
                }

            }
            sistema.at(e)->velocidades();
            sistema.at(e)->posiciones();
            cout <<"eso "<< sistema[e]->getX() << endl;
            fout<< sistema.at(e)->getX();
            fout<<' ';
            fout<<' ';
            fout<<' ';
            cout <<"eso " << sistema.at(e)->getY() << endl;
            fout<< sistema.at(e)->getY();
            if (e!=sistema.length()-1){
                fout<<' ';
                fout<<' ';
                fout<<' ';
            }
            else{
                fout<<endl;

            }
        }


    }
    fout.close();

}



MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}


void MainWindow::on_pushButton_clicked()
{
    numCuerpos = ui->cuerpos->value();
    if (contador < numCuerpos){
        sistema.append(new cuerpo(ui->Xinicial->value(),ui->Yinicial->value(),ui->velocidadX->value(),ui->velocidadY->value(),ui->radio->value(),ui->masa->value()));
        //cout <<"Xinicial: " << ui->Xinicial->value()<<endl;
        //cout <<"getX: " <<sistema[contador]->getX()<< endl;

        fout.open("Posiciones.txt",ios::app);
        fout<<sistema[contador]->getX();
        fout<<" ";
        fout<<' ';
        fout<<' ';
        fout<<sistema[contador]->getY();
        if (contador < numCuerpos-1){
            fout<<" ";
            fout<<' ';
            fout<<' ';
        }
        else{
            fout<<endl;
        }
        contador += 1;
        ui->Xinicial->setValue(0);
        ui->Yinicial->setValue(0);
        ui->masa->setValue(0);
        ui->radio->setValue(0);
        ui->velocidadX->setValue(0);
        ui->velocidadY->setValue(0);
        scene->addItem(sistema.last());
        fout.close();

    }
    /*
    if (contador == numCuerpos-1){
        Actualizar();
        //timer->start(33);
    }

    */

}


void MainWindow::on_pushButton_2_clicked()

//para finalizar la simulacion
{
    int i=0;

    timer->stop();

    for (i=0 ; i < sistema.length() ; i++)
        scene->removeItem(sistema[i]);

    sistema.clear();
    contador = 0;
    secuencia = false;
}



void MainWindow::on_pushButton_3_clicked()
{
    timer->start(33);
}

