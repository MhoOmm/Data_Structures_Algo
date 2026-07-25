class Solution {
public:
    int maxProduct(int n) {
        string st = to_string(n);
        int len = st.length();
        int maxProd = INT_MIN;
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++){
                if(i!=j)
                {
                    int num1 = (st[i]-'0');
                    int num2 = (st[j]-'0');
                    maxProd = max(maxProd,(num1 * num2));
                }
            }   
        }
        return maxProd;
    }
};