#ifndef _Linked_List

#define _Linked_List

struct Node;
//a forward declaration of linked list node.节点的前向声明
typedef struct Node *PtrToNode;
//linked list node pointer.指向节点结构的指针
typedef PtrToNode List;
//'List' represents the head node of the linked list.List是链表的表头
typedef PtrToNode Position;
//链表节点的位置

typedef int ElementType;
//Define the data type in the linked list, replace 'int' according to actual needs.

List CreateList(void);
//Create an empty linked list.建立空链表
void Add(ElementType X, List L);
//Add an element to the end of the linked list.在链表的末尾增加元素
int IsEmpty(List L);
//Check if the linked list is empty.判断链表是否为空
int IsLast(Position P, List L);
//Check if the position is the last node.判断是否为表尾
Position Find(ElementType X, List L);
//Find the position of an element.查找元素位置
void Delete(ElementType X, List L);
//Delete a node.删除节点
Position FindPrevious(ElementType X, List L);
//Find the position of the previous node.查找前一个节点的位置
void Insert(ElementType X, List L, Position P);
//Insert a node.插入节点
int CountElement(List L);
//Count the number of nodes in the linked list.
void MakeEmpty(List L);
//Empty the linked list.
void DeleteList(List L);
//Delete the linked list.删除链表

#endif

/*Place in the implementation file(放在实现文件中)

struct node
{
    ElementType Element;
    Position Next;
};

*/