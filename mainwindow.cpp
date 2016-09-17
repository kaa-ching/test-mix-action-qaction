#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QQmlContext>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    theGameButtonGroup(this)
{
    ui->setupUi(this);

    QAction* theOne = new QAction("Go One", 0);
    theOne->setShortcut(QKeySequence("1"));
    connect(theOne, SIGNAL(triggered(bool)), this, SLOT(goOne()));

    ui->menuMenu2->addAction(theOne);
    ui->push1->setDefaultAction(theOne);

    QAction* theTwo = new QAction("Go Two", 0);
    theTwo->setShortcut(QKeySequence("2"));
    connect(theTwo, SIGNAL(triggered(bool)), this, SLOT(goTwo()));

    ui->menuMenu2->addAction(theTwo);
    ui->push2->addAction(theTwo);


    QCoreApplication::setAttribute(Qt::AA_DontCreateNativeWidgetSiblings, true);
    ui->quickWidget->rootContext()->setContextProperty(QStringLiteral("MainWindow"), this);
    ui->quickWidget->rootContext()->setContextProperty(QStringLiteral("theOne"), theOne);
    ui->quickWidget->rootContext()->setContextProperty(QStringLiteral("theTwo"), theTwo);
    ui->quickWidget->setSource(QUrl("qrc:/main.qml"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goOne()
{
    printf("go one\n");
}

void MainWindow::goTwo()
{
    printf("go two\n");
}
