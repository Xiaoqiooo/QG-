#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h> 

#define OVERFLOW -1
typedef int ElemType;

//������Ľṹ�� 
typedef struct LNode {
	ElemType data;
  	struct LNode *next;
} LNode, *LinkedList;

//˫������Ľṹ�� 
typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;

typedef enum Status{
	error,         //����ط���һ��ʼʹ��EROOR�����򱨴�[Error] expected identifier before numeric constant 
	success        //��ѯ������ERROR�����к궨�壬���Գ�ͻ�ˣ����Ǹ���error 
}Status; 

//������������ͷ��������
/**

 *  @name        : Status InitList(LinkList *L);
 *  @description : initialize an empty linked list with only the head node without value
 *  @param		 : L(the head node)
 *  @return		 : Status
 *  @notice      : None
    */
    Status InitList(LinkedList *L);

//�ݻ������ͷ����н�� 
/**

 *  @name        : void DestroyList(LinkedList *L)
 *  @description : destroy a linked list, free all the nodes
 *  @param		 : L(the head node)
 *  @return		 : None
 *  @notice      : None
    */
    void DestroyList(LinkedList *L);

//�ڽ��p�������q 
/**

 *  @name        : Status InsertList(LNode *p, LNode *q)
 *  @description : insert node q after node p
 *  @param		 : p, q
 *  @return		 : Status
 *  @notice      : None
    */
    Status InsertList(LNode *p, LNode *q);

//�ѽ��p��ĵ�һ������ֵ�����e������ɾ���ý�� 
/**

 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *  @description : delete the first node after the node p and assign its value to e
 *  @param		 : p, e
 *  @return		 : Status
 *  @notice      : None
    */
    Status DeleteList(LNode *p, ElemType *e);

//�������� 
/**

 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *  @description : traverse the linked list and call the funtion visit
 *  @param		 : L(the head node), visit
 *  @return		 : None
 *  @notice      : None
    */
    void TraverseList(LinkedList L, void (*visit)(ElemType e));

//�ҵ������е�һ������Ϊe�Ľ�� 
/**

 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *  @description : find the first node in the linked list according to e
 *  @param		 : L(the head node), e
 *  @return		 : Status
 *  @notice      : None
    */
    Status SearchList(LinkedList L, ElemType e);

//��ת���� 
/**

 *  @name        : Status ReverseList(LinkedList *L)
 *  @description : reverse the linked list
 *  @param		 : L(the head node)
 *  @return		 : Status
 *  @notice      : None
    */
    Status ReverseList(LinkedList *L);

//�ж������Ƿ�ɻ� 
/**

 *  @name        : Status IsLoopList(LinkedList L)
 *  @description : judge whether the linked list is looped
 *  @param		 : L(the head node)
 *  @return		 : Status
 *  @notice      : None
    */
    Status IsLoopList(LinkedList L);

//��������ż����
/**

 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *  @description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *  @param		 : L(the head node)
 *  @return		 : LNode(the new head node)
 *  @notice      : choose to finish
    */
    LNode* ReverseEvenList(LinkedList *L);

//�ҵ�������м��� 
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

/**����˫������ 
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L);

/**�ݻ�˫������ 
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L);

/**������q�ڽ��p֮ǰ 
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q);

/**������q�ڽ��p֮�� 
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q);

/**�ѽ��p��ĵ�һ������ֵ�����e������ɾ���ý�� 
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e);

/**�������� 
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
 void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e));
