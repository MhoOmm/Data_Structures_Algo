class Solution {
public:
    int last;
    unordered_map<int,int>mp;
    int t[2001][2001];
    bool solve(int csi,int pj,vector<int>&stones)
    {
        if(csi==(stones.size()-1))
        {
            return true;
        }
        if(t[csi][pj]!=-1)
        {
            return t[csi][pj];
        }
        bool result = false;
        // if im at currStone and have prevJump i can go 
        for(int i=(pj-1);i<=(pj+1);i++)
        {
            if(i>0)
            {
                int nj = stones[csi]+i;
                if(mp.find(nj)!=mp.end())
                {
                    result = result || solve(mp[nj],i,stones);
                }
            }
        }

        return t[csi][pj] = result;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        memset(t,-1,sizeof(t));
        for(int i =0;i<n;i++)
        {
            mp[stones[i]] = i;
        }
        if(stones[1]!=1)return false;
        return solve(1,1,stones);
    }
};