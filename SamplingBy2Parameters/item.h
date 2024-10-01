#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QDebug>

class Item : public QObject
{
    Q_OBJECT
public:
    explicit Item(QObject *parent = nullptr);
    Item (const Item &item, QObject *parent = nullptr);
    ~Item();

    Item &operator =(const Item &second);
    bool operator < (const Item &second);
    bool operator == (/*const Item &first, */const Item &second);
    QDebug &operator<<(QDebug &stream, const Item &it);

    quint32 parameter1() const;

    quint32 parameter2() const;

    void setParameter1(quint32 newParameter1);

    void setParameter2(quint32 newParameter2);

signals:

private:
    quint32 mParameter1;
    quint32 mParameter2;

};

#endif // ITEM_H
