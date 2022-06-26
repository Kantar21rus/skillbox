#include "colorcircle.h"

colorCircle::colorCircle()
{
	yellowCircle = QPixmap("yellow.png");
	redCircle = QPixmap("red.png");
	greenCircle = QPixmap("green.png");

	plbl = new QLabel;

	setCircleColor(yellowCircle);


}

void colorCircle::setCircleColor(QPixmap& pixmap)
{
	plbl->setPixmap(pixmap);
	plbl->update();
}


void colorCircle::changeColor(int inp)
{
	if (inp < 33) {
		setCircleColor(greenCircle);
	} else if (inp >= 33 and inp < 66) {
		setCircleColor(yellowCircle);
	} else if (inp >= 66) {
		setCircleColor(redCircle);
	}
}
