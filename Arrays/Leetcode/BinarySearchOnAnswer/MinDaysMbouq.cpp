class Solution {
public:
    int bouq(int mid,int k,vector<int>& bloom)
    {
        int m=0;
        int kcount=0;
        for(int i=0;i<bloom.size();i++)
        {
            if(bloom[i]<=mid)
            {
                kcount++;
            }
            else{
                kcount=0;
            }
            if(kcount==k)
            {
                m++;
                kcount=0;
            }
        }
        return m;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        
        int n=bloom.size(); 
        int start=0;
        int endp= *max_element(begin(bloom),end(bloom));
        int result=-1;
        while(start<=endp)
        {
            int mid=start+(endp-start)/2;

            if(bouq(mid,k,bloom)>=m)
            {
                result=mid;
                endp=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return result;
    }
};