// tle (n^2)
class Solution {
public:
    int n;
    bool checkdiff(vector<int>& nums, vector<vector<int>>& queries,int k)
    {
        vector<int>diff(n,0);
        for(int i=0;i<=k;i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];
            int x=queries[i][2];
            diff[start]+=x;
            if(end+1<n)
            {
                diff[end+1]-=x;
            }    
        }
        // cumulative
        int val=0;
        for(int i=0;i<n;i++)
        {
            val+=diff[i];
            diff[i]=val;
            if(nums[i]-diff[i]>0)//not zero
            {
                return false;
            }
        }
        return true;

    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n=nums.size();
        int q=queries.size();
        int sum=0;
        for(int i =0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum==0)
        {
            return 0;
        }
    
        for(int i=0;i<q;i++)
        {
            if(checkdiff(nums,queries,i))
            {
                return i+1;
            }

        }
        return -1;

    }
};

// binary search on the index
class Solution {
public:
    int n;
    bool checkdiff(vector<int>& nums, vector<vector<int>>& queries,int k)
    {
        vector<int>diff(n,0);
        for(int i=0;i<=k;i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];
            int x=queries[i][2];
            diff[start]+=x;
            if(end+1<n)
            {
                diff[end+1]-=x;
            }    
        }
        // cumulative
        int val=0;
        for(int i=0;i<n;i++)
        {
            val+=diff[i];
            diff[i]=val;
            if(nums[i]-diff[i]>0)//not zero
            {
                return false;
            }
        }
        return true;

    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n=nums.size();
        int q=queries.size();
        if(all_of(nums.begin(),nums.end(), [](int x) { return x == 0; }))
        {
            return 0;
        }
        int start=0;
        int end=q-1;
        int k=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(checkdiff(nums,queries,mid))
            {
                k=mid+1;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

    
        return k;

    }
};