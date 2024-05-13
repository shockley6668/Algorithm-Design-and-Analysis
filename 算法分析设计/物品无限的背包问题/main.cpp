//
//  main.cpp
//  物品无限的背包问题
//
//  Created by Shockley on 5/8/24.
//

#include <iostream>
#include "vector"
#include "algorithm"
using namespace std;
int dp_cal(int n,int w,vector<int> &weights,vector<int>& values)
{
    vector<int> dp(w+1,0);
    for(int i=0;i<n;i++)
    {
        for(int j=weights[i];j<=w;j++)
        {
            dp[j]=max(dp[j],dp[j-weights[i]]+values[i]);
        }
    }
    return dp[w];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m;
    while (cin>>n>>m) {
        vector<int> weights(n),values(n);
        for(int i=0;i<n;i++)
        {
            cin>>weights[i]>>values[i];
        }
        cout<<dp_cal(n, m, weights, values)<<endl;
    }
    return 0;
}
