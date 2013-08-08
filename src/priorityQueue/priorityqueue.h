#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <QVector>

class Prioritizable
{
public:
    virtual int getPriority() const = 0;
};

class MinHeap
{
public:
    MinHeap();
    MinHeap(const QVector<Prioritizable *> &data);
    MinHeap(const MinHeap &other);
    ~MinHeap();

    void insert(Prioritizable *x);
    Prioritizable *pop();
    Prioritizable *peek();
    void heapify();
    bool isEmpty();
    int size();
private:
    QVector<Prioritizable *> *data;

    void pushUp(int i);
    void pushDown();
};

#endif // PRIORITYQUEUE_H
