// brute force - TLE 
class Solution {
public:
    int solve(vector<int>& energy,int i, int k)
    {
        if(i>=energy.size()){
            return 0;
        }
        return energy[i] + solve(energy,i+k,k);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int maxSum = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int sum = solve(energy,i,k);
            maxSum = max(sum,maxSum);
        }
        return maxSum;
    }
};
// Recursion + Memoization
class Solution {
public:
    vector<int>t;
    int solve(vector<int>& energy,int i, int k)
    {
        if(i>=energy.size()){
            return 0;
        }
        if(t[i]!=INT_MIN)
        {
            return t[i];
        }
        return t[i] =  energy[i] + solve(energy,i+k,k);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int maxSum = INT_MIN;
        for(int i=0;i<100001;i++)
        {
            t[i]=INT_MIN;
        }
        for(int i=0;i<n;i++)
        {
            int sum = solve(energy,i,k);
            maxSum = max(sum,maxSum);
        }
        return maxSum;
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