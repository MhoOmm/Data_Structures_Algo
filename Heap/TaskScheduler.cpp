class Solution {
public:
    int leastInterval(vector<char>& tasks, int p) {
        int n = tasks.size();

        vector<int>mp(26,0);
        for( char &ch:tasks)
        {
            mp[ch-'A']++;
        }

        priority_queue<int>pq;
        for(auto &i:mp)
        {
            if(i>0)
            {
                pq.push(i);
            }
        }


        int time = 0;
        while(!pq.empty())
        {
            vector<int>temp;
            for(int i=1;i<=p+1;i++)
            {
                if(!pq.empty())
                {
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }

            }
            for(int &i:temp)
            {
                if(i>0)
                {
                    pq.push(i);
                }
            }

            if(pq.empty())
            {
                time+=temp.size();
            }
            else{
                time+=p+1;
            }
        }

        return time;
    }
};