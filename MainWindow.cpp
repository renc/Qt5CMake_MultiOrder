#include <QtWidgets>

#include "MainWindow.h"
#include "SignInDialog.h"

 
MainWindow::MainWindow()
{
	createActions();
	createMenus();

	QWidget *centerWidget = new QWidget;
	QVBoxLayout *centerLayout = new QVBoxLayout;
	centerWidget->setLayout(centerLayout);
	setCentralWidget(centerWidget);
	
	scrollArea = new QScrollArea;
	scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	scrollArea->setBackgroundRole(QPalette::Dark);
	scrollArea->setWidgetResizable(true); // renc: otherwise the scrallWidget will fix fix size.
	centerLayout->addWidget(scrollArea);	

	QWidget *scrollWidget = new QWidget;
	scrollArea->setWidget(scrollWidget);
	 
	scrollWidgetLayout = new QGridLayout; // renc: try to use box layout or grid layout.
	scrollWidgetLayout->setAlignment(Qt::AlignTop); // renc: the new append item will be from top to bottom.
	scrollWidget->setLayout(scrollWidgetLayout); 
	
	addOrder();

	//
	QHBoxLayout *buttonLayout = new QHBoxLayout;
	QPushButton *addOrderButton = new QPushButton(u8"新加合约");
	QPushButton *placeOrderButton = new QPushButton(u8"下单");
	buttonLayout->addWidget(addOrderButton);
	buttonLayout->addStretch();
	buttonLayout->addWidget(placeOrderButton);
	centerLayout->addLayout(buttonLayout); 

	connect(addOrderButton, SIGNAL(clicked()), this, SLOT(onAddOrder()));
	connect(placeOrderButton, SIGNAL(clicked()), this, SLOT(onPlaceOrder()));

	statusBar()->showMessage("status bar message");
	setWindowTitle(u8"多单程序"); 
	setMinimumSize(1000, 480);
}
 
void MainWindow::createActions()
{
	accountAct = new QAction(u8"账号");
	accountAct->setStatusTip(u8"登录 or 退出账号");
	connect(accountAct, &QAction::triggered, this, &MainWindow::onAccountAction);

	aboutAct = new QAction(u8"关于");
	aboutAct->setStatusTip(u8"关于本软件的信息");
	connect(aboutAct, &QAction::triggered, this, &MainWindow::onAboutAction);
}
void MainWindow::createMenus()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(accountAct); 
	fileMenu->addSeparator(); 
	 
	helpMenu = menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction(aboutAct);
}


void MainWindow::onAccountAction()
{
	SignInDialog *pD = new SignInDialog(this);
	pD->exec();
}

void MainWindow::onAboutAction()
{
	;
}

void MainWindow::onAddOrder()
{
	addOrder();
}

void MainWindow::onPlaceOrder()
{
	qInfo() << "onPlaceOrder";
}

void MainWindow::addOrder()
{
	// insert an new row

	static int debugIdx = 0; 
	QLabel *contractLabel = new QLabel(u8"合约号: ");
	QLineEdit *contractNum = new QLineEdit;
	contractNum->setText(QString::number(debugIdx++));
	QHBoxLayout *contractLayout = new QHBoxLayout;
	contractLayout->addWidget(contractLabel);
	contractLayout->addWidget(contractNum);

	QRadioButton *buyIn = new QRadioButton(u8"买入");
	buyIn->setChecked(true);
	QRadioButton *sellOut = new QRadioButton(u8"卖出");
	sellOut->setChecked(false);
	QButtonGroup *buySellGroup = new QButtonGroup;
	buySellGroup->addButton(buyIn, 0);
	buySellGroup->addButton(sellOut, 1);
	QHBoxLayout *buySellLayout = new QHBoxLayout;
	buySellLayout->addWidget(buyIn);
	buySellLayout->addWidget(sellOut);

	
	QCheckBox *openPosition = new QCheckBox(u8"开仓");
	QCheckBox *liquidatePosition = new QCheckBox(u8"平仓");
	QCheckBox *dayTrade = new QCheckBox(u8"平今");
	openPosition->setChecked(true);
	QButtonGroup *positionGroup = new QButtonGroup;
	positionGroup->addButton(openPosition, 0);
	positionGroup->addButton(liquidatePosition, 1);
	positionGroup->addButton(dayTrade, 2);
	QHBoxLayout *positionLayout = new QHBoxLayout;
	positionLayout->addWidget(openPosition);
	positionLayout->addWidget(liquidatePosition);
	positionLayout->addWidget(dayTrade); 
		 
	QLabel *priceLabel = new QLabel(u8"对手价: ");
	QLineEdit *priceNum = new QLineEdit; 
	QHBoxLayout *priceLayout = new QHBoxLayout;
	priceLayout->addWidget(priceLabel);
	priceLayout->addWidget(priceNum);

	QLabel *handLabel = new QLabel(u8"手数: ");
	QSpinBox *handNum = new QSpinBox;
	handNum->setRange(0, 9999);
	QHBoxLayout *handLayout = new QHBoxLayout;
	handLayout->addWidget(handLabel);
	handLayout->addWidget(handNum);
		
	const int rowCount = scrollWidgetLayout->rowCount();
	int columnCount = 0;
	scrollWidgetLayout->addLayout(contractLayout, rowCount, columnCount++);
	scrollWidgetLayout->addLayout(buySellLayout, rowCount, columnCount++);
	scrollWidgetLayout->addLayout(positionLayout, rowCount, columnCount++);
	scrollWidgetLayout->addLayout(priceLayout, rowCount, columnCount++);
	scrollWidgetLayout->addLayout(handLayout, rowCount, columnCount++);
	
	QScrollBar *vBar = scrollArea->verticalScrollBar();
	qInfo() << "scrollbar value" << vBar->value() << ", " << vBar->maximum();
	
	vBar->setValue(vBar->maximum());
}
