//
//  main.cpp
//  圆排列最小宽度
//
//  Created by Shockley on 6/6/24.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// 计算当前排列的宽度
double computeWidth(const vector<double>& radii, const vector<int>& perm) {
    int n = radii.size();
    vector<double> x(n);
    x[perm[0]] = radii[perm[0]];
    double width = x[perm[0]] + radii[perm[0]];
    for (int i = 1; i < n; ++i) {
        int cur = perm[i];
        x[cur] = radii[cur];
        for (int j = 0; j < i; ++j) {
            int prev = perm[j];
            x[cur] = max(x[cur], x[prev] + 2 * sqrt(radii[cur] * radii[prev]));
        }
        width = max(width, x[cur] + radii[cur]);
    }
    return width;
}

// 模拟退火算法求解
double simulatedAnnealing(vector<double>& radii) {
    int n = radii.size();
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) perm[i] = i;
    
    double currentWidth = computeWidth(radii, perm);
    double bestWidth = currentWidth;
    double T = 10000.0;
    double coolingRate = 0.99;
    
    while (T > 1e-8) {
        int a = rand() % n;
        int b = rand() % n;
        swap(perm[a], perm[b]);
        double newWidth = computeWidth(radii, perm);
        if (newWidth < currentWidth || exp((currentWidth - newWidth) / T) > (rand() / (double)RAND_MAX)) {
            currentWidth = newWidth;
            if (newWidth < bestWidth) bestWidth = newWidth;
        } else {
            swap(perm[a], perm[b]);
        }
        T *= coolingRate;
    }
    
    return bestWidth;
}

int main() {
    srand(time(0));
    
    int n;
    cin >> n;
    vector<double> radii(n);
    for (int i = 0; i < n; ++i) {
        cin >> radii[i];
    }
    
    // 排序圆的半径，方便后续排列
    sort(radii.begin(), radii.end(), greater<double>());
    
    double result = simulatedAnnealing(radii);
    printf("%.6f\n", result);
    
    return 0;
}
