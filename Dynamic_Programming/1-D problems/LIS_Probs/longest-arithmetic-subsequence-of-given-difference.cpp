// recursion + memo - giving memory limit exceeded
//  O(n^2) for both tc and sc coz we stroing both prev and i
class Solution {
public:
    vector<vector<int>>t;
    int solve(vector<int>&arr,int diff,int i,int prev)
    {
        if(i>=arr.size())
        {
            return 0;
        }
        if(t[i][prev+1] != -1)
        {
            return t[i][prev+1];
        }
        // take
        int take = 0;
        if(prev==-1  || arr[i]-arr[prev] == diff)
        {
            take = 1 + solve(arr,diff,i+1,i);
        }
        // skip
        int skip = solve(arr,diff,i+1,prev);

        return t[i][prev+1] = max(take,skip);
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        t.assign(n,vector<int>(n+1,-1));
        return solve(arr,difference,0,-1);
    }
};

// optmial approach -> use a map to store if i have seen this arr[i]-diff before
// if yes can i add to it make a bigger subsequence length
// map -> last element -> size of subsequence

class Solution {
public:
    // optimal solution 
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int>mp;
        int maxL = 1;
        for(auto &num:arr)
        {
            int prev = num-diff;
            if(mp.find(prev)!=mp.end())
            {
                mp[num] = mp[prev] + 1; // added to length
                maxL = max(maxL,mp[num]);
            }else{
                mp[num] = 1;
            }
        }

        return maxL;
    }
};