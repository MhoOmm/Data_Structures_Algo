#include<iostream>
using namespace std;
#include <vector>
#include<unordered_map>

// count subarray sum divisible by k
class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        int total= 0;
        int prefix_sum=0;

        unordered_map<int,int>m;
        m[0]=1;

        for(int i=0;i<arr.size();i++)
        {
            prefix_sum+=arr[i];
            int rem= prefix_sum%k;

            if (rem<0)
            {
                rem+=k;
            }
            if (m.count(rem))
            {
                total+=m[rem];
                m[rem]++;
            }
            else{
                m[rem]=1;
            }
        }

        return total;
    }
};


//subarray product less than k 

int numsubarrayproducT(vector<int>&nums, int k)
{
    int product=1,start=0,end=0;
    int n= nums.size();
    int count=0;
    while (end<n)
    {
        product*=nums[end];

        while( product>=k && start<=end)
        {
            product/=nums[start];
            start++;
        }
        count+=(end-start)+1;
        end++;
    }

    return count;
}

//hw
// count subarrays with score less than k

 long long countSubarrays(vector<int>& nums, long long k)
    
    {

        long long count=0,start=0,end=0,ans=1,sum=0;

        long long n=nums.size();

        while(end<n)
        {
            sum+=nums[end];
            ans = sum * ( ( end-start)+1);

            while (ans >= k && start<=end)
            {
                sum-=nums[start];
                start++;
                ans= sum*( ( end-start)+1);
            }

            count+= ( end-start)+1;
            end++;
        }

        return count;
        
    }

//hw
// number of subarrays having sum less than k
int numsubarrasum_lessthan_k(vector<int>&nums, int k)
{
    int sum=0,start=0,end=0;
    int n= nums.size();
    int count=0;
    while (end<n)
    {
        sum+=nums[end];

        while( sum >=k && start<=end)
        {
            sum-=nums[start];
            start++;
        }
        count+=(end-start)+1;
        end++;
    }

    return count;
}



int main()
{
    
    return 0;
}