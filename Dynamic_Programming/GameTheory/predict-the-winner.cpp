class Solution {
public:
    int n ;
    // we try to maximize the winning of player 1 and minimize player 2
    // turn -> 0 player 1
    // turn -> 1 player 2
    int t[21][21][2];
    int solve(vector<int>&nums,int i,int j,int turn)
    {
        if(i>j)
        {
            return 0;
        }
        if(t[i][j][turn]!=-1)
        {
            return t[i][j][turn];
        }
        // for each player there are two options back or front
        int result = turn==0?-1:INT_MAX; // total points earned by player 1

        if(turn==0)
        {
            int front = nums[i]+solve(nums,i+1,j,1);
            int back = nums[j] + solve(nums,i,j-1,1);
            result = max(front,back);
        }else{ // player 1 turn -> we dont pick
            int front  = solve(nums,i+1,j,0);
            int back = solve(nums,i,j-1,0);
            result = min(front,back);
        }
        return t[i][j][turn] = result;
    }
    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        memset(t,-1,sizeof(t));
        int sum = accumulate(nums.begin(),nums.end(),0);
        return solve(nums,0,n-1,0) * 2 >= sum;
    }
};