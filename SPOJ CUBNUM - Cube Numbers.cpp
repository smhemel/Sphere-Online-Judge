//
//  main.cpp
//  SPOJ - CUBNUM - Cube Numbers
//
//  Created by S M HEMEL on 14/8/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#define SIZE 100001
#define INF 1000000
using namespace std;
int cubeSum[SIZE], cubeNumber[46];
void findCubeNumbers(){
    for(int i=0; i<46; i++)
        cubeNumber[i] = pow((i+1),3);
}
void preCompute(){
    cubeSum[0] = 0;
    for(int i=1; i<SIZE; i++){
        cubeSum[i] = INF;
        for(int j=45; j>=0; j--){
            if(cubeNumber[j] > i)
                continue;
            cubeSum[i] = min(cubeSum[i], 1 + cubeSum[i - cubeNumber[j]]);
        }
    }
}
int main()
{
    findCubeNumbers();
    preCompute();
    int n, cas = 1;
    while(scanf("%d", &n) != EOF){
        printf("Case #%d: %d\n", cas++, cubeSum[n]);
    }
    return 0;
}
