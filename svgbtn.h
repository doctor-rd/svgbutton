#ifndef SVGBTN_H
#define SVGBTN_H

#include "svglbl.h"

#include <QImage>
#include <QMouseEvent>

class SvgBtn : public SvgLbl
{
    Q_OBJECT
public:
    SvgBtn( int w, int h, QWidget* parent = 0 );
    SvgBtn( const QByteArray &svgData, int w, int h, QWidget* parent = 0 );
    SvgBtn( const QString &svgName, int w, int h, QWidget* parent = 0 );
    void setHelper( const QImage &helperImage );
    void setHelper( const QByteArray &helperSvg );
    void setHelper( const QString &helperName );
    static QString NrToHex( int n );
signals:
    void clicked( int id );
    void released( int id );
protected:
    virtual void mousePressEvent( QMouseEvent* ev );
    virtual void mouseReleaseEvent( QMouseEvent* ev );
private:
    QImage helper;
    int MouseEventToNr( QMouseEvent* ev );
};

#endif
