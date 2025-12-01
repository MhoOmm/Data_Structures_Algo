// Good Question
class Solution {
public:
    int m ;
    typedef long long ll;

    bool canSurv(ll mid,int n,vector<int>& batt){
        ll runtime = mid*n;
        ll sum = 0;

        for(int i =0;i<m;i++)
        {
            sum+= min(mid,(ll)batt[i]); 

            if(sum>=runtime)
            {
                return true;
            }
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batt) {

        m = batt.size();
        ll sum = accumulate(batt.begin(),batt.end(),0LL);
        ll l = *min_element(batt.begin(),batt.end());
        ll r = sum/n;

        ll result = 0;

        while(l<=r)
        {
            ll mid = l+(r-l)/2;

            if(canSurv(mid,n,batt))
            {
                result  = mid;
                l  = mid+1;
            }else{
                r = mid-1;
            }

        }

        return result;

    }
};