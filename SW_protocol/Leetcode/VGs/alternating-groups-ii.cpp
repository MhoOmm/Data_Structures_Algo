// TLE = making a deque (O(k*n))
class Solution {
public:
    bool isGood(deque<int>&dq)
    {
        for(size_t i =0;i+1<dq.size();i++)
        {
            if(dq[i]==dq[i+1])
            {
                return false;
            }
        }
        return true;
    }
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int count =0;
        vector<int>copy=nums;
        // appending at the last k elements
        for(int i=0;i<k-1;i++)
        {
            copy.push_back(nums[i]);
        }
        int n = copy.size();
        deque<int>dq;
        while(j<n)
        {
            dq.push_back(copy[j]);
            while(j-i+1>k)
            {
                dq.pop_front();
                i++;
            }
            if(dq.size()==k && isGood(dq))
            {
                count++;
            }
            j++;
        }

        return count;
    }
};

// optimal approach O(n)


class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        int i = 0;
        int j = 1;
        int count =0;
        vector<int>copy=nums;
        // appending at the last k elements
        for(int i=0;i<k-1;i++)
        {
            copy.push_back(nums[i]);
        }
        int n = copy.size();
        while(j<n)
        {
            if(copy[j-1]==copy[j])
            {
                i=j;
                j++;
                continue;
            }
            if(j-i+1==k)
            {
                count++;
                i++;
            }
            j++;
        }

        return count;
    }
};
