//
//  main.cpp
//  SPOJ - NDIV - n-divisors
//
//  Created by S M HEMEL on 18/8/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int check[32000];
int prime[10000];
void shieve()
{
    for(int i=3; i<=180; i+=2)
        if(!check[i])
            for(int j=i*i; j<=32000; j+=i)
                check[j]=1;
    prime[0] = 2;
    int j=1;
    for(int i=3;i<=32000;i+=2)
        if(!check[i])
            prime[j++]=i;
}
int main()
{
    shieve();
    int a,b,n,temp,total,res=0,count,k;
    scanf("%d%d%d",&a,&b,&n);
    for(int i=a; i<=b; i++)
    {
        static_cast<void>(temp=i),static_cast<void>(total=1),k=0;
        for(int j=prime[k]; j*j<=temp; j=prime[++k]) {
            count=0;
            while(temp%j==0)
            {
                count++;
                temp/=j;
            }
            total *=count+1;
        }
        if(temp!=1)
            total <<= 1;
        if(total==n)
            res++;
    }
    printf("%d\n",res);
    return 0;
}
