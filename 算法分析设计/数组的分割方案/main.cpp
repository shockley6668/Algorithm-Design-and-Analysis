//
//  main.cpp
//  数组的分割方案
//
//  Created by Shockley on 5/21/24.
//

#include <iostream>
#include "vector"
#include "algorithm"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    while (cin>>n) {
        vector<int> arr(n*2);
        int sum=0;
        for(int i=0;i<n*2;i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n*2;i+=2)
        {
            sum+=arr[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
