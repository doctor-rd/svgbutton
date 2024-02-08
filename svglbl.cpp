#include "svglbl.h"

#include <QFile>
#include <QSvgRenderer>
#include <QPainter>

SvgLbl::SvgLbl( int w, int h, QWidget* parent ) : QLabel( parent )
{
    height = h;
    width = w;
    setFixedSize( w, h );
}

SvgLbl::SvgLbl( const QByteArray &svgData, int w, int h, QWidget* parent ) : QLabel( parent )
{
    origData = svgData;
    height = h;
    width = w;
    setFixedSize( w, h );
}

SvgLbl::SvgLbl( const QString &svgName, int w, int h, QWidget* parent ) : QLabel( parent )
{
    QFile svgfile( svgName );
    if( svgfile.open( QIODevice::ReadOnly ) )
        origData = svgfile.readAll();
    height = h;
    width = w;
    setFixedSize( w, h );
}

void SvgLbl::updateContent()
{
    QByteArray tempData = origData;
    foreach( QString i, vars.keys() )
        tempData.replace( ( "%" + i + "%" ).toUtf8(), vars[i].toUtf8() );
    QSvgRenderer renderer( tempData );
    QPixmap pixmap( width, height );
    pixmap.fill();
    QPainter painter( &pixmap );
    renderer.render( &painter );
    setPixmap( pixmap );
}

void SvgLbl::setData( const QByteArray &svgData )
{
    if( origData.isEmpty() )
        origData = svgData;
}
