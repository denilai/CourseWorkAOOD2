#ifndef DICTIONARY_SNOOPY
#define DICTIONARY_SNOOPY

#include <QWidget>

class QHBoxLayout;
class QVBoxLayout;
class QString;
class QLabel;
class QTextEdit;
class QPushButton;
class MainWindow;

class DictionarySnoopy : public QWidget
{
    Q_OBJECT
public:
    explicit DictionarySnoopy(QWidget *parent = nullptr);
signals:
    void searchElem(QString key);
private:
    QHBoxLayout * requestLayout = nullptr;
    QHBoxLayout * resultLayout = nullptr;
    QHBoxLayout * buttonLayout = nullptr;
    QVBoxLayout * mainLayout = nullptr;
    QVBoxLayout * inputLayout = nullptr;

    QLabel * requestLabel = nullptr;
    QLabel * resultLabel = nullptr;
    QLabel * answerLabel = nullptr;

    QPushButton * searchButton = nullptr;
    QPushButton * clearButton = nullptr;


    QTextEdit * requestEdit = nullptr;

    void clean();
private slots:
    void setOnSearchButtonClicked();
    void setOnClearButtonClicked();
public slots:
    void setResult(int);

};

#endif // DICTIONARY_SNOOPY
