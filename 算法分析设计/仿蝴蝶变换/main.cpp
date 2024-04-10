//
//  main.cpp
//  仿蝴蝶变换
//
//  Created by Shockley on 4/10/24.
//

#include <iostream>
#include <iostream>
#include <vector>
using namespace std;

void butterflyTransform(vector<int>& nums) {
    int n = nums.size();
    while (true) {
        vector<int> odd, even; // 存放奇数位置和偶数位置的数
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0)
                odd.push_back(nums[i]);
            else
                even.push_back(nums[i]);
        }
        if (odd.size() == 0 || even.size() == 0) // 如果奇数位置或偶数位置没有数了，结束循环
            break;
        // 重新排列数组
        for (int i = 0; i < odd.size(); ++i) {
            nums[i] = odd[i];
        }
        for (int i = 0; i < even.size(); ++i) {
            nums[odd.size() + i] = even[i];
        }
        n /= 2; // 缩小数组范围
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        butterflyTransform(nums);
        for (int i = 0; i < n; ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    return 0;
    return 0;
}
