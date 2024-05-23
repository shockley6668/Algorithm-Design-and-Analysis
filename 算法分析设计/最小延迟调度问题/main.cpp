//
//  main.cpp
//  最小延迟调度问题
//
//  Created by Shockley on 5/20/24.
//

#include <iostream>
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
struct Task {
    int duration,ddl;
};
bool cmp(const Task &a,const Task &b)
{
    return a.ddl<b.ddl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<Task> tasks(n);
        for(int i=0;i<n;i++)
        {
            cin>>tasks[i].duration>>tasks[i].ddl;
        }
        sort(tasks.begin(),tasks.end(),cmp);
        
        int time=0,delay=0;
        for(Task task:tasks)
        {
            time+=task.duration;
            if(time>task.ddl)
            {
                delay=max(delay,time-task.ddl);
            }
        }
        cout<<delay<<endl;
    }
    return 0;
}
