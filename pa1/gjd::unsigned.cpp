//
//  main.cpp
//  cstaff
//
//  Created by hkz on 2017/9/17.
//  Copyright © 2017年 黄可钊_2016011332. All rights reserved.
//35

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class bignum
{
    
public:
    unsigned long long a[1115];
    int len;
    bignum()
    {
        memset(a, 0, sizeof(a));
        len = 1;
    }
    void set(string in)
    {
        memset(a,0,sizeof(a));
        const int size = in.size();
        len = 1;
        bool flag = false;
        while(true)
        {
            unsigned long long bei = 1;
            for(int i = 1;i<=9;++i)
            {
                if(size-9*len+9-i<0)
                {
                    flag = true;
                    
                    break;
                }
                a[len] += bei*(unsigned(in[size-9*len+9-i])-48);
                bei*=10;
            }
            if(flag)
                break;
            ++len;
        }
        clear();
        
    }
    void clear()
    {
        len = 1114;
        while(len > 0)
        {
            if(a[len] != 0)
            {
                break;
            }
            --len;
        }
        if(!len) len = 1;
    }
    bignum operator*(const bignum &b)const
    {
        bignum out;
        out.len = len+b.len;
        for(int i=1;i<=b.len;++i)
            for(int j=1;j<=len;++j)
            {
                out.a[i+j-1] += a[j]*b.a[i];
            }
        int u = 1;
        while(u<out.len)
        {
            out.a[u + 1] += out.a[u]/1000000000;
            out.a[u] %= 1000000000;
            ++u;
        }
        out.clear();
        return out;
    }
    friend ostream &operator<<(ostream& out,const bignum& b)
    {
        out<<b.a[b.len];
        for(int i=b.len-1;i>=1;--i)
        {
            //cout<<b.len<<endl;
            unsigned long long temp = b.a[i];
            unsigned long long k = 100000000;
            while(k)
            {
                out<<int(temp/k);
                temp -= (temp/k)*k;
                k/=10;
            }
            
        }
        return out;
    }
    
};
int main()
{
    int n;
    string s1,s2;
    bignum b1;
    bignum b2;
    cin>>n;
    while(n-->0)
    {
        cin>>s1>>s2;
        b1.set(s1);
        
        
        b2.set(s2);
        
        cout<<b1*b2<<endl;
    }
    
    return 0;
}
