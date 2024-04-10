//
//  main.cpp
//  逆序对
//
//  Created by Shockley on 4/10/24.
//
//归并排序是一种经典的分治算法，其思想可以简要概括为以下几步：
//
//分解：将原始序列分解成较小的子序列，直到每个子序列只有一个元素为止。这样，单个元素的序列可以被认为是有序的。
//
//合并：将相邻的子序列两两合并，形成新的有序序列。合并过程中，需要比较两个子序列的元素，并按照顺序将它们合并成一个更大的有序序列。
//
//递归：重复以上步骤，直到所有子序列都被合并成一个完整的序列为止。
//
//在归并排序中，关键的操作是合并两个有序序列。这个操作可以通过创建一个临时数组来实现。合并过程中，两个有序序列的元素逐个进行比较，较小的元素先放入临时数组，直到其中一个序列的所有元素都放入临时数组中。然后将剩余的另一个有序序列的元素直接放入临时数组的末尾。最终，临时数组中存储的就是两个有序序列合并后的结果。
//
//归并排序的主要优势在于其稳定性和时间复杂度稳定的特点，时间复杂度为O(nlogn)。因此，归并排序常被用于需要稳定排序并且数据量较大的情况下。

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int maxn = 1e5 + 10;
int a[maxn], mergeTemp[maxn];
// 合并函数，合并[left, mid)和[mid, right)两个有序序列，并统计逆序对的数量
long long merge(int left, int mid,int right)
{
    long long count=0;
    int i=left,j=mid,k=left;
    // 比较两个序列的元素，并按顺序将它们放入mergeTemp数组
    while (i<mid&& j<right) {
        if(a[i]<=a[j])
        {
            mergeTemp[k++]=a[i++];
        }
        else{
            mergeTemp[k++]=a[j++];
            count+=mid-i;//当右侧序列的元素小于左侧序列的元素时，说明左侧序列的后面的所有元素都构成了逆序对
        }
    }
    while (i<mid) {
        mergeTemp[k++]=a[i++];
    }
    while (j<right) {
        mergeTemp[k++]=a[j++];
    }
    for (int p = left; p < right; p++)
        a[p] = mergeTemp[p];
    return count;
}
long long MergeSort(int left ,int right)
{
    // 当区间长度为1时，已经有序，返回0
    if(right-left<=1)
    {
        return 0;
    }
    int mid=left+(right-left)/2;
    long long count=0;
    count+=MergeSort(left,mid);
    count+=MergeSort(mid,right);
    count+=merge(left, mid, right);
    return count;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("%lld\n", MergeSort(0, n));
    }
    return 0;
}
