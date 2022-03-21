#include "my.h"
int main() {
	HideCursor();    //隐藏光标
	system("color F1");//改变窗口颜色 
	system("mode con cols=110 lines=30");//改变窗口大小 
	int n,x,y,m,temp,i; 
	int *e;
	system("cls");
	gotoxy(0,0);    //使不闪屏 
	playtime(); 
	printf("\n");
	
	int choice,num=0;
	LinkedList head = NULL; 
	DuLinkedList dhead = NULL;
	do{
		fflush(stdin);
		menu();   //菜单
		n = judge_int();
		switch(n){
			case 1:{//单链表菜单 
				system("cls");
				gotoxy(0,0);
				menuone(); 
				x= judge_int();
				switch(x){
					case 1:{//创建新链表
						system("cls");
						gotoxy(0,0);
						if(InitList(&head)){
							printf("创建成功\n"); 
						}else{
							printf("创建失败\n"); 
						}
						system("pause");
						system("cls"); 
						break;
					}
					case 2:{//插入新结点
						system("cls");
						gotoxy(0,0);
						printf("您打算插入几个新结点？\n");
						temp = scanf("%d",&n);
						if(!temp){
							printf("您输入错误，即将返回菜单\n");
							break;
						}
						while(n--){
							printf("请输入结点的数据：\n");
							scanf("%d",&m); 
							Insert(&head,m);
						}
						printf("添加成功\n"); 
						system("pause");
						system("cls"); 
						break;
					}
					case 3:{//指定插入新结点 
							printf("请输入要在数据域为多少的结点后插入新结点？\n");
							m = judge_int();
							printf("新结点的数据为？\n");
							temp = scanf("%d",&n);
							if(!temp){
								printf("您输入错误，即将返回菜单\n");
								break;
							}
							LinkedList p,q;
							p = head->next;          //p是目标结点 
							if(!p){
								printf("未找到该数据对应的结点，即将返回菜单\n");
								break; 
							}
							while(p->data != m){
								p = p->next;
							}
							if(!p){
								printf("未找到该数据对应的结点，即将返回菜单\n");
								break; 
							}
							q = (LinkedList)malloc(sizeof(LNode)); //q是新开辟的结点 
							q->next = NULL;
							q->data = n; 
							if(InsertList(p,q)){
								printf("添加成功\n"); 
							}else{
								printf("添加失败\n"); 
							}	
							system("pause");
							system("cls"); 
						break;
					}	
					case 4:{//删除结点
						system("cls");
						gotoxy(0,0);
						LNode *p;
						printf("请输入删除数第几个位置的结点？\n");
						i = judge_int();
						int m=1;
						p = head;
						while(p->next && m<i){
							p = p->next;
							++m;
						}
						if(!(p->next) || m>i){
							printf("该位置没有结点\n");
							temp = 0; 
						}
						if(temp==1){
							if(DeleteList(p,e)){
								printf("删除成功\n"); 
							}else{
								printf("删除失败\n"); 
							} 	
						}
						system("pause");
						system("cls"); 
						break;
					}
					case 5:{//遍历链表
						system("cls");
						gotoxy(0,0);
						if(head==NULL || head->next ==NULL){
							printf("链表不存在或者只存在一个空的头结点\n"); 
						}else{
							TraverseList(head,visit);
						}
						system("pause");
						system("cls"); 
						break;
					}
					case 6:{//查询数据是否在表中
						system("cls");
						gotoxy(0,0);
						printf("请输入要查找的数据为多少？\n");
						m = judge_int();
						if(SearchList(head,m)){
							printf("查询成功，存在数据为%d的结点\n",m); 
						}else{
							printf("查询失败，不存在数据为%d的结点\n",m); 
						}  
						system("pause");
						system("cls"); 
						break;
					} 
					case 7:{//反转链表
						system("cls");
						gotoxy(0,0);
						if(head==NULL || head->next == NULL){
							printf("链表为空或者链表只含有一个有数据的结点\n");
							printf("反转失败\n");
						}
						if(ReverseList(&head)){
							printf("反转成功\n");
							printf("反转后的结果:"); 
							TraverseList(head,visit);
						}else{
							printf("反转失败\n"); 
						}  
						system("pause");
						system("cls"); 
						break;
					}
					case 8:{//判断链表是否成环
						system("cls");
						gotoxy(0,0);
						if(IsLoopList(head)){
							printf("链表成环\n"); 
						}else{
							printf("链表没有成环\n");
						}
						system("pause");
						system("cls"); 
						break;
					}
					case 9:{//单链表奇偶调换
						system("cls");
						gotoxy(0,0);
						if(ReverseEvenList(&head)){
							printf("单链表奇偶调换成功\n"); 
						}else{
							printf("单链表奇偶调换失败\n");
						}
						system("pause");
						system("cls"); 
						break;
					}
					case 10:{//找到链表的中间结点
						system("cls");
						gotoxy(0,0);
						LNode *p;
						if(head == NULL || head->next == NULL){
							printf("该链表为空链表\n");
						}else{
							p=FindMidNode(&head);
							if(p){
								printf("找到链表的中间结点,它的值为%d\n",p->data); 
							}else{
								printf("没找到链表的中间结点\n");
							}	
						}
						system("pause");
						system("cls"); 
						break;
					}
					case 0:{//删除链表并退出系统
						system("cls");
						gotoxy(0,0);
						DestroyList(&head);
						exit(0);
					}
					default:{
					printf("\n\t抱歉，您输入错误，接下来将返回主菜单");
					system("pause");
					system("cls"); 
					fflush(stdin);       //清空输入缓冲区
					continue;
					}
				} 
				break;
				}
			case 2:{
					system("cls");
					gotoxy(0,0);
					menutwo(); 
					scanf("%d",&x);
					switch(x){
						case 1:{//创建新链表
							system("cls");
							gotoxy(0,0);
							if(InitList_DuL(&dhead)){
								printf("创建成功\n");	
							}else{
								printf("创建失败\n"); 
							}
							system("pause");
							system("cls"); 
							break;
						}
						case 2:{//添加结点 
							system("cls");
							gotoxy(0,0);
							printf("您打算插入几个新结点？\n");
							temp = scanf("%d",&n);
							if(!temp){
								printf("您输入错误，即将返回菜单\n");
								break;
							}
							while(n--){
								printf("请输入结点的数据：\n");
								scanf("%d",&m); 
								DuInsert(&dhead,m);
							}
							printf("添加成功\n"); 
							system("pause");
							system("cls");
							break;
						}
						case 3:{//插入新结点在目标结点之前
							system("cls");
							gotoxy(0,0);
							printf("请输入要在数据域为多少的结点前插入新结点？\n");
							scanf("%d",&m);
							printf("新结点的数据为？\n");
							scanf("%d",&n); 
							DuLNode *p,*q;
							p = dhead;
							q = (DuLNode*)malloc(sizeof(DuLNode)); 
							q->next = NULL;
							q->data = n; 
							while(p->data!=m){
								p = p->next;
							}
							if(InsertBeforeList_DuL(p,q)){
								printf("插入成功\n");
							}else{
								printf("插入失败\n");
							}
							system("pause");
							system("cls"); 
							break;
						}
						case 4:{//插入新结点在目标结点之后
							system("cls");
							gotoxy(0,0);
							printf("请输入要在数据域为多少的结点后插入新结点？\n");
							scanf("%d",&m);
							printf("新结点的数据为？\n");
							scanf("%d",&n); 
							DuLNode *p,*q;
							p = dhead;
							q = (DuLNode*)malloc(sizeof(DuLNode)); 
							while(p->data!=m){
								p = p->next;
							}
							q->next = NULL;
							q->data = n; 
							if(InsertAfterList_DuL(p,q)){
								printf("插入成功\n");
							}else{
								printf("插入失败\n");
							}	
							system("pause");
							system("cls"); 
							break;
						}
						case 5:{//删除结点
							system("cls");
							gotoxy(0,0);
							DuLNode *p;
							printf("请输入删除数据域为多少的结点后的那个结点？\n");
							scanf("%d",&m);
							p = dhead;
							while(p->data!=m){
								p = p->next;
							}
							if(DeleteList_DuL(p,e)){
								printf("删除成功\n");
							}else{
								printf("删除失败\n");
							} 
							system("pause");
							system("cls"); 
							break;
						}
						case 6:{//遍历链表
							system("cls");
							gotoxy(0,0);
							TraverseList_DuL(dhead,visit); 
							system("pause");
							system("cls"); 
							break;
						}
						case 0:{//删除链表并退出系统
							system("cls");
							gotoxy(0,0);
							DestroyList_DuL(&dhead);
							exit(0);
						}
						default:{
						printf("\n\t抱歉，您输入错误，接下来将返回主菜单");
						system("pause");
						system("cls"); 
						fflush(stdin);       //清空输入缓冲区
						continue;
						}
					} 
					break;
					}
			case 0:{//退出系统 
					system("cls");
					gotoxy(0,0);
					exit(0);
				}
			default:{
					printf("\n\t抱歉，您输入错误，请输入您所要执行的功能(0-2)：");
					system("pause");
					system("cls"); 
					fflush(stdin);       //清空输入缓冲区
					continue;
			}
		}
	}while(1); 
	return 0;  
}
