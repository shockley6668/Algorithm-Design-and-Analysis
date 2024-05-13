#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define Inf 1<<31-1

struct Point {
    double x;
    double y;
    int id; //点的编号
};

class ClosestPairFinder {
private:
    Point points[200005];
    int tempIndices[300005];
    int pointA = 2147483647, pointB = 2147483647, minDistance = 2147483647;

    double calculateDistance(Point a, Point b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }

    static bool compareByX(Point a, Point b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x; //第一个排序是按照x坐标升序，排序以后才好分左右平面
    }

    bool compareByY(int a, int b) {
        return points[a].y < points[b].y; //第二个排序是选择中间的点，按y坐标升序排列
    }

    void updateClosestPair(int newA, int newB, int newMinDistance) {
        if (newA > newB) swap(newA, newB);
        if (newMinDistance == minDistance) {
            if (pointA > newA || pointA == newA && pointB > newB) {
                pointA = newA;
                pointB = newB;
            }
        } else { pointA = newA; pointB = newB; minDistance = newMinDistance; }
    }

    void findClosestPair(int left, int right) {
        if (left == right) return; //如果自己和自己的距离最近，则距离为0，应该返回
        if (left + 1 == right) {
            //获取距离
            int currentDistance = calculateDistance(points[left], points[right]);
            //如果当前距离更小，则更新一下答案
            if (minDistance >= currentDistance) updateClosestPair(points[left].id, points[right].id, currentDistance);
            return;
        }
        int mid = (left + right) >> 1; //如果中间还有其他点，那就再中间分开。
        findClosestPair(mid, right); //找右边的最小距离
        findClosestPair(left, mid - 1); //找左边的最小距离
        int k = 0;
        for (int i = left; i <= right; i++) {
            if (fabs(points[mid].x - points[i].x) <= minDistance) {
                tempIndices[++k] = i;
            }
        } //有可能在两个平面中间还有其他的更小距离 这个就是按照x坐标找可能出现的点
        sort(tempIndices + 1, tempIndices + k + 1, [this](int a, int b) { return compareByY(a, b); }); //按这些点的y坐标升序排列
        //线性扫描，找这些点的最小距离
        for (int i = 1; i <= k; i++) {
            for (int j = i + 1; j <= k && points[tempIndices[j]].y - points[tempIndices[i]].y <= minDistance; j++) { //注意第二个判断条件
                if (minDistance >= calculateDistance(points[tempIndices[i]], points[tempIndices[j]])) {
                    int newDistance = calculateDistance(points[tempIndices[i]], points[tempIndices[j]]);
                    updateClosestPair(points[tempIndices[i]].id, points[tempIndices[j]].id, newDistance);
                }
            }
        }
        return;
    }

public:
    void solve() {
        int numPoints;
        cin >> numPoints;
        for (int i = 1; i <= numPoints; i++) {
            cin >> points[i].x >> points[i].y;
            //点的序号
            points[i].id = i - 1;
        }
        //按横坐标升序排列
        sort(points + 1, points + numPoints + 1, compareByX);
        findClosestPair(1, numPoints);
        cout << pointA << " " << pointB;
    }
};

int main() {
    ClosestPairFinder cpf;
    cpf.solve();
    return 0;
}
