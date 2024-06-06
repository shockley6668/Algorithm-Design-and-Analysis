//
//  main.cpp
//  n皇后问题
//
//  Created by Shockley on 6/4/24.
//

#include <iostream>
#include "vector"
using namespace std;
void solveNQueens(int n,int row,vector<int>& position ,int &count)
{
    if(row==n)
    {
        //all queen has placed
        count++;
        return ;
    }
    for(int col=0;col<n;col++)
    {
        bool safe=true;
        for(int i=0;i<row;i++)
        {
            //检查是否冲突
            if(position[i]==col || abs(position[i]-col)==abs(i-row))
            {
                safe=false;
                break;
            }
        }
        if(safe)
        {
            position[row]=col;
            solveNQueens(n,row+1, position, count);
        }
    }
}
int getTotalQ(int n)
{
    vector<int> pos(n);
    int count=0;
    solveNQueens(n, 0, pos, count);
    return count;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    while (cin>>n) {
        cout<<getTotalQ(n)<<endl;
    }
    return 0;
}
