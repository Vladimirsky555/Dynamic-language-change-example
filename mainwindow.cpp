#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItems(QStringList() << "ru_RU" << "en_US");

    /*
     * Поключаем к сигналу изменения пункта комбобокса лямбда-функцию, в которой будет
     * изменяться перевод приложения.
     * Поскольку QComboBox имеет перегрузку сигнатуры сигнала, то нам необходимо
     * скастовать сигнал к нужной сигнатуре. В данном случае будем использовать
     * название пункта при его изменении.
     */

    connect(ui->comboBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
            [=](const QString &str)
    {
        translator.load(":lan/tr_" + str + ".");//Загружаем перевод
        qApp->installTranslator(&translator);//Устанавливаем перевод в приложение
    });

    //Сделаем первоначальную инициализацию для окна приложения
    translator.load(":lan/tr_" + QString("ru_RU"));
    qApp->installTranslator(&translator);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *event)
{
    //В случае получения события о смене языка
    if(event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);//переведём окно заново
    }
}


void MainWindow::on_btnOpen_clicked()
{
    Widget *w = new Widget();
    w->show();
}

