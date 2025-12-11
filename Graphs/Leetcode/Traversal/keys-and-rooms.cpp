class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();
        queue<int>q;
        vector<int>visited(n,0);
        q.push(0);
        while(!q.empty())
        {
            int idx = q.front();
            q.pop();
            visited[idx] = true;

            for(int adj:rooms[idx])
            {
                if(!visited[adj])
                {
                    q.push(adj);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                return false;
            }
        }

        return true;
        
    }
};