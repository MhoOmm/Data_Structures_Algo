class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        int n = recipes.size();
        unordered_map<string,vector<int>>adj;

        unordered_set<string>st(supplies.begin(),supplies.end());
        vector<int>inDeg(n,0);

        for(int i = 0;i<n;i++)
        {
            for(string &ing:ingredients[i])
            {
                if(!st.count(ing))
                {
                    adj[ing].push_back(i);
                    inDeg[i]++;
                }
            }
        }

        // kahn's algo 
        queue<int>q;
        vector<string>result;
        for(int i=0;i<n;i++)
        {
            if(inDeg[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int item = q.front();
            q.pop();
            string temp=recipes[item];
            result.push_back(temp);

            for(auto neig:adj[temp])
            {
                inDeg[neig]--;
                if(inDeg[neig]==0)
                {
                    q.push(neig);
                }
            }
        }
        return result;
    }
};