// brute force O(n*k)
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int i =0;
        int j =k-1;
        if(k==1)
        {
            return nums;
        }
        vector<int>result;
        while(j<n)
        {
            int flag = true;
            int maxEle = 0;
            for(int m =i;m<j;m++)
            {
                if(nums[m]+1 != nums[m+1])
                {
                    flag = false;
                }
                maxEle = nums[m+1];
            }
            result.push_back(flag==true?maxEle:-1);
            i++;
            j++;
        }

        return result;
    }
};


// optimised approach O(n)

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int i =0;
        int j =1;
        if(k==1)
        {
            return nums;
        }
        vector<int>result;
        int consC =0;
        while(j<n)
        {
            if(nums[j]-1 == nums[j-1])
            {
                consC++;  
            }
            if(j-i+1 > k)
            {
                if (nums[i + 1] == nums[i] + 1)
                    consC--;
                i++;
            }

            if(j-i+1 ==k){
                result.push_back(consC==k-1? nums[j]:-1);
            }
            
            j++;
        }

        return result;
    }
};

