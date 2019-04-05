//
// Created by wangyu on 4/5/19.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <assert.h>
using namespace std;

void prt(int arr[],int n)
{
    for(int i=0;i<n;i++)
        printf("<%d>",arr[i]);
    printf("\n");
}

void compare_swap(int &a,int &b,bool inv)
{
    bool smaller=(a>b);
    if(smaller^inv)
    {
        int tmp=a;a=b;b=tmp;
    }
}
void merge(int arr[],int begin,int end,bool inv)
{
    int len=end-begin+1;
    if(len==1) return;
    for(int i=begin,j=begin+len/2;i<begin+len/2;i++,j++)
    {
        compare_swap(arr[i],arr[j],inv);
    }
    merge(arr,begin,begin+len/2-1,inv);
    merge(arr,begin+len/2,end,inv);
}
void bsort(int arr[],int begin,int end,bool inv=0)
{
    int len=end-begin+1;
    if(len==1) return;
    bsort(arr,begin,begin+len/2-1,0);
    bsort(arr,begin+len/2,end,1);
    //prt(arr+begin,len);
    merge(arr,begin,end,inv);
    //prt(arr+begin,len);
}
int cnt=0;
int main()
{
    {
        int arr[8]= {5,2,1,7,3,8,6,4};

        printf("===case %d====\n",cnt++);
        int len=sizeof(arr) / sizeof(arr[0]);
        int arr2[len];
        memcpy(arr2,arr,sizeof(arr));
        prt(arr, len);
        bsort(arr, 0, len-1);
        prt(arr, len);
        sort(arr2,arr2+len);
        prt(arr2,len);
    }

    {
        int arr[16] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 2, 3, 4, 5, 6};

        printf("===case %d====\n",cnt++);
        int len=sizeof(arr) / sizeof(arr[0]);
        int arr2[len];
        memcpy(arr2,arr,sizeof(arr));
        prt(arr, len);
        bsort(arr, 0, len-1);
        prt(arr, len);
        sort(arr2,arr2+len);
        prt(arr2,len);
    }

    {
        int arr[32] = {1, 3, 35, 7, 9, 42, 14, 36, 8, 20, 21, 82, 3, 46, 75, 86,
                        5,48,27,36,75,14,23,92,1,0,11,52,43,84,4,26};

        printf("===case %d====\n",cnt++);
        int len=sizeof(arr) / sizeof(arr[0]);
        int arr2[len];
        memcpy(arr2,arr,sizeof(arr));
        prt(arr, len);
        bsort(arr, 0, len-1);
        prt(arr, len);
        sort(arr2,arr2+len);
        prt(arr2,len);
    }
    return 0;
}

