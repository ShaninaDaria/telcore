#include "sampling.h"

Sampling::Sampling(QObject *parent)
    : QObject{parent}
{

}

Sampling::~Sampling()
{

}

void Sampling::createKit(const quint32 count, const quint32 maxPar1, const quint32 maxPar2)
{
    items.reserve(count);

    Item tmp;
    for (quint32 i = 0; i < count; i++)
    {
        tmp.setParameter1(QRandomGenerator::global()->bounded(maxPar1));
        tmp.setParameter2(QRandomGenerator::global()->bounded(maxPar2));
        items[i] = tmp;
    }

}

void Sampling::select(const quint32 minPar1, const quint32 maxPar1, const quint32 minPar2, const quint32 maxPar2)
{
    std::sort(items.begin(), items.end());

    for (const auto &it: items)
    {
        if ((it.parameter1() > minPar1) && (it.parameter1() < maxPar1))
        {
            items.removeOne(it);
        }
    }

    auto sortBy2ndPar = [=] ()
    {
        for (int i = 0; i < (items.size() - 1); i++)
        {
            if (items.at(i).parameter2() > items.at(i+1).parameter2())
            {
                items.swapItemsAt(i, (i + 1));
            }
        }
    };

    std::sort(items.begin(), items.end(), sortBy2ndPar);

    for (const auto &it: items)
    {
        if ((it.parameter2() > minPar2) && (it.parameter2() < maxPar2))
        {
            items.removeOne(it);
        }
    }
}

void Sampling::print()
{
    qDebug() << items;
}
