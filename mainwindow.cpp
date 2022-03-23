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
    int i=0, j=0,r=0,e=0;
    /*
    QList <cuerpo*>::iterator K = sistema.begin();

    while (K != sistema.end()){
        cout << *K << endl;
        K++;
    }
    */
    if (numCuerpos == contador){
        fout.open("Posiciones.txt",ios::app); //abre el archivo para escritura
        for (r=0 ; r<2  ; r++)
        {
            for (e=0; e < sistema.length(); e++) {
                for (j=0 ; j < sistema.length() ; j++)
                {
                    sistema.at(j)->aceleracion(sistema[e]->getX(),sistema[e]->getY(),sistema[e]->getMasa());
                    sistema.at(j)->velocidades();
                    sistema.at(j)->posiciones();
                    cout <<"eso "<< sistema[j]->getX() << endl;
                    fout<< sistema.at(j)->getX();
                    fout<<' ';
                    fout<<' ';
                    cout <<"eso " << sistema.at(j)->getY() << endl;
                    fout<< sistema.at(j)->getY();
                }
            }
            fout<<endl;

        }
        fout.close();
    }
}



MainWindow::~MainWindow()
{
    delete ui;
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
        fout<<sistema[contador]->getY();
        if (contador < numCuerpos-1){
            fout<<" ";
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
        /*
        timer->start(33);
        */
        fout.close();

    }
    if (contador == numCuerpos-1){
        Actualizar();
        timer->start(33);
    }



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


