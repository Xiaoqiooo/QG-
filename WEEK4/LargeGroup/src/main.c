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
		menu();   //菜单
		choice = judge_int();
		switch(choice){
			case 1:{//查找 
				system("cls");
				gotoxy(0,0);
				printf("请输入你要查找的数据：\n");
				scanf("%d",&x);
				if(BST_search(tree,x)){
					printf("树中存在数据%d\n",x);
				}else{
					printf("树中不存在数据%d\n",x); 
				}
				system("pause");
				system("cls"); 
				
				break;
			}
			case 2:{//删除 
				system("cls");
				gotoxy(0,0);				
				printf("请输入你要删除的数据：\n");
				scanf("%d",&y);
				if(BST_delete(tree,y)){
					printf("删除成功\n");
				}else{
					printf("删除失败\n"); 
					if(!BST_search(tree,y)){
						printf("树中不存在数据%d\n",y);
					}
				}
				system("pause");
				system("cls"); 
				break;
			}
			case 3:{//插入
				system("cls");
				gotoxy(0,0);
				printf("请输入你要插入的数据：\n");
				scanf("%d",&z);
				if(BST_insert(tree,z)){
					printf("插入成功\n");
				}else{
					printf("插入失败\n"); 
				}
				system("pause");
				system("cls"); 
				break;
			}
			case 4:{//先序遍历 
				system("cls");
				gotoxy(0,0);
				if(BST_preorderI(tree)){
					printf("先序遍历（递归）完成\n"); 
				}else{
					printf("先序遍历失败\n");
				}
				if(BST_preorderR(tree)){
					printf("先序遍历（非递归）完成\n"); 
				}else{
					printf("先序遍历失败\n");
				}
				system("pause");
				system("cls"); 
				break;
			}
			case 5:{//中序遍历
				system("cls");
				gotoxy(0,0);
				if(BST_inorderI(tree)){
					printf("中序遍历（递归）完成\n"); 
				}else{
					printf("中序遍历失败\n");
				}
				if(BST_inorderR(tree)){
					printf("中序遍历（非递归）完成\n"); 
				}else{
					printf("中序遍历失败\n");
				}
				system("pause");
				system("cls"); 
				break;
			}
			case 6:{//后序遍历 
				system("cls");
				gotoxy(0,0);
				if(BST_postorderI(tree)){
					printf("后序遍历（递归）完成\n"); 
				}else{
					printf("后序遍历失败\n");
				}
				if(BST_postorderR(tree)){
					printf("后序遍历（非递归）完成\n"); 
				}else{
					printf("后序遍历失败\n");
				}
				system("pause");
				system("cls"); 
				break;
			}
			case 7:{//层序遍历 
				system("cls");
				gotoxy(0,0);
				if(BST_levelOrder(tree)){
					printf("层序遍历完成\n"); 
				}else{
					printf("层序遍历失败\n");
				}
				system("pause");
				system("cls"); 
				break;
			}
			case 0:{//退出系统 
				system("cls");
				gotoxy(0,0);
				exit(0);
			}
			default:{
				printf("\n\t抱歉，您输入不合法，接下来将返回主菜单");
				system("pause");
				system("cls"); 
				fflush(stdin);       //清空输入缓冲区
				continue;
			}
		}
	}while(1);
	return 0;
}

