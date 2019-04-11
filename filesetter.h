#ifndef FILESETTER_H
#define FILESETTER_H

#include <QWidget>
#include "canclickedqlabel.h"
#include "QFileDialog"
#include "QTextStream"
#include "QThread"
#include "filecontroller.h"

using namespace std;

namespace Ui {
class FileSetter;
}

class FileSetter : public QWidget
{
    Q_OBJECT

public:
    explicit FileSetter(QWidget *parent = nullptr);

    QList<QString> *  getDatasFromCfg();
    QString getToolPathByName(QString name);
    QString getQmlPathByName(QString name);

    ~FileSetter();

signals:
    void refreshCfg();
    void findFileInPath(QString path, QString fileName);

private slots:
    CanClickedQLabel * addLine();
    void deleteLine();
    void selectLabel(CanClickedQLabel *selectedLabel);
    void reSet();
    void selectFile();
    void selectPath();
    void autoSet(int step = 1);
    void setSchedule(QString schedule);
    void setResult(QList<QString> result);

private:
    Ui::FileSetter *ui;
    CanClickedQLabel *label;
    CanClickedQLabel *selectedLabel;
    QList<QString> * datas;
    QList<CanClickedQLabel *> labelList;    //左侧配置列表的label的集合
    const QString cfgPath = "./config.txt";
    QString defaultRootPath;
    int successCount;
    FileController *fileController;
    QThread fileControllerThread;
    QList<QString> fullNameList;

    void checkCfgPath();
    bool saveDataToCfg();
    bool writeToCfg();
    //QList<QString> findFileInPath(QString path, QString fileName);
};

#endif // FILESETTER_H
