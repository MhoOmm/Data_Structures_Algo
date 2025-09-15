class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quant) {
        int size=quant.size( );
        int start=1;
        int finish=*max_element(begin(quant),end(quant));
        int result=1;
        while(start<=finish)
        {
            int mid= start+(finish-start)/2;

            long long  total = 0;
            for (int q : quant) {
                total += (q + mid - 1) / mid;
            }
            if(total<=n)
            {
                result=mid;
                finish=mid-1;
                
            }else{
                start=mid+1;
            }
        }

        return result;
    }
};