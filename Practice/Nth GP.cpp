#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>
#include<algorithm>
#include<set>
#include<string.h>
#include<iomanip>
using namespace std;

class Solution {
    vector<string> result;
public:

    double solve(double second, double third, int n) {
        double r = (third / second);
        double a = (second / r);

        return (a*pow(r, n-1));
    }
};

int main()
{

    int n = 4;

    Solution S;
    double result = S.solve(1, 2, 4);
    cout << fixed;
    cout <<setprecision(1);
    cout<<result<<endl;

    return 0;
}
