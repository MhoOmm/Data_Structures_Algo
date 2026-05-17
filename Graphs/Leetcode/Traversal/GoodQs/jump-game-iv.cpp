class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        int step = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int node = q.front();
                q.pop();
                if(node==n-1)
                {
                    return step;
                }
                // plus one
                if(node+1>=0 && node+1<n && arr[node+1]!=-1)
                {
                    q.push(node+1);
                }
                // minus one
                if(node-1>=0 && node-1<n && arr[node-1]!=-1)
                {
                    q.push(node-1);
                }
                // all indexes with same arr[i]
                for(auto &num:mp[arr[node]])
                {
                    if(arr[num]!=-1)
                    {
                        q.push(num);
                    }
                }
                mp[arr[node]].clear();//clear the vector with index - can never use further
                arr[node]=-1;
            }

            step++;
        }

        return step;
    }
};