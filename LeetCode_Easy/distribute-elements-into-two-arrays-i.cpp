class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int numar1 = nums[0];
        int numar2 = nums[1];
        int i = 2;
        while (i < n) {
            if (numar1 > numar2) {
                arr1.push_back(nums[i]);
                numar1 = nums[i];
            } 
            else {
                arr2.push_back(nums[i]);
                numar2 = nums[i];
            }

            i++;
        }
        vector<int> result;
        for (int x : arr1){
            result.push_back(x);
        }
        for (int x : arr2){
            result.push_back(x);
        }
        return result;
    }
};