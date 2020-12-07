#include "greeting.h"

#include <QPushButton>
#include <QAction>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileSystemModel>
#include <QTreeView>
#include <QFileDialog>
#include <QDir>
#include <QEvent>

#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPixmap>
#include <QCloseEvent>
#include <QMessageBox>

Greeting::Greeting(QWidget *parent) :
    QDialog(parent)
{
    this -> setWindowTitle("Frequency Dictionary");
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);
    this->setWindowFlag(Qt::WindowContextHelpButtonHint, false);
    QIcon::setThemeName("mySet");
    this->setWindowIcon(QIcon::fromTheme("windows10"));
    setSizeGripEnabled(false);
    this->setFixedSize(300,250);
    createButtonPanel();
    createConnections();
}


void Greeting::createConnections(){

    // установка соединения сигнал - слот (создание нового текста)
    connect(newSourcePushButton, &QPushButton::clicked,this, &Greeting::sig_newSourse);
   //  установка соединения сигнал - слот (открытие существующего текста)
    connect(openSourcePushButton, &QPushButton::clicked,this, &Greeting::sig_openSourse);
   //  установка соединения сигнал - слот (открытие cписка существующих словарей)
    connect(openDictPushButton, &QPushButton::clicked,this, &Greeting::sig_openDictList);
    //  установка соединения сигнал - слот (открытие шаблонного текста)
    connect(templatePushButton, &QPushButton::clicked, this, &Greeting::sig_template);

}


void Greeting::closeEvent(QCloseEvent *event)
{
    emit indicateClosing();
    event ->accept();
}


void Greeting::createButtonPanel(){

    QVBoxLayout *vbox = new QVBoxLayout(this);

    newSourcePushButton = new QPushButton(tr("&Cоздать исходный текст"), this);
    openSourcePushButton = new QPushButton(tr("&Открыть исходный текст"),this);
    openDictPushButton = new QPushButton(tr("Готовые &словари"),this);
    templatePushButton = new QPushButton(tr("Открыть &шаблон"),this);

    newSourcePushButton->setToolTip(tr("Новый текст для анализа"));
    openSourcePushButton->setToolTip(tr("Существующие тексты для анализа"));
    openDictPushButton->setToolTip(tr("Открыть сформированный частотный словарь"));
    templatePushButton -> setToolTip(tr("Открыть стихотворение В.Маяковского 'Послушайте'"));

    newSourcePushButton->setIcon(QIcon(QIcon::fromTheme("new1")));
    openSourcePushButton->setIcon(QIcon(QIcon::fromTheme("open")));
    openDictPushButton->setIcon(QIcon::fromTheme("book"));
    templatePushButton->setIcon(QIcon::fromTheme("template"));


    vbox->setSpacing(2);
    vbox->addStretch(1);
    vbox->addWidget(newSourcePushButton);
    vbox->addWidget(openSourcePushButton);
    vbox->addWidget(openDictPushButton);
    vbox->addWidget(templatePushButton);
    vbox->addStretch(1);
}
