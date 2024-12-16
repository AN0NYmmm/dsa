#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    ElementType Element;
    PtrToNode Next;
};

Stack CreateStack(void)
{
    PtrToNode stack = malloc(sizeof(struct Node));
    if(stack == NULL)
    {
        fprintf(stderr, "Stack creation failed.\n");
        return NULL;
    }
    else
    {
        stack->Element = 0;
        stack->Next = NULL;
        return stack;
    }
}

int IsEmpty(Stack S)
{
    if(S == NULL)
    {
        fprintf(stderr, "Can't find this stack.\n");
        return -1;
    }

    return S->Next == NULL;
}

void Push(ElementType X, Stack S)
{
    if(S == NULL)
    {
        fprintf(stderr, "Can't find this stack.\n");
        return;
    }

    PtrToNode new_node = malloc(sizeof(struct Node));
    if(new_node == NULL)
    {
        fprintf(stderr, "Failed to push.\n");
        return;
    }
    
    PtrToNode tmp = S->Next;
    S->Next = new_node;
    new_node->Element = X;
    new_node->Next = tmp;

}

ElementType *Top(Stack S)
{
    if (S == NULL)
    {
        fprintf(stderr, "Can't find this stack.\n");
        return NULL;
    }

    if(S->Next == NULL)
    {
        fprintf(stderr, "This stack is empty.\n");
        return NULL;
    }

    return &(S->Next->Element);
}

void Pop(Stack S)
{
    if(S == NULL)
    {
        fprintf(stderr, "Can't find this stack.\n");
        return;
    }

    if(S->Next == NULL)
    {
        fprintf(stderr, "This stack is empty,cannot pop anymore.\n");
        return;
    }

    PtrToNode old_top = S->Next;
    S->Next = old_top->Next;
    free(old_top);

}

void MakeEmpty(Stack S)
{
    if(S == NULL)
    {
        fprintf(stderr, "Can't find this stack.\n");
        return;
    }
    
    if(S->Next == NULL)
    {
        fprintf(stderr, "This stack is already empty.\n");
        return;
    }
/*
    PtrToNode current = S->Next;
    while(current != NULL)
    {
        PtrToNode tmp = current->Next;
        free(current);
        current = tmp;
    }
    S->Next = NULL;
*/

    while(S->Next != NULL)
    {
        pop(S);
    }
    
}

void DisposeStack(Stack S)
{
    MakeEmpty(S);
    free(S);
}