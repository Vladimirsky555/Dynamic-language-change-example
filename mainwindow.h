#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QEvent>

#include "widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QTranslator translator;

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

private:
    Ui::MainWindow *ui;

    // QWidget interface
protected:
    virtual void changeEvent(QEvent *event) override;
private slots:
    void on_btnOpen_clicked();
};
#endif // MAINWINDOW_H
