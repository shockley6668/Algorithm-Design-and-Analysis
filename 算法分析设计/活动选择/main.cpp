//
//  main.cpp
//  活动选择
//
//  Created by Shockley on 5/20/24.
//

#include <iostream>
#include <vector>
#include "algorithm"
using namespace std;
struct Active{
    int start;
    int end;
};
bool cmp(const Active & a,const Active & b)
{
    return a.end<b.end;
}
int main(int argc, const char * argv[]) {
    int n;
    while(cin>>n)
    {
        vector<Active> actives(n);
        for(int i=0;i<n;i++)
        {
            cin>>actives[i].start>>actives[i].end;
        }
        sort(actives.begin(),actives.end(),cmp);
        int current_time=actives[0].end;
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(actives[i].start>=current_time)
            {
                current_time=actives[i].end;
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
