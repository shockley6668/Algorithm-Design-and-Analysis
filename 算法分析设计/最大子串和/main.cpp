//
//  main.cpp
//  最大子串和
//
//  Created by Shockley on 4/29/24.
//

#include <iostream>
#include "algorithm"
#include "cmath"
#include<cstdio>
using namespace std;
const int maxn = 1e5 + 10;
int n,arr[maxn],dp[maxn];
int solve()
{
    int ans=-0x3f3f3f3f;
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=max(dp[i-1]+arr[i],arr[i]);
        ans=max(dp[i],ans);
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    while(scanf("%d", &n) != EOF) {
        for(int i = 1; i <= n; i ++)
            scanf("%d", &arr[i]);
        printf("%d\n", solve());
    }
    return 0;
}
