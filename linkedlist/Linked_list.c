#include "Linked_list.h"
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int Element;
    Position Next;
};

//Create and initialize a linked list.
//Use standard error output for error massages.
List CreateList(void)
{
    List L;

    L = malloc(sizeof(struct Node));

    if(L == NULL)
    {
        fprintf(stderr, "List creation failed!\n");
        return NULL; 
    }
    else
    {
        L->Element = 0;
        L->Next = NULL;
        return L;
    }
}

//Add an element to the end of the linked list.
void Add(ElementType X, List L)
{
    if(L == NULL)
    {
        fprintf(stderr, "Can't find the list.\n");
        return;
    }
    
    Position current;
    current = L;

    while(current->Next != NULL)
    {
        current = current->Next;
    }

    Position new_node = malloc(sizeof(struct Node));
    
    if(new_node != NULL)
    {
        new_node->Element = X;
        new_node->Next = NULL;
        current->Next = new_node;
        L->Element++;
    }
    else
    {
        fprintf(stderr, "Failed to add node.\n");
    }
    
}

int IsEmpty(List L)
{
    if(L == NULL)
    {
        fprintf(stderr, "Can't find the list.\n");
        return -1;
    }
    else
    {
        return L->Next == NULL;
    }
}

int IsLast(Position P, List L)
{
    if(L == NULL)
    {
        fprintf(stderr, "Can't find the list.\n");
        return -1;
    }
    else if(P == NULL)
    {
        fprintf(stderr, "Can't find the node.\n");
        return -1;
    }
    
    Position current = L->Next;

    while(P != current && current != NULL)
    {
        current = current->Next;
    }

    if(current == NULL)
    {
        fprintf(stderr, "This node is not in the list.\n");
        return -1;
    }

    return P->Next == NULL;
}

Position Find(ElementType X, List L)
{
    if(L == NULL)
    {
        fprintf(stderr, "Can't find the list.\n");
        return NULL;
    }

    Position currentP = L->Next;

    while(currentP != NULL && X != currentP->Element)
    {
        currentP = currentP->Next;
    }

    if(currentP == NULL)
    {
        fprintf(stderr, "%d is not in this list.\n", X);
        return NULL;
    }

    return currentP;
}