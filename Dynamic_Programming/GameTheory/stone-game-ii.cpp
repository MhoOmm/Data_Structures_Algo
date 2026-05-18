class Solution {
public:
    int n ;
    // 1 -> Alice
    // 0 -> Bob
    int t[2][101][101];
    int solveA(int person,int i,int m,vector<int>&piles)
    {
        if(i>=n)return 0;
        if(t[person][i][m]!=-1)
        {
            return t[person][i][m] ;
        }
        int result = person==1?-1:INT_MAX;
        int stones = 0;
        // Maximise for alice, minimise for bob
        for(int x=1;x<=min(2*m,n-i);x++)
        {
            stones += piles[i+x-1];
            if(person==1){// maximise
                result = max(result,stones+solveA(0,i+x,max(x,m),piles));
            }else{ // minimise
                result = min(result,solveA(1,i+x,max(x,m),piles));
            }
        }
        return t[person][i][m] = result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(t,-1,sizeof(t));
        return solveA(1,0,1,piles); 
    }
};