class Solution {
public:
    typedef pair<int,int> p;
    int solve(unordered_map<int,int>&mp, int x)
    {
        priority_queue<p,vector<p>,greater<p>>pq;
        for(auto &it:mp){
            int freq = it.second;
            int num = it.first;
            pq.push({freq,num});

            if(pq.size()>x)// through repeating this i will get the top  element
            {
                pq.pop();
            }
        }
        
        int sum = 0;
        while(!pq.empty())
        {
            auto[freq,num] =pq.top();
            pq.pop();
            sum+=num*freq; 
        }

        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n= nums.size();
        unordered_map<int,int>mp;
        int i = 0,j=0;

        vector<int>answer;
        while(j<n)
        {
          mp[nums[j]]++;
          if(k==j-i+1)
          {
            answer.push_back(solve(mp,x));
            mp[nums[i]]--;
            if(mp[nums[i]]==0)
            {
                mp.erase(nums[i]);
            }
            i++;
          }
          j++;
        }
        return answer; 
    }
};