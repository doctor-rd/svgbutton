#ifndef SVG2UPDN_H
#define SVG2UPDN_H

#include "svg2btn.h"

#include <QTimer>

class Svg2updn : public Svg2btn
{
    Q_OBJECT
public:
    Svg2updn( int w, int h, QWidget* parent = 0 );
    Svg2updn( const QByteArray &svgData, int w, int h, QWidget* parent = 0 );
    Svg2updn( const QString &svgName, int w, int h, QWidget* parent = 0 );
    void setRange( int min, int max );
    operator int();
public slots:
    void setValue( int v );
    void timerslot();
    void onClick( int id );
    void onRelease( int id );
signals:
    void valueChanged( int value );
protected:
    virtual QString valueToString( int v );
    virtual int calcSpeed( int r );
    virtual int calcInterval( int r );
private:
    int min;
    int max;
    int value;
    int direction;
    int rounds;
    QTimer timer;
    void init();
};

#endif
