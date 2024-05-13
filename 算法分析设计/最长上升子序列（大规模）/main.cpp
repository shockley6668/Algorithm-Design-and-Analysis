//
//  main.cpp
//  最长上升子序列（大规模）
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
    vector<int> tails(nums.size(), 0);
    int size = 0;
    for (int k=1;k<nums.size();k++) {
        int i = 0, j = size;
        while (i != j) {
            int m = (i + j) / 2;
            if (tails[m] < nums[k])
                i = m + 1;
            else
                j = m;
        }
        tails[i] = nums[k];
        if (i == size) ++size;
    }
    return size;
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
