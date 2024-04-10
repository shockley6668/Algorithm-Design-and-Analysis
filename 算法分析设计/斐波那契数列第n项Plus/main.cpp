//
//  main.cpp
//  斐波那契数列第n项Plus
//
//  Created by Shockley on 4/10/24.
//

#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

const int mod = 1e9 + 7;

class Node {
public:
    long long mat[2][2];

    Node() {
        mat[0][0] = mat[1][1] = 1;
        mat[0][1] = mat[1][0] = 0;
    }

    Node(long long a, long long b, long long c, long long d) {
        mat[0][0] = a % mod;
        mat[0][1] = b % mod;
        mat[1][0] = c % mod;
        mat[1][1] = d % mod;
    }

    Node operator*(const Node &y) {
        Node res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                res.mat[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    res.mat[i][j] = (res.mat[i][j] + (mat[i][k] * y.mat[k][j]) % mod) % mod;
                }
            }
        }
        return res;
    }

    Node pow(int n) {
        Node res;
        Node base = *this;
        while (n) {
            if (n & 1)
                res = res * base;
            base = base * base;
            n >>= 1;
        }
        return res;
    }
};

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Node x(1, 1, 1, 0); // 斐波那契数列推导矩阵
        Node ans = x.pow(n - 1); // 计算斐波那契数列推导矩阵的 n - 1 次方
        cout << ans.mat[0][0] << endl; // 输出斐波那契数列第 n 项的值
    }
    return 0;
}
