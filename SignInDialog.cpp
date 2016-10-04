#include <QtWidgets>

#include "MainWindow.h"
#include "SignInDialog.h"

 
SignInDialog::SignInDialog(MainWindow *pMainWindow)
	: QDialog(pMainWindow)
{
	QVBoxLayout *mainLayout = new QVBoxLayout;

	QLineEdit *frontAddrEdit = new QLineEdit;
	QLineEdit *brokerIdEdit = new QLineEdit;
	QLineEdit *investorIdEdit = new QLineEdit;
	QLineEdit *passwordIdEdit = new QLineEdit;
	QFormLayout *formLayout = new QFormLayout;
	formLayout->addRow(u8"前置地址", frontAddrEdit);
	formLayout->addRow(u8"经纪公司代码", brokerIdEdit);
	formLayout->addRow(u8"投资者代码", investorIdEdit);
	formLayout->addRow(u8"用户密码", passwordIdEdit);
	mainLayout->addLayout(formLayout);

	QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Apply
		| QDialogButtonBox::Cancel);
	QPushButton *applyBtn = buttonBox->button(QDialogButtonBox::Apply);
	applyBtn->setText(u8"登入");
	QPushButton *cancelBtn = buttonBox->button(QDialogButtonBox::Cancel);
	cancelBtn->setText(u8"断开");
	mainLayout->addWidget(buttonBox);

	QFrame *line = new QFrame;
	line->setObjectName(QStringLiteral("line"));
	line->setGeometry(QRect(240, 170, 441, 16));
	line->setFrameShape(QFrame::HLine);
	line->setFrameShadow(QFrame::Sunken);
	mainLayout->addWidget(line);

	signInInfo = new QTextEdit;
	signInInfo->setText("not log in yet.");
	mainLayout->addWidget(signInInfo);

	//mainLayout->addStretch();
	setLayout(mainLayout);

	setWindowTitle(u8"账号 登入/登出");
}

