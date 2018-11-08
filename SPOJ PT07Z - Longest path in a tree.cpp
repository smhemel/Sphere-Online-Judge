//
//  main.cpp
//  SPOJ PT07Z - Longest path in a tree
//
//  Created by S M HEMEL on 2/9/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
vector <int> v[10011];
int visit[1011],n,cnt[1011];
void dfs(int x){
    fill(visit, visit+n, 0);
    fill(cnt, cnt+n, 0);
    queue <int> q;
    q.push(x);
    cnt[x] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if(visit[u])
            continue;
        visit[u] = 1;
        for(auto z: v[u]){
            q.push(z);
            cnt[z] = cnt[u]+1;
        }
    }
}
int main()
{
    int x,y,Max = 0;
    scanf("%d",&n);
    for(int i=1; i<n; i++){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        //v[y].push_back(x);
    }
    for(int i=1; i<=n; i++){
        dfs(i);
        for(int l=1; l<=n; l++){
            if(Max<cnt[l])
                Max = cnt[l];
        }
    }
    printf("%d\n",Max);
    return 0;
}
