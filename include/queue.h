#ifdef ArrayBasedQueue

#define MaxQueue 1000
#define QueueEntry int

struct Queue
{
    int front ;
    int rear;
    int size;
    QueueEntry Entry[MaxQueue];
};

void CreateQueue(Queue *pq);
void Enqueue (Queue *pq , int item);
int Dequeue (Queue *pq);
bool IsQueueEmpty (Queue *pq);
bool IsQueueFull (Queue *pq);
int QueueSize (Queue *pq);
void DisplayQueue (Queue *pq);
void ClearQueue (Queue *pq);
void TraverseQueue (Queue *pq , void (*pf)(QueueEntry));

#else

#define QueueEntry int

struct QueueNode
{
    QueueEntry element;
    QueueNode *next;
};

struct Queue
{
    QueueNode *front;
    QueueNode *rear;
    int size;
};

void CreateQueue (Queue *pq);
void Enqueue (Queue *pq , QueueEntry item);
QueueEntry Dequeue (Queue *pq);
bool IsQueueEmpty (Queue *pq);
bool IsQueueFull (Queue *pq);
int QueueSize (Queue *pq);
void ClearQueue (Queue *pq);
void TraverseQueue (Queue *pq, void (*pf)(QueueEntry));

#endif