#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "basesmanager.h"
#include <QStringListModel>
#include <QList>
#include "basesitemmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_base_changed();

    void on_lineEditCurrenNumber_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    BasesManager *baseManager;
    QStringListModel basesModel;
    BasesItemModel basesItemModel;


};
#endif // MAINWINDOW_H
