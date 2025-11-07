#include<iostream>
using namespace std;
#include<vector>

vector<vector<int>> solve(vector<int>&nums, int target)
{
    int n = nums.size();

    vector<vector<int>>ans;

    for(int idx = 0;idx < n;idx++)
    {
        int n1 = nums[idx];
        int i= idx+1;
        int j= n-1;

        while(i<j)
        {
            if(nums[i]+nums[j] > target-n1)
            {
                j--;
            }else if(nums[i]+nums[j]<target-n1)
            {
                i++;
            }else{
                ans.push_back({n1,nums[i],nums[j]});
                i++;
                j--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {0,1,2,3,4,5,6,7}; 
    int target;
    cout<<"Enter the target";
    cin>>target;

    vector<vector<int>>ans = solve(arr,target);

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}