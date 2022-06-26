#ifndef COLORCIRCLE_H
#define COLORCIRCLE_H

#include "qobject.h"
#include "qobjectdefs.h"
#include "qpixmap.h"
#include <QObject>
#include <QWidget>
#include "qlabel.h"

class colorCircle: public QObject
{
	Q_OBJECT

	QPixmap yellowCircle;
	QPixmap redCircle;
	QPixmap greenCircle;

	QLabel* plbl;

	void setCircleColor(QPixmap& pixmap);

public:
	colorCircle();
	QLabel* getLblPtr() {return plbl;};

public slots:
	void changeColor(int inp);
};

#endif // COLORCIRCLE_H
