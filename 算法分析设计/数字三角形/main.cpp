//
//  main.cpp
//  数字三角形
//
//  Created by Shockley on 4/29/24.
//

#include <iostream>
#include "cmath"
using namespace std;
int arr[102][102];
int main(int argc, const char * argv[]) {
    // insert code here...
    int t,n,temp;
    cin>>t;
    while (t--) {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                cin>>temp;
                arr[i][j]=max(arr[i-1][j-1],arr[i-1][j])+temp;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(ans<arr[n][i])
            {
                ans=arr[n][i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
