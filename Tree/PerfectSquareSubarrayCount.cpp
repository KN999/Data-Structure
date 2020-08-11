#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<int> perfectSquareSet;

void intializePerfectSquareSet() {

    for (int i = 0; i < 1001; i++)
        perfectSquareSet.insert(i * i);
}

bool isPerfectSquare(int num) {

    return (perfectSquareSet.find(num) != perfectSquareSet.end());
}

int countPerfectSubarray(vector<int> arr) {

    int count = 0;
    int N = arr.size();
    vector<int> psum;
    psum.push_back(0);
    int csum = 0;

    for (int i = 0; i < N; i++)
    {
        csum += arr[i];
        psum.push_back(csum);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            int sum = psum[j] - psum[i];
            if (perfectSquareSet.find(sum) != perfectSquareSet.end())
                count++;
        }
    }

    return count;
}

int main() {

    intializePerfectSquareSet();

    vector<int> arr = {4,0,0,16};

    countPerfectSubarray(arr);

    return 0;
}
