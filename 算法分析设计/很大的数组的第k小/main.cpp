//
//  main.cpp
//  很大的数组的第k小
//
//  Created by Shockley on 4/10/24.
//
//只对需要的那部分继续排序，而不对整个数组进行排序。

#include <iostream>
#include "vector"
using namespace std;
const int mod=1e9+7;
int qs(vector<int>& nums,int l,int r,int k)
{
    // 当区间只有一个元素时，直接返回该元素
    if(l==r)
    {
        return nums[l];
    }
    // 选择一个基准元素（这里选择区间的中间元素）
    int pIndex=l+(r-l)/2;
    int p=nums[pIndex];
    // 将基准放到最右边
    swap(nums[pIndex],nums[r]);
    int i=l;
    for(int j=l;j<r;j++)
    {
        if(nums[j]<p)
        {
            swap(nums[i++],nums[j]);
        }
    }
    swap(nums[i], nums[r]); // 将基准放到正确的位置
    // 如果基准的位置恰好是第 k 小的数，则返回基准值
    if(i-l==k)
    {
        return nums[i];
    }
    else if(i-l>k)
        return qs(nums,l,i-1,k);
    else{
        return qs(nums,i+1,r,k-(i+1)+l);
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m,k;
    while (cin>>n>>m>>k) {
        vector<int> a(n);
        a[0] = m;
        for (int i = 1; i < n; i++)
            a[i] = 1LL * a[i - 1] * m % mod;
        int res=qs(a,0,n-1,k-1);
        cout<<res<<endl;
    }
    return 0;
}
