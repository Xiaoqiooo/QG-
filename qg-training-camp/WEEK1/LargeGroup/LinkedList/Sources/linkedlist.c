#include"my.h"
//添加结点 （OK） 
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
	while(p->next!=NULL){//找到表尾结点 
		p = p->next;
	}
	q = (LinkedList)malloc(sizeof(LNode));
	q->data = e;
	q->next = p->next;
	p->next = q; 
}

//创建带无数据头结点的链表（OK） 
/**
 *  @name        : Status InitList(LinkList *L);
 *  @description : initialize an empty linked list with only the head node without value
 *  @param		 : L(the head node)
 *  @return		 : Status
 *  @notice      : None
    */
Status InitList(LinkedList *L)//使用二级指针进行初始化表头 
{
	*L = (LinkedList)malloc(sizeof(LNode));  //创建结点 
	if(!(*L)){           //当存储分配失败时 
		return error;
	} 
	(*L)-> next = NULL;  //设置头结点 
	return success;
}

//摧毁链表并释放所有结点 
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
	p = (*L)->next;        //p指向第一个结点 
	while(p){              //当链表存在结点，还未到表尾时 
		q = p->next; 
		free(p);
		p = q;
	}
	free(*L);
	*L = NULL;
}


//在结点p后插入结点q 
/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *  @description : insert node q after node p
 *  @param		 : p, q
 *  @return		 : Status
 *  @notice      : None
    */
Status InsertList(LNode *p, LNode *q)
{
	if(p == NULL || q == NULL){//当p或者q结点不存在的时候 
		return error;
	}          
	q->next = p->next; //当p、q结点都存在的时候 
	p->next = q;         
	return success;
}

//把结点p后的第一个结点的值保存给e，并且删除该结点 
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *  @description : delete the first node after the node p and assign its value to e
 *  @param		 : p, e
 *  @return		 : Status
 *  @notice      : None
    */
Status DeleteList(LNode *p, ElemType *e)
{
	if(p==NULL||p->next==NULL){      //当p结点或者p结点的下一个结点不存在的时候 
		return error;
	}
	e = p->next->data;              //把结点p后的第一个结点的值保存给e
	LNode *q = p->next;              //删除该结点 
	p->next = q->next;
	free(q); 
	return success; 
}

//遍历链表,调用visit（）函数 (OK)
/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *  @description : traverse the linked list and call the funtion visit
 *  @param		 : L(the head node), visit
 *  @return		 : None
 *  @notice      : None
    */
void TraverseList(LinkedList L, void (*visit)(ElemType e))//把这种有函数指针作为参数的函数称为回调函数 
{
	//对于void (*visit)(ElemType e)，visit是一个指针，指向函数，该函数有一个整形参数，返回类型为void 
	L = L->next;    //把指针指向首结点（不是无数据的头结点） 
	while(L){       //当链表存在有数据的结点的时候 
		visit(L->data);
		L = L->next; 
	}
}

//找到链表中第一个数据为e的结点(OK) 
/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *  @description : find the first node in the linked list according to e
 *  @param		 : L(the head node), e
 *  @return		 : Status
 *  @notice      : None
    */
Status SearchList(LinkedList L, ElemType e)
{
	L = L->next;     //把指针指向首结点（不是无数据的头结点） 
	while(L){        //当链表存在有数据的结点的时候
		if(L->data == e){    //当指针指向的结点的数据与e相同时 
			return success;
		}
		L = L->next;         //若不相同，指针接着往下移 
	}
	return error;   //若一直没有数据与e相同，最后L将指向NULL 
}

//反转链表 
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
	p1 = (*L)->next; //p1是目标指针 
	p2 = p1->next;   //p2是遍历指针 
	p1->next = NULL;
	s = p1;         //s用来存储每一次反转后的第一个结点 
	while(p2!=NULL){
		p1 = p2;
		p2 = p1->next;
		p1->next = s;
		s = p1;
	}
	(*L)->next = s; //最终连接头结点 
	return success;
}

//判断链表是否成环 
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
	if(L->next==NULL){     //当链表为空时 
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

//单链表奇偶调换
/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *  @description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *  @param		 : L(the head node)
 *  @return		 : LNode(the new head node)
 *  @notice      : choose to finish
    */
LNode* ReverseEvenList(LinkedList *L)//？？为什么返回值是LNod1e* 
{
	if((*L)->next==NULL){     //当链表为空时 
		return *L;
	}
	if((*L)->next->next==NULL){    //当链表只有一个有数据的结点时 
		return *L; 
	}
	LinkedList p,q;
	p = (*L)->next;         //指针p指向链表中有数据的奇数结点 
	q = (*L)->next->next;   //指针q指向链表中有数据的偶数结点
	do{
		exchange(p,q);	
	}while(p!=NULL && q!=NULL);
	return *L;
}

//找到链表的中间结点 
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

//访问（输出）结点的数据 
void visit(ElemType e)
{
	printf("%d\t",e); 
}

LinkedList ReverseEvenList2(LinkedList *L,int i); 

LinkedList ChoseOne(LinkedList L);

//交换两结点位置 
void exchange (LinkedList p,LinkedList q)
{
	LNode temp;
	temp = *p;
	*p = *q;
	*q = temp; 
}

//检验是否有乱输入其他字符
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
                printf("请输入整数：");
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
    for(m=0;m<len;m++)  // 将字符重新转换为数字
    {
        for(k=0;k<j;k++)
            arg *= 10;
        num += (word[m]-'0')*arg;
        arg = 1;
        j--;
    }
    return num;
} 

void menu()//菜单
{
	HideCursor();
	Beep(2000,250); //进入菜单发声 
	printf("\n");
	printf("\t******************************************************\n\n");
	printf("\t*            	     系统功能菜单                     *\n\n");
	printf("\t*            	                                      *\n\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t******************************************************\n");
	printf("\t*                  1.单链表菜单                      *\n");
	printf("\t*                  2.双向链表菜单                    *\n");
	printf("\t*                  0.退出系统                        *\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t请输入您所要执行的功能(0-2)：");
}

void menuone()//单链表菜单
{
	HideCursor();
	Beep(2000,250); //进入菜单发声 
	printf("\n");
	printf("\t******************************************************\n\n");
	printf("\t*            	     系统功能菜单                     *\n\n");
	printf("\t*            	                                      *\n\n");
	printf("\t******************************************************\n");
	printf("\t********************单链表操作************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t******************************************************\n");
	printf("\t*                  1.创建新链表                      *\n");
	printf("\t*                  2.添加结点                        *\n");
	printf("\t*                  3.插入新结点                      *\n");
	printf("\t*                  4.删除结点                        *\n");
	printf("\t*                  5.遍历链表                        *\n");
	printf("\t*                  6.查询数据是否在表中              *\n");
	printf("\t*                  7.反转链表                        *\n");
	printf("\t*                  8.判断链表是否成环                *\n");
	printf("\t*                  9.单链表奇偶调换                  *\n");
	printf("\t*                  10.找到链表的中间结点             *\n");
	printf("\t*                  0.删除链表并退出系统              *\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t请输入您所要执行的功能(0-10)：");
}

void menutwo()//双向链表菜单
{
	HideCursor();
	Beep(2000,250); //进入菜单发声 
	printf("\n");
	printf("\t******************************************************\n\n");
	printf("\t*            	     系统功能菜单                     *\n\n");
	printf("\t*            	                                      *\n\n");
	printf("\t******************************************************\n");
	printf("\t********************双向链表操作**********************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t******************************************************\n");
	printf("\t*                  1.创建新链表                      *\n");
	printf("\t*                  2.添加结点                        *\n");
	printf("\t*                  3.插入新结点在目标结点之前        *\n");
	printf("\t*                  4.插入新结点在目标结点之后        *\n");
	printf("\t*                  5.删除结点                        *\n");
	printf("\t*                  6.遍历链表                        *\n");
	printf("\t*                  0.删除链表并退出系统              *\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t请输入您所要执行的功能(0-6)：");
}

/**创建双向链表 
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L)
{
	*L = (DuLinkedList)malloc(sizeof(DuLNode));  //创建结点 
	(*L)-> prior = NULL;                      //无数据结点的设置
	(*L)-> next = NULL; 
	(*L)-> data = 0;
	return success;
}

/**摧毁双向链表 
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L)
{
	while(*L){             //当链表存在结点时 
		DuLinkedList p = *L;
		(*L) = (*L)->next;
		free(p);
	}
}

//添加结点 
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
	while(p->next!=NULL){//找到表尾结点 
		p = p->next;
	}
	q = (LinkedList)malloc(sizeof(LNode));
	q->data = e;
	q->prior = p;
	q->next = NULL;
	p->next = q; 
}
/**插入结点q在结点p之前 
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
	if(p==NULL || q==NULL){//当p或者q结点不存在的时候 
		return error;
	}
	p->prior ->next = q;           //当p、q结点都存在的时候 
	q->prior = p->prior;
	q->next = p;
	return success;
}

/**插入结点q在结点p之后 
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
	if(p==NULL || q==NULL){//当p或者q结点不存在的时候 
		return error;
	}
	q->next = p->next;     //当p、q结点都存在的时候
	p->next = q;            
	q->prior = p;
	return success;
}

/**把结点p后的第一个结点的值保存给e，并且删除该结点 
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
	if(p==NULL||p->next==NULL){      //当p结点或者p结点的下一个结点不存在的时候 
		return error;
	}
	DuLNode *q = p->next;              //删除该结点 
	e = q->data;              //把结点p后的第一个结点的值保存给e
	p->next = q->next;
	q->prior = NULL;
	free(q); 
	return success; 
}

/**遍历链表 
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
 void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 {
 	L = L->next;    //把指针指向首结点（不是无数据的头结点） 
	while(L){       //当链表存在有数据的结点的时候 
		visit(L->data);
		L = L->next; 
	}
 }
 
 void HideCursor()//隐藏光标  
{
	CONSOLE_CURSOR_INFO cursor_info = {1,0}; //第二个值为0表示隐藏光标
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void gotoxy(int x,int y)  //光标定位函数:让光标直接跳转到（x,y）位置的函数
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
    COORD pos; 
    pos.X = x;  //横坐标 
    pos.Y = y;  //纵坐标 
    SetConsoleCursorPosition(handle,pos);
}

void playtime() //显示时间函数 
{
	time_t timep;
    time(&timep);
    struct tm *p = gmtime(&timep);
    printf("\t%d/%d/%d", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday);
    printf(" %d:%d:%d\n", (8+p->tm_hour), p->tm_min, p->tm_sec); 
}
