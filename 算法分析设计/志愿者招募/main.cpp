//
//  main.cpp
//  志愿者招募
//
//  Created by Shockley on 6/5/24.
//
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
const double EPSILON = 1e-7;  // 浮点数比较精度
struct Simplex {
    vector<double> b, c; // 约束条件的右端项和目标函数的系数
    vector<vector<double>> a; // 约束条件的系数矩阵
    double z; // 目标函数的当前值
    int m, n; // 约束条件个数和自由变量个数

    // 初始化
    void Init(int numConstraints, int numVariables) {
        m = numConstraints, n = numVariables, z = 0;
        a.resize(m+10, vector<double>(n+10, 0));
        b.resize(m+10, 0);
        c.resize(n+10, 0);
    }

    // 主元选取和更新
    void Pivot(int leaving, int entering) {
        b[leaving] /= a[leaving][entering]; // 更新替出行的右端项
        for (int j = 0; j < n; j++) // 更新替出行的系数
            if (j != entering)
                a[leaving][j] /= a[leaving][entering];
        a[leaving][entering] = 1 / a[leaving][entering]; // 更新替出行的新主元
        for (int i = 0; i < m; i++) { // 更新其他行
            if (i == leaving || fabs(a[i][entering]) < EPSILON) // 跳过已更新行和系数为0的行
                continue;
            b[i] -= a[i][entering] * b[leaving]; // 更新右端项
            for (int j = 0; j < n; j++) // 更新系数
                if (j != entering)
                    a[i][j] -= a[i][entering] * a[leaving][j];
            a[i][entering] = -a[i][entering] * a[leaving][entering]; // 更新新主元
        }
        // 更新目标函数值和系数
        z += c[entering] * b[leaving];
        for (int j = 0; j < n; j++)
            if (j != entering)
                c[j] -= c[entering] * a[leaving][j];
        c[entering] *= -a[leaving][entering];
    }

    // 解线性规划
    double Solve() {
        while (true) {
            int entering = -1, leaving = -1;
            double maxC = EPSILON;
            // 找替入变量
            for (int j = 0; j < n; j++)
                if (c[j] > maxC) {
                    maxC = c[j];
                    entering = j;
                }
            if (entering == -1) // 如果没有可选的替入变量，则达到最优解
                return z;
            double minRatio = INFINITY;
            // 找替出变量
            for (int i = 0; i < m; i++)
                if (a[i][entering] > EPSILON) {
                    double ratio = b[i] / a[i][entering];
                    if (ratio < minRatio) {
                        minRatio = ratio;
                        leaving = i;
                    }
                }
            if (leaving == -1) // 如果没有替出变量，线性规划无界
                return INFINITY;
            Pivot(leaving, entering); // 执行主元选取和更新
        }
    }
};
Simplex simplexSolver; // 创建 Simplex 对象

int main() {
    int n,m;
    while(cin>>n>>m)
    {
        simplexSolver.Init(m, n);
        std::vector<int> S(m), T(m), A(m), C(n);
        for(int i=0;i<n;i++) cin>>simplexSolver.c[i];
        for(int i=0;i<m;i++) cin>>S[i]>>T[i]>>C[i];
        for(int j = 0; j < m; j ++) {
            for(int i = 0; i < n; i ++) {
                simplexSolver.a[j][i] = i + 1 >= S[j] && i + 1 <= T[j];
            }
            simplexSolver.b[j] = C[j];
        }
        cout<<(long long)(simplexSolver.Solve()+EPSILON)<<endl;
        return 0;
    }
    

}

