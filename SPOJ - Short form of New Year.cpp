//
//  main.cpp
//  SPOJ - Short form of New Year
//
//  Created by S M HEMEL on 4/16/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
#include <cstdio>
#define ll long long int
using namespace std;
ll mod = 100;
ll bigmod(ll b,ll p){
    if(!p)
        return 1;
    ll x = bigmod(b,p>>1);
    x = (x*x)%mod;
    if(p&1)
        x = (x*b)%mod;
    return x;
}
int main()
{
    ll base,power;
    while (scanf("%lld%lld",&base,&power)!=EOF)
    {
        ll ans = bigmod(base,power);
        if(ans==10){
            puts("00");
            continue;
        }
        if(ans<10){
            printf("0%lld\n",ans);
        }
        else
            cout << ans << endl;
    }
    return 0;
}
