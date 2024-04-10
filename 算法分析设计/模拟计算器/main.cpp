//
//  main.cpp
//  模拟计算器
//
//  Created by Shockley on 4/9/24.
//

#include <iostream>
#include <vector>
using namespace std;
vector<long long> nums(100);
vector<char> op(101);
int n;
int main(int argc, const char * argv[]) {
    // insert code here...
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    for(int i=1;i<n;i++)
    {
        cin>>op[i];
    }
    long long n1=nums[0];
    long long n2=nums[1];
    char type=op[1];
    for(int i=2;i<n;i++)
    {
        char nt=op[i];
        long long nn=nums[i];
        if(nt!='*')
        {
            if(type=='+')
            {
                n1=n1+n2;
            }
            else if(type=='-')
            {
                n1-=n2;
            }
            else{
                n1*=n2;
            }
            n2=nn;
            type=nt;
        }
        else{
            n2*=nn;
        }
    }
    
    if(type=='-')
        cout<<n1-n2;
    else if(type=='+')
        cout<<n1+n2;
    else{
        cout<<n1*n2;
    }
    cout<<endl;
    return 0;
}
