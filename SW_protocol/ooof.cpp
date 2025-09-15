#include<iostream>
using namespace std;
#include <vector>
#include<unordered_map>


//minimum window substring

class Solution {
public:
    string minWindow(string s, string t) {

        int start=0,end=0,ans=INT16_MAX,index=-1;
        int total=t.size();

        vector<int>m(256,0);
        for(int i=0;i<t.size();i++)
        {
            m[t[i]]++;
        }
        while( end<s.size() )
        {
            m[s[end]]--;
            if ( m[s[end]]  >= 0)
            {
                total--;
            }
            while( !total && start<=end)
            {
                if ( ans > (end-start)+1)
                {
                    ans=end-start+1;
                    index=start;
                }
                m[s[start]]++;
                if(m[s[start]]>0)
                {
                    total++; 
                }

                 start++;
            }

            end++;
        }

        if(index == -1)
        {
            return "";
        }
        string str="";

        for(int i=index;i<index+ans;i++)
        {
            str+=s[i];
        }

        return str;

        
    }
};

//length of longest subarray with atmost k frequency

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int start=0,end=0,len=0;

        unordered_map<int,int>count;

        while(end<nums.size())
        {
            count[nums[end]]++;
            while (count[nums[end]]>k && start<=end)
            {
                count[nums[start]]--;
                start++;
            }
            len=max(len,end-start+1);
            end++;
        }
        return len;
    }
    
};

//count subarray where max element appear at least k times
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int start=0,end=0,count=0,max_ele=0;
        long long total=0;
        int n=nums.size();

        for( int i=0;i<n;i++)
        {
            max_ele=max(max_ele,nums[i]);
        }

        while(end<n)
        {
            if (nums[end]==max_ele)
            {
                count++;
            }
            while (count==k)
            {
                total+=n-end;
                if ( nums[start]==max_ele)
                {
                    count--;
                }
                start++;
            }
            end++;
           
        }
        return total;
    }
    
};


// subarray with k diffrent integers

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int total=0;
        unordered_map<int,int>freq;
        int start =0,end=0,count=0,n=nums.size();
        while (end<n)
        {
            freq[nums[end]]++;

            if (freq[nums[end]]==1)
            {
                count++;
            }

            while(count==k)
            {
                total+=n-end;
                freq[nums[start]]--;
                if (freq[nums[start]]==0)
                {
                    count--;
                }
                start++;
            }

            end++;
        }

        start=0,end=0,count=0;
        freq.clear();
        k++;

        while (end<n)
        {
            freq[nums[end]]++;

            if (freq[nums[end]]==1)
            {
                count++;
            }

            while(count==k)
            {
                total-=n-end;
                freq[nums[start]]--;
                if (freq[nums[start]]==0)
                {
                    count--;
                }
                start++;
            }

            end++;
        }

        return total;
    }
};





int main()
{
    
    return 0;
}