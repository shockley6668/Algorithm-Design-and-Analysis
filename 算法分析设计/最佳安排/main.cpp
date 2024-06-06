//
//  main.cpp
//  最佳安排
//
//  Created by Shockley on 6/4/24.
//

#include <iostream>
#include "vector"
#include "climits"
using namespace std;
int ans=INT_MAX;
vector<bool> vis;
vector<vector<int>> tm;
void dfs(int cur,int nowSum,int n){
    if(nowSum>ans) return;
    if(cur==n){
        ans=min(ans,nowSum);
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;
        vis[i]=true;
        dfs(cur+1,nowSum+tm[cur][i],n);
        vis[i]=false;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin>>n;
    tm.resize(n,vector<int>(n,0));
    vis.resize(n,false);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>tm[i][j];
        }
    }
    dfs(0,0,n);
    cout<<ans<<endl;
    return 0;
}
