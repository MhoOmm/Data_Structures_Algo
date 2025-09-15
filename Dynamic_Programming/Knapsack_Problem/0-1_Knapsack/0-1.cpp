//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int t[1001][1001];
    int solve(int W, vector<int> &val, vector<int> &wt, int n){
        if(n == 0 || W == 0) {
            return 0;
        }
        if(t[W][n]!=-1)
        {
            return t[W][n];
        }
        

        if(wt[n-1] > W) {
            return t[W][n]=solve(W, val, wt, n-1);  
        }

        int take = val[n-1] + solve(W - wt[n-1], val, wt, n-1);
        int skip = solve(W, val, wt, n-1); 

        return t[W][n]=max(take, skip);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        memset(t,-1,sizeof(t));
        return solve(W, val, wt, n);
    }
};

// bottom up approach

class Solution {
  public:
    int knapsack(int w, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>>t(n+1,vector<int>(w+1));
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<w+1;j++)
            {
                if(i==0||j==0)
                {
                    t[i][j]=0;
                }
                else if(wt[i-1]>j)
                {
                    t[i][j]=t[i-1][j];
                }
                else if (wt[i-1]<=j){
                    
                    t[i][j]=max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
                }
            }
        }
        return t[n][w];
    }
};



//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}



// } Driver Code Ends