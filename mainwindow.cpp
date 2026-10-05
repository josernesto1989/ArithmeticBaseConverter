#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QStringListModel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    baseManager = new BasesManager(this);
    this->basesModel.setStringList((baseManager->getBases()));
    ui->comboBoxBase->setModel(&basesModel);
    ui->tableView->setModel(&basesItemModel);
    on_base_changed();
    connect(baseManager,&BasesManager::valueChanged,this, &MainWindow::on_base_changed);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete baseManager;
}

void MainWindow::on_pushButton_clicked()
{
    bool ok;
    int number = ui->lineEditAddBase->text().toInt(&ok);
    if(ok){
        baseManager->addBase(number);
    }
    else{
        //TODO: lanzar mensaje de error
    }
}

void MainWindow::on_base_changed()
{
    basesModel.setStringList((baseManager->getBases()));
    basesItemModel.setValues(baseManager->getBases(),baseManager->getAllConvertedValuesFromBases(
                                                          ui->lineEditCurrenNumber->text()));
}


void MainWindow::on_lineEditCurrenNumber_textChanged(const QString &arg1)
{
    bool ok;
    int base =ui->comboBoxBase->currentText().toInt(&ok);
    if(!ok){
        return ;
    }
    int decimal = arg1.toInt(&ok,base);
    if(!ok){
        return ;
    }
    QString decimalBaseStr = QString::number(decimal);
    basesItemModel.setValues(baseManager->getBases(),baseManager->getAllConvertedValuesFromBases(
                                                          decimalBaseStr));




}

