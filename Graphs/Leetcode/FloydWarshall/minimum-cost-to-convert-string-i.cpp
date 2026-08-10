class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        int n = original.size();
        vector<vector<long long>>adj(26,vector<long long>(26,INT_MAX));

        // populating the adj matrix
        for (int i = 0; i < 26; i++) {
            adj[i][i] = 0;
        }
        for(int i=0;i<n;i++)
        {
            int s = original[i] - 'a';
            int t = changed[i] - 'a';
            adj[s][t] = min(adj[s][t], (long long)cost[i]);
        }

        // floyd warshall
        // for going via
        for(int k=0;k<26;k++)
        {
            // for going to every character
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        // getting the min cost for converting string
        long long ans = 0;
        for(int i=0;i<source.length();i++)
        {
            if(source[i]==target[i])
            {
                continue;
            }
            if(adj[source[i]-'a'][target[i]-'a']==INT_MAX)
            {
                return -1;
            }
            ans += adj[source[i]-'a'][target[i]-'a']; 
        }
        return ans;
    }
};