// recursion + Memoization
class Solution {
public:
    int n;
    int shelfw;
    int totalH = 0;
    unordered_map<string,int>mp;
    int solve(int i,int height,int remWidth,vector<vector<int>>& books)
    {
        if(i==n)
        {
            // no more books
            return height;
        }
        string key = to_string(i)+"_"+to_string(height)+"_"+to_string(remWidth);
        if(mp.find(key)!=mp.end())
        {
            return mp[key];
        }
        int bheight = books[i][1];
        int bwidth = books[i][0];

        int take = INT_MAX;
        if(bwidth <= remWidth){
            take =  solve(i+1, max(height, bheight), remWidth - bwidth, books);
        }
        int nextShelf = height + solve(i+1,bheight,shelfw-bwidth,books);

        return mp[key] = min(take,nextShelf); 
        
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        shelfw = shelfWidth;
        return solve(0,0,shelfWidth,books);
    }
};


// since the height is answer in the problem and we have to minimize it we can simply 
// ignore it in the dp state
class Solution {
public:
    int n;
    int shelfw;
    int totalH = 0;
    int t[1001][1001];
    int solve(int i,int height,int remWidth,vector<vector<int>>& books)
    {
        if(i==n)
        {
            // no more books
            return height;
        }
        if(t[i][remWidth]!=-1)
        {
            return t[i][remWidth];  
        }
        int bheight = books[i][1];
        int bwidth = books[i][0];

        int take = INT_MAX;
        if(bwidth <= remWidth){
            take =  solve(i+1, max(height, bheight), remWidth - bwidth, books);
        }
        int nextShelf = height + solve(i+1,bheight,shelfw-bwidth,books);

        return t[i][remWidth] = min(take,nextShelf); 
        
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        shelfw = shelfWidth;
        memset(t,-1,sizeof(t));
        return solve(0,0,shelfWidth,books);
    }
};