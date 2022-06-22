# Dynamic-language-change-example

Перевод c динамической сменой языка:

1) В tr.pro вставим строчку TRANSLATIONS += tr_ru.ts
2) Запустим хотя бы раз приложение
3) Инструменты -> Внешние -> Linguist -> Обновить
   Появляется файл tr_ru.ts
4) Открываем файл tr_ru.ts в Linguist и переводим тексты
5) Компилируем в tr_ru.qm
6) Далее помещаем tr_ru.ts в папку bin, а tr_ru.qm в папку bin/lan
7) Создаём файл ресурсов в папке bin
8) Добавляем в ресурс файл tr_ru.qm, с префиксом / без псевдонима
9) В файле MainWindow.cpp пишем код (#include <QTranslator> не забываем):
    
	MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItems(QStringList() << "ru_RU" << "en_US");

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

void MainWindow::changeEvent(QEvent *event)
{
    //В случае получения события о смене языка
    if(event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);//переведём окно заново
    }
}