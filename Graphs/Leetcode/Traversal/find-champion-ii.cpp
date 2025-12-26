class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        vector<int>inDeg(n,0);
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            inDeg[v]++;
        }

        int count =0;
        int result =0;
        for(int i=0;i<n;i++)
        {
            if(inDeg[i]==0)
            {
                count++;
                result = i;
            }
        }

        return count>1?-1:result; 
    }
};