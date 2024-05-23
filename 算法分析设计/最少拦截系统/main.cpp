//
//  main.cpp
//  最少拦截系统
//
//  Created by Shockley on 5/21/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> height(n), systems;
        for (int i = 0; i < n; ++i) {
            cin >> height[i];
        }
        systems.push_back(height[0]);
        for (int i = 1; i < n; ++i) {
            sort(systems.begin(), systems.end());
            int j=0;
            for(j=0;j<systems.size();j++)
            {
                if(height[i]<=systems[j])
                {
                    systems[j]=height[i];
                    break;
                }
            }
            if(j==systems.size())
            {
                systems.push_back(height[i]);
            }
        }
        cout<<systems.size()<<endl;
    }
    return 0;
}
