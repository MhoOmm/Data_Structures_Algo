// basic linear search approach - recurr+memo 
// TLE - O(n^2)
class Solution {
public:
    vector<vector<int>>t;
    int solve(vector<vector<int>>&jobs,int i,int currEnd)
    {
        if(i>=jobs.size())
        {
            return 0;//no profit
        }
        if(t[i][currEnd+1]!=-1) // currEnd+1 coz initially currEnd is -1
        {
            return t[i][currEnd+1];
        }
        int take =0;
        if(currEnd==-1 || jobs[i][0] >= jobs[currEnd][1])
        {
            take = jobs[i][2] + solve(jobs,i+1,i);
        }
        int skip = solve(jobs,i+1,currEnd);

        return t[i][currEnd+1] = max(take,skip);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>jobs;
        for(int i=0;i<n;i++)
        {
            jobs.push_back({
                startTime[i],
                endTime[i],
                profit[i]
            });
        }
        sort(jobs.begin(),jobs.end());
        t.assign(n,vector<int>(n+1,-1));
        return solve(jobs,0,-1);
    }
};

// binary search in the sorted jobs array - O(nlogn)

class Solution {
public:
    vector<int>t;
    int solve(vector<vector<int>>&jobs,int i)
    {
        if(i>=jobs.size())
        {
            return 0;//no profit
        }
        if(t[i]!=-1)
        {
            return t[i];
        }
        int skip = solve(jobs,i+1);
        int l = i+1;
        int r = jobs.size()-1;
        int nextJobidx = jobs.size();
        while(l<=r){
            int mid = l + (r-l)/2;
            if(jobs[mid][0]>=jobs[i][1])
            {
                nextJobidx = mid;
                r = mid-1; // apne level pe aana- itna bada mat socho   
            }else{
                l = mid+1; // further biggest profit element ke pass jane ki koshish 
            }
        }
        int take = jobs[i][2] + solve(jobs,nextJobidx);;
        return t[i] = max(take,skip);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>jobs;
        for(int i=0;i<n;i++)
        {
            jobs.push_back({
                startTime[i],
                endTime[i],
                profit[i]
            });
        }
        sort(jobs.begin(),jobs.end());
        t.assign(n,-1);
        return solve(jobs,0);
    }
};