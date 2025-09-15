#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        vector<pair<int, pair<int, int>>> temp;
        for (int i = 0; i < K; i++) {
            temp.push_back(make_pair(arr[i][0], make_pair(i, 0)));
        }
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq(temp.begin(), temp.end());
        vector<int> ans;
        while (!pq.empty()) {
            auto ele = pq.top();
            pq.pop();
            ans.push_back(ele.first);
            int i = ele.second.first;
            int j = ele.second.second;
            if (j + 1 < arr[i].size()) {
                pq.push(make_pair(arr[i][j + 1], make_pair(i, j + 1)));
            }
        }
        return ans;
    }

int main() {
    vector<vector<int>> arr = {
        {1, 2, 4, 6},
        {2, 6, 10, 14},
        {3, 7, 11, 15},
        {4, 8, 12, 16},
        {17, 21, 25, 29},
        {18, 22, 26, 30},
        {19, 23, 27, 31}
    };
    int K = arr.size();
    vector<int> result = mergeKArrays(arr, K);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
