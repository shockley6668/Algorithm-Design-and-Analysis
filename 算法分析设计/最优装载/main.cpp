//
//  main.cpp
//  最优装载
//
//  Created by Shockley on 5/20/24.
//

#include <iostream>
#include "algorithm"
using namespace std;
int weight,n,t;
int main(int argc, const char * argv[]) {
    // insert code here...
    cin>>t;
    while(t--)
    {
        cin>>weight>>n;
        vector<int> weights(n);
        for(int i=0;i<n;i++)
        {
            cin>>weights[i];
        }
        sort(weights.begin(),weights.end());
        int c=0;
        int i=0;
        for(;i<n;i++)
        {
            if(c+weights[i]>weight)
            {
                break;
            }
            else
                c+=weights[i];
        }
        cout<<i<<endl;
    }

    return 0;
}
