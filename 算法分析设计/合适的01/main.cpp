//
//  main.cpp
//  合适的01
//
//  Created by Shockley on 6/4/24.
//

#include<cstdio>
#include<cstdlib>
#include<cstring>

char op[22];
int cnt;
//cur表示当前处理的字符的位置，now表示当前'+'和'-'的数量差
void DFS(int cur, int now) {
    if(cur == 8) {
        cnt += now > 0;
        return;
    }
    DFS(cur + 1, now + (cur == 0 || op[cur - 1] == '+' ? 1 : -1));
    DFS(cur + 1, now);
}
int main() {

    while(scanf("%s", op) != EOF) {
        cnt = 0;
        DFS(0, 0);
        printf("%d\n", cnt);
    }
    return 0;
}
