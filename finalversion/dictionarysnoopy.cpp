#include "dictionarysnoopy.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QPushButton>
#include <QTextEdit>
#include <QFileDialog>

DictionarySnoopy::DictionarySnoopy(QWidget *parent) : QWidget(parent)
{
    requestLabel = new QLabel("Найти");
    requestLabel -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);


    resultLabel = new QLabel ("Результат поиска - ");
    resultLabel -> setSizePolicy(QSizePolicy ::Fixed, QSizePolicy::Fixed);


    requestEdit = new QTextEdit(this);
    requestEdit -> setMaximumHeight(30);
    requestEdit -> setMinimumWidth(300);
    requestEdit  -> setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    answerLabel = new QLabel(this);
    answerLabel -> setMaximumHeight(30);
    answerLabel  -> setMinimumWidth(300);
    answerLabel -> setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    searchButton = new QPushButton ("Найти");
    searchButton -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    clearButton = new QPushButton ("Очистить");
    clearButton -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);


    buttonLayout = new QHBoxLayout;
    buttonLayout -> addWidget(searchButton);

    requestLayout =  new QHBoxLayout;
    requestLayout -> setAlignment(Qt::AlignLeft);
    requestLayout -> setSpacing(4);
    requestLayout -> addWidget(requestLabel);
    requestLayout -> addWidget(requestEdit);

    resultLayout =  new QHBoxLayout;
    resultLayout -> setAlignment(Qt::AlignLeft);
    resultLayout -> setSpacing(4);
    resultLayout -> addWidget(resultLabel);
    resultLayout -> addWidget(answerLabel);
    resultLayout -> addWidget(clearButton);

    inputLayout = new QVBoxLayout;
    inputLayout -> addLayout(requestLayout);
    inputLayout -> addLayout(resultLayout);

    mainLayout = new QVBoxLayout(this);
    mainLayout -> addLayout(inputLayout);
    mainLayout -> addLayout(buttonLayout);
    this-> setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    this -> setMaximumHeight(147);
    connect(searchButton, &QPushButton::clicked, this, &DictionarySnoopy::setOnSearchButtonClicked);
    connect(clearButton, &QPushButton::clicked, this, &DictionarySnoopy::setOnClearButtonClicked);
}

void DictionarySnoopy::setOnSearchButtonClicked(){
    emit searchElem(requestEdit->toPlainText());
}

void DictionarySnoopy::setOnClearButtonClicked(){
    requestEdit -> setText("");
    answerLabel -> setText("");
}

void DictionarySnoopy::setResult(int count){
    answerLabel->setText(QString::number(count));
}


