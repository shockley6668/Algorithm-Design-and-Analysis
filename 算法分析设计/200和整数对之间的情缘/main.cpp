//
//  main.cpp
//  200和整数对之间的情缘
//
//  Created by Shockley on 4/9/24.
//

#include <iostream>
using namespace std;
#include "vector"
vector<int> v(200);
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    while(t--)
    {
        int p;
        cin>>p;
        v[p%200]++;
    }
    long int ans=0;
    for(auto i : v)
    {
        ans+=i*(i-1);
    }
    cout<<ans/2<<endl;
    return 0;
}
