class Solution {
public:
    vector<vector<int>>directions{{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        if(image[sr][sc] == color)return image;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int parColor=image[sr][sc] ;
        image[sr][sc] = color;

        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(auto &dir:directions)
            {
                int ni = i+dir[0];
                int nj = j+dir[1];

                if(ni>=0 && nj>=0 && ni<m && nj<n && (image[ni][nj] == parColor))
                {
                    image[ni][nj] = color;
                    q.push({ni,nj});
                }
            }
        }
        return image;
    }
};