class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<array<int,3>>tasksort;
        for(int i=0;i<n;i++)
        {
            int start=tasks[i][0];
            int process=tasks[i][1];

            tasksort.push_back({start,process,i});
        }

        // sort the tasks 
        sort(begin(tasksort),end(tasksort));
        vector<int>result;

        long long  curr = 0;
        int idx  = 0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;

        while(idx<n || !pq.empty())
        {
            if(pq.empty() && curr<tasksort[idx][0]){// first task ka curr time daa rhe
                curr=tasksort[idx][0];
            }

            while(idx<n && tasksort[idx][0]<=curr )//jo jo curr se pehle aa chuke hai pq mein daaldo 
            {
                pq.push({tasksort[idx][1],tasksort[idx][2]});
                idx++;
            }

            pair<int,int>curr_task=pq.top();
            pq.pop();

            curr+=curr_task.first;
            result.push_back(curr_task.second);
        }

        return result;
    }
};