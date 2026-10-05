#include "basesmanager.h"
#include <QDebug>

BasesManager::BasesManager(QObject *parent)
    : QObject{parent}
{
    bases<<"10";
}

QStringList BasesManager::getBases() const
{
    return bases;
}

void BasesManager::setBases(const QStringList &newBases)
{
    bases = newBases;
}

QString BasesManager::convertFromBaseXtoBaseY(int baseX, int baseY, QString number)
{
    bool ok=false;
    int decimal = number.toInt(&ok, baseX);
    if(ok){
        return QString::number(decimal, baseY);
    }
    return tr("ERROR");
}

QStringList BasesManager::getAllConvertedValuesFromBases(QString value)
{
    QStringList values;
    bool ok;
    bool ok2;
    int decimal ;
    int currentBaseInt;
    foreach (QString currentBase, bases) {
        decimal= value.toInt(&ok);
        currentBaseInt= currentBase.toInt(&ok2);
        values<<(ok && ok2 ? QString::number(decimal,currentBaseInt) : "ERROR");
    }
    return values;

}

void BasesManager::addBase(int baseNew)
{
    bases<<QString::number(baseNew);
    emit valueChanged();
}

void BasesManager::removeBase(int baseNew)
{
    int indice = bases.indexOf(QString::number(baseNew));
    if(indice >= 0){
        bases.removeAt(indice);
    }


}
