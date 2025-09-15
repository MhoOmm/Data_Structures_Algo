class Solution {
public:
    typedef pair<int,int>pp;
    int M=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }
        int ans = 0 ;

        for(int count=1;count<=right;count++)//because indexed form 1 
        {
            auto p=pq.top();
            pq.pop();

            int sum=p.first;
            int idx=p.second;

            if(count>=left)
            {
                ans=(ans+sum)%M;
            }
            int newidx = idx+1;
            if(newidx<n)
            {
                int newsum=sum+nums[newidx];
                pq.push({newsum,newidx});
            }
        }

        return ans;

    }
};
