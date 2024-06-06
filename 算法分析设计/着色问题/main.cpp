//
//  main.cpp
//  着色问题
//
//  Created by Shockley on 6/4/24.
//

#include <iostream>
#include <vector>
using namespace std;
class Graph{
public:
    Graph(int nodes ,int colors,int edges):n(nodes),m(colors),e(edges),total_ways(0){
        adj.resize(n);
        color.resize(n,0);
    }
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int countColor()
    {
        countColoringsUtil(0);
        return total_ways;
    }
private:
    int n,m,e;
    int total_way;
    vector<vector<int>> adj;
    vector<int> color;
    int total_ways;
bool isValid(int node,int c)
{
    for(int neighbor:adj[node])
    {
        if(color[neighbor]==c)
        {
            return false;
        }
    }
    return true;
}
void countColoringsUtil(int node)
{
    if(node==n)
    {
        total_ways++;
        return ;
    }
    for(int c=1;c<=m;c++)
    {
        if(isValid(node, c))
        {
            color[node]=c;
            countColoringsUtil(node+1);
            color[node]=0;
        }
    }
}
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m,e;
    cin>>n>>m>>e;
    Graph g(n,m,e);
    for(int i=0;i<e;i++)
    {
        int u;
        int v;
        cin>>u>>v;
        g.addEdge(u-1, v-1);
        
    }
    cout<<g.countColor()<<endl;
    return 0;
}
