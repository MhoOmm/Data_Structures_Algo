// brute force approach O(N^3)
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int result =0;

        for(int i = 0;i<n;i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for(int j =0;j<n;j++)
            {
               if(i == j) continue;
               int x2 = points[j][0];
               int y2 = points[j][1];

               if(x2>=x1 && y2<=y1)
               {
                bool flag = false;
                for(int k = 0;k<n;k++)
                {
                    if(k==i || k==j)continue;

                    int x3 = points[k][0];
                    int y3 = points[k][1];

                    if(x3>=x1 && x3<=x2 && y3>=y2 && y3<=y1)
                    {
                        flag = true;
                    }
                }

                if(flag == false)
                {
                    result++;
                }
               }
            }
        }

        return result;

    }
};



// Optimised approach O(N^2)


class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int result =0;
        sort(begin(points),end(points),[](vector<int>p1,vector<int>p2){
            if(p1[0] == p2[0])
            {
                return p1[1]>p2[1];
            }

            return p2[0]>p1[0];
        });

        for(int i = 0;i<n;i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int mxY = INT_MIN;
            for(int j =i+1;j<n;j++)
            {
               
               int x2 = points[j][0];
               int y2 = points[j][1];
               if(y2>y1) continue;

               if (y2>mxY)
               {
                result++;
                mxY = y2;
               }
            }
        }

        return result;

    }
};