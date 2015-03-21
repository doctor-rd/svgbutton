#include "svg2st.h"

Svg2st::Svg2st( int w, int h, QWidget* parent ) : SvgBtn( w, h, parent )
{
}

Svg2st::Svg2st( const QByteArray &svgData, int w, int h, QWidget* parent ) : SvgBtn( svgData, w, h, parent )
{
}

Svg2st::Svg2st( const QString &svgName, int w, int h, QWidget* parent ) : SvgBtn( svgName, w, h, parent )
{
}

void Svg2st::setColors( const QString &up, const QString &dn )
{
    dnColor = dn;
    upColor = up;
}

void Svg2st::initButtons( int n )
{
    nButtons = n;
    clearStates();
}

void Svg2st::clearStates()
{
    for( int i = 1; i <= nButtons; i++ )
        states[ i ] = false;
}

void Svg2st::updateContent()
{
    foreach( int i, states.keys() )
        vars[ "BUTTON" + QString::number( i ) ] = states[ i ] ? dnColor : upColor;
    SvgLbl::updateContent();
}
