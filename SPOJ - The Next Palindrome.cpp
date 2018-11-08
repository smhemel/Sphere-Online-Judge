//
//  main.cpp
//  SPOJ - The Next Palindrome
//
//  Created by S M HEMEL on 2/28/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[1000002];
int flag;
void find_palin()
{
    int len,t,tmp1;
    len = (int) strlen(s);
    flag = 1;
    for(int i=0; i<len; i++)
        if(s[i] != '9') {
            flag = 0;
            break;
        }
    if(flag==1)
    {
        s[0] = '1';
        for(int i=1; i<len; i++)
            s[i] = '0';
        s[len] = '1';
        s[len+1] = '\0';
        return ;
    }
    flag = 0;
    for(int i=0; i<len/2; i++)
    {
        if(s[i] < s[len-i-1])
            flag = -1;
        else if(s[i] > s[len-i-1])
            flag = 1;
        s[len-i-1] = s[i];
    }
    if(flag == -1 || flag==0)
    {
        t = 0;
        if(len%2 == 0)
            tmp1 = len/2-1;
        else
            tmp1 = len/2;
        while(s[tmp1-t] == '9')
        {
            s[tmp1-t] = '0';
            s[len-1-tmp1+t] = '0';
            t++;
        }
        s[tmp1-t]++;
        s[len-1-tmp1+t] = s[tmp1-t];
    }
    return ;
}
int main()
{
    int t;
    scanf("%d\n",&t);
    for(int i=0; i<t; i++)
    {
        gets(s);
        find_palin();
        printf("%s\n",s);
    }
    return 0;
}
