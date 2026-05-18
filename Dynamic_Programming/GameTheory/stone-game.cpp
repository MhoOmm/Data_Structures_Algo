class Solution {
public:
    int n;
    int t[2][501][501];
    int solve(int i,int j,int person,vector<int>& piles){ // return the max alice can have
        if(i>j){
            return 0;
        }
        if(t[person][i][j]!=-1)
        {
            return t[person][i][j];
        }
        int result = person==0?-1:INT_MAX;

        // alice
        if(person==0){
            result = max(piles[i]+solve(i+1,j,1,piles),piles[j]+solve(i,j-1,1,piles));
        }
        // bob
        else{
            result = min(solve(i+1,j,0,piles),solve(i,j-1,0,piles));
        }

        return t[person][i][j] = result;
    }
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        memset(t,-1,sizeof(t));
        int total = accumulate(piles.begin(),piles.end(),0);
        int aliceTake = solve(0,n-1,0,piles);
        return aliceTake > total-aliceTake; // compare between alice and bob
    }
};

// troll solution 
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};