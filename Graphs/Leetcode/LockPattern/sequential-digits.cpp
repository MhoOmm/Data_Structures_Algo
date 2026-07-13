class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int>q;
        for(int i=1;i<=9;i++)
        {
            q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int size = q.size();
            while(size--)
            {
                int num = q.front();
                q.pop();
                // next sequential digit
                int last = num%10;
                num = num*10 + (last+1);
                if(last == 9)continue;
                if(num>high)
                {
                    break;
                }
                if(low<=num && num<=high)
                {
                    ans.push_back(num);
                }
                q.push(num);
            }
        }
        return ans;
    }
};