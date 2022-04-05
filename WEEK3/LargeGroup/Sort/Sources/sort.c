#include "sort.h"

void insertSort(int *a,int n)//插入排序(从大到小)
{
	int i,j,temp; 
	//默认第一个元素为已排序区间的元素，故从第二个元素开始进行插入的相关操作 
	for(i=1 ; i<n ; i++){
		temp = *(a+i);
		for(j=i-1 ; j>=0 ; j--){//从目标元素的前一个元素开始比较判断，是否要进行插入操作 
			while(*(a+j) < temp && j>=0){//目标元素小于前面的元素时，进行插入 
				*(a+j+1) = *(a+j);
				j--;
			} 
			*(a+j+1) = temp;
		} 
	}
}

void MergeArray(int *a,int begin,int mid,int end,int *temp)//归并排序（合并数组）
{
	int i,j,k;
	i = begin;
	j = mid+1;
	k = begin;
	while((i<=mid) && (j<=end)){//进行前后两个部分按大小排序合并的操作 
		if(*(a+i) <= *(a+j)){
			*(temp+k) = *(a+i);
			i++;
			k++;
		}else{
			*(temp+k) = *(a+j);
			j++;
			k++;
		}
	}
	//此时前后两部分至少有一个部分的元素已经在temp中排序好，则将另外一部分剩余的元素放在temp后 
	while(i <= mid){
		*(temp+k) = *(a+i);
		k++;
		i++;
	}
	while(j <= end){
		*(temp+k) = *(a+j);
		k++;
		j++;
	}
}

void MergeSort(int *a,int begin,int end,int size,int *temp)//归并排序
{
	int mid = (begin+end)/2;
	if(begin == end){
		*(temp+begin) = *(a+begin); 
	}else{
		int *t = (int*)malloc(sizeof(int)*size);
		if(t!=NULL){
			MergeSort(a,begin,mid,size,t);
		 	MergeSort(a,mid+1,end,size,t);
			MergeArray(t,begin,mid,end,temp);	
		}
	}
}

void QuickSort_Recursion(int *a, int begin, int end)//快速排序（递归版）
{
	if(begin>end){
		return;
	} 
	int i,j,base,temp;
	i = begin;
	j = end;
	base = *(a+begin);//基准数 
	while(i != j){//当哨兵j和i还未相遇的时候 
		while(*(a+j) <= base && j > i){//找到哨兵j比基准数小的位置 
			j--;
		}
		while(*(a+i) >= base && j > i){//找到哨兵i比基准数大的位置 
			i++;			
		} 
		if(j > i){//哨兵j和i都找好位置后 
			temp = *(a+i);
			*(a+i) = *(a+j);
			*(a+j) = temp;
		} 
	}
	//当哨兵i和j相遇时，将它们两坐在的位置和基准数交换，并作为新的基准数 
	*(a+begin) = *(a+i);
	*(a+i) = base;
	//以上就是一轮探测，它将整个数据分为两部分，对这两部分分别再做上述操作
	QuickSort_Recursion(a,begin,i-1);
	QuickSort_Recursion(a,i+1,end);
}

void QuickSort(int *a,int size)//快速排序（非递归版）no
{
	
}

int Partition(int *a, int begin, int end)//快速排序（枢轴存放）no
{
	
}

void CountSort(int *a, int size)//计数排序
{
	int max,min,i,j,sum=0;
	max = *a;
	min = *a;
	for(i=0 ; i<size ; i++){//找到最大数值 
		if(*(a+i)>max){
			max = *(a+i);
		}
	}
	for(i=0 ; i<size ; i++){//找到最小数值 
		if(*(a+i)<min){
			min = *(a+i);
		}
	}
	int num = max-min;//最多出现num种数值 
	//创建数组，用来统计对应元素的个数 
	int count[num+1];
	for(i=0 ; i<num+1 ; i++){
		count[i] = 0;
	}
	for(i=0 ; i<size ; i++){
		count[*(a+i)-min]++;
	}
	//将该数组的值进行加工，后面的元素等于前面元素之和(对应到正确的索引处)
	for(i=0 ; i<num+1 ; i++){
		sum += count[i];
		count[i] = sum;
	}
	//倒序遍历数组，在count数组中找到正确位置，并保存在temp数组 
	int temp[size];
	for(i=size-1 ; i>=0 ; i--){
		temp[count[*(a+i)-min]-1] = *(a+i);
		count[*(a+i)-min]--;
	} 
	//将temp数组的结果，移到a数组
	for(i=0,j=size-1 ; i<size ; i++,j--){
		*(a+i) = temp[j];
	} 
}
/*
int GetDigit(int m, int i) //取整数m的第i位数
{
	while(i > 1){
		m /= 10;
		i--;
	}
	return m % 10;
}

void RadixCountSort(int *a, int size)//基数排序 
{
	int i, j, k, l, digit,num=0,max=0;
	int temp[10][size];	//temp数组，存储临时结果 

	memset(temp, 0, sizeof(temp));//初始化temp数组

	for(i=0 ; i<size ; i++){//找到最大数值 
		if(*(a+i)>max){
			max = *(a+i);
		}
	}
	//算最大有几位数，就知道要进行几次循环
	while(max){
		num++;
		max/=10;
	}

	for(i = 1; i <= num; i++)
	{
		//分配相应位数的数据，并存入temp数组
		for(j = 0; j < size; j++){			
			digit = GetDigit(*(a+j), i);
			k = 0;
			while(temp[digit][k])
				k++;
			temp[digit][k] = *(a+j);
		}
		//将temp数组的数据依次收集到原数组中
		if(i!=num){
			l = 0; 
			for(j = 0; j < 10; j++)	{	
				k = 0;
				while(temp[j][k] > 0){
					*(a+l) = temp[j][k];
					l++;
					k++;
				}
			}	
		}else{
			l = size-1; 
			for(j = 0; j < 10; j++)	{	
				k = 0;
				while(temp[j][k] > 0){
					*(a+l) = temp[j][k];
					l--;
					k++;
				}
			}	
		}
		
		//每次分配，收集后初始化temp数组，用于下一位数的分配和收集
		memset(temp, 0, sizeof(temp));
	}
}
*/
typedef struct Que  //队列
{
 	int*  data;
 	int head;
 	int tail;
}Que;

int GetMaxDigit(int* a,int size)//得到数据的最大数字的位数 
{
	int i;
 	int max = a[0];
	for(i=0 ; i<size ; ++i){
  		if(max<a[i]){
   			max=a[i];
  		}
 	}
	int num = 0;
 	while(max>0){
  		num++;
  		max/=10;
 	}
 	return num;
}

int GetNumOfData(int data,int width)//得到数据的位数 
{
 	int num = data%10;//对10取余  
 	while(width){ //初始width==0,表示取个位的值，不进循环，直接返回num
  		data /= 10;
  		width--;
  		num = data%10;
 	}
 	return num;
}

void RadixCountSort(int*  a,int size)
{
	int i,j,num;
 	//获取最大数字的位数
 	int max = GetMaxDigit(a,size);
 	Que que[10];
 	for(i=0;i<10;++i)  //初始化十个队列
 	{
  		que[i].data =(int*)malloc(sizeof(int)*size);
  		que[i].head =que[i].tail =0;
 	}
 	//i=0;个位  i=1;十位  i=2;百位   i=3;千位
 	for(i=0 ; i<max ; ++i){
  		for(j=0 ; j<size ; ++j){//进队列 
   			num = GetNumOfData(a[j],i);
   			que[num].data [que[num].tail++]=a[j];
  		}
  		int count=0;
  		for(i=0 ; i<10 ; ++i){//数据出队列进入a中
   			while(que[i].head!=que[i].tail){//有数据
    				a[count++]=que[i].data[que[i].head++];
   			}
   		que[i].head =que[i].tail=0;//队列初始化，为下一次放数据做准备
  		}
 	}
 	for(i=0;i<10;++i){
  		free(que[i].data);
	 }
}

void ColorSort(int *a,int size)//颜色排序
{
	int p0=0,p1,p2=size-1;
	int i,temp;
	for(p1=1 ; p1!=p2 ;){
		if(*(a+p1) == 0){
			temp = *(a+p1);
			*(a+p1) = *(a+p0);
			*(a+p0) = temp;
			p0++;
		}else if(*(a+p1) == 2){
			temp = *(a+p1);
			*(a+p1) = *(a+p2);
			*(a+p2) = temp;
			p2--;
		}else{
			p1++;
		}
	}
}

int FoundGoal(int *a,int begin,int end,int k)//在一个无序序列中找到第K小的数
{
	int i,j,m,mid,temp;
	i = begin;
	j = end;
	m = (i+j)/2;
	mid = *(a+m);
	do{
		while(*(a+j) > mid){
			j--;
		}
		while(*(a+i) < mid){
			i++;
		}
		if(i <= j){
			temp = *(a+i);
			*(a+i) = *(a+j);
			*(a+j) = temp;
			i++;
			j--;
		}
	}while(i <= j);
	//进行了一次快排 
	if(k <= j){//搜寻左区间 
		return FoundGoal(a,begin,j,k);
	}else if(i <= k){//搜寻右区间 
		return FoundGoal(a,i,end,k);
	}else{
		j++;
		return *(a+j);
	}
}

int* RandomArray(int *a,int size) //生成随机数的函数 
{
	int count;
	for(count = 0 ; count < size ; count++){
		srand((unsigned)(time(0)+count));
		*a = rand()%1000000+1;
		a++;
	}
	return a;
}

int* RandomArrays(int *a,int size) //生成随机数的函数 
{
	int count;
	for(count = 0 ; count < size ; count++){
		srand((unsigned)(time(0)+count));
		*a = rand()%3;
		a++;
	}
}

void show(int *a,int n){//打印函数 
	int i = 0;
	for(i=0 ; i<n ; i++){
		printf("%d\t",*(a+i));
	} 
	printf("\n");
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

//菜单 
void menu(){
	printf("\n");
	printf("\t******************************************************\n\n");
	printf("\t*            	     排序功能菜单                     *\n\n");
	printf("\t*            	                                      *\n\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t******************************************************\n");
	printf("\t*          1.排序函数在不同的大数据量下的用时        *\n");
	printf("\t*          2.排序函数在大量小数据量下的排序用时      *\n");
	printf("\t*          3.排序应用题                              *\n");
	printf("\t*          0.退出系统                                *\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t请输入您所要执行的功能(0-3)：");
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

