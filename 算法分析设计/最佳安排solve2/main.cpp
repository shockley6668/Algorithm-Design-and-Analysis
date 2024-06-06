//
//  main.cpp
//  最佳安排solve2
//
//  Created by Shockley on 6/4/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

const int maxn = 20;
const int INF = 1e9;
int tm[maxn][maxn], n;
int dp[1<<maxn];

int main() {
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                scanf("%d", &tm[i][j]);
        memset(dp, 63, sizeof(dp));
        dp[0] = 0;
        for(int mask = 0; mask < (1<<n); mask++) {
            int cnt = __builtin_popcount(mask);
            for(int i = 0; i < n; i++) {
                if(!(mask & (1<<i))) {
                    dp[mask|(1<<i)] = std::min(dp[mask|(1<<i)], dp[mask] + tm[cnt][i]);
                }
            }
        }
        printf("%d\n", dp[(1<<n)-1]);
    }
    return 0;
}
