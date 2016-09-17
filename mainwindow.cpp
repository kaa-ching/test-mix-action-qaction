#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QQmlContext>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    theGameButtonGroup(this),
    theActionOnePtr(nullptr),
    theActionTwoPtr(nullptr)
{
    ui->setupUi(this);

    QAction* theOne = new QAction("Go One", nullptr);
    theOne->setShortcut(QKeySequence("1"));
    theOne->setCheckable(true);
    connect(theOne, SIGNAL(triggered(bool)), this, SLOT(goOne()));

    ui->menuMenu2->addAction(theOne);
    ui->push1->setDefaultAction(theOne);

    QAction* theTwo = new QAction("Go Two", nullptr);
    theTwo->setShortcut(QKeySequence("2"));
    theTwo->setCheckable(true);
    connect(theTwo, SIGNAL(triggered(bool)), this, SLOT(goTwo()));

    ui->menuMenu2->addAction(theTwo);
    ui->push2->setDefaultAction(theTwo);

    theGameButtonGroup.addAction(theOne);
    theGameButtonGroup.addAction(theTwo);
    theGameButtonGroup.setExclusive(true);

    QCoreApplication::setAttribute(Qt::AA_DontCreateNativeWidgetSiblings, true);
    ui->quickWidget->rootContext()->setContextProperty(QStringLiteral("MainWindow"), this);
    ui->quickWidget->rootContext()->setContextProperty(QStringLiteral("theOne"), theOne);
    ui->quickWidget->rootContext()->setContextProperty(QStringLiteral("theTwo"), theTwo);
    ui->quickWidget->setSource(QUrl("qrc:/main.qml"));

    theActionOnePtr = ui->quickWidget->rootObject()->findChild<QObject*>("actionOne");
    theActionTwoPtr = ui->quickWidget->rootObject()->findChild<QObject*>("actionTwo");

    emit theTwo->trigger();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goOne()
{
    printf("go one\n");
    theActionOnePtr->setProperty("checked", true);
}

void MainWindow::goTwo()
{
    printf("go two\n");
    theActionTwoPtr->setProperty("checked", true);
}
