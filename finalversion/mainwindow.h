#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//Qt classes
class QString;
class QMenu;
class QHBoxLayout;
class QVBoxLayout;
class QAction;
class QTextEdit;
class QFile;
class QTextStream;
class QPushButton;
class QLabel;
class QTableView;
class QStandardItemModel;



// custom classes
class Dictionary;       // класс, реализующий функционал и внутреннее представление словаря
class Greeting;         // приветственная форма приложения
class DictionarySnoopy; // класс, реализующий функционал поиска в словаря по ключу


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
public slots:

    // slots about SOURCE file
    void handleNewSource();
    void newSource(QString );

        // SAVING
    void saveSource();
    void saveSourceAs();
        // OPENING
    void openNewSource();
    void openSource(QString);


    // slots about DICTIONARY file
    void handleNewDict();
    void newDict(QString);
        // SAVING
    void saveDictAs();
    void saveDict();
        // OPENING
    void openDict();
    void openTemplate();

        // SEARCHING
    void searchInDict(QString);

    // saving procedure before closings
    void closeEvent(QCloseEvent *);

private slots:
    // "setOn" slots (buttons and menubars action)
    void setOnCreateDictClicked();
    void setOnGreetingClosed();
    void setOnFindClicked();

signals:
    void countOfFindingKeys(int);

private:
    bool first = true;
    const int fieldWidth = 20;
    bool openSuccessful = false;
    bool createSuccessful = false;

    Greeting * greetForm = nullptr;
    Dictionary * dictionary = nullptr;
    QMenu * sourceMenu = nullptr,
        * dirMenu = nullptr;
    QHBoxLayout  * mainLayout = nullptr;
    QVBoxLayout * sourceLayout = nullptr,
        * dictLayout = nullptr,
        * buttonLayout = nullptr;


    DictionarySnoopy * snoopy = nullptr;
    QTableView * table = nullptr;
    QStandardItemModel * model = nullptr;
    QTextEdit * sourceEdit = nullptr,
        * dictEdit = nullptr;
    QFile * sourceFile = nullptr,
        * dictFile = nullptr;
    QTextStream * sourceStream = nullptr;
    QPushButton * createDictPushButton = nullptr;
    QPushButton * findPushButton = nullptr;
    QTextEdit * dictLabel = nullptr,
        * sourceLabel = nullptr;
    QLabel * statusBarLabel = nullptr;

    void createMenu();
    void setConnections();
    void moveToCenter();
    void cleanDictArea();
    void createWorkArea();
    void createStatusBar();
    void setStatusBarText(QString);

    void turnOn();
    void turnOff();

    void parseDictToTable(QFile *, QStandardItemModel *);

    void printFile(QFile*, QTextEdit*);
    void saveFile(QFile*, QString);

    QString dictOfThisFile(QString);
    QString fileOpenDialog(QString);
    QString fileNewDialog();
};
#endif // MAINWINDOW_H

