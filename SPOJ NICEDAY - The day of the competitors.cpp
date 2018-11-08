//
//  main.cpp
//  SOPJ NICEDAY - The Day of The Competitors
//
//  Created by S M HEMEL on 29/7/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>
#define N 100011
using namespace std;
int position[N];
template <typename T>
void read(T &x)
{
    char c;
    bool t=false;
    for(c=getchar(); (c<'0'||c>'9') && c!='-'; c=getchar());
    if(c=='-'){
        c = getchar();
        t = true;
    } x = c-'0';
    for(c=getchar(); c>='0'&&c<='9'; c=getchar())
        x=x*10+c-'0';
    if(t) x=-x;
}
int main()
{
    int n,x,test;
    read(test);
    while(test--)
    {
        cin >> n;
        int cnt = 0;
        long long int total_position = n*3LL;
        if(total_position&1)
            total_position = total_position/2+1;
        else
            total_position /= 2;
        
        for(int i=1; i<=n; i++){
            for(int l=0; l<3; l++){
                read(x);
                position[i] += x;
            }
        }
        sort(position+1,position+n+1);
        if(position[1]>=total_position){
            for(int i=1; i<=n; i++){
                if(position[1]!=position[i])
                    break;
                else
                    cnt++;
            }
            printf("%d\n",cnt);
        }
        else{
            for(int i=1; i<=n; i++){
                if(position[i]>=total_position)
                    break;
                else
                    cnt++;
            }
            cout << cnt << endl;
        }
        memset(position,0,sizeof(position));
    }
    return 0;
}

