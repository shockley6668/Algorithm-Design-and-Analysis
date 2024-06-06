//
//  main.cpp
//  生成r子集
//
//  Created by Shockley on 5/22/24.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

const int maxn = 310;

class SubsetGenerator {
private:
    int n, r;
    int a[maxn];
    bool chose[maxn];

    void DFS(int cur, int rcnt) {
        if (cur == -1) {  // 递归终点,所有元素都已确定
            if (rcnt != r) return;
            for (int i = 0, flg = 1; i < n; i++) {  // 输出子集
                if (!chose[i]) continue;
                printf(" %d" + flg, a[i]); flg = 0;
            }
            printf("\n");
            return;  // 注意return
        }
        // 由n-1~0逆序以便按字典序枚举子集
        chose[cur] = false; DFS(cur - 1, rcnt);  // 不取a[cur]后确定第cur-1个
        chose[cur] = true; DFS(cur - 1, rcnt + 1);  // 取a[cur]后确定第cur-1个
    }

public:
    void generateSubsets() {
        while (scanf("%d%d", &n, &r) != EOF) {
            for (int i = 0; i < n; i++)
                scanf("%d", &a[i]);
            DFS(n - 1, 0);
        }
    }
};

int main() {
    SubsetGenerator generator;
    generator.generateSubsets();
    return 0;
}
