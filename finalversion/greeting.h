#ifndef GREETING_H
#define GREETING_H

#include <QDialog>
#include <QMainWindow>
#include <QApplication>

#include <QMenu>
#include <QDialog>
#include <QTextEdit>
#include <QString>


class QAction;
class QLabel;
class QCloseEvent;

class Greeting : public QDialog
{
    Q_OBJECT

public:
    explicit Greeting(QWidget *parent = nullptr);

signals:
    void sig_newSourse();
    void sig_openSourse();
    void sig_openDictList();
    void indicateClosing();

private:
    QPushButton *newSourcePushButton = nullptr;
    QPushButton *openSourcePushButton = nullptr;
    QPushButton *openDictPushButton = nullptr;
    QMainWindow *mainWindow = nullptr;

    void createButtonPanel();
    void createConnections();


    public slots:
    void closeEvent(QCloseEvent*);
    //void closeEvent();
protected:
};

#endif // GREETING_H
