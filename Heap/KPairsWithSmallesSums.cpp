class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pp,vector<pp>>pq;

        int n = nums1.size();
        int m = nums2.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k)
                {
                    pq.push({sum,{i,j}});
                }else if(sum< pq.top().first)
                {
                    pq.pop();
                    pq.push({sum,{i,j}});
                }else{
                    break; // idhar hi bada hogya toh aage toh sab bade hain as sorted
                }
            }
        }

        vector<vector<int>>result;
        while(!pq.empty())
        {
            auto temp= pq.top();
            int ele1 = nums1[temp.second.first];
            int ele2 = nums2[temp.second.second];
            result.push_back({ele1,ele2});
            pq.pop();
        }

        return result;
    }
};

