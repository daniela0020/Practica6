#include "cuerpo.h"
/*
cuerpo::cuerpo()
{

}
*/
cuerpo::cuerpo(double _x, double _y, double _vx, double _vy, double _rad, double _masa)
{
    x = _x;
    y = _y;
    vx = _vx;
    vy = _vy;
    ax = 0;
    ay = 0;
    radio = _rad;
    masa = _masa;

    // sin ajustar los cuadrantes
    // setPos((x/EX), (y/EY));

    // ajustando los cuadrates
    setPos((x/EX), (-y/EY));
}
QRectF cuerpo::boundingRect() const
{
    return QRect(-radio/ER, -radio/ER, (radio*2)/ER, (radio*2)/ER);
}

void cuerpo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkGreen);
    painter->drawEllipse(boundingRect());
}

double cuerpo::getX() const
{
    return x;
}
double cuerpo::getY() const
{
    return y;
}
double cuerpo::getVx() const
{
    return vx;
}
double cuerpo::getVy() const
{
    return vy;
}
double cuerpo::getAx() const
{
    return ax;
}
double cuerpo::getAy() const
{
    return ay;
}
double cuerpo::getRad() const
{
    return radio;
}
double cuerpo::getMasa() const
{
    return masa;
}


void cuerpo::aceleracion(double x2, double y2, double m2, double numCuerpos)
{
    double dist = 0;

    dist =  pow((pow((x2-x),2) + pow((y2-y),2)),0.5);
    if (num<numCuerpos){
        ax += G*m2*(x2-x)/pow(dist,3);
        ay += G*m2*(y2-y)/pow(dist,3);
    }
    else {
        atx = ax;
        aty = ay;
        ax = G*m2*(x2-x)/pow(dist,3);
        ay = G*m2*(y2-y)/pow(dist,3);
        num = 0;
    }
    num += 1;

}

void cuerpo::velocidades()
// calcula las aceleraciones
{
    vx = vx + (atx*DT);
    vy = vy + (aty*DT);
}

void cuerpo::posiciones()
// calcula y Actualiza las posiciones
{
    x = x + (vx * DT); //+(0.5 * ax * pow(DT,2));
    y = y + (vy * DT); //+ (0.5 * ay * pow(DT,2));

    // sin ajustar los cuadrantes
    // setPos((x/EX), (y/EY));

    // ajustando los cuadrantes
    setPos((x/EX), (-y/EY));
}
