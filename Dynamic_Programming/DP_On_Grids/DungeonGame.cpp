
//binary search on the answer

class Solution {
public:
    int m,n;
    unordered_map<string, bool> memo;

    bool cansurvive(int i, int j, int curr, vector<vector<int>>& dungeon) {
        if (i >= m || j >= n) return false;
        curr += dungeon[i][j];
        if (curr <= 0) return false;
        if (i == m - 1 && j == n - 1) return true;

        string key = to_string(i) + "," + to_string(j) + "," + to_string(curr);
        if (memo.count(key)) return memo[key];
        
        bool can = cansurvive(i, j + 1, curr, dungeon) || cansurvive(i + 1, j, curr, dungeon);

        memo[key]=can;
        return can;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        m=dungeon.size();
        n=dungeon[0].size();

        int start=1;
        int end=4*1e7;
        int result=end;

        while(start<=end)
        {
            int mid=start+(end-start)/2 ;
            memo.clear();

            if(cansurvive(0,0,mid,dungeon))
            {
                result=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        return result;
        
    }
};



// recursion and memo

class Solution {
public:
    int m,n;
    int t[201][201];
    int solve(int i,int j,vector<vector<int>>& dungeon)
    {
        if(i>=m||j>=n)
        {
            return 1e9;
        }
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        if(i==m-1 && j==n-1)
        {
           return t[i][j] = (dungeon[i][j] > 0 ? 1 : abs(dungeon[i][j]) + 1);
        }

        int right=solve(i,j+1,dungeon);
        int down=solve(i+1,j,dungeon);

        int need = min(right, down) - dungeon[i][j];
        return t[i][j] = max(1, need);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,dungeon); 
    }
};


//bottom up 
class Solution {
public:
    int m,n;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size();

        vector<vector<int>>t(m,vector<int>(n));

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 &&j==n-1){
                    if(dungeon[i][j]<=0)
                    {
                        t[i][j]=abs(dungeon[i][j])+1;
                    }
                    else{
                        t[i][j]=1;
                    }
                }else{
                    int right=(j+1>=n)?1e9:t[i][j+1];
                    int down=(i+1>=m)?1e9:t[i+1][j];
                    int result=min(down,right)-dungeon[i][j];

                    t[i][j]=(result>0?result:1);
                }
            }
        }
        
        return t[0][0]; 
    }
};
