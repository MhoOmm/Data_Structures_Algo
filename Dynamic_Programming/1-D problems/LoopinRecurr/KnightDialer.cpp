// Recurr + Memo
class Solution {
public:
    int M = 1e9+7;
    vector<vector<int>>adj={
        {4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}
    };

    int t[5001][10];

    int solve(int n,int i)
    {
        if(n==0)return 1;

        int ways=0;
        if(t[n][i]!=-1)
        {
           return t[n][i];
        }

        for(auto &next:adj[i])
        {
           ways = (ways + solve(n-1,next))%M;
        }

        return t[n][i]=ways;
    }
    int knightDialer(int n) {
        int result = 0;
        memset(t,-1,sizeof(t));
        for(int cell = 0;cell<10;cell++ )
        {
            result= (result+solve(n-1,cell))%M;
        }

        return result;
        
    }
};


// Bottom Up

class Solution {
public:
    int M = 1e9+7;
    vector<vector<int>>adj={
        {4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}
    };
    int knightDialer(int n) {

        int result  =0;
        vector<vector<int>>t(n+1,vector<int>(11,0));
        for(int cell = 0;cell<10;cell++ )
        {
            t[0][cell]=1;
        }

        for(int i=1;i<n;i++)
        {
            for(int count=0;count<10;count++)
            {
                int ways = 0;
                for(int next:adj[count]){
                    ways = (ways+t[i-1][next])%M;
                }
                t[i][count]=ways;
            }
        }

        for(int cell = 0; cell <= 9; cell++) {
            result = (result + t[n-1][cell]) % M;
        }

        return result;
        
    }
};