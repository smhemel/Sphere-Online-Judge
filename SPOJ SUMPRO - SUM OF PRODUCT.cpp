//
//  main.cpp
//  SPOJ SUMPRO - SUM OF PRODUCT
//
//  Created by S M HEMEL on 14/8/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#define ll long long int
#define mod 1000000007
using namespace std;
ll range_sum(ll a, ll b) {
    return ((a*(a+1)>>1)-(b*(b+1)>>1))%mod;
}
int main()
{
    int test;
    ll n;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%lld",&n);
        ll root= (int)sqrt(n);
        ll low = 0,up = 0,sum = 0;
        for(int i=1; i<=root; i++)
        {
            up = n/i;
            low =max(n/(i+1),root);
            sum = (sum+((range_sum(up,low)*i)%mod))%mod;
            sum = (sum+((i*(n/i))%mod))%mod;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
