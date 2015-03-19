#ifndef SVG2RAD_H
#define SVG2RAD_H

#include "svg2st.h"

class Svg2rad : public Svg2st
{
    Q_OBJECT
public:
    Svg2rad( int w, int h, QWidget* parent = 0 );
    Svg2rad( const QByteArray &svgData, int w, int h, QWidget* parent = 0 );
    Svg2rad( const QString &svgName, int w, int h, QWidget* parent = 0 );
    int getSelected();
public slots:
    void onClick( int id );
signals:
    void changed( int id );
private:
    void init();
    int idSelected;
};

#endif
