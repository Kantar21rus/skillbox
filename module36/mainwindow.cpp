#include "mainwindow.h"
#include "colorcircle.h"
#include "qnamespace.h"
#include "qpainter.h"
#include "qpixmap.h"
#include "qslider.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	QWidget* wgt = new QWidget;

	auto layout = new QVBoxLayout(wgt);
	auto ptrSlider = new QSlider(Qt::Horizontal);
	colorCircle* circle = new colorCircle;

	ptrSlider->setRange(0,99);
	ptrSlider->setPageStep(33);
	ptrSlider->setValue(50);
	ptrSlider->setTickInterval(33);
	ptrSlider->setTickPosition(QSlider::TicksBelow);

	QObject::connect(ptrSlider, SIGNAL(valueChanged(int)),circle, SLOT(changeColor(int)));

	layout->addWidget(circle->getLblPtr());
	layout->addWidget(ptrSlider);


	wgt->setLayout(layout);
	wgt->resize(300, 600);

	wgt->show();
}

MainWindow::~MainWindow()
{
}

