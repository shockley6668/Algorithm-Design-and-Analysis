//
//  main.cpp
//  防守战线
//
//  Created by Shockley on 6/5/24.
//
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const int N = 1010; // 最大约束数
const int M = 1e4 + 10; // 最大变量数

const double eps = 1e-8; // 浮点数比较误差
const double inf = 1e9 + 7; // 无穷大

double a[N][M]; // 约束系数矩阵
double lim[M]; // 变量约束
double c[M]; // 目标函数系数
double ans; // 最终结果
int m, n; // 约束数和变量数
// 浮点数比较
int cmp(double x) {
    if (x < -eps) return -1;
    if (x > eps) return 1;
    return 0;
}

// 约束转换
void transform(int e, int l) {
    // 更新 l 行的约束
    lim[l] /= a[l][e];
    double t = a[l][e];
    a[l][e] = 1;
    for (int i = 1; i <= n; i++)
        if (i != e) a[l][i] /= t;
    
    // 更新其余行的约束
    for (int i = 1; i <= m; i++) {
        if (i != l && cmp(a[i][e]) != 0) {
            lim[i] -= a[i][e] * lim[l];
            for (int j = 1; j <= n; j++)
                if (j != e) a[i][j] -= a[i][e] * a[l][j];
            a[i][e] = -a[i][e] * a[l][e];
        }
    }

    // 更新目标函数的值
    ans += c[e] * lim[l];
    for (int i = 1; i <= n; i++)
        if (i != e) c[i] -= c[e] * a[l][i];
    c[e] = -c[e] * a[l][e];
}

int main() {
    
    cin >> m >> n;

    // 输入变量的约束
    for (int i = 1; i <= m; i++)
        cin >> lim[i];

    // 输入目标函数系数和约束范围
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r >> c[i];
        for (int j = l; j <= r; j++)
            a[j][i] = 1;
    }

    // Simplex算法迭代
    while (1) {
        double mn = inf;
        int j = 0, k = 0;

        // 寻找目标函数系数大于0的变量
        for (j = 1; j <= n; j++)
            if (cmp(c[j]) == 1)
                break;

        // 所有目标函数系数都小于等于0，则算法结束
        if (j > n)
            break;

        // 在可行域内找到目标函数系数最大的变量
        for (int i = 1; i <= m; i++) {
            if (cmp(a[i][j]) == 1 && mn > lim[i] / a[i][j])
                k = i, mn = lim[i] / a[i][j];
        }

        // 更新约束
        transform(j, k);
    }

    // 输出结果
    cout << (int)(ans + 0.55);
    
    return 0;
}
