// change nums inplace
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
    
        int i=0;
        int j=0;
        while(i<n)
        {
            if(nums[i]%2==0)
            {
                swap(nums[i],nums[j]);
                j++;
            }
            i++;
        }
        return nums;
    }
};

// custom comparator
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        auto comp = [](int a,int b){
            return (a%2)<(b%2);
        };
        sort(nums.begin(),nums.end(),comp);
        return nums;
    }
};

// explained comparator
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        auto comp = [](int a,int b){
            if((a%2==0 && b%2==0) ||(a%2!=0 && b%2!=0 )){
                return a<b;
            }
            return a%2==0; //checks if a is even then true and a<b otherwise b<a
        };
        sort(nums.begin(),nums.end(),comp);
        return nums;
    }
};