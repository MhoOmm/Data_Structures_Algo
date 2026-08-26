class Solution {
public:
    //this is a function for alice 
    // turns -> alice-1,bob-0
    int n;
    int t[2][101][101];
    int solve(int person,int idx,int m,vector<int>&piles)
    {
        if(idx >= n)
        {
            return 0;
        }
        if(t[person][idx][m]!=-1)
        {
            return t[person][idx][m];
        }
        int stones = 0;
        // for alice we have to maximise but for bob we have to minimise
        int result = person==1?-1:INT_MAX;
        for(int x =1;x <= min(2*m,n-idx);x++)
        {
            // prefix sum
            stones += piles[idx+x-1];
            if(person == 1)
            {
                result = max(result,stones+solve(0,idx+x,max(m,x),piles));
            }else{
                result = min(result,solve(1,idx+x,max(m,x),piles));
            }
        }
        return t[person][idx][m] = result;
    }
    int stoneGameII(vector<int>& piles) {
        memset(t,-1,sizeof(t));
        n = piles.size();
        // person,idx,m
        return solve(1,0,1,piles);
    }
};