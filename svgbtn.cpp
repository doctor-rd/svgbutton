#include "svgbtn.h"

#include <QSvgRenderer>
#include <QPainter>
#include <QFile>

SvgBtn::SvgBtn( int w, int h, QWidget* parent ) : SvgLbl( w, h, parent )
{
}

SvgBtn::SvgBtn( const QByteArray &svgData, int w, int h, QWidget* parent ) : SvgLbl( svgData, w, h, parent )
{
}

SvgBtn::SvgBtn( const QString &svgName, int w, int h, QWidget* parent ) : SvgLbl( svgName, w, h, parent )
{
}

void SvgBtn::setHelper( const QImage &helperImage )
{
    if( helper.isNull() )
        helper = helperImage;
}

void SvgBtn::setHelper( const QByteArray &helperSvg )
{
    QImage h( width, height, QImage::Format_ARGB32 );
    h.fill( 0 );
    QPainter painter( &h );
    painter.setRenderHint( QPainter::Antialiasing, false );
    QSvgRenderer renderer( helperSvg );
    renderer.render( &painter );
    setHelper( h );
}

void SvgBtn::setHelper( const QString &helperName )
{
    QFile svgfile( helperName );
    if( svgfile.open( QIODevice::ReadOnly ) )
        setHelper( svgfile.readAll() );
}

QString SvgBtn::NrToHex( int n )
{
    QString res( "#" );
    for( int i = 0; i < 3; i++ )
        res.append( ( ( n>>i ) & 1 ) == 1 ? "ff" : "00" );
    return res;
}

int SvgBtn::MouseEventToNr( QMouseEvent* ev )
{
    QRgb rgb = helper.pixel( ev->pos() );
    if( rgb>>24 != 0xff )
        return -1;
    for( int i = 1; i <= 6; i++ )
        if( NrToHex( i ) == QColor( rgb ).name() )
            return i;
    return -1;
}

void SvgBtn::mousePressEvent( QMouseEvent* ev )
{
    emit clicked( MouseEventToNr( ev ) );
}

void SvgBtn::mouseReleaseEvent( QMouseEvent* ev )
{
    emit released( MouseEventToNr( ev ) );
}
