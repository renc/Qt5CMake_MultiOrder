#ifndef SignInDialog_H
#define SignInDialog_H

#include <QDialog>

class QDialog; 
class QScrollArea;
class QGridLayout;
class QVBoxLayout;
class QScrollBar;
class QMenu;
class QAction; 
class QTextEdit;


class SignInDialog : public QDialog
{
public:
	SignInDialog(MainWindow *pMainWindow); 
	 
private:
	QTextEdit *signInInfo;
};

#endif //SignInDialog_H