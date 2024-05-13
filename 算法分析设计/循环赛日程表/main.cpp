//
//  main.cpp
//  循环赛日程表
//
//  Created by Shockley on 4/17/24.
//
//创建一个n x n的二维数组table，用于存储日程表。
//定义一个函数schedule，接受一个参数k，表示当前的问题规模。
//如果k为1，那么只有两个选手，他们在第一天进行比赛，所以table[1][1] = 2，table[2][1] = 1。
//如果k大于1，那么我们将问题分解为两个子问题，每个子问题的规模为k/2。我们对这两个子问题分别调用schedule函数。
//然后，我们将这两个子问题的解合并为原问题的解。对于前k个选手，他们在后k天的对手是他们在前k天的对手加k。对于后k个选手，他们在前k天的对手是他们在后k天的对手减k。
//最后，我们输出日程表

#include <iostream>
#include <vector>
using namespace std;
void shedule(vector<vector<int>> &table,int n)
{
    if (n == 1) {
        table[0][0] = 1;
        return;
    }

    shedule(table, n / 2);

    int hn = n / 2;
    for (int i = 0; i < hn; i++) {
        for (int j = 0; j < hn; j++) {
            table[i + hn][j] = table[i][j] + hn;
            table[i][j + hn] = table[i + hn][j];
            table[i + hn][j + hn] = table[i][j];
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin>> n;
    vector<vector<int>> table(n,vector<int>(n,0));
    shedule(table, n);
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
