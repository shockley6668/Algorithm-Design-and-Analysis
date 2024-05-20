//
//  main.cpp
//  找零钱
//
//  Created by Shockley on 5/20/24.
//

#include <iostream>
#include "vector"
using namespace std;
vector<int> notes ={100,50,20,10,5,2,1};
int n;
int main(int argc, const char * argv[]) {
    while(cin>>n)
    {
        int total=0;
        int num=0;
        string res;
        for(int note:notes)
        {
            int count=n/note;
            total+=count*note;
            num+=count;
            n-=count*note;
            if(!res.empty()&& count>0)
                res+="+";
            if(count>0)
            {
                res+=to_string(note);
            }
            
            if(count>1) res+="*"+to_string(count);
        }
        res+="="+to_string(total);
        cout<<num<<" "<<res<<endl;
    }
   
    return 0;
}
