#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h> 

#define OVERFLOW -1
typedef int ElemType;

//单链表的结构体 
typedef struct LNode {
	ElemType data;
  	struct LNode *next;
} LNode, *LinkedList;

//双向链表的结构体 
typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;

typedef enum Status{
	error,         //这个地方最一开始使用EROOR，程序报错：[Error] expected identifier before numeric constant 
	success        //查询后发现是ERROR本身有宏定义，所以冲突了，于是改用error 
}Status; 

//创建带无数据头结点的链表
/**

 *  @name        : Status InitList(LinkList *L);
 *  @description : initialize an empty linked list with only the head node without value
 *  @param		 : L(the head node)
 *  @return		 : Status
 *  @notice      : None
    */
    Status InitList(LinkedList *L);

//摧毁链表并释放所有结点 
/**

 *  @name        : void DestroyList(LinkedList *L)
 *  @description : destroy a linked list, free all the nodes
 *  @param		 : L(the head node)
 *  @return		 : None
 *  @notice      : None
    */
    void DestroyList(LinkedList *L);

//在结点p后插入结点q 
/**

 *  @name        : Status InsertList(LNode *p, LNode *q)
 *  @description : insert node q after node p
 *  @param		 : p, q
 *  @return		 : Status
 *  @notice      : None
    */
    Status InsertList(LNode *p, LNode *q);

//把结点p后的第一个结点的值保存给e，并且删除该结点 
/**

 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *  @description : delete the first node after the node p and assign its value to e
 *  @param		 : p, e
 *  @return		 : Status
 *  @notice      : None
    */
    Status DeleteList(LNode *p, ElemType *e);

//遍历链表 
/**

 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *  @description : traverse the linked list and call the funtion visit
 *  @param		 : L(the head node), visit
 *  @return		 : None
 *  @notice      : None
    */
    void TraverseList(LinkedList L, void (*visit)(ElemType e));

//找到链表中第一个数据为e的结点 
/**

 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *  @description : find the first node in the linked list according to e
 *  @param		 : L(the head node), e
 *  @return		 : Status
 *  @notice      : None
    */
    Status SearchList(LinkedList L, ElemType e);

//反转链表 
/**

 *  @name        : Status ReverseList(LinkedList *L)
 *  @description : reverse the linked list
 *  @param		 : L(the head node)
 *  @return		 : Status
 *  @notice      : None
    */
    Status ReverseList(LinkedList *L);

//判断链表是否成环 
/**

 *  @name        : Status IsLoopList(LinkedList L)
 *  @description : judge whether the linked list is looped
 *  @param		 : L(the head node)
 *  @return		 : Status
 *  @notice      : None
    */
    Status IsLoopList(LinkedList L);

//单链表奇偶调换
/**

 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *  @description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *  @param		 : L(the head node)
 *  @return		 : LNode(the new head node)
 *  @notice      : choose to finish
    */
    LNode* ReverseEvenList(LinkedList *L);

//找到链表的中间结点 
/**

 *  @name        : LNode* FindMidNode(LinkedList *L)
 *  @description : find the middle node in the linked list
 *  @param		 : L(the head node)
 *  @return		 : LNode
 *  @notice      : choose to finish
    */
    LNode* FindMidNode(LinkedList *L);

void visit(ElemType e);

LinkedList ReverseEvenList2(LinkedList *L,int i); 

LinkedList ChoseOne(LinkedList L);

void exchange (LinkedList p,LinkedList q);

int judge_int();

/**创建双向链表 
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L);

/**摧毁双向链表 
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L);

/**插入结点q在结点p之前 
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q);

/**插入结点q在结点p之后 
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q);

/**把结点p后的第一个结点的值保存给e，并且删除该结点 
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e);

/**遍历链表 
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
 void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e));
