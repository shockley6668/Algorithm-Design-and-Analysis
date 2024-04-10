//
//  main.cpp
//  排队
//
//  Created by Shockley on 4/9/24.
//

#include <iostream>
#include "deque"
#include "vector"
using namespace std;
struct Person{
    int id;
    int frame;
    Person(int i,int f):id(i),frame(f){}
};
void lastRemain(vector<int> p,deque<Person> &q)
{
    for(int i=0;i<p.size();i++)
    {
        if(q.empty())
        {
            q.push_back(Person(i+1,p[i]));
        }
        else if(q.size()<5&& q.back().frame<p[i])
        {
            q.push_back(Person(i+1,p[i]));
        }
        else if(q.back().frame<p[i])
        {
            q.pop_front();
            q.push_back(Person(i+1,p[i]));
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    deque<Person> q;
    int n;
    cin>>n;
    vector<int> p;
    for (int i = 0; i < n; ++i) {
        int a;
        cin>>a;
        p.push_back(a);
    }
    lastRemain(p,q);
    for(auto r:q)
    {
        cout<<r.id<<" ";
    }
    return 0;
}
