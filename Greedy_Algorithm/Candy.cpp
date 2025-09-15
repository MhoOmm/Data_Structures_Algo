// O(2n) space
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>l2r(n,1);
        vector<int>r2l(n,1);

        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                l2r[i]=max(l2r[i],l2r[i-1]+1);
            }
        }

        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                r2l[i]=max(r2l[i],r2l[i+1]+1);
            }
        }
        int sum= 0;
        for(int i=0;i<n;i++)
        {
            sum+=max(l2r[i],r2l[i]);
        }

        return sum;
    }
};

// O(n) space
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>final(n,1);

        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                final[i]=max(final[i],final[i-1]+1);
            }
        }

        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                final[i]=max(final[i],final[i+1]+1);
            }
        }
        int sum= 0;
        for(int i=0;i<n;i++)
        {
            sum+=final[i];
        }

        return sum;
    }
};

// O(1) space

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n; 
        
        int i=1;
        while(i < n){
            
            if(ratings[i] == ratings[i-1]) {
                i++;
                continue;
            }
            
            //For increasing slope
            int peak = 0;
            while(ratings[i] > ratings [i-1]){
                peak++;
                candy += peak;
                i++;
                if(i == n) return candy;
            }
            
            //For decreasing slope
            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                valley++;
                candy += valley;
                i++;
            }
            candy -= min(peak, valley);
        }
        
        return candy;
    }
};