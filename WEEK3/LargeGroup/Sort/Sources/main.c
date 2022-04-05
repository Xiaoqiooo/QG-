#include "sort.h"
int main() {
	double time; 
	int ifsave = 1;  //是否保存数据的标记 
	int n,k,choice,m,i; 
	clock_t start,diff;
	/*FILE *fp=fopen("SortTime.txt","a+"); 
	FILE *fpm=fopen("st.txt","a+"); 
	if(!fp){
		perror("fopen");
		return 0;
	}
	if(!fpm){
		perror("fopen");
		return 0;
	}*/
	do{
		fflush(stdin);
		menu();   //菜单
		choice = judge_int();
		switch(choice){
			case 1:{//排序函数在不同的大数据量下的用时 
				system("cls");
				/*char ch[100] = {};
				fclose(fp);
				FILE *fp=fopen("SortTime.txt","a+"); 
				if(!fp){
					perror("fopen");
					return 0;
				}
				printf("排序算法      用时（ms）\n");
				while(1){
					if(fgets(ch,10,fp) == NULL){
						if(feof(fp)){
							break;
						}
						fputs(ch,stdout);
					}
				}*/
				printf("请选择测试数据量\n");
				printf("10000、50000、200000\n");
				printf("建议先测试别的功能，最后测试200000数量\n"); 
				m = judge_int();
				if(m == 10000){
					//数据量为10000时
					int arr[simple];
					int *a = arr;
					printf("在10000的数据量下\n"); 
					RandomArray(a,simple);
					start = clock();
					insertSort(a,simple);
					diff = clock() - start;
					printf("\t插入排序的用时：%d ms\n",diff);
					
					RandomArray(a,simple);
					start = clock();
					MergeSort(a,0,simple,simple,a);
					diff = clock() - start;
					printf("\t归并排序的用时：%d ms\n",diff);	
					
					RandomArray(a,simple);
					start = clock();
					QuickSort_Recursion(a,0,simple);
					diff = clock() - start;
					printf("\t快速排序的用时：%d ms\n",diff);	 
				
					RandomArray(a,simple);
					start = clock();
					CountSort(a,simple);
					diff = clock() - start;
					printf("\t计数排序的用时：%d ms\n",diff);	 
				
					RandomArray(a,simple);
					start = clock();
					RadixCountSort(a,simple);
					diff = clock() - start;
					printf("\t基数排序的用时：%d ms\n",diff);
					free(a); 
				}else if(m == 50000){
					//数据量为50000时
					int brr[medium];
					int *b = brr;
					printf("\n在50000的数据量下\n"); 
					RandomArray(b,medium);
					start = clock();
					insertSort(b,medium);
					diff = clock() - start;
					printf("\t插入排序的用时：%d ms\n",diff);
					
					RandomArray(b,medium);
					start = clock();
					MergeSort(b,0,medium,medium,b);
					diff = clock() - start;
					printf("\t归并排序的用时：%d ms\n",diff);	
					
					RandomArray(b,medium);
					start = clock();
					QuickSort_Recursion(b,0,medium);
					diff = clock() - start;
					printf("\t快速排序的用时：%d ms\n",diff);	 
				
					RandomArray(b,medium);
					start = clock();
					CountSort(b,medium);
					diff = clock() - start;
					printf("\t计数排序的用时：%d ms\n",diff);	 
				
					RandomArray(b,medium);
					start = clock();
					RadixCountSort(b,medium);
					diff = clock() - start;
					printf("\t基数排序的用时：%d ms\n",diff);
					free(b);
				}else if(m == 200000){
					//数据量为200000时
					int crr[senior];
					int *c = crr;
					printf("\n在200000的数据量下\n"); 
					RandomArray(c,senior);
					start = clock();
					insertSort(c,senior);
					diff = clock() - start;
					printf("\t插入排序的用时：%d ms\n",diff);
					
					RandomArray(c,senior);
					start = clock();
					MergeSort(c,0,senior,senior,c);
					diff = clock() - start;
					printf("\t归并排序的用时：%d ms\n",diff);	
					
					RandomArray(c,senior);
					start = clock();
					QuickSort_Recursion(c,0,senior);
					diff = clock() - start;
					printf("\t快速排序的用时：%d ms\n",diff);	 
				
					RandomArray(c,senior);
					start = clock();
					CountSort(c,senior);
					diff = clock() - start;
					printf("\t计数排序的用时：%d ms\n",diff);	 
				
					RandomArray(c,senior);
					start = clock();
					RadixCountSort(c,senior);
					diff = clock() - start;
					printf("\t基数排序的用时：%d ms\n",diff);
					//printf("\t基数排序的用时：19856 ms\n");
					free(c);
				}else{
					printf("请输入10000或者50000或者200000，注意！其他输入均为无效输入！！");
				}
				system("pause");
				system("cls"); 
				break;
			}
			case 2:{//排序函数在大量小数据量下的排序用时
				system("cls");
				int trr[text];
				int *t = trr;
				printf("在100的数据量,进行100k次的情况下\n"); 
					RandomArray(t,text);
					start = clock();
					for(i=0 ; i<times ; i++){
						insertSort(t,text);	
					}
					diff = clock() - start;
					printf("\t插入排序的用时：%d ms\n",diff);
					
					RandomArray(t,text);
					start = clock();
					for(i=0 ; i<times ; i++){
						MergeSort(t,0,text,text,t);	
					}
					diff = clock() - start;
					printf("\t归并排序的用时：%d ms\n",diff);	
					
					RandomArray(t,text);
					start = clock();
					for(i=0 ; i<times ; i++){
						QuickSort_Recursion(t,0,text);
					}
					diff = clock() - start;
					printf("\t快速排序的用时：%d ms\n",diff);	 
				
					RandomArray(t,text);
					start = clock();
					for(i=0 ; i<times ; i++){
						CountSort(t,text);
					}
					diff = clock() - start;
					printf("\t计数排序的用时：%d ms\n",diff);	 
				
					RandomArray(t,text);
					start = clock();
					for(i=0 ; i<times ; i++){
						RadixCountSort(t,text);
					}
					printf("\t基数排序的用时：%d ms\n",diff);
					free(t); 
				/*char ch[100] = {};
				fclose(fpm);
				FILE *fpm=fopen("st.txt","a+"); 
				if(!fpm){
					perror("fopen");
					return 0;
				}
				printf("排序算法      用时（ms）\n");
				while(1){
					if(fgets(ch,10,fpm) == NULL){
						if(feof(fpm)){
							break;
						}
						fputs(ch,stdout);
					}
				}*/
				system("pause");
				system("cls"); 
				break;
			}
			case 3:{//排序应用题
				system("cls");
				printf("1.测试颜色排序（数组大小为10）\n"); 
			    int array[20];
			    int *d = array;
			    RandomArrays(d,10);
			    printf("排序前：\n");
			    show(d,10);
			    printf("\n排序后：\n");
			    ColorSort(d,10);
			    show(d,10);
			    printf("\n\n\n\n\n\n\n");
			    printf("2.分治法排序-查找数组第k小的数字（数组大小为100）\n"); 
			    printf("请问你要查询数组第k小的元素\n");
				k = judge_int();
				RandomArray(d,100);
				printf("无序数组：\n");
				show(d,100);
				printf("\n第%d小的数字是%d\n",k,FoundGoal(d,0,99,k-1));
				free(d);
				system("pause");
				system("cls"); 
				break;
			}
			case 0:{//退出系统 
				system("cls");
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
