class Solution {
public:
    typedef pair<int,int> pp;
    long long findScore(vector<int>& nums) {
        
        int n=nums.size();
        vector<bool>marked(n,false);
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        for(int i=0;i<n ;i++)
        {
            pq.push({nums[i],i});
        }

        long long sum=0;
        while(!pq.empty())
        {
            int idx=pq.top().second;
            int num=pq.top().first;
            pq.pop();
            if(!marked[idx])
            {
                sum+=num;
                marked[idx]=true;
                if(idx-1>=0 && !marked[idx-1])marked[idx-1]=true;
                if(idx+1<n && !marked[idx+1])marked[idx+1]=true;
            }
        }

        return sum;
    }
};
