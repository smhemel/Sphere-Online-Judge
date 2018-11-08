//
//  main.cpp
//  SPOJ - INVCNT - Inversion Count
//
//  Created by S M HEMEL on 16/8/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int arr[200011];
int main()
{
    int test,n;
    scanf("%d",&test);
    while (test--) {
        printf("\n");
        scanf("%d",&n);
        for(int i=0; i<n; scanf("%d",&arr[i]),i++);
        int cnt = 0;
        for(int i=0; i<n-1; i++){
            for(int k=i+1; k<n; k++){
                if(arr[i]>arr[k])
                    cnt++;
            }
        }
        printf("%d\n",cnt);
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
