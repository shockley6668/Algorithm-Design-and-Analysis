//
//  main.cpp
//  台阶问题
//
//  Created by Shockley on 4/10/24.
//
//对于第 n 级台阶，可以由 n-k 到 n-1 这些台阶的情况得到。因此，ans[n] = ans[n-1] + ans[n-2] + ... + ans[n-k]
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int mod = 100003;
int n, k;
int ans[1111111];
int main()
{
    while(scanf("%d%d", &n, &k) != EOF)
    {
        ans[0] = 1;
        // TODO: 递推得到 ans[n]
        for(int i=1;i<=n;i++)
        {
            ans[i]=0;
            for(int j=1;j<=k&& j<=i;j++)
            {
                ans[i]=(ans[i]+ans[i-j])%mod;
            }
        }
        printf("%d\n", ans[n]);
    }
    return 0;
}
