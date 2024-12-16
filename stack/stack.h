#ifndef _Stack_h

#define _Stack_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

typedef int ElementType;

Stack CreateStack(void);
int IsEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType *Top(Stack S);
void Pop(Stack S);
void MakeEmpty(Stack S);
void DisposeStack(Stack S);

#endif