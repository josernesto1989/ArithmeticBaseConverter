#ifndef BASESMANAGER_H
#define BASESMANAGER_H

#include <QObject>
#include <QList>
#include <QStringList>

class BasesManager : public QObject
{
    Q_OBJECT
private:
    QStringList bases;

public:
    explicit BasesManager(QObject *parent = nullptr);

    QStringList getBases() const;
    void setBases(const QStringList &newBases);
    QString convertFromBaseXtoBaseY(int baseX ,int baseY, QString number);
    QStringList getAllConvertedValuesFromBases(QString value);

public slots:
    void addBase(int);
    void removeBase(int);


signals:
    void valueChanged();
};

#endif // BASESMANAGER_H
