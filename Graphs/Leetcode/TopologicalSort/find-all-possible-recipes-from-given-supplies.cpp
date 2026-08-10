class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // recipe not in supplies-> ingredients 
        // this gives the dependency
        unordered_map<string,vector<int>>mp;
        unordered_set<string>st(supplies.begin(),supplies.end());
        int n = recipes.size();
        vector<int>inDeg(n,0);

        for(int i=0;i<n;i++)// in the recipe vector
        {
            for(auto &item:ingredients[i])
            {
                if(!st.count(item))
                {
                    mp[item].push_back(i);
                    inDeg[i]++;
                }
            }
        }
        // topo sort
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(inDeg[i]==0)
            {
                q.push(i);
            }
        }
        vector<string>ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(recipes[node]);
            for(auto &neig:mp[recipes[node]])
            {
                inDeg[neig]--;
                if(inDeg[neig]==0)
                {
                    q.push(neig);
                }
            }
        }
        return ans;
    }
};