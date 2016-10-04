#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QScrollArea;
class QGridLayout;
class QVBoxLayout;
class QScrollBar;
class QMenu;
class QAction;
class SignInDialog;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();
	void createActions();
	void createMenus();
	void addOrder();

private slots:
	void onAccountAction();
	void onAboutAction();
		void onAddOrder();
		void onPlaceOrder();

private:
	QScrollArea *scrollArea; 
	QScrollBar *scrollBar;
	QGridLayout *scrollWidgetLayout;

	QMenu *fileMenu;
	QMenu *helpMenu;
	QAction *accountAct;
	QAction *aboutAct;
}; 

#endif //MAINWINDOW_H