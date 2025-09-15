// approach 1
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(i==k||i==j||j==k)
                    {
                        continue;
                    }
                    int num=digits[i]*100+digits[j]*10+digits[k]*1;
                    if(num>=100 && num%2==0)
                    {
                        st.insert(num);
                    }
                }
            }
            
        }
        vector<int>ans(begin(st),end(st));
        sort(begin(ans),end(ans));

        return ans;
        
    }
};


//approach 2
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();
        vector<int>map(10,0);

        vector<int>result;

        for(int &digits:digits)
        {
            map[digits]++;
        }

        for(int i=1;i<=9;i++)
        {
            if(map[i]==0)continue;
            map[i]--;
            for(int j=0;j<=9;j++)
            {
                if(map[j]==0)continue;
                map[j]--;
                for(int k=0;k<=8;k+=2)
                {
                    if(map[k]==0)continue;
                    map[k]--;
                    int num=i*100+j*10+k;
                    result.push_back(num);
                    map[k]++;
                }
                map[j]++;
            }
            map[i]++;
        }
        return result;

    }
};