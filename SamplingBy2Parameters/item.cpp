#include "item.h"

Item::Item(QObject *parent)
    : QObject{parent}
    , mParameter1 (0)
    , mParameter2 (0)
{

}

Item::Item(const Item &item, QObject *parent)
    : QObject{parent}
{
    this->mParameter1 = item.parameter1();
    this->mParameter2 = item.parameter2();
}

Item::~Item()
{

}

Item &Item::operator =(const Item &second)
{
    this->mParameter1 = second.parameter1();
    this->mParameter2 = second.parameter2();

    return *this;

}

bool Item::operator <(const Item &second)
{
    return (this->parameter1() < second.parameter1());
}

bool Item::operator ==(/*const Item &first, */const Item &second)
{
    return ((this->parameter1() == second.parameter1()) && (this->parameter2() == second.parameter2()));
}

QDebug &operator<<(QDebug &stream, const Item &it)
{
    QDebug stream;
    stream << it.parameter1();
    stream << it.parameter2();
    return stream;
}

quint32 Item::parameter1() const
{
    return mParameter1;
}

quint32 Item::parameter2() const
{
    return mParameter2;
}

void Item::setParameter1(quint32 newParameter1)
{
    mParameter1 = newParameter1;
}

void Item::setParameter2(quint32 newParameter2)
{
    mParameter2 = newParameter2;
}
