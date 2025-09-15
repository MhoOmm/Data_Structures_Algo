//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends\

// top down approach

class Solution {
  public:
    int t[10001][201]; // Change to int

    bool solve(vector<int>& arr, int sum, int n) {
        if (sum == 0) return true;
        if (n == 0) return false;
        if (t[sum][n] != -1) return t[sum][n];

        if (arr[n - 1] > sum)
            return t[sum][n] = solve(arr, sum, n - 1);

        bool take = solve(arr, sum - arr[n - 1], n - 1);
        bool skip = solve(arr, sum, n - 1);

        return t[sum][n] = take || skip;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        memset(t, -1, sizeof(t)); // OK since t is now int
        return solve(arr, sum, n);
    }
};

// bottom up approach

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> t(sum + 1, vector<bool>(n + 1, false));

        
        for (int j = 0; j <= n; j++) {
            t[0][j] = true;
        }
        for (int i = 1; i <= sum; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[j - 1] > i) {
                    t[i][j] = t[i][j - 1];
                } else {
                    t[i][j] = t[i][j - 1] || t[i - arr[j - 1]][j - 1];
                }
            }
        }

        return t[sum][n];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends