#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{

    set<int> perfectSquareSet;

    for (int i = 0; i < 1001; i++)
        perfectSquareSet.insert(i * i);

    int T;
    int t = 0;
    cin >> T;

    while (t <= T)
    {

        int count = 0;
        int N;
        cin >> N;

        vector<int> arr;
        int temp;

        for (int i = 0; i < N; i++)
        {
            cin >> temp;
            arr.push_back(temp);
        }

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
        cout << "Case #" << ++t << ": " << count << endl;
    }
}

// 5 1
// 2 1 4 53 1
