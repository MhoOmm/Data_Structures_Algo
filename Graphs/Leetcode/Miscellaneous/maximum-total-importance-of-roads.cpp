class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

        vector<int>degree(n,0);
        for(auto &road:roads){
            int u = road[0];
            int v = road[1];
            degree[u]++;
            degree[v]++;
        }

        sort(begin(degree),end(degree),greater<int>());

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += 1LL * degree[i] * (n - i);
        }

        return sum;
        
    }
};