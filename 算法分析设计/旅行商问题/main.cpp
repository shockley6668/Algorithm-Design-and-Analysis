//
//  main.cpp
//  旅行商问题
//
//  Created by Shockley on 6/4/24.
//

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class TSPSolver {
private:
    int n; // 图中节点数量
    vector<vector<int>> graph; // 图的邻接矩阵
    vector<int> path; // 记录当前路径
    vector<bool> visited; // 记录节点是否被访问过
    int minPathLength; // 记录最小路径长度

public:
    TSPSolver(int numNodes) : n(numNodes), graph(numNodes, vector<int>(numNodes, 0)), visited(numNodes, false), minPathLength(INT_MAX) {}

    // 添加边
    void addEdge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    // DFS搜索
    void dfs(int node, int depth, int pathLength,int begin) {
        if (depth == n) { // 已经访问完所有节点
            
            minPathLength = min(minPathLength, pathLength+graph[node][begin]); // 更新最小路径长度
            
            return;
        }
        if(pathLength>minPathLength) return ;
        for (int next = 0; next < n; ++next) {
            if (!visited[next] && graph[node][next] != 0) { // 如果节点未被访问且与当前节点相连
                visited[next] = true;
                path.push_back(next);
                dfs(next, depth + 1, pathLength + graph[node][next],begin); // 递归搜索下一个节点
                visited[next] = false;
                path.pop_back();
            }
        }
    }

    // 解决TSP问题并返回最小路径长度
    int solveTSP() {
        // 从每个节点开始搜索
        for (int i = 0; i < n; ++i) {
            path.clear();
            path.push_back(i); // 将当前节点加入路径中
            visited[i] = true;
            dfs(i, 1, 0,i); // 从当前节点开始DFS搜索
            visited[i] = false;
        }
        return minPathLength;
    }
};

int main() {
    int n;
    cin >> n; // 输入顶点数

    TSPSolver solver(n); // 创建TSPSolver对象

    // 读取边信息并添加到图中
    for (int i = 0; i < n * (n - 1) / 2; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        solver.addEdge(u - 1, v - 1, weight); // 节点编号从1开始，转换为0-based
    }

    // 解决TSP问题并输出结果
    cout << solver.solveTSP() << endl;

    return 0;
}
