#ifndef CUERPO_H
#define CUERPO_H
#include <QGraphicsItem>
#include <QPainter>
#include <math.h>
#define EX 20
#define EY 20
#define ER 20
#define G 1
#define DT 1

class cuerpo : public QGraphicsItem
{
private:
    double x, y, vx, vy, ax, ay, radio, masa,atx,aty;
public:
    cuerpo();
    cuerpo(double _x, double _y, double _vx, double _vy, double _radio, double _masa);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    // Funciones mvto
    void aceleracion(double x2, double y2,double m2,double numCuerpos);
    void velocidades();
    void posiciones();

    // get
    double getX() const;
    double getY() const;
    double getVx() const;
    double getVy() const;
    double getAx() const;
    double getAy() const;
    double getRad() const;
    double getMasa() const;
    unsigned int num = 0;

};

#endif // CUERPO_H
