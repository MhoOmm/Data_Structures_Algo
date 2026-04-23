// Brute force approach O(N^2)
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long>arr(n,0);

        for(int i=0;i<n;i++)
        {
            long long sum =0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && nums[i]==nums[j])
                {
                    sum+=abs(i-j);
                }
            }
            arr[i] = sum;
        }
        return arr;
    }
};

// Optimal Approach O(n) using map
class Solution {
public:
    typedef long long ll;
    vector<ll> distance(vector<int>& nums) {
        int n = nums.size();
        vector<ll>arr(n,0);
        unordered_map<int,ll>indexSum;
        unordered_map<int,ll>freqIndex;

        // left pass
        for(int i=0;i<n;i++)
        {
            ll numFreq = freqIndex[nums[i]];
            ll sumi = indexSum[nums[i]]; 
            arr[i] += (numFreq*i-sumi);
            freqIndex[nums[i]]+=1;
            indexSum[nums[i]]+=i;
        }
        freqIndex.clear();
        indexSum.clear();
        // right pass
        for(int i=n-1;i>=0;i--)
        {
            ll numFreq = freqIndex[nums[i]];
            ll sumi = indexSum[nums[i]]; 
            arr[i] += (sumi - numFreq*i);
            freqIndex[nums[i]]+=1;
            indexSum[nums[i]]+=i;
        }
        return arr;
    }
};

