#include "svg2updn.h"

Svg2updn::Svg2updn( int w, int h, QWidget* parent ) : Svg2btn( w, h, parent )
{
    init();
}

Svg2updn::Svg2updn( const QByteArray &svgData, int w, int h, QWidget* parent ) : Svg2btn( svgData, w, h, parent )
{
    init();
}

Svg2updn::Svg2updn( const QString &svgName, int w, int h, QWidget* parent ) : Svg2btn( svgName, w, h, parent )
{
    init();
}

void Svg2updn::init()
{
    timer.setSingleShot( true );
    connect(this, &Svg2updn::clicked, this, &Svg2updn::onClick);
    connect(this, &Svg2updn::released, this, &Svg2updn::onRelease);
    connect(&timer, &QTimer::timeout, this, &Svg2updn::timerslot);
    value = 0;
    setRange( 0, 100 );
}

void Svg2updn::setRange( int _min, int _max )
{
    min = _min;
    max = _max;
    setValue( value );
}

void Svg2updn::setValue( int v )
{
    if( v < min )
        v = min;
    if( v > max )
        v = max;
    bool chng = value != v;
    value = v;
    vars[ "TEXT" ] = valueToString( v );
    updateContent();
    if( chng )
        emit valueChanged( value );
}

void Svg2updn::timerslot()
{
    if( direction == 0 )
        return;
    rounds++;
    setValue( value + direction * calcSpeed( rounds ) );
    timer.start( calcInterval( rounds ) );
}

void Svg2updn::onClick( int id )
{
    direction = 0;
    rounds = 0;
    switch( id )
    {
        case 1: direction = 1; break;
        case 2: direction = -1; break;
    }
    setValue( value + direction * calcSpeed( 0 ) );
    timer.start( calcInterval( 0 ) );
}

void Svg2updn::onRelease( int id )
{
    direction = 0;
    timer.stop();
}

QString Svg2updn::valueToString( int v )
{
    return QString::number( v );
}

int Svg2updn::calcSpeed( int r )
{
    return 1;
}

int Svg2updn::calcInterval( int r )
{
    if( r == 0 )
        return 1000;
    return 100;
}

Svg2updn::operator int()
{
    return value;
}
