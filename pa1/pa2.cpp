//
//  main.cpp
//  cstaff
//
//  Created by hkz on 2017/9/17.
//  Copyright © 2017年 黄可钊_2016011332. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int x[200005];
int y[200005];
int min_bei(int a,int b)
{
    int max,min;
    if(a>b)
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }
    while(min!=0)
    {
        int temp = min;
        min = max%min;
        max = temp;
        
    }
    return a*b/max;
}
void quicksort(int *a,int num) // num stands for the element number in the array
{
    
    if(num == 1||num == 0 || num<0)
        return;
    int L = 0;
    int R = num-1;
    int temp = a[0];
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
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>x[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>y[i];
    }
    int m;
    quicksort(x, n);
    quicksort(y, n);
    cin>>m;
    int qx,qy;
    while(m--)
    {
        cin>>qx>>qy;
        int head = 0,tail = n-1;
        int ans = 0;
        int hgongbei = min_bei(x[head], y[head]);
        if(hgongbei/x[head]*qx+hgongbei/y[head]*qy<hgongbei)
        {
            cout<<0<<endl;
            continue;
        }
        hgongbei = min_bei(x[tail],y[tail]);
        if(hgongbei/x[tail]*qx+hgongbei/y[tail]*qy>=hgongbei)
        {
            cout<<n<<endl;
            continue;
        }
        bool flag = false;
        while(tail-head>1)
        {
            int mid = (head+tail)/2;
            int gongbei = min_bei(x[mid], y[mid]);
            if(gongbei/x[mid]*qx+gongbei/y[mid]*qy>gongbei)
            {
                head = mid;
            }
            else if(gongbei/x[mid]*qx+gongbei/y[mid]*qy==gongbei)
            {
                cout<<mid<<endl;
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
            cout<<head<<endl;
        }
        
        
    }
}
