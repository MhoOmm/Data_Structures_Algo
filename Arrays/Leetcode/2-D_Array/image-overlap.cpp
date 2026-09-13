class Solution {
public:
    int overlap(vector<vector<int>>& img1, vector<vector<int>>& img2,int ro,int co)
    {
        int n = img1.size();
        // count in the overlapping region the number of ones
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int u = i + ro;
                int v = j + co;
                if(u<0 || u>=n || v<0 || v>=n)
                {
                    continue;
                }
                if(img1[i][j] == 1 && img2[u][v]==1)
                {
                    count++;
                }
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxCo = 0;
        for(int ro = -n+1;ro<n;ro++)
        {
            for(int co=-n+1;co<n;co++)
            {
                int count = overlap(img1,img2,ro,co);
                maxCo = max(maxCo,count);
            }
        }
        return maxCo;
    }
};