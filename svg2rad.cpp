#include "svg2rad.h"

Svg2rad::Svg2rad( int w, int h, QWidget* parent ) : Svg2st( w, h, parent )
{
    init();
}

Svg2rad::Svg2rad( const QByteArray &svgData, int w, int h, QWidget* parent ) : Svg2st( svgData, w, h, parent )
{
    init();
}

Svg2rad::Svg2rad( const QString &svgName, int w, int h, QWidget* parent ) : Svg2st( svgName, w, h, parent )
{
    init();
}

void Svg2rad::init()
{
    idSelected = 0;
    connect(this, &Svg2rad::clicked, this, &Svg2rad::onClick);
}

int Svg2rad::getSelected()
{
    return idSelected;
}

void Svg2rad::onClick( int id )
{
    if( id == -1 )
        return;
    bool chng = idSelected != id;
    idSelected = id;
    clearStates();
    if( idSelected > 0 )
        states[ idSelected ] = true;
    updateContent();
    if( chng )
        emit changed( idSelected );
}
