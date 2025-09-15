// hella slow solution
#include <vector>
#include <algorithm> 

class Solution {
public:
    int maxCount(std::vector<int>& arr, int n, int maxSum) {
        int ans = 0;
        int count=0;

        for (int i = 1; i <= n; i++) {
            if (find(arr.begin(), arr.end(), i) == arr.end()) { // not in array
                if (ans + i > maxSum) {
                    break;
                }
                ans=ans+i;
                count++;
            }
        }

        return count;
    }
};


// optimised :using set

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>st(begin(banned),end(banned));
        int sum = 0;
        int count = 0;
        for(int i= 1;i<=n;i++)
        {
            if(st.count(i)){
                continue;
            }
            if(sum+i<=maxSum)
            {
                count++;
                sum+=i;
            }else{
                break;
            }
        }

        return count;
    }
};