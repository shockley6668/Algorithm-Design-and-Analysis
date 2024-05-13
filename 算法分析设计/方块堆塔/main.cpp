//
//  main.cpp
//  方块堆塔
//
//  Created by Shockley on 5/13/24.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

// 定义一个结构体，表示一个立方体
struct Block {
    std::vector<int> dimensions; // 存储立方体的三个维度
    Block(int a, int b, int c) : dimensions{a, b, c} {} // 构造函数
};

std::vector<Block> blocks; // 存储所有的立方体
std::vector<int> dp; // dp[i]表示以i为起点的最长路径长度
std::vector<std::vector<bool>> graph; // graph[i][j]表示是否存在一条从i到j的边

// 计算以current为起点的最长路径长度
int DPS(int current) {
    int &ans = dp[current];
    if(ans != -1) return ans; // 如果已经计算过，直接返回结果
    ans = blocks[current].dimensions[2]; // 初始化为当前立方体的高度
    for(int i = 0; i < blocks.size(); i ++) {
        // 如果存在一条从current到i的边，尝试更新最长路径长度
        if(graph[current][i]) ans = std::max(ans, DPS(i) + blocks[current].dimensions[2]);
    }
    return ans; // 返回结果
}

int main() {
    int n;
    while(std::cin >> n) {
        blocks.clear(); // 清空立方体列表
        dp = std::vector<int>(n * 3, -1); // 初始化dp数组
        graph = std::vector<std::vector<bool>>(n * 3, std::vector<bool>(n * 3, false)); // 初始化图
        for(int i = 0; i < n; i ++) {
            int a, b, c;
            std::cin >> a >> b >> c;
            // 对于每个立方体，生成三个新的立方体，每个新的立方体都以原立方体的一个面作为底面
            blocks.emplace_back(a, b, c);
            blocks.emplace_back(b, c, a);
            blocks.emplace_back(c, a, b);
            for(int j = 0; j < 3; j ++) {
                // 确保每个立方体的底面的长和宽满足长>=宽
                if(blocks[i * 3 + j].dimensions[0] > blocks[i * 3 + j].dimensions[1])
                    std::swap(blocks[i * 3 + j].dimensions[0], blocks[i * 3 + j].dimensions[1]);
            }
        }
        // 构建图
        for(int i = 0; i < n * 3; i ++)
            for(int j = 0; j < n * 3; j ++)
                // 如果立方体i可以放在立方体j的上面，就添加一条从i到j的边
                graph[i][j] = blocks[i].dimensions[0] > blocks[j].dimensions[0] && blocks[i].dimensions[1] > blocks[j].dimensions[1];
        int ans = 0;
        for(int i = 0; i < n * 3; i ++) {
            // 计算以每个立方体为起点的最长路径长度，并找出最大的长度
            ans = std::max(ans, DPS(i));
        }
        std::cout << ans << std::endl; // 输出结果
    }
    return 0;
}
