#include "tree.h"
//初始化树 
Status BST_init(BinarySortTreePtr p) 
{
	Node* t = (Node*)malloc(sizeof(Node));//建立头结点
	t = NULL; 
	p->root = t;
	return succeed;
}

//创建二叉树
void BST_create(BinarySortTreePtr p)
{
	int a,i,x;
	printf("请输入该数有几个数据：\n");
	scanf("%d",&a);
	for(i=0 ; i<a ; i++){
		srand((unsigned)time(0)); //随机数种子
		x = rand()%50;         //0到100范围内的随机数
		BST_insert(p,x);
	}
}  

//插入
Status BST_insert(BinarySortTreePtr p, ElemType e)
{
	BinarySortTree* temp = (BinarySortTree*)malloc(sizeof(BinarySortTree));
	if(p->root==NULL){
		p->root = (Node*)malloc(sizeof(Node));
		p->root->value = e;
		p->root->left = NULL;
		p->root->right = NULL;
		return succeed;
	}else if(p->root->value >= e){
		//e是左孩子
		temp = &(p->root->left);
		return BST_insert(temp,e);
	}else{
		//e是右孩子 
		temp = &(p->root->right);
		return BST_insert(temp,e);
	} 
 } 
 
//删除
Status BST_delete(BinarySortTreePtr p, ElemType e)
{
	//找到要删除结点的位置
	if(!p->root){
		return failed;
	}
	if(p->root->value == e){
		return delete(p->root);
	}
	if(p->root->value >= e){
		return BST_delete(&(p->root->left),e);
	}
	if(p->root->value < e){
		return BST_delete(&(p->root->right),e);
	}
 } 
 Status delete(Node* p)
 {
 	Node *temp,*l;
	//目标结点没有儿子的时候，直接删除
	if(p->right==NULL && p->left==NULL){
		free(p);
	} 
	//目标结点有左儿子或者右儿子的时候，儿子顶替
	if(p->left==NULL && p->right!=NULL){
		temp = p;
		p = p->right;
		free(temp);
	}
	if(p->left!=NULL && p->right==NULL){
		temp = p;
		p = p->left;
		free(temp);
	}
	//目标结点有两个儿子的时候，找左边的最大的树（前驱结点）进行交换，最后删除前驱结点 
	if(p->left!=NULL && p->right!=NULL){
		temp = p;
		l = p->left;
		while(l->right){//找到左边的最大的结点 
			temp = l;
			l = l->right;
		}
		//退出循环是 l是前驱结点，l是temp的右节点
		//进行交换 
		p->value = l->value;
		if(temp == p){//目标结点如果是根节点的左儿子 
			temp->left = l->left; 
		}else{
			temp->right = l->left; 
		}
		free(l);
	}
	return succeed;
}

 
//查找
Status BST_search(BinarySortTreePtr p, ElemType e)
{
	if(!p->root){
		return failed;
	}
	if(p->root->value == e){
		return succeed;
	}
	if(p->root->value >= e){
		return BST_search(&(p->root->left),e);
	}
	if(p->root->value < e){
		return BST_search(&(p->root->right),e);
	}
} 
 
//递归的前序遍历
Status BST_preorderI(BinarySortTreePtr p)
{
	BinarySortTree* templ = (BinarySortTree*)malloc(sizeof(BinarySortTree));
	BinarySortTree* tempr = (BinarySortTree*)malloc(sizeof(BinarySortTree));
	if(p->root){
		printf("%d\t",p->root->value);
		templ->root = p->root->left;
		BST_preorderI(templ);
		tempr->root = p->root->right;
		BST_preorderI(tempr);
	}
	return succeed;
}

//非递归的前序遍历
Status BST_preorderR(BinarySortTreePtr p)
{
	//利用栈
	//定义一个栈
	Node* s[10],*r;
	int top = -1;//初始化
	Node* temp = p->root; 
	while(temp!=NULL || top!=-1){
		if(temp!=NULL){
			top++;
			s[top] = temp;
			printf("%d\t",temp->value);
			temp = temp->left;
		}else{
			temp = s[top];
			top--;
			temp = temp->right;
		}
	} 
/*	if(p->root){//判断二叉树是否为空，不为空，则将根节点入栈。
		top++;
		s[top] = p->root;
		while(top > -1){//退栈并访问该节点
			r = s[top];
			top--;
			printf("%d\t",r->value);
			if(p->root->right){//如果有右孩子则右孩子先进栈 
				top++;
				s[top] = p->root->right;
			}
			if(p->root->left){//如果有左孩子则左孩子先进栈 
				top++;
				s[top] = p->root->left;
			}
		}
	}*/
	return succeed; 
}

//递归的中序遍历 
Status BST_inorderI(BinarySortTreePtr p)
{
	if(p->root){
		BST_inorderI(&(p->root->left));
		printf("%d\t",p->root->value);
		BST_inorderI(&(p->root->right));
	}
	return succeed;
}

//非递归的中序遍历 
Status BST_inorderR(BinarySortTreePtr p)
{
	//利用栈
	//定义一个栈
	Node* s[10],*r;
	int top = -1;//初始化
	Node* temp = p->root; 
	while(temp!=NULL || top!=-1){
		if(temp!=NULL){
			top++;
			s[top] = temp;
			temp = temp->left;
		}else{
			temp = s[top];
			top--;
			printf("%d\t",temp->value);
			temp = temp->right;
		}
	} 
	/*if(p->root){//判断二叉树是否为空，不为空，则将根节点入栈。
		top++;
		s[top] = p->root;
		while(p->root->left){//一致找到最左边的那个结点 
			r = s[top];
			top++;
			s[top] = r->left;
		} 
		while(top > -1){//退栈并访问该节点
			r = s[top];
			top--;
			printf("%d\t",r->value);
			r = s[top];
			if(r->right){//如果右边有 
				top++;
				s[top] = r->right;
			}else{
				r = s[top];
				top--;
				printf("%d\t",r->value);
			} 
		}
	}*/
	return succeed; 
}

//递归的后序遍历 
Status BST_postorderI(BinarySortTreePtr p)
{
		if(p->root){
		BST_postorderI(&(p->root->left));
		BST_postorderI(&(p->root->right));
		printf("%d\t",p->root->value);
	}
	return succeed;
}

//非递归的后序遍历 
Status BST_postorderR(BinarySortTreePtr p)
{
	//利用栈
	//定义一个栈
	Node* s[10],*r;
	int flags[10];//记录每个节点访问次数的栈 
	int top = -1;//初始化
	Node* temp = p->root; 
	while(temp!=NULL||top!=-1){
        if(temp!=NULL){     //第一次访问，flag置1，入栈
            s[++ top] = temp;
            flags[top] = 1;   
            temp = temp->left;
        }else{//（temp == NULL）
            if(flags[top] == 1){  //第二次访问，flag置2，取栈顶元素但不出栈
                temp = s[top];
                flags[top] = 2;
                temp = temp->right;
            }else{         //第三次访问，出栈
                temp = s[top --];
                printf("%d\t",temp->value);    //出栈时，访问输出
                temp = NULL;      //p置空，以便继续退栈
            }
        }
    }
	return succeed; 
}

//层序遍历 
Status BST_levelOrder(BinarySortTreePtr p)
{
	//利用队列，头出队列，它的孩子进队列 
	LQueue Q;
	InitLQueue(&Q);
	if(p->root){
		EnLQueue(&Q,p->root);//把根节点放入队列 
	}
	while(Q.length){//当队列不为空时
		NodePtr x = DeLQueue(&Q); //对队列的第一个元素操作 
		printf("%d\t",x->value); 
		if(x->left){//如果有左孩子 
			EnLQueue(&Q,x->left);
		}
		if(x->right){//如果有右孩子 
			EnLQueue(&Q,x->right);
		} 
	}
	return succeed; 
}
//初始化队列 
void InitLQueue(LQueue *Q)
{
	//建立头结点 
	Node *n = (Node*)malloc(sizeof(Node));
	//将front和rear都指向头结点 
	Q->front = Q->rear = n;
	Q->length = 0; 
	if(!Q->front || !Q->rear){
		printf("初始化失败\n");
	}
}

//入队操作
Status EnLQueue(LQueue *Q, NodePtr data)
{
	//建立新结点 
	QNode *n = (QNode*)malloc(sizeof(QNode));
	if(!n){
		return failed;
	}
	n->data = data;
	n->next = NULL;
	Q->rear->next = n;//将新结点与原链队列相连 
	Q->rear = n;      //更新尾指针的位置 
	Q->length++;
	return succeed; 
}

//出队操作
NodePtr DeLQueue(LQueue *Q)
{
	//BinarySortTreePtr pt = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	//pt = Q->front->next; 
	if(Q->length == 0){  //当队列为空时 
		return;
	}
	
	QNode *p = (QNode*)malloc(sizeof(QNode));
	p = Q->front->next;//将欲删除的队头结点暂存给p
	Q->front->next = p->next;
	if(Q->rear == p){  //如果队列中有一个有数据的结点，删除后front和rear都指向头结点 
		Q->rear = Q->front; 
	}
	NodePtr x = p->data;
	free(p);
	Q->length--;
	return x;
}	
void menu(){ 
	printf("\n");
	printf("\t******************************************************\n\n");
	printf("\t*            	     树功能菜单                     *\n\n");
	printf("\t*            	                                      *\n\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t******************************************************\n");
	printf("\t*                  1.查找                            *\n");
	printf("\t*                  2.删除                            *\n");
	printf("\t*                  3.插入                            *\n");
	printf("\t*                  4.先序遍历                        *\n");
	printf("\t*                  5.中序遍历                        *\n");
	printf("\t*                  6.后序遍历                        *\n");
	printf("\t*                  7.层序遍历                        *\n");
	printf("\t*                  0.退出系统                        *\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t请输入您所要执行的功能(0-7)：");
}

int judge_int()
{
	int len, num = 0, arg = 1;
    char word[1000];  
    int m, j= 1, k;
    while(j)
    {
        gets(word);
        len = strlen(word);
        for(m = 0;m<len;m++)
        {
            if(word[m]<'0' || word[m]>'9')  
            {
                printf("请输入合乎要求的整数：");
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
void gotoxy(int x,int y)  //光标定位函数:让光标直接跳转到（x,y）位置的函数
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
    COORD pos; 
    pos.X = x;  //横坐标 
    pos.Y = y;  //纵坐标 
    SetConsoleCursorPosition(handle,pos);
}
