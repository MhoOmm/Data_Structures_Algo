// 2 pass solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int count0=0;
        int count1=0;
        int count2=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                count0++;
            }else if(nums[i]==1)
            {
                count1++;
            }
            else{
                count2++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(count0>0)
            {
                nums[i]=0;
                count0--;
            }else if(count1>0)
            {
                nums[i]=1;
                count1--;
            }
            else if(count2>0){
                nums[i]=2;
                count2--;
            }
        }
    }
};
// dutch national flag
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        int j =0;
        int k = n-1;
        while(j<=k)
        {
            if(nums[j]==1)
            {
                j++; // no need of change
            }else if(nums[j]==2)
            {
                swap(nums[j],nums[k]);
                k--;//we are sure 2 is place correctly
            }
            else{// j is at 0
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }
    }
};
