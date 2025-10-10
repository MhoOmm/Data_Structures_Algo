// Recursion + Memoization
class Solution {
public:
    int n;
    int solve(int i,int k,vector<int>&energy,vector<int>&t)
    {
        if(i>=n){
            return 0;
        }
        if(t[i]!=INT_MIN)
        {
            return t[i];
        }
        return t[i] =energy[i]+solve(i+k,k,energy,t);
    }
    int maximumEnergy(vector<int>& energy, int k) {

        n= energy.size();
        int maxE = INT_MIN;
        vector<int>t(n, INT_MIN);
        for(int i=0;i<n;i++)
        {
            int en  = solve(i,k,energy,t);
            maxE = max(maxE,en);
        }
        return maxE; 
    }
};


// Bottom up - Approach

// t[i] = maximum energy if we start from the index i
// therefor filling from right to left

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {

        int n = energy.size();
        vector<int>t(n,INT_MIN);

        for(int i=n-1;i>=0;i--)
        {
            if(i+k <n)t[i] = t[i+k]+energy[i];
            else t[i] = energy[i]; 
        }

        return *max_element(t.begin(),t.end());
        
    }
};