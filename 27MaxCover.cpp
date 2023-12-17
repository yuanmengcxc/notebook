#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <algorithm>

bool Less(const pair<int, int>& kv1, const pair<int, int>& kv2)
{
    return kv1.first < kv2.first;
}

int main()
{
    // num of section
    int count = 0;
    cin >> count;

    // receive section
    vector<pair<int, int>> v;
    int first = 0;
    int second = 0;
    while (count--)
    {
        cin >> first >> second;
        v.push_back(make_pair(first, second));
    }

    sort(v.begin(), v.end(), Less);
    int max = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto x : v)
    {
        while ((!pq.empty()) && pq.top() <= x.first)
        {
            pq.pop();
        }

        pq.push(x.second);
        max = max > pq.size() ? max : pq.size();
    }

    cout << max << endl;
}