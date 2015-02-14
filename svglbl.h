#ifndef SVGLBL_H
#define SVGLBL_H

#include <QLabel>
#include <QHash>
#include <QByteArray>

class SvgLbl : public QLabel
{
    Q_OBJECT
public:
    SvgLbl( int w, int h, QWidget* parent = 0 );
    SvgLbl( const QByteArray &svgData, int w, int h, QWidget* parent = 0 );
    SvgLbl( const QString &svgName, int w, int h, QWidget* parent = 0 );
    void updateContent();
    QHash<QString, QString> vars;
protected:
    void setData( const QByteArray &svgData );
    int height;
    int width;
private:
    QByteArray origData;
};

#endif
