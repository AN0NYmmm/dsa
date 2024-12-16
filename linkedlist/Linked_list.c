#include "Linked_list.h"
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    ElementType Element;
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

void Delete(ElementType X, List L)
{
    if(L == NULL)
    {
        fprintf(stderr, "Can't find the list.\n");
        return;
    }
    else if(L->Next == NULL)
    {
        fprintf(stderr, "This is an empty list.\n");
        return;
    }

    Position current = L->Next;
    Position previous = L;
    while (current != NULL && X != current->Element)
    {
        previous = current;
        current = current->Next;
    }

    if(current == NULL)
    {
        fprintf(stderr, "%d is not in this list.\n", X);
        return;
    }
    
    previous->Next = current->Next;
    free(current);
    current = NULL;
    L->Element--;
    
}

Position FindPrevious(ElementType X, List L)
{
    if(L == NULL)
    {
        fprintf(stderr, "Can't find this list.\n");
        return NULL;
    }

    if(L->Next == NULL)
    {
        fprintf(stderr, "This list is empty.\n");
        return NULL;
    }

    Position previous = L;
    Position current = L->Next;
    while(current != NULL && X != current-> Element)
    {
        previous = current;
        current = current->Next;
    }

    if(current == NULL)
    {
        fprintf(stderr, "%d is not in this list.\n", X);
        return NULL;
    }
    else
    {
        return previous;
    }

}

void Insert(ElementType X, List L, Position P)
{
    if(L == NULL)
    {
        fprintf(stderr, "Can't find this list.\n");
        return;
    }

    Position current = L;
    if(P == NULL)
    {
        fprintf(stderr, "Can't find this position.\n");
        return;
    }
    else
    {
        while(current != NULL && current != P)
        {
            current = current->Next;
        }

        if(current == NULL)
        {
            fprintf(stderr, "Can't find the position in this list.\n");
            return;
        }
    }

    Position new_node = malloc(sizeof(struct Node));
    if(new_node == NULL)
    {
        fprintf(stderr, "Fail to insert node.\n");
        return;
    }
    
    new_node->Element = X;
    new_node->Next = current->Next;
    current->Next = new_node;
    L->Element++;

}

int CountElement(List L)
{
    if(L == NULL)
    {
        fprintf(stderr, "Can't find this list.\n");
        return -1;
    }
    
    int count = 0;
    Position p = L->Next;
    while(p != NULL)
    {
        count++;
        p = p->Next;
    }

    return count;
}

void MakeEmpty(List L)
{
    if(L == NULL)
    {
        fprintf(stderr, "Can't find this list.\n");
        return;
    }

    Position next = L->Next;
    while(next != NULL)
    {
        Position current = next->Next;
        free(next);
        next = current;
    }
    L->Next = NULL;

}

void DeleteList(List L)
{
    if(L == NULL)
    {
        fprintf(stderr, "This list does not exist.\n");
        return;
    }

    Position node = L->Next;
    while(node != NULL)
    {
        Position tmp = node->Next;
        free(node);
        node = tmp;
    }
    free(L);
}