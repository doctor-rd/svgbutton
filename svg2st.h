#ifndef SVG2ST_H
#define SVG2ST_H

#include "svgbtn.h"

class Svg2st : public SvgBtn
{
    Q_OBJECT
public:
    Svg2st( int w, int h, QWidget* parent = 0 );
    Svg2st( const QByteArray &svgData, int w, int h, QWidget* parent = 0 );
    Svg2st( const QString &svgName, int w, int h, QWidget* parent = 0 );
    void setColors( QString &up, QString &dn );
    void updateContent();
    QHash<int, bool> states;
private:
    QString upColor;
    QString dnColor;
};

#endif
