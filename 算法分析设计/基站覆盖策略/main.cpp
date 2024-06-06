//
//  main.cpp
//  基站覆盖策略
//
//  Created by Shockley on 6/6/24.
//

#include <iostream>
#include "vector"
using namespace std;
class stationPlace{
private:
    int n,m;
    vector<vector<int>> grid;
    int minS;
    bool canPlaceStation(int x,int y)
    {
        return grid[x][y]==0;
    }
    void placeStation(int x,int y,int v)
    {
        grid[x][y]+=v;
        if (x - 1 >= 0) grid[x - 1][y] += v; // 上
        if (x + 1 < m) grid[x + 1][y] += v; // 下
        if (y - 1 >= 0) grid[x][y - 1] += v; // 左
        if (y + 1 < n) grid[x][y + 1] += v; // 右
    }
    void backTrack(int i,int j,int sta)
    {
        if(sta>= minS) return ;
        while (i < m && (j < n && grid[i][j] > 0)) {
            j++;
            if (j == n) { i++; j = 0; }
        }
        if (i == m) {
            minS = min(minS,sta);
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<grid[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;

            return;
        }
        placeStation(i, j, 1);
        backTrack(i, j, sta+1);
        placeStation(i, j, -1);
        backTrack(i, j + 1, sta);
    }
public:
    stationPlace(int r,int c):m(r),n(c),grid(r,vector<int>(c,0)),minS(r*c){}
    int find()
    {
        backTrack(0, 0, 0);
        return minS;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int r,c;
    cin>>r>>c;
    stationPlace s(r,c);
    cout<<s.find()<<endl;
    return 0;
}
