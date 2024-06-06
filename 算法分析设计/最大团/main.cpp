//
//  main.cpp
//  最大团
//
//  Created by Shockley on 6/4/24.
//

#include <iostream>
#include "vector"
using namespace std;
class Graph{
public:
    Graph(int n):adj(n,vector<bool>(n,false)),n(n){}
    void addEdge(int u,int v){
        adj[u][v]=true;
        adj[v][u]=true;
    }
    // 返回最大团的顶点个数
    int maxClique()
    {
        vector<int> clique;// 当前团的顶点集合
        vector<int> candidates; // 候选顶点集合
        for(int i=0;i<n;i++)
        {
            candidates.push_back(i); //初始化候选点
        }
        int maxCliqueSize=0;
        dfs(clique,candidates,maxCliqueSize);
        return maxCliqueSize;
    }
    
private:
    vector<vector<bool>> adj; //邻接矩阵
    int n;
    void dfs(vector<int>& clique,vector<int>& candidates,int &maxCliqueSize)
    {
        if(candidates.empty())// 如果没有候选顶点，更新最大团大小
        {
            maxCliqueSize=max(maxCliqueSize,(int)clique.size());
            return;
        }
        while (!candidates.empty()) {
            int v=candidates.back();
            candidates.pop_back();
            // 剪枝：如果当前团的大小加上候选顶点的数量不超过当前最大团大小，则无需继续
            if(clique.size()+candidates.size()+1<=maxCliqueSize) return;
            // 将顶点加入当前团
            clique.push_back(v);
            // 构造新的候选顶点集合
            vector<int> newCandidates;
            for(int u:candidates)
            {
                if(adj[u][v])
                {
                    newCandidates.push_back(u);// 仅保留与v相邻的顶点
                }
            }
            dfs(clique,newCandidates,maxCliqueSize);// 递归调用DFS
            // 回溯
            clique.pop_back();// 从当前团中移除顶点v
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdge(u-1, v-1);
    }
    cout<<g.maxClique()<<endl;
    return 0;
}
