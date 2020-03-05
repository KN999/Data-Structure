#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>
#include<algorithm>
#include<set>
#include<string.h>
#include<iomanip>
#include <stdio.h> 
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        map<char, int> m;
        int Max = 0;
        for (int i = 0, j = 0; j < s.size();)
        {
            m[s[j]]++;

            if (m.size() > k)
            {
                if (m[s[i]] == 1)
                    m.erase(s[i]);
                else
                    m[s[i]]--;
                i++;
            }

            Max = max(Max, j - i + 1);
            j++;
        }

        return Max;
    }
};

int main()
{
    string s = "djfaslfj";
    int k = 0;

    Solution S;
    int results = S.lengthOfLongestSubstringKDistinct(s, k);
    cout<<results<<endl;

    return 0;
}
