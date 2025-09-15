// sorting
class Solution {
public:
     
    long long maximumHappinessSum(vector<int>& happi, int k) {
        int n = happi.size();
        int count =0;
        sort(happi.begin(), happi.end(),greater<int>());
        long long  sum=0;
        for(int i=0;i<k;i++)
        {
            if(count>happi[i])
            {
                break;
            }
            sum+=happi[i]-count;
            count++;
        }

        return sum;
    }
};


// heap approach

class Solution {
public: 
    long long maximumHappinessSum(vector<int>& happi, int k) {
        int n = happi.size();
        int count =0;
        priority_queue<int>pq;
        long long  sum=0;
        for(int i=0;i<n;i++)
        {
            pq.push(happi[i]);
        }

        while(k>0)
        {
            long long temp=pq.top();
            if(count>temp)
            {
                break;
            }
            sum+= temp-count;
            pq.pop();
            count++;
            k--;
        }

        return sum;

    }
};