
// brute force Approach O(nlogn +n )
// extra space : temp array
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        vector<vector<int>>ans;
        for(int i=0;i<n;i+=3)
        {
            vector<int>temp;
            int min = nums[i];
            for(int j=i;j<3;j++)
            {
                if(nums[j]-min<=k && j<n)
                {
                    temp.push_back(nums[j]);
                }
            }
            
            ans.push_back(temp);
        }
        return ans;
    }
};



// better approach O(nlogn)
// no extra space 
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        vector<vector<int>>ans;
        for(int i=0;i<=n-3;i+=3)
        {   
            if(nums[i+2]-nums[i]>k)
            {
                return {};            
            }
            ans.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        return ans;
    }
};