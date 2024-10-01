#ifndef SAMPLING_H
#define SAMPLING_H

#include <QObject>
#include <QRandomGenerator>
#include <QDebug>

#include "item.h"

class Sampling : public QObject
{
    Q_OBJECT
public:
    explicit Sampling(QObject *parent = nullptr);
    ~Sampling();

    void createKit(const quint32 count, const quint32 maxPar1, const quint32 maxPar2);

    void select(const quint32 minPar1, const quint32 maxPar1, const quint32 minPar2, const quint32 maxPar2);

    void print();

signals:

private:
    QList <Item> items;

};

#endif // SAMPLING_H
