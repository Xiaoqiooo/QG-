#include "tree.h" 
int main() {
	int x,y,z,choice;
	Node* root = (Node*)malloc(sizeof(Node));
	BinarySortTree* tree = (BinarySortTree*)malloc(sizeof(BinarySortTree));
	tree->root = root;
	BST_init(tree);
	BST_create(tree);
	do{
		fflush(stdin);
		menu();   //�˵�
		choice = judge_int();
		switch(choice){
			case 1:{//���� 
				system("cls");
				gotoxy(0,0);
				printf("��������Ҫ���ҵ����ݣ�\n");
				scanf("%d",&x);
				if(BST_search(tree,x)){
					printf("���д�������%d\n",x);
				}else{
					printf("���в���������%d\n",x); 
				}
				system("pause");
				system("cls"); 
				
				break;
			}
			case 2:{//ɾ�� 
				system("cls");
				gotoxy(0,0);				
				printf("��������Ҫɾ�������ݣ�\n");
				scanf("%d",&y);
				if(BST_delete(tree,y)){
					printf("ɾ���ɹ�\n");
				}else{
					printf("ɾ��ʧ��\n"); 
					if(!BST_search(tree,y)){
						printf("���в���������%d\n",y);
					}
				}
				system("pause");
				system("cls"); 
				break;
			}
			case 3:{//����
				system("cls");
				gotoxy(0,0);
				printf("��������Ҫ��������ݣ�\n");
				scanf("%d",&z);
				if(BST_insert(tree,z)){
					printf("����ɹ�\n");
				}else{
					printf("����ʧ��\n"); 
				}
				system("pause");
				system("cls"); 
				break;
			}
			case 4:{//������� 
				system("cls");
				gotoxy(0,0);
				if(BST_preorderI(tree)){
					printf("����������ݹ飩���\n"); 
				}else{
					printf("�������ʧ��\n");
				}
				if(BST_preorderR(tree)){
					printf("����������ǵݹ飩���\n"); 
				}else{
					printf("�������ʧ��\n");
				}
				system("pause");
				system("cls"); 
				break;
			}
			case 5:{//�������
				system("cls");
				gotoxy(0,0);
				if(BST_inorderI(tree)){
					printf("����������ݹ飩���\n"); 
				}else{
					printf("�������ʧ��\n");
				}
				if(BST_inorderR(tree)){
					printf("����������ǵݹ飩���\n"); 
				}else{
					printf("�������ʧ��\n");
				}
				system("pause");
				system("cls"); 
				break;
			}
			case 6:{//������� 
				system("cls");
				gotoxy(0,0);
				if(BST_postorderI(tree)){
					printf("����������ݹ飩���\n"); 
				}else{
					printf("�������ʧ��\n");
				}
				if(BST_postorderR(tree)){
					printf("����������ǵݹ飩���\n"); 
				}else{
					printf("�������ʧ��\n");
				}
				system("pause");
				system("cls"); 
				break;
			}
			case 7:{//������� 
				system("cls");
				gotoxy(0,0);
				if(BST_levelOrder(tree)){
					printf("����������\n"); 
				}else{
					printf("�������ʧ��\n");
				}
				system("pause");
				system("cls"); 
				break;
			}
			case 0:{//�˳�ϵͳ 
				system("cls");
				gotoxy(0,0);
				exit(0);
			}
			default:{
				printf("\n\t��Ǹ�������벻�Ϸ������������������˵�");
				system("pause");
				system("cls"); 
				fflush(stdin);       //������뻺����
				continue;
			}
		}
	}while(1);
	return 0;
}

