#include "dictionary.h"
#include <locale>
#include <wchar.h>
#include <ctype.h>
#include <vector>
#include <QTableView>
#include <QModelIndex>
#include <QStandardItemModel>

Dictionary::Dictionary(){}

void Dictionary::add(QString key){
    if(dictionary.find(key)==dictionary.end())
        dictionary[key] = 1;
    else increase(key);
    count++;
}

int Dictionary::getCount(){
    return count;
}

void Dictionary::increase(QString key){
    dictionary[key]+=1;
}

void Dictionary::clear(){
    dictionary.clear();
}

void Dictionary::createModel(QStandardItemModel * model){
    QModelIndex index;
    model ->setColumnCount(2);
    model->setRowCount(dictionary.size());
    model->setHeaderData(0,Qt::Horizontal, "Слово");
    model->setHeaderData(1,Qt::Horizontal, "Кол-во\nвхождений");
    //model->setS
    for(int col = 0; col< model->columnCount();col++){
        auto iterator = dictionary.begin();
        for(int row = 0;row < model->rowCount() && iterator!=dictionary.end();row++,iterator++){
            index = model->index(row,col);
            if(col == 0){
                model->setData(index,iterator->first);
            }
            if(col == 1){
                model->setData(index,iterator->second);
            }
        }
    }
}

void Dictionary::show(QTextStream * stream, int fieldWidth){
    stream->setFieldWidth(fieldWidth);
    stream->setFieldAlignment(QTextStream::AlignLeft);
    *stream<<"Word";
    stream->setFieldWidth(1);
    *stream<<"|";
    stream->setFieldWidth(fieldWidth);
    *stream<<"Count";
    stream->setFieldWidth(1);
    *stream<<endl;
    for(auto pair:dictionary){
        stream->setFieldWidth(fieldWidth);
        *stream<<pair.first;
        stream->setFieldWidth(1);
        *stream<<"|";
        stream->setFieldWidth(fieldWidth);
        *stream<<pair.second;
        stream->setFieldWidth(1);
        *stream<<endl;
    }
}

bool Dictionary::isalphaRus(wchar_t c) {
    return c >= (L'а') && c <= (L'я') || c >= (L'А') && c <= (L'Я')
        || c == (L'ё') || c == (L'Ё');
}

void Dictionary::analise(QString text){
    QString withoutPunctuation = cleanPunctuation(text);
    QStringList words = withoutPunctuation.split(" ",QString::SkipEmptyParts);
    for(QString word:words){
        this->add(word.toLower());
    }
}

int Dictionary::find(QString key){
    std::map<QString,int>::iterator ptr = dictionary.find(key);
    if(ptr!=dictionary.end()){
        return ptr->second;
    }
    else return 0;
}

QString Dictionary::cleanPunctuation(QString text){
    QRegExp val("[,.!»«—@#$%^&*-()_+?<>\\/;:'\"`|{}]");
    QRegExp val1("[,.]");
    QString newStr = text.replace(val, QString(""));
    return newStr;
}

QString Dictionary::cleanWord(QString word){
    wchar_t array [word.length()];
    word.toWCharArray(array);
    std::vector<wchar_t> vect;
    for(int i=0;i<word.length();i++){
        vect.push_back(array[i]);
    }
    for(auto p = vect.begin(); p!=vect.end();p++){
        if (!isalphaRus(*p)){
            vect.erase(p);
        }
    }
    wchar_t answer[vect.size()];
    int i=0;
    for(auto p = vect.begin(); p!=vect.end();p++,i++){
        answer[i]=*p;
    }
    return QString::fromWCharArray(answer);
}


