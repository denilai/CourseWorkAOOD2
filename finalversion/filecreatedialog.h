#ifndef FILECREATEDIALOG_H
#define FILECREATEDIALOG_H

#include <QWidget>

class QHBoxLayout;
class QVBoxLayout;
class QString;
class QLabel;
class QTextEdit;
class QPushButton;

class FileCreateDialog : public QWidget
{
    Q_OBJECT
public:
    explicit FileCreateDialog(QWidget *parent = nullptr);
signals:
    void createFile(QString dir, QString name);
private:
    QHBoxLayout * dirLayout = nullptr;
    QHBoxLayout * nameLayout = nullptr;
    QHBoxLayout * buttonLayout = nullptr;
    QVBoxLayout * mainLayout = nullptr;
    QVBoxLayout * inputLayout = nullptr;
    QLabel * nameLabel = nullptr;
    QLabel * dirLabel = nullptr;
    QPushButton * searchButton = nullptr;
    QPushButton * createButton = nullptr;
    QTextEdit * nameEdit = nullptr;
    QTextEdit * dirEdit = nullptr;
    void clean();
private slots:
    void setOnSearchDirClicked();
    void setOnCreateButtonClicked();

};

#endif // FILECREATEDIALOG_H
