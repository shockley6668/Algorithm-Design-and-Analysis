//
//  main.cpp
//  汉诺塔
//
//  Created by Shockley on 4/10/24.
//
//​汉诺塔，是一个源于印度的玩具。大梵天创造世界的时候做了三根金刚石柱子，在一根柱子上从下往上按照大小顺序摞着64片黄金圆盘。大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。并且规定，在小圆盘上不能放大圆盘，在三根柱子之间一次只能移动一个圆盘。
//
//​ 现在给你一个n片圆盘的汉诺塔，并从小到大编号为1
//
//至
//。请你输出搬动
//个圆盘最少次数的全过程。
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void move(int disk, char from, char to) {
    printf("Move disk %d from %c to %c\n", disk, from, to);
}
void Hannoi(int n, char from, char to, char temp) {
    if (n == 1) {
        move(n, from, to);
        return;
    }
    
    Hannoi(n - 1, from, temp, to);
    move(n, from, to);
    Hannoi(n - 1, temp, to, from);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    while(scanf("%d", &n) != EOF) {
        Hannoi(n, 'A', 'C', 'B'); // 从柱子A移动n个盘子到柱子C，柱子B作为辅助
    }
    return 0;
}
