#include <QtWidgets>

#include "MainWindow.h"

MainWindow::MainWindow()
{
	QWidget *widget = new QWidget;
	setCentralWidget(widget);

	setWindowTitle(u8"多单程序"); 
	setMinimumSize(640, 480);
}