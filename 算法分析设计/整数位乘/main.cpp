//
//  main.cpp
//  整数位乘
//
//  Created by Shockley on 4/17/24.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
typedef vector<int> bigBinary;
void check(bigBinary & x)
{
    while(!x.empty() && x.back()==0)
        x.pop_back();
    int cur=0;  //目前的进位
    for(int i=0;i<x.size();i++)
    {
        x[i]+=cur;
        cur=x[i]>>1;
        x[i]&=1;
    }
    for(;cur;cur>>=1)
        x.push_back(cur &1);
}
void Print(bigBinary &x) {
    // 打印大整数
    check(x);
    for(int i = x.size() - 1; i >= 0; i --) printf("%d", x[i]);
    if(x.empty()) printf("0");  // 如果x数组为空，则上一行没有输出，得输出个 0
    printf("\n");
}


bigBinary add(const bigBinary &a ,const bigBinary &b,int negf=1)
{
    bigBinary ans(a);
    for(size_t i=0;i<b.size();i++)
    {
        ans[i]+=b[i]*negf;
    }
    return ans;
}
bigBinary Minus(const bigBinary &a,const bigBinary& b)
{
    return add(a,b,-1);
}
bigBinary mul(const bigBinary &a, const bigBinary &b)
{
    bigBinary ans;
    ans.resize(a.size()*b.size()+1);
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b.size();j++)
        {
            ans[i+j]+=a[i]*b[j];
        }
    }
    return ans;
}
 void mulN2(bigBinary &a,int n2)
{
     size_t isize=a.size();
     a.resize(isize+n2);
     for(int i = a.size() - 1, j = isize - 1; j >= 0; i --, j--)
     {
         a[i]=a[j];
     }
     for(int i=n2-1;i>=0;i--)
     {
         a[i]=0;
     }
 }

bigBinary fasterMul(const bigBinary &a,const bigBinary &b)
{
    if(a.size()<32) return mul(a,b);
    int n2=a.size()>>1;
    bigBinary aH(a.begin()+n2,a.end());
    bigBinary aL(a.begin(),a.begin()+n2);
    bigBinary bH(b.begin()+n2,b.end());
    bigBinary bL(b.begin(),b.begin()+n2);
    bigBinary aH_bH=fasterMul(aH,bH);
    bigBinary aL_bL= fasterMul(aL,bL);
    bigBinary AH_bLPaL_bL = Minus(Minus(fasterMul(add(aH,aL),add(bH,bL)),aH_bH),aL_bL);
    mulN2(aH_bH, n2<<1);
    mulN2(AH_bLPaL_bL,n2);
    return add(add(aH_bH, AH_bLPaL_bL), aL_bL);
}
const int maxn=1e5+10;
char buf[maxn];
bigBinary a,b;
int main()
{
    while (scanf("%s",buf)!=EOF) {
        a.clear();
        b.clear();
        for(int i=strlen(buf)-1;i>=0;i--)
        {
            a.push_back(buf[i]=='1');
        }
        scanf("%s", buf);
        for(int i = strlen(buf) - 1; i >= 0; i --)
        {
            b.push_back(buf[i] == '1');
        }
        if(a.size()<b.size())
        {
            a.resize(b.size(),0);
        }
        else{
            b.resize(a.size(),0);
        }
        bigBinary res = fasterMul(a, b);
        Print(res);
    }
}
