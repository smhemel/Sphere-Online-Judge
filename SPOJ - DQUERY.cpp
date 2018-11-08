//
//  main.cpp
//  SPOJ - DQUERY
//
//  Created by S M HEMEL on 2/8/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 311111
#define A 1111111
#define BLOCK 555 //sqrt(N)
using namespace std;
int cnt[A], a[N], ans[N], answer = 0;
struct Total_Query {
    int l,r,p;
}Query[N];
bool cmp(Total_Query x, Total_Query y) {
    if(x.l/BLOCK != y.l/BLOCK)
        return x.l/BLOCK < y.l/BLOCK;
    return x.r < y.r;
}
void add(int position) {
    cnt[a[position]]++;
    if(cnt[a[position]]==1)
        answer++;
}
void remove(int position) {
    cnt[a[position]]--;
    if(cnt[a[position]]==0)
        answer--;
}
int main() {
    int n,m;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d%d", &Query[i].l, &Query[i].r);
        Query[i].l--; Query[i].r--;
        Query[i].p = i;
    }
    sort(Query, Query+m, cmp);
    int current_left = 0, current_right = 0;
    for(int i=0; i<m; i++) {
        int left = Query[i].l, Right = Query[i].r;
        while(current_left < left) {
            remove(current_left);
            current_left++;
        }
        while(current_left > left) {
            add(current_left-1);
            current_left--;
        }
        while(current_right <= Right) {
            add(current_right);
            current_right++;
        }
        while(current_right > Right+1) {
            remove(current_right-1);
            current_right--;
        }
        ans[Query[i].p] = answer;
    }
    
    for(int i=0; i<m; i++)
        printf("%d\n", ans[i]);
    return 0;
}
