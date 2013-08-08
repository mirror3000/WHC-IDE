#include "priorityqueue.h"

MinHeap::MinHeap()
{
    data = new QVector<Prioritizable *>();
}

MinHeap::MinHeap(const QVector<Prioritizable *> &data)
{
    this->data = new QVector<Prioritizable *>(data);
}

MinHeap::MinHeap(const MinHeap &other)
{
    data = new QVector<Prioritizable *>(*(other.data));
    heapify();
}

MinHeap::~MinHeap()
{
    delete data;
}

void MinHeap::insert(Prioritizable *x)
{
    data->append(x);
    pushUp(data->size() - 1);
}

Prioritizable *MinHeap::pop()
{
    if(data->size() == 0)
        return NULL;

    Prioritizable *retValue = data->first();
    data->replace(0, data->last());
    data->remove(data->size() - 1);

    if(data->size() > 0)
        pushDown();

    return retValue;
}

Prioritizable *MinHeap::peek()
{
    if(data->size() == 0)
        return NULL;
    return data->first();
}

void MinHeap::heapify()
{
    for(int i = 0; i < data->size(); i++)
        pushUp(i);
}

bool MinHeap::isEmpty()
{
    return data->isEmpty();
}

int MinHeap::size()
{
    return data->size();
}

void MinHeap::pushUp(int i)
{
    int parent = (i - 1) / 2;
    Prioritizable *aux;

    while(i > 0 &&
          data->at(parent)->getPriority() > data->at(i)->getPriority())
    {
        aux = data->at(parent);
        data->replace(parent, data->at(i));
        data->replace(i, aux);

        i = parent;
        parent = (i - 1) / 2;
    }
}

void MinHeap::pushDown()
{
    int i = 0;
    Prioritizable *aux;

    while(1)
    {
        if(2 * i + 1 > data->size() - 1)
        {
            break;
        }
        if(2 * i + 2 > data->size() - 1)
        {
            if(data->at(2 * i + 1)->getPriority() < data->at(i)->getPriority())
            {
                aux = data->at(i);
                data->replace(i, data->at(2 * i + 1));
                data->replace(2 * i + 1, aux);
            }
            break;
        }
        if(data->at(2 * i + 1)->getPriority() <=
           data->at(2 * i + 2)->getPriority() &&
           data->at(2 * i + 1)->getPriority() < data->at(i)->getPriority())
        {
            aux = data->at(i);
            data->replace(i, data->at(2 * i + 1));
            data->replace(2 * i + 1, aux);

            i = 2 * i + 1;
        }
        else if(data->at(2 * i + 2)->getPriority() <=
                data->at(2 * i + 1)->getPriority() &&
                data->at(2 * i + 2)->getPriority() < data->at(i)->getPriority())
        {
            aux = data->at(i);
            data->replace(i, data->at(2 * i + 2));
            data->replace(2 * i + 2, aux);

            i = 2 * i + 2;
        }
        else
        {
            break;
        }
    }
}
