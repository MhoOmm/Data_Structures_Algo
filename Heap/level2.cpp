#include<iostream>
using namespace std;
#include<queue>

//kth smallest element
//optimised method in o(nlogn) time

int kthsmallest(int arr[],int l ,int r, int k)
{
    priority_queue<int>p;
    for(int i= 0; i<k;i++)
    {
        p.push(arr[i]);
    }

    for( int i=k;i<=r;i++)
    {
        if (arr[i]<p.top())
        {
            p.pop();
            p.push(arr[i]);
        }
    }
    return p.top();
}

// kth largest element in the array 
// similar to previos problem::


int kthlargest(vector<int>&nums,int k)
{
    priority_queue<int>p;
    for(int i= 0; i<k;i++)
    {
        p.push(nums[i]);
    }

    for( int i=k;i<=nums.size();i++)
    {
        if (nums[i]>p.top())
        {
            p.pop();
            p.push(nums[i]);
        }
    }
    return p.top();
}

//kthe largest in a stream 

class kthlargest{
 public:
    priority_queue<int,vector<int>,greater<int>>p;
    int k;
    int minheap(vector<int>&nums,int k)
    {
        int K=k;
        priority_queue<int,vector<int>,greater<int>>p;
        for(int i= 0; i<K;i++)
        {
            p.push(nums[i]);
        }
    }
    vector<int> add(int n)
    {

        vector<int>ans;
        p.push(n);

        if (p.size()>k)
        {
            p.pop();
        }
        if (p.top())
        {
            ans.push_back(p.top());
        }
        return ans;
        
    }
    
};

int main()
{
}