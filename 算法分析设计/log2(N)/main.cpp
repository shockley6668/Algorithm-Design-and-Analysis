//
//  main.cpp
//  log2(N)
//
//  Created by Shockley on 4/9/24.
//

#include <iostream>
#include <cmath>
long double n;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin>>n;
    int k=0;
    while(pow(2,k+1)<=n)
        k++;
    std::cout<<k<<std::endl;
    return 0;
}
