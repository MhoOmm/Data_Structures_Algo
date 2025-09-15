class Solution {
public:
    int solve(int mid,vector<int>& price)
    {
        int k=1;
        int a=price[0];
        for(int i=0;i<price.size();i++)
        {
            if(price[i]-a>=mid)
            {
                k++;
                a=price[i];
            }
        }
        return k;
    }
    int maximumTastiness(vector<int>& price, int k) {
        int n=price.size();
        sort(begin(price),end(price));
        int start=0;
        int finish=price[n-1]-price[0];
        int result=0;
        while(start<=finish)
        {
            int mid=start+(finish-start)/2;
            if(solve(mid,price)>=k)
            {
                result=mid;
                start=mid+1;
            }
            else{
                finish=mid-1;
            }
        }
        return result ;
    }
};