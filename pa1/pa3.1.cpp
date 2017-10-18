//
//  main.cpp
//  cstaff
//
//  Created by hkz on 2017/9/17.
//  Copyright © 2017年 黄可钊_2016011332. All rights reserved.
//

#include <iostream>
using namespace std;
const int Size = 2000005;
struct a
{
    int p;
    int num;
}R[Size];
int a[Size];
int ans[Size];
int n;
int init(){
    int x=0,f=1;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    return x*f;
}
int main()
{
    n = init();
    int anspos = 0;
    int right = 2*n;
    int head = -1;
    for(int i=0;i<n;++i)
    {
        a[i] = init();
        if(a[i]==n)
        {
            head = i-1;
            right = i+1;
            ans[0] = n;
            ++anspos;
            a[i] = 0;
        }
    }
    int outmax = a[n-1];
    int outpos = n-1;
    R[n-1].p = n-1;
    R[n-1].num = outmax;
    for(int i=n-2;i>=right;--i)
    {
        if(a[i]>outmax)
        {
            outmax = a[i];
            outpos = i;
        }
        R[i].p = outpos;
        R[i].num = outmax;
    }
    
    while(right<n)
    {
        int max = R[right].num;
        int pos = R[right].p;
        if(head<0) // choose from the right side
        {
            ans[anspos] = max;
            a[pos] = 0;
            ++anspos;
            right = pos+1;
            head = pos - 1;
            while(head>=0&&a[head] == 0)
                --head;
            continue;
        }
        while(head>=0)
        {
             if (max<a[head])
             {
                ans[anspos] = a[head];
                a[head] = 0;
                ++anspos;    
                --head;
                while(head>=0&&a[head] == 0)
                    --head;    
             }
             else
             {
                ans[anspos] = max;
                a[pos] = 0;
                ++anspos;    
                right = pos+1;
                head = pos - 1;
                while(head>=0&&a[head] == 0)
                --head;
                break;
             }
        }
    }
    
    while(head>=0)
    {
        if(a[head])
        {
            ans[anspos] = a[head];
            ++anspos;
        }
        --head;
    }
    
    for(int i=0;i<n;++i)
        printf("%d ",ans[i]);
    
}
