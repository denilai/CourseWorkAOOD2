#ifndef Dictionary_H
#define Dictionary_H

#include <map>
#include <string>
#include <iomanip>
#include <ostream>
#include <QTextStream>
#include <QString>


class QStandardItemModel;
class QTableView;

class Dictionary
{
private:
    std::map <QString, int> dictionary;
    bool isalphaRus(wchar_t);
    QString cleanPunctuation(QString);
    int count = 0;

public:
    Dictionary();              // создание пустого словаря
    void add(QString);     // добавление элемента в словарь
    void increase(QString);// увеличение значения счетчика
                               // слова в элементе словаря с заданным словом

    void show(QTextStream *, int);   // вывести элементы словаря в алфавитном порядке
    void createModel(QStandardItemModel *);
    int find(QString);    // поиск элемента словаря по слову
    void analise(QString); // построить словарь по заданному тексту
    QString cleanWord(QString); // очистка слова от знаков препинаний и лишних символов
    int getCount();
    void clear();
};

#endif // Dictionary_H
