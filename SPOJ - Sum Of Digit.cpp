//
//  main.cpp
//  SPOJ - Sum Of Digit
//
//  Created by S M HEMEL on 11/1/18.
//  Copyright © 2018 Eastern University. All rights reserved.
//

#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
ll dp[20][180][2];
void getDigits(ll x, vector <int> &digit)
{
    while (x)
    {
        digit.push_back(x%10);
        x /= 10;
    }
}
long long digitSum(int idx, int sum, int tight,
                   vector <int> &digit)
{
    if (idx == -1)
        return sum;
    
    if (dp[idx][sum][tight] != -1 and tight != 1)
        return dp[idx][sum][tight];
    
    long long ret = 0;
    
    int k = (tight)? digit[idx] : 9;
    
    for (int i = 0; i <= k ; i++)
    {
        int newTight = (digit[idx] == i)? tight : 0;
        ret += digitSum(idx-1, sum+i, newTight, digit);
    }
    
    if (!tight)
        dp[idx][sum][tight] = ret;
    
    return ret;
}
ll rangeDigitSum(ll a, ll b)
{
    memset(dp, -1, sizeof(dp));
    
    vector<int> digitA;
    getDigits(a-1, digitA);
    
    long long ans1 = digitSum((int)digitA.size()-1, 0, 1, digitA);
    vector<int> digitB;
    getDigits(b, digitB);
    long long ans2 = digitSum((int)digitB.size()-1, 0, 1, digitB);
    
    return (ans2 - ans1);
}

int main()
{
    long long a,b;
    while(cin >> a >> b){
        if(a==-1 && b==-1) break;
        cout << rangeDigitSum(a, b) << endl;
    }
    return 0;
}
