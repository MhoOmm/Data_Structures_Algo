class Solution {
public:
    int n;
    bool candy(vector<int>& candies,int mid, long long k){
        long long count = 0;
        for(int i=0;i<n;i++)
        {
            count+=floor(candies[i]/mid);
        }
        return count>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        n=candies.size();
        int l=1;
        int r=*max_element(begin(candies),end(candies));
        int result=0;

        while(l<=r)
        {
            int mid=l+(r-l)/2;

            if(candy(candies,mid,k))
            {
                result=mid;
                l=mid+1;

            }else{
                r=mid-1;
            }
        }
        return result;
    }
};