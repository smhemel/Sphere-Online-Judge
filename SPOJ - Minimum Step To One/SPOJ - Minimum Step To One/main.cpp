//
//  main.cpp
//  SPOJ - Minimum Step To One
//
//  Created by S M HEMEL on 4/9/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int main()
{
    const int N_MAX = 20000001;
    int *dp = new int[N_MAX];
    dp[1] = 0;
    for(int i=2; i<N_MAX; i++)
    {
        int m = dp[i-1];
        if(!(i%3))
            m = min(m,dp[i/3]);
        if(!(i%2))
            m = min(m,dp[i/2]);
        dp[i] = m+1;
    }
    int test, n,t = 1;
    cin >> test;
    while (test--) {
        cin >> n;
        cout << "Case " << t++ << ": " << dp[n] << endl;
    }
    delete[] dp;
    return 0;
}
