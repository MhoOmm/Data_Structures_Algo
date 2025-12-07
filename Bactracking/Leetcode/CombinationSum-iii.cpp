class Solution {
public:

    void solve(int i,int n,int target,int k,vector<int>&curr,vector<vector<int>>&result){
        if(target<0 || curr.size()>k)
        {
            return;
        }

        if(target==0 && curr.size()==k)
        {
            result.push_back(curr);
            return;
        }

        for(int id=i+1;id<=n;id ++)
        {
            curr.push_back(id);
            solve(id,n,target-id,k,curr,result);
            curr.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int>curr;
        vector<vector<int>>result;
        int target  = n;

        if(k>n){
            return {};
        }
        solve(0,9,target,k,curr,result);

        return result;
    }
};