#include "my.h"
int main() {
	HideCursor();    //���ع��
	system("color F1");//�ı䴰����ɫ 
	system("mode con cols=110 lines=30");//�ı䴰�ڴ�С 
	int n,x,y,m,temp,i; 
	int *e;
	system("cls");
	gotoxy(0,0);    //ʹ������ 
	playtime(); 
	printf("\n");
	
	int choice,num=0;
	LinkedList head = NULL; 
	DuLinkedList dhead = NULL;
	do{
		fflush(stdin);
		menu();   //�˵�
		n = judge_int();
		switch(n){
			case 1:{//������˵� 
				system("cls");
				gotoxy(0,0);
				menuone(); 
				x= judge_int();
				switch(x){
					case 1:{//����������
						system("cls");
						gotoxy(0,0);
						if(InitList(&head)){
							printf("�����ɹ�\n"); 
						}else{
							printf("����ʧ��\n"); 
						}
						system("pause");
						system("cls"); 
						break;
					}
					case 2:{//�����½��
						system("cls");
						gotoxy(0,0);
						printf("��������뼸���½�㣿\n");
						temp = scanf("%d",&n);
						if(!temp){
							printf("��������󣬼������ز˵�\n");
							break;
						}
						while(n--){
							printf("������������ݣ�\n");
							scanf("%d",&m); 
							Insert(&head,m);
						}
						printf("��ӳɹ�\n"); 
						system("pause");
						system("cls"); 
						break;
					}
					case 3:{//ָ�������½�� 
							printf("������Ҫ��������Ϊ���ٵĽ�������½�㣿\n");
							m = judge_int();
							printf("�½�������Ϊ��\n");
							temp = scanf("%d",&n);
							if(!temp){
								printf("��������󣬼������ز˵�\n");
								break;
							}
							LinkedList p,q;
							p = head->next;          //p��Ŀ���� 
							if(!p){
								printf("δ�ҵ������ݶ�Ӧ�Ľ�㣬�������ز˵�\n");
								break; 
							}
							while(p->data != m){
								p = p->next;
							}
							if(!p){
								printf("δ�ҵ������ݶ�Ӧ�Ľ�㣬�������ز˵�\n");
								break; 
							}
							q = (LinkedList)malloc(sizeof(LNode)); //q���¿��ٵĽ�� 
							q->next = NULL;
							q->data = n; 
							if(InsertList(p,q)){
								printf("��ӳɹ�\n"); 
							}else{
								printf("���ʧ��\n"); 
							}	
							system("pause");
							system("cls"); 
						break;
					}	
					case 4:{//ɾ�����
						system("cls");
						gotoxy(0,0);
						LNode *p;
						printf("������ɾ�����ڼ���λ�õĽ�㣿\n");
						i = judge_int();
						int m=1;
						p = head;
						while(p->next && m<i){
							p = p->next;
							++m;
						}
						if(!(p->next) || m>i){
							printf("��λ��û�н��\n");
							temp = 0; 
						}
						if(temp==1){
							if(DeleteList(p,e)){
								printf("ɾ���ɹ�\n"); 
							}else{
								printf("ɾ��ʧ��\n"); 
							} 	
						}
						system("pause");
						system("cls"); 
						break;
					}
					case 5:{//��������
						system("cls");
						gotoxy(0,0);
						if(head==NULL || head->next ==NULL){
							printf("�������ڻ���ֻ����һ���յ�ͷ���\n"); 
						}else{
							TraverseList(head,visit);
						}
						system("pause");
						system("cls"); 
						break;
					}
					case 6:{//��ѯ�����Ƿ��ڱ���
						system("cls");
						gotoxy(0,0);
						printf("������Ҫ���ҵ�����Ϊ���٣�\n");
						m = judge_int();
						if(SearchList(head,m)){
							printf("��ѯ�ɹ�����������Ϊ%d�Ľ��\n",m); 
						}else{
							printf("��ѯʧ�ܣ�����������Ϊ%d�Ľ��\n",m); 
						}  
						system("pause");
						system("cls"); 
						break;
					} 
					case 7:{//��ת����
						system("cls");
						gotoxy(0,0);
						if(head==NULL || head->next == NULL){
							printf("����Ϊ�ջ�������ֻ����һ�������ݵĽ��\n");
							printf("��תʧ��\n");
						}
						if(ReverseList(&head)){
							printf("��ת�ɹ�\n");
							printf("��ת��Ľ��:"); 
							TraverseList(head,visit);
						}else{
							printf("��תʧ��\n"); 
						}  
						system("pause");
						system("cls"); 
						break;
					}
					case 8:{//�ж������Ƿ�ɻ�
						system("cls");
						gotoxy(0,0);
						if(IsLoopList(head)){
							printf("����ɻ�\n"); 
						}else{
							printf("����û�гɻ�\n");
						}
						system("pause");
						system("cls"); 
						break;
					}
					case 9:{//��������ż����
						system("cls");
						gotoxy(0,0);
						if(ReverseEvenList(&head)){
							printf("��������ż�����ɹ�\n"); 
						}else{
							printf("��������ż����ʧ��\n");
						}
						system("pause");
						system("cls"); 
						break;
					}
					case 10:{//�ҵ�������м���
						system("cls");
						gotoxy(0,0);
						LNode *p;
						if(head == NULL || head->next == NULL){
							printf("������Ϊ������\n");
						}else{
							p=FindMidNode(&head);
							if(p){
								printf("�ҵ�������м���,����ֵΪ%d\n",p->data); 
							}else{
								printf("û�ҵ�������м���\n");
							}	
						}
						system("pause");
						system("cls"); 
						break;
					}
					case 0:{//ɾ�������˳�ϵͳ
						system("cls");
						gotoxy(0,0);
						DestroyList(&head);
						exit(0);
					}
					default:{
					printf("\n\t��Ǹ����������󣬽��������������˵�");
					system("pause");
					system("cls"); 
					fflush(stdin);       //������뻺����
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
						case 1:{//����������
							system("cls");
							gotoxy(0,0);
							if(InitList_DuL(&dhead)){
								printf("�����ɹ�\n");	
							}else{
								printf("����ʧ��\n"); 
							}
							system("pause");
							system("cls"); 
							break;
						}
						case 2:{//��ӽ�� 
							system("cls");
							gotoxy(0,0);
							printf("��������뼸���½�㣿\n");
							temp = scanf("%d",&n);
							if(!temp){
								printf("��������󣬼������ز˵�\n");
								break;
							}
							while(n--){
								printf("������������ݣ�\n");
								scanf("%d",&m); 
								DuInsert(&dhead,m);
							}
							printf("��ӳɹ�\n"); 
							system("pause");
							system("cls");
							break;
						}
						case 3:{//�����½����Ŀ����֮ǰ
							system("cls");
							gotoxy(0,0);
							printf("������Ҫ��������Ϊ���ٵĽ��ǰ�����½�㣿\n");
							scanf("%d",&m);
							printf("�½�������Ϊ��\n");
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
								printf("����ɹ�\n");
							}else{
								printf("����ʧ��\n");
							}
							system("pause");
							system("cls"); 
							break;
						}
						case 4:{//�����½����Ŀ����֮��
							system("cls");
							gotoxy(0,0);
							printf("������Ҫ��������Ϊ���ٵĽ�������½�㣿\n");
							scanf("%d",&m);
							printf("�½�������Ϊ��\n");
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
								printf("����ɹ�\n");
							}else{
								printf("����ʧ��\n");
							}	
							system("pause");
							system("cls"); 
							break;
						}
						case 5:{//ɾ�����
							system("cls");
							gotoxy(0,0);
							DuLNode *p;
							printf("������ɾ��������Ϊ���ٵĽ�����Ǹ���㣿\n");
							scanf("%d",&m);
							p = dhead;
							while(p->data!=m){
								p = p->next;
							}
							if(DeleteList_DuL(p,e)){
								printf("ɾ���ɹ�\n");
							}else{
								printf("ɾ��ʧ��\n");
							} 
							system("pause");
							system("cls"); 
							break;
						}
						case 6:{//��������
							system("cls");
							gotoxy(0,0);
							TraverseList_DuL(dhead,visit); 
							system("pause");
							system("cls"); 
							break;
						}
						case 0:{//ɾ�������˳�ϵͳ
							system("cls");
							gotoxy(0,0);
							DestroyList_DuL(&dhead);
							exit(0);
						}
						default:{
						printf("\n\t��Ǹ����������󣬽��������������˵�");
						system("pause");
						system("cls"); 
						fflush(stdin);       //������뻺����
						continue;
						}
					} 
					break;
					}
			case 0:{//�˳�ϵͳ 
					system("cls");
					gotoxy(0,0);
					exit(0);
				}
			default:{
					printf("\n\t��Ǹ���������������������Ҫִ�еĹ���(0-2)��");
					system("pause");
					system("cls"); 
					fflush(stdin);       //������뻺����
					continue;
			}
		}
	}while(1); 
	return 0;  
}
