#ifdef ArrayBasedQueue

#include "../include/queue.h"

void CreateQueue(Queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
void Enqueue ( Queue *pq , int item )
{
    pq->rear=(pq->rear+1)%MaxQueue;
    pq->Entry[pq->rear]=item;
    pq->size++;
}
int Dequeue ( Queue *pq )
{
     QueueEntry poped_val;
     poped_val=pq->Entry[pq->front];
     pq->front=(pq->front+1)%MaxQueue;
    pq->size--;
    return poped_val;
}
bool IsQueueEmpty (Queue *pq)
{
    return (pq->size==0);
}
bool IsQueueFull (Queue *pq)
{
    return (pq->size==MaxQueue);
}
int QueueSize (Queue *pq)
{
    return (pq->size);
}
void ClearQueue (Queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
void DisplayQueue (Queue *pq)
{
    int index=pq->front;
    for (int i=0; i<pq->size; i++)
    {
     cout<<pq->Entry[index]<<" ";
     index=(index+1)%MaxQueue;
    }
}
void TraverseQueue (Queue *pq , void (*pf)(QueueEntry))
{
    int index=pq->front;
    for (int i=0; i<pq->size; i++)
    {
        (*pf)(pq->Entry[index]);
        index=(index+1)%MaxQueue;
    }
}

#else

#include "../include/queue.h"
void CreateQueue (Queue *pq)
{
    pq->front=NULL;
    pq->rear= NULL;
    pq->size=0;
}
void Enqueue (Queue *pq , QueueEntry item)
{
    QueueNode *pn=new QueueNode;
    pn->element=item;
    pn->next=NULL;
    if ((pq->front)==NULL)
        pq->front=pn;
        else
        pq->rear->next=pn;
        pq->size++;
        pq->rear=pn;
        delete pn;
}
QueueEntry Dequeue (Queue *pq)
{
    QueueEntry poped_val;
    poped_val=pq->front->element;
    QueueNode *pn=new QueueNode;
    pn=pq->front;
    pq->front=pq->front->next;
    pq->size--;
    if ((pq->front)==NULL)
        pq->rear=NULL;

         delete pn;
        return poped_val;
}
bool IsQueueEmpty (Queue *pq)
{
    return ((pq->size)==0);
}
bool IsQueueFull (Queue *pq)
{
    return 0;
}
int QueueSize (Queue *pq)
{
    return (pq->size);
}
void ClearQueue (Queue *pq)
{
    while (pq->front)
    {
    pq->rear=pq->front->next;
    delete pq->front;
    pq->front=pq->rear;
    }
    pq->size=0;

}
void TraverseQueue (Queue *pq, void (*pf)(QueueEntry))
{
    QueueNode *pn=new QueueNode;
    pn=pq->front;
    for (int i=0; i<pq->size; i++)
    {
        (*pf)(pn->element);
        pn=pn->next;
    }
}

#endif
