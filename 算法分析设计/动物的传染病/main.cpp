//
//  main.cpp
//  动物的传染病
//
//  Created by Shockley on 4/10/24.
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
long long Solve(long long x, long long n)
{
    long long ans=1;
    for(int i=0;i<n;i++)
    {
        ans=ans*x+ans;
    }
    return ans;
    // TODO: 递推第 n 轮的结果
}
int main()
{
    long long x, n;
    while(scanf("%lld%lld", &x, &n) != EOF)
    {
        printf("%lld\n", Solve(x, n));
    }
    return 0;
}
