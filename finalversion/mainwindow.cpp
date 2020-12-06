#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QIcon>
#include <QDir>
#include <QFileDialog>
#include <QTextEdit>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QStatusBar>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMdiArea>
#include <QLabel>
#include <QPushButton>
#include <QTextCursor>
#include <QByteArray>
#include "dictionarysnoopy.h"
#include "dictionary.h"
#include "greeting.h"
#include <QScreen>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QTableView>
#include <QCloseEvent>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    //ui(new Ui::MainWindow)
{

    this -> setWindowTitle("Frequency Dictionary");
    this->setWindowIcon(QIcon::fromTheme("windows10"));
    snoopy = new DictionarySnoopy;
    //createDialog = new FileCreateDialog;
    greetForm = new Greeting(this);// должно быть с parent this, иначе открывается сзади
    dictionary = new Dictionary();
    //dictFile = new QFile("newDict.txt");
    this->setMinimumSize(800,500);
    createMenu();
    createWorkArea();
    createStatusBar();
    setConnections();
    turnOff();
    greetForm->show();

}

void MainWindow::turnOff(){
    this->centralWidget()->setEnabled(false);
    this->menuBar()->setEnabled(false);
}

void MainWindow::turnOn(){
    this->centralWidget()->setEnabled(true);
    this->menuBar()->setEnabled(true);
}


void MainWindow::moveToCenter(){
    setGeometry((int)(QApplication::desktop()->width() - (QApplication::desktop()->width() - (QApplication::desktop()->width() / 2)) * 1.5) / 2,
      (int)(QApplication::desktop()->height() - (QApplication::desktop()->height() -
      (QApplication::desktop()->height() / 2)) * 1.5) / 2,
      (int)((QApplication::desktop()->width() -  (QApplication::desktop()->width() / 2)) * 1.5),
      (int)((QApplication::desktop()->height() - (QApplication::desktop()->height() / 2)) * 1.5));
}

void MainWindow::createWorkArea(){
     moveToCenter();

    QMdiArea *mdiArea = new QMdiArea(this);


    // оформление блока исходного текста
    sourceLayout = new QVBoxLayout();
    sourceLabel = new QTextEdit(tr("Исходный текст"));
    sourceLabel->setEnabled(false);
    sourceLabel->setEnabled(false);
    sourceLabel -> setAlignment(Qt::AlignCenter);
    sourceLabel->setMaximumHeight(50);
    sourceLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
    sourceLayout -> setSpacing(10);
    sourceEdit = new QTextEdit();
    //sourceEdit -> setMinimumSize(100,200);
    sourceEdit->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    sourceLayout -> addWidget(sourceLabel);
    sourceLayout -> addWidget(sourceEdit);

    // оформление блока управляющих кнопок
    buttonLayout = new QVBoxLayout;
    createDictPushButton = new QPushButton(tr("Создать словарь"));
    createDictPushButton -> setMaximumSize(170,40);
    createDictPushButton -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    findPushButton = new QPushButton(tr("Найти в словаре"));
    findPushButton->setEnabled(false);
    findPushButton -> setMaximumSize(170,40);
    findPushButton -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    buttonLayout-> setSpacing(10);
    buttonLayout -> addStretch(1);
    buttonLayout -> addWidget(createDictPushButton);
    buttonLayout -> addWidget(findPushButton);
    buttonLayout -> addStretch(1);

    // оформление блока словаря

    table = new QTableView(this);
    table->setMinimumSize(400,200);
    table->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::MinimumExpanding);


    dictLayout = new QVBoxLayout();
    dictLabel = new QTextEdit(tr("Словарь"));
    dictLabel ->setEnabled(false);
    dictLabel->setMaximumHeight(50);
    dictLabel->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::MinimumExpanding);
    dictLabel -> setAlignment(Qt::AlignCenter);
    dictLayout -> setSpacing(10);
//    dictEdit = new QTextEdit();
//    dictEdit -> setMinimumSize(100,200);
//    dictEdit -> setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    dictLayout -> addWidget(dictLabel);
    //dictLayout -> addWidget(dictEdit);
    dictLayout -> setAlignment(table, Qt::AlignCenter);
    dictLayout->addWidget(table);

    // установка основгого менеджера компановки
    mainLayout = new QHBoxLayout(mdiArea);
    mainLayout -> addLayout(sourceLayout);
    mainLayout -> addLayout(buttonLayout);
    mainLayout -> addLayout(dictLayout);

    setCentralWidget(mdiArea);
}

void MainWindow::createStatusBar(){
    statusBarLabel = new QLabel();
    statusBar() -> addPermanentWidget(statusBarLabel);
}

void MainWindow::setStatusBarText(QString text){
    statusBarLabel -> setText(text);
}

void MainWindow::createMenu(){

    QIcon::setThemeName("mySet");

    QMenu * sourceMenu = new QMenu("&Текст");
    sourceMenu->addAction(QIcon::fromTheme("new1"),"Новый текст",this, SLOT(handleNewSource()),Qt::CTRL+Qt::Key_N);
    sourceMenu->addAction(QIcon::fromTheme("open"),"Открыть текст", this, SLOT(openNewSource()),Qt::CTRL+Qt::Key_O);
    sourceMenu->addAction(QIcon::fromTheme("save"),"Сохранить", this, SLOT(saveSource()),Qt::CTRL+Qt::Key_S);
    sourceMenu->addAction(QIcon::fromTheme("save-us"),"Сохранить как", this, SLOT(saveSourceAs()));
    sourceMenu->addSeparator();

    QMenu * dirMenu = new QMenu("Словарь");
    dirMenu->addAction(QIcon::fromTheme("ink"),"Новый словарь",this, SLOT(handleNewDict()),Qt::ALT+Qt::Key_N);
    dirMenu->addAction(QIcon::fromTheme("book"),"Отркыть словарь",this,SLOT(openDict()),Qt::ALT+Qt::Key_O);
    dirMenu->addAction(QIcon::fromTheme("find1"),"&Поиск в словаре",this,SLOT(setOnFindClicked()),Qt::ALT+Qt::Key_F);
    dirMenu->addAction(QIcon::fromTheme("save"),"&Сохранить словарь",this,SLOT(saveDict()),Qt::ALT+Qt::Key_S);
    dirMenu->addAction(QIcon::fromTheme("save-us"),"&Сохранить словарь как",this,SLOT(saveDictAs()));


    menuBar()->addMenu(sourceMenu);
    menuBar()->addMenu(dirMenu);
}

void MainWindow::setConnections(){
    connect(greetForm,&Greeting::sig_newSourse, this, &MainWindow::handleNewSource);
    connect(greetForm, &Greeting::indicateClosing ,this,&MainWindow::setOnGreetingClosed);
    //connect(greetForm, &Greeting::sig_newSourse, this, &MainWindow::handleNewSource);
    connect(greetForm, &Greeting::sig_openSourse, this, &MainWindow::openNewSource);
    connect(greetForm, &Greeting::sig_openDictList, this, &MainWindow::openDict);
    connect(findPushButton, &QPushButton::clicked, this, &MainWindow::setOnFindClicked);
    connect(createDictPushButton, &QPushButton::clicked, this, &MainWindow::setOnCreateDictClicked);
    connect(snoopy, &DictionarySnoopy::searchElem, this, &MainWindow::searchInDict);
    connect(this, &MainWindow::countOfFindingKeys, snoopy, &DictionarySnoopy::setResult);
    connect(greetForm, &Greeting::sig_template, this, &MainWindow::openTemplate);
    //connect(greetForm, &Greeting::sig_newDict,this, newDict());
}

void MainWindow::openTemplate(){
    qDebug()<<QDir::currentPath();
    qDebug()<<QApplication::applicationDirPath();
    turnOn();
    //QString path ="‪‪D:/Documents/Denisov/Алена.txt";
    openSource(QApplication::applicationDirPath()+ tr("/mayak.txt"));
}

void MainWindow::setOnGreetingClosed(){
        turnOn();
}

void MainWindow::setOnCreateDictClicked(){
//    if(dictFile == nullptr){
//        handleNewDict();
//        return;
//    }

    dictionary->clear();
    dictionary->analyze(sourceEdit->toPlainText());

    if(model!= nullptr)
        delete model;
    model = new QStandardItemModel(table);
    dictionary->createModel(model);
    table ->setModel(model);
    //printFile(dictFile, dictEdit);
    findPushButton->setEnabled(true);
    //saveDict();
    saveSource();
}


void MainWindow::setOnFindClicked(){
    setOnCreateDictClicked();
    snoopy->show();
}

MainWindow::~MainWindow(){
    //delete ui;
}



//////////////////////////////////////////////////////////////////////////////////////////////


void MainWindow::handleNewSource(){

    QString newName = QFileDialog::getSaveFileName(
                this,tr("New source"),
                QDir::currentPath(),
                tr("Text files (*.txt)"));
    newSource(newName);
}

void MainWindow::handleNewDict(){
    QString newName = QFileDialog::getSaveFileName(
                this,tr("New dictionary"),
                QDir::currentPath(),
                tr("Dictionary files (*.dict)"));
    newDict(newName);
}

void MainWindow::cleanDictArea(){
    findPushButton->setEnabled(false);
    if (model!=nullptr)
        delete model;
}


void MainWindow::newSource(QString name){
    //cleanDictArea();
    delete sourceFile;
    sourceFile = new QFile(name);
    sourceFile->close();
    if(greetForm!=nullptr&&name!="")
        greetForm -> close();
//    if(createDialog!=nullptr){
//        createDialog -> close();
//    }
    sourceEdit -> setText("");
    sourceLabel->setText(tr("Исходный текст ") + sourceFile->fileName());
}


void MainWindow::openNewSource(){
    sourceFile = new QFile(fileOpenDialog("Text files (*.txt)"));
    openSource(sourceFile->fileName());
}



void MainWindow::openSource(QString path){
    findPushButton->setEnabled(false);
    delete sourceFile;
    sourceFile = new QFile(path);
//    if(createDialog!=nullptr)
//        createDialog -> close();
    if(path!=""&&greetForm!=nullptr)
        greetForm -> close();
    printFile(sourceFile,sourceEdit);
    sourceLabel->setText(tr("Исходный текст ") + sourceFile->fileName());
}



void MainWindow::parseDictToTable(QFile *dictFile, QStandardItemModel * model){
    if (!dictFile->open(QIODevice::ReadOnly)){
        qDebug()<<"MainWindow::parseDictToTable: File "+dictFile->fileName()+" not open\n";
        return;
    }

    model->setColumnCount(2);
    model->setRowCount(20);
    model->setHeaderData(0,Qt::Horizontal, "Слово");
    model->setHeaderData(1,Qt::Horizontal, "Кол-во\nвхождений");

    int row = 0;
    dictFile->readLine();
    while(!dictFile->atEnd()){
        QString line = QString::fromUtf8(dictFile->readLine());
        line = line.simplified();
        QStringList words = line.split("|",QString::SkipEmptyParts);
        model->setData(model->index(row, 0),words.at(0));
        model->setData(model->index(row, 1),words.at(1));
        row++;
    }
    model->setRowCount(row);
}

void MainWindow::newDict(QString name){
    //cleanDictArea();
    delete dictFile;
    dictFile = new QFile(name);
    dictFile->close();
    if(greetForm!=nullptr&&name!="")
        greetForm -> close();
//    if(createDialog!=nullptr&&name!=""){
//        createDialog -> close();
//    }
    delete model;
    model = new QStandardItemModel(table);
    table->setModel(model);
    dictLabel->setText(tr("Словарь") + dictFile->fileName());
    setOnCreateDictClicked();
}

void MainWindow::openDict(){
    delete dictFile;
    delete model;
    dictFile = new QFile(fileOpenDialog("Dictionary (*.dict)"));
    if(openSuccessful){
        greetForm->close();
        model = new QStandardItemModel(table);
        parseDictToTable(dictFile, model);
        table->setModel(model);
        printFile(dictFile,dictEdit);
        findPushButton->setEnabled(true);
    }
    dictLabel->setText(tr("Словарь: ")+dictFile->fileName());
}

void MainWindow::saveSource(){
    if (sourceFile!=nullptr)
        saveFile(sourceFile,sourceEdit->toPlainText());
    else
        saveSourceAs();
    sourceLabel->setText(tr("Исходный текст ") + sourceFile->fileName());
}

void  MainWindow::saveDict(){

    if (dictFile == nullptr){
        handleNewDict();
        return;
        //dictFile = new QFile(fileNewDialog());
        //dictFile = new QFile(path);
    }

    if(dictFile->exists())
        dictFile->resize(0);
    if(dictFile->open(QIODevice::WriteOnly)){
        QTextStream * stream = new QTextStream(dictFile);
        stream->setCodec("UTF-8");
        dictionary->show(stream, fieldWidth);
        dictFile->close();
        delete stream;
    }
    dictLabel->setText(tr("Словарь: ")+dictFile->fileName());
}

void MainWindow::saveSourceAs(){
    QString newName = QFileDialog::getSaveFileName(
                this,tr("Save a file"),
                QDir::currentPath(),
                tr("Text files (*.txt)"));
    if (newName!= ""){
        delete sourceFile;
        sourceFile = new QFile(newName);
        saveFile(sourceFile,sourceEdit->toPlainText());
    }
    sourceLabel->setText(tr("Исходный текст ") + sourceFile->fileName());
}

void MainWindow::saveDictAs(){
    QString newName = QFileDialog::getSaveFileName(
                this,tr("Save a file"),
                QDir::currentPath(),
                tr("Text files (*.txt)"));
    if (newName!= ""){
        delete dictFile;
        dictFile = new QFile(newName);
        if(dictFile->open(QIODevice::WriteOnly)){
            QTextStream * stream = new QTextStream(dictFile);
            stream->setCodec("UTF-8");
            dictionary->show(stream, fieldWidth);
            dictFile->close();
            delete stream;
        }
    }
    dictLabel->setText(tr("Словарь: ")+dictFile->fileName());
}

//////////////////////////////////////////////////////////////////////////////////////////////



void MainWindow::printFile(QFile * file, QTextEdit * edit){
   if(!file -> open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"MainWindow::printFile: File "+file->fileName()+ " not open for reading";
        return;
    }
    edit-> setPlainText(QString::fromUtf8(file->readAll()));
    file->close();
    QTextCursor cursor(edit -> textCursor());
    cursor.movePosition(QTextCursor::End);
    edit -> setTextCursor(cursor);
}

void MainWindow::saveFile(QFile* file, QString text){
    if (!file->open(QIODevice::WriteOnly)){
        qDebug()<<"MainWindow::printFile: File "+file->fileName()+ " not open for writing";
        return;
    }
    file->write(text.toUtf8());
    file->close();
}

QString MainWindow::fileOpenDialog(QString mask){
    openSuccessful = false;
    QString answer = QFileDialog::getOpenFileName
        (this, "Open a file",
         QDir::currentPath(),
         mask);
    if (answer != "")
        openSuccessful = true;
    return answer;
}

QString MainWindow::fileNewDialog(){
    createSuccessful = false;
    QString answer = QFileDialog::getExistingDirectory
            (this, tr("Open Directory"),
            "/home",
            QFileDialog::ShowDirsOnly
            | QFileDialog::DontResolveSymlinks);
    if(answer!= "")
        createSuccessful = true;
    return answer;
}

QString MainWindow::dictOfThisFile(QString sourcePath){
    QString dictPath = QString::fromStdString(
                sourcePath.toStdString().substr(
                    0,sourcePath.toStdString().find_last_of("/")));
    //int s = sourcePath.toStdString().find_last_of("/");

    std::string  shortName =
                sourcePath.toStdString().substr(sourcePath.toStdString().find_last_of("/"));
    shortName = shortName.substr(0,shortName.find_last_of("."));
    QDir().mkdir(QDir().currentPath()+"/Dictionaries");
    dictPath = QDir().currentPath() +   QString::fromStdString( "/Dictionaries"+shortName + "_dictionary.dict");
    return dictPath;
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton ret;
    ret = QMessageBox::question(
                this,
                QApplication::applicationName(),
                tr("Завершить работу программы?"),
                QMessageBox::Yes | QMessageBox::No , QMessageBox::No);

    if (ret == QMessageBox::No){
        turnOn();
        event->ignore();
    }
    if (ret == QMessageBox::Yes){
        if(sourceFile!=nullptr)
            saveSource();
        if(dictFile!=nullptr)
            saveDict();

    }

}





void MainWindow::searchInDict(QString key){
    emit countOfFindingKeys(dictionary->find(key));

}

