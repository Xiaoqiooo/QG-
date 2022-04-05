#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define simple 10000
#define medium 50000 
#define senior 200000 
#define text 100
#define times 100000 

/**

 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
    */
    void insertSort(int *a,int n);


/**

 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
    */
    void MergeArray(int *a,int begin,int mid,int end,int *temp);


/**

 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
    */
    void MergeSort(int *a,int begin,int end,int size,int *temp);


/**

 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
    */
    void QuickSort_Recursion(int *a, int begin, int end);


/**

 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
    */
    void QuickSort(int *a,int size);


/**

 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
    */
    int Partition(int *a, int begin, int end);


/**

 *  @name        : void CountSort(int *a, int size)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size
    */
    void CountSort(int *a, int size);


/**

 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
    */
    void RadixCountSort(int *a,int size);


/**

 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
    */
    void ColorSort(int *a,int size);


/**

 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K小的数
 *  @param       : 数组指针a，数组长度size
    */
    int FoundGoal(int *a,int begin,int end,int k);
    
/**

 *  @name        : int *a RandomArray(int *a,int size) 
 *  @description : 生成随机数的函数 
 *  @param       : 数组指针a，数组长度size
 *  @return      : 数组指针a 
    */
    int* RandomArray(int *a,int size);

int GetDigit(int m, int i); //取整数m的第i位数
int GetMaxDigit(int* a,int size);
int GetNumOfData(int data,int width);
int* RandomArrays(int *a,int size);
void show(int *a,int n);
int judge_int();
void menu();
void HideCursor();
void gotoxy(int x,int y);
void playtime(); 


#endif // QUEUE_H_INCLUDED
