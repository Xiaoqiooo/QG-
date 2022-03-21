#include"my.h"
//��ӽ�� ��OK�� 
/**
 *  @name        : void Insert(LinkedList *L,ElemType e);
 *  @description : insert a new node after list
 *  @param		 : L(the head node),e
 *  @return		 : None
 *  @notice      : None
    */
void Insert(LinkedList *L,ElemType e)
{
	LinkedList p,q;
	p = *L;
	while(p->next!=NULL){//�ҵ���β��� 
		p = p->next;
	}
	q = (LinkedList)malloc(sizeof(LNode));
	q->data = e;
	q->next = p->next;
	p->next = q; 
}

//������������ͷ��������OK�� 
/**
 *  @name        : Status InitList(LinkList *L);
 *  @description : initialize an empty linked list with only the head node without value
 *  @param		 : L(the head node)
 *  @return		 : Status
 *  @notice      : None
    */
Status InitList(LinkedList *L)//ʹ�ö���ָ����г�ʼ����ͷ 
{
	*L = (LinkedList)malloc(sizeof(LNode));  //������� 
	if(!(*L)){           //���洢����ʧ��ʱ 
		return error;
	} 
	(*L)-> next = NULL;  //����ͷ��� 
	return success;
}

//�ݻ������ͷ����н�� 
/**
 *  @name        : void DestroyList(LinkedList *L)
 *  @description : destroy a linked list, free all the nodes
 *  @param		 : L(the head node)
 *  @return		 : None
 *  @notice      : None
    */
void DestroyList(LinkedList *L)
{
	LinkedList p,q;
	p = (*L)->next;        //pָ���һ����� 
	while(p){              //��������ڽ�㣬��δ����βʱ 
		q = p->next; 
		free(p);
		p = q;
	}
	free(*L);
	*L = NULL;
}


//�ڽ��p�������q 
/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *  @description : insert node q after node p
 *  @param		 : p, q
 *  @return		 : Status
 *  @notice      : None
    */
Status InsertList(LNode *p, LNode *q)
{
	if(p == NULL || q == NULL){//��p����q��㲻���ڵ�ʱ�� 
		return error;
	}          
	q->next = p->next; //��p��q��㶼���ڵ�ʱ�� 
	p->next = q;         
	return success;
}

//�ѽ��p��ĵ�һ������ֵ�����e������ɾ���ý�� 
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *  @description : delete the first node after the node p and assign its value to e
 *  @param		 : p, e
 *  @return		 : Status
 *  @notice      : None
    */
Status DeleteList(LNode *p, ElemType *e)
{
	if(p==NULL||p->next==NULL){      //��p������p������һ����㲻���ڵ�ʱ�� 
		return error;
	}
	e = p->next->data;              //�ѽ��p��ĵ�һ������ֵ�����e
	LNode *q = p->next;              //ɾ���ý�� 
	p->next = q->next;
	free(q); 
	return success; 
}

//��������,����visit�������� (OK)
/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *  @description : traverse the linked list and call the funtion visit
 *  @param		 : L(the head node), visit
 *  @return		 : None
 *  @notice      : None
    */
void TraverseList(LinkedList L, void (*visit)(ElemType e))//�������к���ָ����Ϊ�����ĺ�����Ϊ�ص����� 
{
	//����void (*visit)(ElemType e)��visit��һ��ָ�룬ָ�������ú�����һ�����β�������������Ϊvoid 
	L = L->next;    //��ָ��ָ���׽�㣨���������ݵ�ͷ��㣩 
	while(L){       //��������������ݵĽ���ʱ�� 
		visit(L->data);
		L = L->next; 
	}
}

//�ҵ������е�һ������Ϊe�Ľ��(OK) 
/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *  @description : find the first node in the linked list according to e
 *  @param		 : L(the head node), e
 *  @return		 : Status
 *  @notice      : None
    */
Status SearchList(LinkedList L, ElemType e)
{
	L = L->next;     //��ָ��ָ���׽�㣨���������ݵ�ͷ��㣩 
	while(L){        //��������������ݵĽ���ʱ��
		if(L->data == e){    //��ָ��ָ��Ľ���������e��ͬʱ 
			return success;
		}
		L = L->next;         //������ͬ��ָ����������� 
	}
	return error;   //��һֱû��������e��ͬ�����L��ָ��NULL 
}

//��ת���� 
/**
 *  @name        : Status ReverseList(LinkedList *L)
 *  @description : reverse the linked list
 *  @param		 : L(the head node)
 *  @return		 : Status
 *  @notice      : None
    */	
Status ReverseList(LinkedList *L)
{
	LinkedList p1,p2,s;
	p1 = (*L)->next; //p1��Ŀ��ָ�� 
	p2 = p1->next;   //p2�Ǳ���ָ�� 
	p1->next = NULL;
	s = p1;         //s�����洢ÿһ�η�ת��ĵ�һ����� 
	while(p2!=NULL){
		p1 = p2;
		p2 = p1->next;
		p1->next = s;
		s = p1;
	}
	(*L)->next = s; //��������ͷ��� 
	return success;
}

//�ж������Ƿ�ɻ� 
/**
 *  @name        : Status IsLoopList(LinkedList L)
 *  @description : judge whether the linked list is looped
 *  @param		 : L(the head node)
 *  @return		 : Status
 *  @notice      : None
    */
Status IsLoopList(LinkedList L)
{
	LinkedList fast,slow;
	if(L->next==NULL){     //������Ϊ��ʱ 
		return error;
	}
	fast = L->next;
	slow = L->next;
	while(fast->next!=NULL &&slow->next!=NULL){
		fast = fast->next->next;  
		slow = slow->next;    
		if(fast == slow){
			return success;
		}   
		if((fast = fast->next->next)==NULL){
			return error;
		}
	}
}

//��������ż����
/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *  @description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *  @param		 : L(the head node)
 *  @return		 : LNode(the new head node)
 *  @notice      : choose to finish
    */
LNode* ReverseEvenList(LinkedList *L)//����Ϊʲô����ֵ��LNod1e* 
{
	if((*L)->next==NULL){     //������Ϊ��ʱ 
		return *L;
	}
	if((*L)->next->next==NULL){    //������ֻ��һ�������ݵĽ��ʱ 
		return *L; 
	}
	LinkedList p,q;
	p = (*L)->next;         //ָ��pָ�������������ݵ�������� 
	q = (*L)->next->next;   //ָ��qָ�������������ݵ�ż�����
	do{
		exchange(p,q);	
	}while(p!=NULL && q!=NULL);
	return *L;
}

//�ҵ�������м��� 
/**

 *  @name        : LNode* FindMidNode(LinkedList *L)
 *  @description : find the middle node in the linked list
 *  @param		 : L(the head node)
 *  @return		 : LNode
 *  @notice      : choose to finish
    */
LNode* FindMidNode(LinkedList *L)
{
	LinkedList fast,slow;
	fast = (*L);
	slow = (*L);
	while(fast!=NULL && slow!=NULL){
		fast = fast->next->next;  
		slow = slow->next;        
	}
	return slow;
}

//���ʣ�������������� 
void visit(ElemType e)
{
	printf("%d\t",e); 
}

LinkedList ReverseEvenList2(LinkedList *L,int i); 

LinkedList ChoseOne(LinkedList L);

//���������λ�� 
void exchange (LinkedList p,LinkedList q)
{
	LNode temp;
	temp = *p;
	*p = *q;
	*q = temp; 
}

//�����Ƿ��������������ַ�
int judge_int()
{
	int len, num = 0, arg = 1;
    char word[10];  
    int m, j= 1, k;
    while(j)
    {
        scanf("%s", word);
        len = strlen(word);
        for(m = 0;m<len;m++)
        {
            if(word[m]<'0' || word[m]>'9')  
            {
                printf("������������");
                break;
            }
            else 
            {
                if(m == len-1)
                    j = 0;
            }
        }
    }
    j = len-1;
    for(m=0;m<len;m++)  // ���ַ�����ת��Ϊ����
    {
        for(k=0;k<j;k++)
            arg *= 10;
        num += (word[m]-'0')*arg;
        arg = 1;
        j--;
    }
    return num;
} 

void menu()//�˵�
{
	HideCursor();
	Beep(2000,250); //����˵����� 
	printf("\n");
	printf("\t******************************************************\n\n");
	printf("\t*            	     ϵͳ���ܲ˵�                     *\n\n");
	printf("\t*            	                                      *\n\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t******************************************************\n");
	printf("\t*                  1.������˵�                      *\n");
	printf("\t*                  2.˫������˵�                    *\n");
	printf("\t*                  0.�˳�ϵͳ                        *\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t����������Ҫִ�еĹ���(0-2)��");
}

void menuone()//������˵�
{
	HideCursor();
	Beep(2000,250); //����˵����� 
	printf("\n");
	printf("\t******************************************************\n\n");
	printf("\t*            	     ϵͳ���ܲ˵�                     *\n\n");
	printf("\t*            	                                      *\n\n");
	printf("\t******************************************************\n");
	printf("\t********************���������************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t******************************************************\n");
	printf("\t*                  1.����������                      *\n");
	printf("\t*                  2.��ӽ��                        *\n");
	printf("\t*                  3.�����½��                      *\n");
	printf("\t*                  4.ɾ�����                        *\n");
	printf("\t*                  5.��������                        *\n");
	printf("\t*                  6.��ѯ�����Ƿ��ڱ���              *\n");
	printf("\t*                  7.��ת����                        *\n");
	printf("\t*                  8.�ж������Ƿ�ɻ�                *\n");
	printf("\t*                  9.��������ż����                  *\n");
	printf("\t*                  10.�ҵ�������м���             *\n");
	printf("\t*                  0.ɾ�������˳�ϵͳ              *\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t����������Ҫִ�еĹ���(0-10)��");
}

void menutwo()//˫������˵�
{
	HideCursor();
	Beep(2000,250); //����˵����� 
	printf("\n");
	printf("\t******************************************************\n\n");
	printf("\t*            	     ϵͳ���ܲ˵�                     *\n\n");
	printf("\t*            	                                      *\n\n");
	printf("\t******************************************************\n");
	printf("\t********************˫���������**********************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t******************************************************\n");
	printf("\t*                  1.����������                      *\n");
	printf("\t*                  2.��ӽ��                        *\n");
	printf("\t*                  3.�����½����Ŀ����֮ǰ        *\n");
	printf("\t*                  4.�����½����Ŀ����֮��        *\n");
	printf("\t*                  5.ɾ�����                        *\n");
	printf("\t*                  6.��������                        *\n");
	printf("\t*                  0.ɾ�������˳�ϵͳ              *\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t����������Ҫִ�еĹ���(0-6)��");
}

/**����˫������ 
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L)
{
	*L = (DuLinkedList)malloc(sizeof(DuLNode));  //������� 
	(*L)-> prior = NULL;                      //�����ݽ�������
	(*L)-> next = NULL; 
	(*L)-> data = 0;
	return success;
}

/**�ݻ�˫������ 
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L)
{
	while(*L){             //��������ڽ��ʱ 
		DuLinkedList p = *L;
		(*L) = (*L)->next;
		free(p);
	}
}

//��ӽ�� 
/**
 *  @name        : void DuInsert(DuLinkedList *L,ElemType e);
 *  @description : insert a new node after list
 *  @param		 : L(the head node),e
 *  @return		 : None
 *  @notice      : None
    */
void DuInsert(DuLinkedList *L,ElemType e)
{
	DuLinkedList p,q;
	p = *L;
	while(p->next!=NULL){//�ҵ���β��� 
		p = p->next;
	}
	q = (LinkedList)malloc(sizeof(LNode));
	q->data = e;
	q->prior = p;
	q->next = NULL;
	p->next = q; 
}
/**������q�ڽ��p֮ǰ 
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
	if(p==NULL || q==NULL){//��p����q��㲻���ڵ�ʱ�� 
		return error;
	}
	p->prior ->next = q;           //��p��q��㶼���ڵ�ʱ�� 
	q->prior = p->prior;
	q->next = p;
	return success;
}

/**������q�ڽ��p֮�� 
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
	if(p==NULL || q==NULL){//��p����q��㲻���ڵ�ʱ�� 
		return error;
	}
	q->next = p->next;     //��p��q��㶼���ڵ�ʱ��
	p->next = q;            
	q->prior = p;
	return success;
}

/**�ѽ��p��ĵ�һ������ֵ�����e������ɾ���ý�� 
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
	if(p==NULL||p->next==NULL){      //��p������p������һ����㲻���ڵ�ʱ�� 
		return error;
	}
	DuLNode *q = p->next;              //ɾ���ý�� 
	e = q->data;              //�ѽ��p��ĵ�һ������ֵ�����e
	p->next = q->next;
	q->prior = NULL;
	free(q); 
	return success; 
}

/**�������� 
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
 void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 {
 	L = L->next;    //��ָ��ָ���׽�㣨���������ݵ�ͷ��㣩 
	while(L){       //��������������ݵĽ���ʱ�� 
		visit(L->data);
		L = L->next; 
	}
 }
 
 void HideCursor()//���ع��  
{
	CONSOLE_CURSOR_INFO cursor_info = {1,0}; //�ڶ���ֵΪ0��ʾ���ع��
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void gotoxy(int x,int y)  //��궨λ����:�ù��ֱ����ת����x,y��λ�õĺ���
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������
    COORD pos; 
    pos.X = x;  //������ 
    pos.Y = y;  //������ 
    SetConsoleCursorPosition(handle,pos);
}

void playtime() //��ʾʱ�亯�� 
{
	time_t timep;
    time(&timep);
    struct tm *p = gmtime(&timep);
    printf("\t%d/%d/%d", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday);
    printf(" %d:%d:%d\n", (8+p->tm_hour), p->tm_min, p->tm_sec); 
}
