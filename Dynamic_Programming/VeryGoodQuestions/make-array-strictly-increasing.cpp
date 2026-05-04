class Solution {
public:
    map<pair<int,int>,int>mp;
    int solve(vector<int>& arr1, vector<int>& arr2,int i,int prev)
    {
        if(i>=arr1.size()){
            return 0; // no more operations
        }

        if(mp.find({i,prev})!=mp.end())
        {
            return mp[{i,prev}];
        }

        // take this and move further
        int op1 = 1e9;
        if(arr1[i]>prev)
        {
            op1 = solve(arr1,arr2,i+1,arr1[i]);
        }
        // isko change karke dekhte hain kya pata yhi dikkat dega
        int op2 = 1e9;
        auto it = upper_bound(arr2.begin(),arr2.end(),prev); // just isse bada lauta dega
        if(it!=arr2.end())
        {
            int j = it - arr2.begin();
            op2 = 1 + solve(arr1,arr2,i+1,arr2[j]);
        }
        return  mp[{i,prev}] = min(op1,op2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        mp.clear();
        int n = arr1.size();
        sort(arr2.begin(),arr2.end());
        int ans = solve(arr1,arr2,0,-1);
        return (ans>=1e9)?-1:ans;
    }
};