//
//  main.cpp
//  两面包夹芝
//
//  Created by Shockley on 4/9/24.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    int maxA=0,minB=1001;
    cin>>t;
    int n;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        if(n>maxA)
            maxA=n;
    }
    for(int i=0;i<t;i++)
    {
        cin>>n;
        if(n<minB)
            minB=n;
    }
    if (minB - maxA >= 0)
    {
        cout << minB - maxA + 1;
    }
    else {
        cout<<0<<endl;
    }
    return 0;
}
