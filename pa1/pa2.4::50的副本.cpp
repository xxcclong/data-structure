//
//  main.cpp
//  cstaff
//
//  Created by hkz on 2017/9/17.
//  Copyright © 2017年 黄可钊_2016011332. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;
long long x[200005];
long long y[200005];
int init()
{
    int x=0,f=1;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    return x*f;
}
void quicksort(long long *a,int num) // num stands for the element number in the array
{
    
    if(num == 1||num == 0 || num<0)
        return;
    int L = 0;
    int R = num-1;
    long long temp = a[0];
    while(L<R)
    {
        while(L<R&&a[R]>=temp)
        {
            --R;
        }
        a[L] = a[R];
        while(L<R&&a[L]<=temp)
        {
            ++L;
        }
        a[R] = a[L];
    }
    a[R] = temp;
    quicksort(a,R);
    quicksort(a+R+1,num-R-1);
    
}



int main()
{
    /*int a[7] = {4,242,3,14,5,25,2};
     quicksort(a, 7);
     for(int i=0;i<=6;++i)
     cout<<a[i]<<' ';*/
    int n;
    n = init();
    for(int i=0;i<n;++i)
    {
        x[i] = init();
    }
    for(int i=0;i<n;++i)
    {
        y[i] = init();
    }
    int m;
    quicksort(x, n);
    quicksort(y, n);
    
    m = init();
    long long qx,qy;
    while(m--)
    {
        qx = init();
        qy = init();
        int head = 0,tail = n-1;
        long long hgongbei = x[head]*y[head];
        if(y[head]*qx+x[head]*qy<hgongbei)
        {
            printf("0\n");
            continue;
        }
        if(y[head]*qx+x[head]*qy == hgongbei)
        {
            printf("1\n");
            continue;
        }
        hgongbei = x[tail]*y[tail];
        if(y[tail]*qx+x[tail]*qy>=hgongbei)
        {
            printf("%d\n",n);
            continue;
        }
        bool flag = false;
        while(tail-head>1)
        {
            int mid = (head+tail)/2;
            long long gongbei = x[mid]*y[mid];
            long long cmp = y[mid]*qx+x[mid]*qy;
            if(cmp>gongbei)
            {
                head = mid;
            }
            else if(cmp==gongbei)
            {
                printf("%d\n",mid+1);
                flag = true;
                break;
            }
            else
            {
                tail = mid;
            }
            
        }
        if(!flag)
        {
            printf("%d\n",head+1);
        }
        
        
    }
}
