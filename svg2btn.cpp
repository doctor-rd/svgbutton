#include "svg2btn.h"

Svg2btn::Svg2btn( int w, int h, QWidget* parent ) : Svg2st( w, h, parent )
{
    init();
}

Svg2btn::Svg2btn( const QByteArray &svgData, int w, int h, QWidget* parent ) : Svg2st( svgData, w, h, parent )
{
    init();
}

Svg2btn::Svg2btn( const QString &svgName, int w, int h, QWidget* parent ) : Svg2st( svgName, w, h, parent )
{
    init();
}

void Svg2btn::init()
{
    connect(this, &Svg2btn::clicked, this, &Svg2btn::onClick);
    connect(this, &Svg2btn::released, this, &Svg2btn::onRelease);
}

void Svg2btn::onClick( int id )
{
    if( id == -1 )
        return;
    states[ id ] = true;
    updateContent();
}

void Svg2btn::onRelease( int id )
{
    clearStates();
    updateContent();
}
