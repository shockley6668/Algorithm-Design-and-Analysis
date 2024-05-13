//
//  main.cpp
//  模9
//
//  Created by Shockley on 5/8/24.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 1000000007;
int dp[101][2][11];
int digit[101];
int sum[101];
int a[101], b[101];

int dfs(int pos, int limit, int mod, int d) {
    if (pos == 0) return mod == 0 && d == 0;
    if (!limit && dp[pos][mod][d] != -1) return dp[pos][mod][d];
    int up = limit ? digit[pos] : 9;
    int ans = 0;
    for (int i = 0; i <= up; ++i) {
        if (d - i >= 0) {
            ans += dfs(pos - 1, limit && i == up, (mod + i) % 10, d - i);
            ans %= MOD;
        }
    }
    if (!limit) dp[pos][mod][d] = ans;
    return ans;
}

int solve(int n, int d) {
    int len = 0;
    while (n) {
        digit[++len] = n % 10;
        n /= 10;
    }
    return dfs(len, 1, 0, d);
}

int main() {
    int n, d;
    while (cin >> n >> d) {
        memset(dp, -1, sizeof(dp));
        cout << (solve(n, d) - 1 + MOD) % MOD << endl;
    }
    return 0;
}
