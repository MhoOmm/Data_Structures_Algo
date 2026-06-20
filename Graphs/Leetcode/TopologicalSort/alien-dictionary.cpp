class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n = words.size();
        vector<vector<int>>adj(26);
        vector<int>inDeg(26,0);
        vector<bool>present(26,false);
        for (auto &word : words) {
            for (char ch : word) {
                present[ch - 'a'] = true;
            }
        }
        
        // making the graph
        for(int i=1;i<n;i++)
        {
            string s1 = words[i-1];
            string s2 = words[i];
            bool found = false;
            int k = min(s1.length(),s2.length());
            for(int j=0;j<k;j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    inDeg[s2[j]-'a']++;
                    found = true;
                    break;
                }
            }
            if(!found && s1.size() > s2.size()) return "";
        }
        // topo sort
        queue<int>q;
        for(int i=0;i<26;i++)
        {
            if(present[i] && inDeg[i]==0)
            {
                q.push(i);
            }
        }
        string ans = "";
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans+=(node+'a');
            for(auto &neig:adj[node])
            {
                inDeg[neig]--;
                if(inDeg[neig]==0)
                {
                    q.push(neig);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (present[i]) cnt++;
        }

        if (ans.size() != cnt) return "";
        
        return ans;
    }
};