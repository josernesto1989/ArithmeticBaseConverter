#include "basesitemmodel.h"

BasesItemModel::BasesItemModel() {}

QModelIndex BasesItemModel::index(int row, int column, const QModelIndex &parent) const
{
    if (row < 0 || row >= rowCount(parent) ||
        column < 0 || column >= columnCount(parent))
        return QModelIndex(); // inválido

    return createIndex(row, column); // sin puntero interno
}

QModelIndex BasesItemModel::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);
    return QModelIndex();
}

int BasesItemModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return values[0].length();
}

int BasesItemModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 2;
}

QVariant BasesItemModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if(index.column()<0 || index.column()>=values[0].length() || index.row()<0 || index.row()>=values[0].length()){
        return QVariant();
    }
    if(role == Qt::DisplayRole){
        return QVariant(values[index.column()][index.row()]);
    }
    return QVariant();
}

void BasesItemModel::setValues(QStringList base, QStringList val)
{

    beginResetModel();
    this->values[0]=base;
    this->values[1]=val;
    endResetModel();

}


