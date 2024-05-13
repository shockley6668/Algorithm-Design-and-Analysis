//
//  main.cpp
//  最长公共子序列
//
//  Created by Shockley on 5/8/24.
//

#include <iostream>
#include <string>
#include <vector>
using namespace::std;
int dp(string t1,string t2)
{
    int m=t1.size();
    int n=t2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(t1[i-1]==t2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string s1,s2;
    while (cin>>s1>>s2) {
        cout<<dp(s1,s2)<<endl;
    }
    return 0;
}
