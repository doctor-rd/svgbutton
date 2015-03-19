#ifndef SVG2BTN_H
#define SVG2BTN_H

#include "svg2st.h"

class Svg2btn : public Svg2st
{
    Q_OBJECT
public:
    Svg2btn( int w, int h, QWidget* parent = 0 );
    Svg2btn( const QByteArray &svgData, int w, int h, QWidget* parent = 0 );
    Svg2btn( const QString &svgName, int w, int h, QWidget* parent = 0 );
public slots:
    void onClick( int id );
    void onRelease( int id );
private:
    void init();
};

#endif
