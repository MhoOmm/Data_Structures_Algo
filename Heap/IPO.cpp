class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>>project(n);

        for(int i=0; i<n ;i++)
        {
            project[i]={capital[i],profits[i]};
        }
        int i=0;
        sort(begin(project),end(project));
        priority_queue<int>pq;// will store the profit in this
        int ans = 0;
        while(k--)
        {
            while(i<n && project[i].first<=w)
            {
                pq.push(project[i].second);
                i++;
            }
            if(pq.empty())
            {
                break;
            }
            int prof=pq.top();
            pq.pop();
            w+=prof;
        }

        return w;

    }
};