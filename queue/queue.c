#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct Node
{
    ElementType Element;
    struct Node *Next;
};

struct Q_Head
{
    struct Node *Front;
    struct Node *Rear;
    int items;
};


Queue CreateQueue(void)
{
    Queue q = malloc(sizeof(struct Q_Head));

    if(q == NULL)
    {
        fprintf(stderr, "Can't create a queue.\n");
        return NULL;
    }

    q->Front = NULL;
    q->Rear = NULL;
    q->items = 0;
    return q;
}

int CheckExistence(Queue Q)
{
    if(Q == NULL)
    {
        fprintf(stderr, "Can't find this queue.\n");
    }
    return Q != NULL;
}

int IsEmpty(Queue Q)
{
    if(Q == NULL)
    {
        fprintf(stderr, "Can't find this queue.\n");
        return -1;
    }

    return Q->items == 0;
}

int IsFull(Queue Q)
{
    if(Q == NULL)
    {
        fprintf(stderr, "Can't find the queue.\n");
        return -1;
    }

    return Q->items == MAXQUEUE;
}

int Count(Queue Q)
{
    if(Q == NULL)
    {
        fprintf(stderr, "Can't find this queue.\n");
        return -1;
    }

    return Q->items;
}

void EnQueue(ElementType X, Queue Q)
{
    if(Q == NULL)
    {
        fprintf(stderr, "Can't find this queue.\n");
        return;
    }


    struct Node *new_node = malloc(sizeof(struct Node));

    if(new_node == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for new node.\n");
        return;
    }

    new_node->Element = X;
    new_node->Next = NULL;

    if(Q->Rear == NULL)
    {
        Q->Front = new_node;
        Q->Rear = new_node;
        Q->items++;
        return;
    }
    
    Q->Rear->Next = new_node;
    Q->Rear = new_node;
    Q->items++;
    
}

ElementType DeQueue(Queue Q)
{
    struct Node *old_front = Q->Front;
    ElementType front = Q->Front->Element;

    Q->Front = Q->Front->Next;
    free(old_front);
    old_front = NULL;
    Q->items--;

    if(Q->Front == NULL)
    {
        Q->Rear =NULL;
    }
    return front;
}

void MakeEmpty(Queue Q)
{
    while(Q->Front != NULL)
    {
        struct Node *old = Q->Front;
        Q->Front = Q->Front->Next;
        free(old);
    }

    Q->Rear = NULL;
    Q->items = 0;
}

void DisposeQueue(Queue Q)
{
    MakeEmpty(Q);
    free(Q);
}