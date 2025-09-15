class Solution {
public:
    //steps
    //1. clear out all the previous elements for nums[i] to enter
    //2. clear out all the elemnt form the back if nums[i] is bigger
    //3. pushback nums[i]
    //4. as the window is closed i>=k-1 push back the front in result
    // we iterate till i>=k-1 kyunki uske baad se result milna chalu hota jata hai
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>result;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            while(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);
            if(i>=k-1)
            {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};