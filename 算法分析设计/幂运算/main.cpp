//
//  main.cpp
//  幂运算
//
//  Created by Shockley on 4/10/24.
//
//给你三个整数a,b,p，求ab mod p的值
//具体思想。分解成a^2k
#include <iostream>
using namespace std;
long long fast_pow(long long base,long long exp,long long mod)
{
    base%=mod;
    long long result=1;
    while (exp>0) {
        if(exp&1)
        {
            result=result*base%mod;
        }
        exp>>=1;
        base=base*base%mod;
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    while (t--) {
        int a,b,p;
        cin>>a>>b>>p;
        long long res=fast_pow(a, b, p);
        cout<<res<<endl;
    }
    return 0;
}
