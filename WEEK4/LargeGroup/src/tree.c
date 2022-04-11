#include "tree.h"
//��ʼ���� 
Status BST_init(BinarySortTreePtr p) 
{
	Node* t = (Node*)malloc(sizeof(Node));//����ͷ���
	t = NULL; 
	p->root = t;
	return succeed;
}

//����������
void BST_create(BinarySortTreePtr p)
{
	int a,i,x;
	printf("����������м������ݣ�\n");
	scanf("%d",&a);
	for(i=0 ; i<a ; i++){
		srand((unsigned)time(0)); //���������
		x = rand()%50;         //0��100��Χ�ڵ������
		BST_insert(p,x);
	}
}  

//����
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
		//e������
		temp = &(p->root->left);
		return BST_insert(temp,e);
	}else{
		//e���Һ��� 
		temp = &(p->root->right);
		return BST_insert(temp,e);
	} 
 } 
 
//ɾ��
Status BST_delete(BinarySortTreePtr p, ElemType e)
{
	//�ҵ�Ҫɾ������λ��
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
	//Ŀ����û�ж��ӵ�ʱ��ֱ��ɾ��
	if(p->right==NULL && p->left==NULL){
		free(p);
	} 
	//Ŀ����������ӻ����Ҷ��ӵ�ʱ�򣬶��Ӷ���
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
	//Ŀ�������������ӵ�ʱ������ߵ���������ǰ����㣩���н��������ɾ��ǰ����� 
	if(p->left!=NULL && p->right!=NULL){
		temp = p;
		l = p->left;
		while(l->right){//�ҵ���ߵ����Ľ�� 
			temp = l;
			l = l->right;
		}
		//�˳�ѭ���� l��ǰ����㣬l��temp���ҽڵ�
		//���н��� 
		p->value = l->value;
		if(temp == p){//Ŀ��������Ǹ��ڵ������� 
			temp->left = l->left; 
		}else{
			temp->right = l->left; 
		}
		free(l);
	}
	return succeed;
}

 
//����
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
 
//�ݹ��ǰ�����
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

//�ǵݹ��ǰ�����
Status BST_preorderR(BinarySortTreePtr p)
{
	//����ջ
	//����һ��ջ
	Node* s[10],*r;
	int top = -1;//��ʼ��
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
/*	if(p->root){//�ж϶������Ƿ�Ϊ�գ���Ϊ�գ��򽫸��ڵ���ջ��
		top++;
		s[top] = p->root;
		while(top > -1){//��ջ�����ʸýڵ�
			r = s[top];
			top--;
			printf("%d\t",r->value);
			if(p->root->right){//������Һ������Һ����Ƚ�ջ 
				top++;
				s[top] = p->root->right;
			}
			if(p->root->left){//����������������Ƚ�ջ 
				top++;
				s[top] = p->root->left;
			}
		}
	}*/
	return succeed; 
}

//�ݹ��������� 
Status BST_inorderI(BinarySortTreePtr p)
{
	if(p->root){
		BST_inorderI(&(p->root->left));
		printf("%d\t",p->root->value);
		BST_inorderI(&(p->root->right));
	}
	return succeed;
}

//�ǵݹ��������� 
Status BST_inorderR(BinarySortTreePtr p)
{
	//����ջ
	//����һ��ջ
	Node* s[10],*r;
	int top = -1;//��ʼ��
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
	/*if(p->root){//�ж϶������Ƿ�Ϊ�գ���Ϊ�գ��򽫸��ڵ���ջ��
		top++;
		s[top] = p->root;
		while(p->root->left){//һ���ҵ�����ߵ��Ǹ���� 
			r = s[top];
			top++;
			s[top] = r->left;
		} 
		while(top > -1){//��ջ�����ʸýڵ�
			r = s[top];
			top--;
			printf("%d\t",r->value);
			r = s[top];
			if(r->right){//����ұ��� 
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

//�ݹ�ĺ������ 
Status BST_postorderI(BinarySortTreePtr p)
{
		if(p->root){
		BST_postorderI(&(p->root->left));
		BST_postorderI(&(p->root->right));
		printf("%d\t",p->root->value);
	}
	return succeed;
}

//�ǵݹ�ĺ������ 
Status BST_postorderR(BinarySortTreePtr p)
{
	//����ջ
	//����һ��ջ
	Node* s[10],*r;
	int flags[10];//��¼ÿ���ڵ���ʴ�����ջ 
	int top = -1;//��ʼ��
	Node* temp = p->root; 
	while(temp!=NULL||top!=-1){
        if(temp!=NULL){     //��һ�η��ʣ�flag��1����ջ
            s[++ top] = temp;
            flags[top] = 1;   
            temp = temp->left;
        }else{//��temp == NULL��
            if(flags[top] == 1){  //�ڶ��η��ʣ�flag��2��ȡջ��Ԫ�ص�����ջ
                temp = s[top];
                flags[top] = 2;
                temp = temp->right;
            }else{         //�����η��ʣ���ջ
                temp = s[top --];
                printf("%d\t",temp->value);    //��ջʱ���������
                temp = NULL;      //p�ÿգ��Ա������ջ
            }
        }
    }
	return succeed; 
}

//������� 
Status BST_levelOrder(BinarySortTreePtr p)
{
	//���ö��У�ͷ�����У����ĺ��ӽ����� 
	LQueue Q;
	InitLQueue(&Q);
	if(p->root){
		EnLQueue(&Q,p->root);//�Ѹ��ڵ������� 
	}
	while(Q.length){//�����в�Ϊ��ʱ
		NodePtr x = DeLQueue(&Q); //�Զ��еĵ�һ��Ԫ�ز��� 
		printf("%d\t",x->value); 
		if(x->left){//��������� 
			EnLQueue(&Q,x->left);
		}
		if(x->right){//������Һ��� 
			EnLQueue(&Q,x->right);
		} 
	}
	return succeed; 
}
//��ʼ������ 
void InitLQueue(LQueue *Q)
{
	//����ͷ��� 
	Node *n = (Node*)malloc(sizeof(Node));
	//��front��rear��ָ��ͷ��� 
	Q->front = Q->rear = n;
	Q->length = 0; 
	if(!Q->front || !Q->rear){
		printf("��ʼ��ʧ��\n");
	}
}

//��Ӳ���
Status EnLQueue(LQueue *Q, NodePtr data)
{
	//�����½�� 
	QNode *n = (QNode*)malloc(sizeof(QNode));
	if(!n){
		return failed;
	}
	n->data = data;
	n->next = NULL;
	Q->rear->next = n;//���½����ԭ���������� 
	Q->rear = n;      //����βָ���λ�� 
	Q->length++;
	return succeed; 
}

//���Ӳ���
NodePtr DeLQueue(LQueue *Q)
{
	//BinarySortTreePtr pt = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	//pt = Q->front->next; 
	if(Q->length == 0){  //������Ϊ��ʱ 
		return;
	}
	
	QNode *p = (QNode*)malloc(sizeof(QNode));
	p = Q->front->next;//����ɾ���Ķ�ͷ����ݴ��p
	Q->front->next = p->next;
	if(Q->rear == p){  //�����������һ�������ݵĽ�㣬ɾ����front��rear��ָ��ͷ��� 
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
	printf("\t*            	     �����ܲ˵�                     *\n\n");
	printf("\t*            	                                      *\n\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t******************************************************\n");
	printf("\t*                  1.����                            *\n");
	printf("\t*                  2.ɾ��                            *\n");
	printf("\t*                  3.����                            *\n");
	printf("\t*                  4.�������                        *\n");
	printf("\t*                  5.�������                        *\n");
	printf("\t*                  6.�������                        *\n");
	printf("\t*                  7.�������                        *\n");
	printf("\t*                  0.�˳�ϵͳ                        *\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t����������Ҫִ�еĹ���(0-7)��");
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
                printf("������Ϻ�Ҫ���������");
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
void gotoxy(int x,int y)  //��궨λ����:�ù��ֱ����ת����x,y��λ�õĺ���
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������
    COORD pos; 
    pos.X = x;  //������ 
    pos.Y = y;  //������ 
    SetConsoleCursorPosition(handle,pos);
}
