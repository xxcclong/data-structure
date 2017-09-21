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
class bignum
{
    
public:
    int a[10005];
    int len;
    bignum()
    {
        memset(a, 0, sizeof(a));
        len = 1;
    }
    bignum(string in)
    {
        memset(a, 0, sizeof(a));
        len = 1;
        int size = in.size();
        for(len = 1;len <= size;++len)
        {
            a[len] = int(in[size-len])-48;
        }
        len = in.size();
        clear();
    }
    void set(string in)
    {
        memset(a,0,sizeof(a));
        len = 1;
        int size = in.size();
        for(len = 1;len<=size;++len)
        {
            a[len] = int(in[size-len])-48;
        }
        len = size;
        clear();
    }
    void clear()
    {
        len = 10004;
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
        while(u<out.len-1)
        {
            out.a[u + 1] += out.a[u]/10;
            out.a[u] %= 10;
            ++u;
        }
        out.clear();
        return out;
    }
    friend ostream &operator<<(ostream& out,const bignum& b)
    {
        for(int i=b.len;i>=1;--i)
        {
            out<<b.a[i];
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
