class Solution {
public:
    int n ;
    unordered_map<int,int>mp;

    int t[2001][2001];

    bool solve(int csi,int pj,vector<int>& stones)
    {
        if(csi==n-1)
        {
            return true;
        }

        if(t[csi][pj]!=-1)
        {
            return t[csi][pj];
        }

        bool result = false;

        for(int idx = pj-1;idx<=pj+1;idx++)
        {
            if(idx>0)
            {
                int nextst = stones[csi]+idx;
                if(mp.find(nextst)!=mp.end()){
                    result = result || solve(mp[nextst],idx,stones);
                }
            }
        }
        return t[csi][pj]=result;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();

        if(stones[1]!=1)return false;
        for(int i = 0;i<n;i++)
        {
            mp[stones[i]]=i;
        }
        memset(t,-1,sizeof(t));
        return solve(0,0,stones);
    }
};