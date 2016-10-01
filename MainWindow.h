#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QScrollArea;
class QGridLayout;
class QVBoxLayout;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();

	void addOrder();

private slots:
		void onAddOrder();
		void onPlaceOrder();

private:
	QScrollArea *scrollArea;
	//QVBoxLayout *scrollWidgetLayout;
	QGridLayout *scrollWidgetLayout;
}; 

#endif //MAINWINDOW_H