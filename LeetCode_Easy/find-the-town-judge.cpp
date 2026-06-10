// Using two inDeg and OutDeg arrays
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>inDeg(n+1,0);
        vector<int>outDeg(n+1,0);
        for(auto &edge:trust)
        {
            int u = edge[0];
            int v = edge[1];
            inDeg[v]++;
            outDeg[u]++;
        }
        int ans = -1;
        for(int i=1;i<=n;i++)
        {
            if(outDeg[i]==0 && inDeg[i]==n-1)
            {
                ans = i;
            } 
        }

        return ans;
    }
};

// using a single array 
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>count(n+1,0);
        for(auto &edge:trust)
        {
            int u = edge[0];
            int v = edge[1];
            count[v]++;
            count[u]--;
        }
        int ans = -1;
        for(int i=1;i<=n;i++)
        {
            if(count[i]==n-1)
            {
                ans = i;
            } 
        }

        return ans;
    }
};
