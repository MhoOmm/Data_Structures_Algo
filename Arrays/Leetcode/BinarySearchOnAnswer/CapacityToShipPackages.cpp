class Solution {
public:
    int solve(int mid, vector<int>& we) {
        int daycount = 1;
        int currLoad = 0;

        for (int w : we) {
            if (currLoad + w > mid) {
                daycount++;
                currLoad = 0;
            }
            currLoad += w;
        }
        return daycount;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int start=*max_element(begin(weights),end(weights));
        int finish=accumulate(begin(weights), end(weights), 0);
        int n=weights.size();
        if(n < days)
            return -1;
        
        if(days == 1)
            return finish;
        
        while(start<finish)
        {
            int mid=start+(finish-start)/2;
            if(solve(mid,weights)<=days)
            {   
                finish=mid;
            }else{
                start=mid+1;
            }
        }
        return finish;
    }
};