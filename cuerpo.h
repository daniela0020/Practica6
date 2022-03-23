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
    float x, y, vx, vy, ax, ay, radio, masa;
public:
    cuerpo();
    cuerpo(float _x, float _y, float _vx, float _vy, float _radio, float _masa);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    // Funciones mvto
    void aceleracion(float x2, float y2,float m2);
    void velocidades();
    void posiciones();

    // get
    float getX() const;
    float getY() const;
    float getVx() const;
    float getVy() const;
    float getAx() const;
    float getAy() const;
    float getRad() const;
    float getMasa() const;

    // set
    void setX(float value);
    void setY(float value);
    void setVx(float value);
    void setVy(float value);
    void setAx(float value);
    void setAy(float value);
    void setRad(float value);
    void setMasa(float value);

};

#endif // CUERPO_H
