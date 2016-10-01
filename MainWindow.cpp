#include <QtWidgets>

#include "MainWindow.h"

MainWindow::MainWindow()
{
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

	//scrollWidgetLayout = new QVBoxLayout;
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

	setWindowTitle(u8"多单程序"); 
	setMinimumSize(640, 480);
}
 
void MainWindow::onAddOrder()
{
	qInfo() << "onAddOrder";
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

	QLabel *priceLabel = new QLabel(u8"对手价: ");
	QLineEdit *priceNum = new QLineEdit; 
	QHBoxLayout *priceLayout = new QHBoxLayout;
	priceLayout->addWidget(priceLabel);
	priceLayout->addWidget(priceNum);

	QLabel *handLabel = new QLabel(u8"手数: ");
	QLineEdit *handNum = new QLineEdit;
	QHBoxLayout *handLayout = new QHBoxLayout;
	handLayout->addWidget(handLabel);
	handLayout->addWidget(handNum);


	
	const int rowCount = scrollWidgetLayout->rowCount();
	scrollWidgetLayout->addLayout(contractLayout, rowCount, 0);
	scrollWidgetLayout->addLayout(priceLayout, rowCount, 1);
	scrollWidgetLayout->addLayout(handLayout, rowCount, 2);
	
	//QHBoxLayout *rowLayout = new QHBoxLayout;
	//rowLayout->addLayout(contractLayout);
	//rowLayout->addLayout(priceLayout);
	//rowLayout->addLayout(handLayout);  
	//scrollWidgetLayout->insertLayout(debugIdx-1, rowLayout); 
}