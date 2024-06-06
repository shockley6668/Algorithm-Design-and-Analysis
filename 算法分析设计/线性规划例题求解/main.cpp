//
//  main.cpp
//  线性规划例题求解
//
//  Created by Shockley on 6/5/24.
//
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

const double EPSILON = 1e-7; // 定义精度常量
const double INFINITYY = 1e20; // 定义无穷大常量

struct Simplex {
    std::vector<double> b, c; // 存储约束条件的右端项和目标函数的系数
    std::vector<std::vector<double>> a; // 存储约束条件的系数矩阵
    double z; // 目标函数的当前值
    int m, n; // 约束条件个数和自由变量个数
    
    void initialize(int numConstraints, int numVariables) {
        m = numConstraints;
        n = numVariables;
        z = 0.0;
        a.resize(m + 1, std::vector<double>(n + 1, 0.0));
        b.resize(m + 1, 0.0);
        c.resize(n + 1, 0.0);
    }
    
    void pivot(int entering, int leaving) {
        double pivotValue = a[leaving][entering];
        b[leaving] /= pivotValue;
        for (int j = 0; j < n; j++) {
            if (j != entering) {
                a[leaving][j] /= pivotValue;
            }
        }
        a[leaving][entering] = 1.0 / pivotValue;
        
        for (int i = 0; i < m; i++) {
            if (i == leaving || fabs(a[i][entering]) < EPSILON) continue;
            double ratio = a[i][entering];
            b[i] -= ratio * b[leaving];
            for (int j = 0; j < n; j++) {
                if (j != entering) {
                    a[i][j] -= ratio * a[leaving][j];
                }
            }
            a[i][entering] = -ratio * a[leaving][entering];
        }
        
        z += c[entering] * b[leaving];
        for (int j = 0; j < n; j++) {
            if (j != entering) {
                c[j] -= c[entering] * a[leaving][j];
            }
        }
        c[entering] *= -a[leaving][entering];
    }
    
    double solve() {
        while (true) {
            int entering = -1, leaving = -1;
            double maxC = EPSILON;
            for (int j = 0; j < n; j++) {
                if (c[j] > maxC) {
                    maxC = c[j];
                    entering = j;
                }
            }
            if (entering == -1) {
                return z;
            }
            
            double minRatio = INFINITY;
            for (int i = 0; i < m; i++) {
                if (a[i][entering] > EPSILON) {
                    double ratio = b[i] / a[i][entering];
                    if (ratio < minRatio) {
                        minRatio = ratio;
                        leaving = i;
                    }
                }
            }
            if (leaving == -1) {
                return INFINITY;
            }
            pivot(entering, leaving);
        }
    }
};

Simplex simplexSolver; // 创建 Simplex 对象

int main() {
    simplexSolver.initialize(3, 3); // 初始化 Simplex 对象，3 个约束，3 个变量
    
    // 输入目标函数系数，并转换为求解最小化问题的形式
    scanf("%lf%lf%lf", &simplexSolver.c[0], &simplexSolver.c[1], &simplexSolver.c[2]);
    simplexSolver.c[0] *= -1;
    simplexSolver.c[1] *= -1;
    simplexSolver.c[2] *= -1;
    
    // 输入约束条件的系数和右端项
    scanf("%lf%lf%lf%lf", &simplexSolver.a[0][0], &simplexSolver.a[0][1], &simplexSolver.a[0][2], &simplexSolver.b[0]);
    scanf("%lf%lf%lf%lf", &simplexSolver.a[1][0], &simplexSolver.a[1][1], &simplexSolver.a[1][2], &simplexSolver.b[1]);
    scanf("%lf%lf%lf%lf", &simplexSolver.a[2][0], &simplexSolver.a[2][1], &simplexSolver.a[2][2], &simplexSolver.b[2]);
    
    // 调用求解函数
    double result = simplexSolver.solve();
    
    // 输出结果，判断是否有解
    if (result >= INFINITYY - EPSILON) {
        printf("No solution\n");
    } else {
        printf("%.2f\n", -result); // 输出最优值，注意需要取反
    }
    
    return 0;
}
