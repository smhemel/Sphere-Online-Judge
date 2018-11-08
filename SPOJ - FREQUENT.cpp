//
//  main.cpp
//  SPOJ - FREQUENT
//
//  Created by S M HEMEL on 12/8/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 1001111
using namespace std;
int arr[N],cnt[N];
struct quary {
    int l,r;
}Q[N];
bool cmp(quary x,quary y){
    if(x.l != x.l)
        return x.l < x.l;
    return x.r < x.r;
}
int ans;
void add(int n){
    cnt[n]++;
    cout << "add = " << n << endl;
    if(cnt[n]>ans)
        ans = cnt[n];
}
void remove(int n){
    cnt[n]--;
    cout << "remove = " << n << endl;
    if(cnt[n]>ans)
        ans = cnt[n];
}
void clear(){
    memset(cnt,0,sizeof(cnt));
    memset(Q,0,sizeof(Q));
    memset(arr,0,sizeof(arr));
}
int main()
{
    int n,q;
    while (scanf("%d",&n) && n)
    {
        scanf("%d",&q);
        for(int i=0; i<n; scanf("%d",&arr[i]), i++);
        for(int i=0; i<q; scanf("%d%d",&Q[i].l,&Q[i].r), i++);
        sort(Q,Q+q,cmp);
        int currentL = 0 , currentR = 0;
        for(int i=0; i<q; i++){
            int L = Q[i].l-1, R = Q[i].r-1;
            ans = 0;
            while(currentL<L){
                remove(arr[currentL]);
                currentL++;
            }
            while(currentL>L){
                add(arr[currentL]);
                currentL--;
            }
            while(currentR <= R){
                add(arr[currentR]);
                currentR++;
            }
            while(currentR>R+1){
                remove(arr[currentR-1]);
                currentR--;
            }
            printf("%d\n",ans);
        }
        clear();
    }
    return 0;
}
