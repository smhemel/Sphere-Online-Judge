//
//  main.cpp
//  SOPJ NKTEAM - Team Selection
//
//  Created by S M HEMEL on 29/7/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
#define N 500011
using namespace std;
int a[N],b[N],c[N];
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
    int n,x,cnt = 0;
    cin >> n;
    long long int total_position = n*3LL;
    if(total_position&1)
        total_position = total_position/2+1;
    else
        total_position /= 2;
    
    for(int i=1; i<=n; i++){
        read(x);
        a[x] = i;
    }
    for(int i=1; i<=n; i++){
        read(x);
        b[x] = i;
    }
    for(int i=1; i<=n; i++){
        read(x);
        position[x] = a[x]+b[x]+i;
    }
    sort(position+1,position+n+1);
    if(position[1]>=total_position){
        for(int i=1; i<=n; i++){
            if(position[1]!=position[i])
                break;
            else
                cnt++;
        }
        return 0 * printf("%d\n",cnt);
    }
    for(int i=1; i<=n; i++){
        if(position[i]>=total_position)
            break;
        else
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
