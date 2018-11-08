//
//  main.cpp
//  SPOJ - ADDREV - Adding Reversed Numbers
//
//  Created by S M HEMEL on 14/8/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
unsigned reverse(unsigned num){
    unsigned reversed = 0;
    while(num){
        reversed = reversed*10+num%10;
        num = num/10;
    }
    return reversed;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        unsigned num1,num2;
        scanf("%u %u",&num1,&num2);
        printf("%u\n",reverse(reverse(num1)+reverse(num2)));
    }
    return 0;
}
