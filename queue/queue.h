#ifndef _Queue_h
#define _Queue_h

struct Q_Head;
struct Node;

typedef struct Q_Head *Queue;

#define MAXQUEUE 100

typedef int ElementType;

Queue CreateQueue(void);
int CheckExistence(Queue Q);
int IsEmpty(Queue Q);
int IsFull(Queue Q);
int Count(Queue Q);
void EnQueue(ElementType X, Queue Q);
ElementType DeQueue(Queue Q);
void MakeEmpty(Queue Q);
void DisposeQueue(Queue Q);

#endif