class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        int n=tasks.size();
        for(int i=0;i<n;i++)
        {
            mp[tasks[i]]++;
        }
        int result=0;
        for(auto &it:mp)
        {
            int count=it.second;
            if(count==1)
            {
                return -1;
            }
            if(count%3==0)
            {
                result+=count/3;
            }else{
                result+=count/3+1;
            }

        }
        return result;
        
    }
};