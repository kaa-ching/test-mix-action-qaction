#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QActionGroup>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void goOne();
    void goTwo();

private:
    Ui::MainWindow *ui;

    QActionGroup theGameButtonGroup;
    QAction* theOne;
    QAction* theTwo;
};

#endif // MAINWINDOW_H
