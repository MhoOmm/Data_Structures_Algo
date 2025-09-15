class Solution {
public:
    unordered_map<string,double>mp;
    double solve(int r,int c,int k,int n)
    {
        if(r<0||r>=n||c<0||c>=n)
        {
            return 0;//went out of bounds
        }
        if(k==0)
        {
            return 1;
        }
        string key=to_string(r)+"_"+to_string(c)+"_"+to_string(k);
        if(mp.find(key)!=mp.end())
        {
            return mp[key];
        }
        double result=solve(r-2,c+1,k-1,n)+solve(r-2,c-1,k-1,n)+solve(r-1,c+2,k-1,n)+solve(r-1,c-2,k-1,n)+solve(r+2,c+1,k-1,n)+solve(r+2,c-1,k-1,n)+solve(r+1,c+2,k-1,n)+solve(r+1,c-2,k-1,n);

        return mp[key]=double(result/8);
    }
    double knightProbability(int n, int k, int row, int column) {
        
        return solve(row,column,k,n);
    }
};