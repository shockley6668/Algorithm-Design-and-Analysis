//
//  main.cpp
//  最长上升子序列（小规模）
//
//  Created by Shockley on 5/8/24.
//

#include <iostream>
#include <iostream>
#include "vector"
#include "algorithm"
using namespace std;
const int mod = 1e9 + 7;
int dp(vector<long long > &nums)
{
    int n=nums.size();
    vector<int> dp(n,1);
    for(int i=2;i<n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(nums[i]>nums[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,b;
    cin>>n>>b;
    vector<long long>a(n+1);
    a[1] = b;
    for(int i = 2; i <= n; i ++) {
        a[i] = 1LL * (a[i - 1] + 1) * (a[i - 1] + 1) % mod;
    }
    cout<<dp(a);
    return 0;
}
