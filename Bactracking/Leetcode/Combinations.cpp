class Solution {
public:
    void solve(int i,int n,int k,vector<vector<int>>&ans,vector<int>&curr){
        if(curr.size()==k)
        {
            ans.push_back(curr);
            return;
        }
        for(int idx=i;idx<=n;idx++)
        {
            curr.push_back(idx);
            solve(idx+1,n,k,ans,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>>ans;
        vector<int>curr;
        solve(1,n,k,ans,curr);
        return ans; 
    }
};