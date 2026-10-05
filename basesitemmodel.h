#ifndef BASESITEMMODEL_H
#define BASESITEMMODEL_H
#include <QAbstractItemModel>

class BasesItemModel: public QAbstractItemModel
{
public:
    BasesItemModel();


    QStringList values[2];

public:
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void setValues(QStringList, QStringList);
};

#endif // BASESITEMMODEL_H
