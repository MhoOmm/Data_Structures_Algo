// brute force approach O(N^2) 
class Solution {
public:
    int maxDistance(vector<int>& colors) {

        int n = colors.size();
        int maxCount = INT_MIN;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(colors[i]!=colors[j])
                {
                    int dist = abs(j-i);
                    maxCount= max(maxCount,dist);
                }
            }
        }

        return maxCount;
        
    }
};

// optmised approach (O(N))

class Solution {
public:
    int maxDistance(vector<int>& colors) {

        int n = colors.size();
        int maxLeft = INT_MIN;
        int maxRight = INT_MIN;
        // left iteration
        int i =0;
        int j = n-1;
        while(j>0)
        {
            if(colors[i]!=colors[j])
            {
                int dist = abs(j-i);
                maxLeft  = max(maxLeft,dist);
                break;
            }
            j--;
        }
        // right iteration

        j=n-1;
        i=0;
        while(i<n-1)
        {
            if(colors[i]!=colors[j])
            {
                int dist = abs(j-i);
                maxRight = max(maxRight,dist);
                break;
            }
            i++;
        }
        return max(maxLeft,maxRight);
        
    }
};