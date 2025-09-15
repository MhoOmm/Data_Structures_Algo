class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) {
        int n=capacity.size();
        vector<int>diff(n,0);
        for(int i=0;i<n;i++)
        {
            diff[i]=capacity[i]-rocks[i];
        }
        sort(begin(diff),end(diff));
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(diff[i]==0)
            {
                count++;
            }else{
                if(ar>=diff[i])
                {
                    ar-=diff[i];
                    count++;
                }else{
                    break;
                }
            }
        }
        return count;
    }
};