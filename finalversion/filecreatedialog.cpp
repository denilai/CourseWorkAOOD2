#include "filecreatedialog.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QPushButton>
#include <QTextEdit>
#include <QFileDialog>
FileCreateDialog::FileCreateDialog(QWidget *parent) : QWidget(parent)
{
    nameLabel = new QLabel("Имя");
    dirLabel = new QLabel ("Расположение");
    nameLabel -> setFixedWidth(110);
    dirLabel -> setFixedWidth(110);

    nameLabel -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    dirLabel -> setSizePolicy(QSizePolicy ::Fixed, QSizePolicy::Fixed);


    nameEdit = new QTextEdit(this);
    nameEdit -> setMaximumHeight(30);
    nameEdit -> setMinimumWidth(300);
    nameEdit  -> setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    dirEdit = new QTextEdit(this);
    dirEdit -> setMaximumHeight(30);
    dirEdit  -> setMinimumWidth(300);
    dirEdit -> setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    searchButton = new QPushButton ("Обзор");
    searchButton -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    createButton = new QPushButton ("Создать");
    createButton->setShortcut(Qt::Key_Enter);
    createButton -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    buttonLayout = new QHBoxLayout;
    buttonLayout -> addWidget(createButton);

    nameLayout =  new QHBoxLayout;
    nameLayout -> setAlignment(Qt::AlignLeft);
    nameLayout -> setSpacing(4);
    nameLayout -> addWidget(nameLabel);
    nameLayout -> addWidget(nameEdit);

    dirLayout =  new QHBoxLayout;
    dirLayout -> setAlignment(Qt::AlignLeft);
    dirLayout -> setSpacing(4);
    dirLayout -> addWidget(dirLabel);
    dirLayout -> addWidget(dirEdit);
    dirLayout -> addWidget(searchButton);

    inputLayout = new QVBoxLayout;
    inputLayout -> addLayout(nameLayout);
    inputLayout -> addLayout(dirLayout);

    mainLayout = new QVBoxLayout(this);
    mainLayout -> addLayout(inputLayout);
    //mainLayout -> addStretch(1);
    mainLayout -> addLayout(buttonLayout);

    //this ->setLayout(mainLayout);

    this-> setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    this -> setMaximumHeight(147);
    connect(searchButton, &QPushButton::clicked, this, &FileCreateDialog::setOnSearchDirClicked);
    connect(createButton, &QPushButton::clicked, this, &FileCreateDialog::setOnCreateButtonClicked);

}

void FileCreateDialog::setOnCreateButtonClicked(){
    emit createFile(dirEdit->toPlainText(),nameEdit->toPlainText());
    clean();
}

void FileCreateDialog::setOnSearchDirClicked(){
    dirEdit -> setPlainText(
                QFileDialog::getExistingDirectory
                    (this, tr("Open Directory"),
                    "/home",
                    QFileDialog::ShowDirsOnly
                    | QFileDialog::DontResolveSymlinks));
}

void FileCreateDialog::clean(){
    nameEdit -> setText("");
    dirEdit -> setText("");
}


