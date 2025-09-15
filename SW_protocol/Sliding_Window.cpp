#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

long long int findsubarray(vector<long long int>&arr, int n)
{
    long long int total= 0;

    //initialize an unordered map by 0 ka value is 1 

    unordered_map<long long int, long long int>m;
    long long int prefix_sum=0;

    m[0]=1;
    for (int i =0;i<n;i++)
    {
        prefix_sum+=arr[i];
        if (m.count(prefix_sum))
        {
            total+=m[prefix_sum];
            m[prefix_sum]++;
        }
        else{
            m[prefix_sum]=1;
        }

    }
    return total;
}

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
            int rem= prefix_sum-k;
            if (m.count(rem))
            {
                total+=m[rem];
                m[prefix_sum]++;
            }
            else{
                m[prefix_sum]++;
            }
        }

        return total;
    }
};




int main()
{
    
    return 0;
}