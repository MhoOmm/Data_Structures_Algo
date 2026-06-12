// simple but very confusing
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        if(source == target)
        {
            return 0;
        }
        unordered_map<int,vector<int>>mp;
        for(int bus=0;bus<n;bus++)
        {
            for(auto &stop:routes[bus])
            {
                mp[stop].push_back(bus);
            }
        }
        // push all bus who have the source
        queue<int>q;
        vector<bool>visited(501,false); // total 500 bus can be there
        for(auto &bus:mp[source])
        {
            q.push(bus);
            visited[bus] = true;
        }
        int numbus = 1;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int route = q.front();
                q.pop();
                for(auto&stop :routes[route])
                {
                    if(stop==target)
                    {
                        return numbus;
                    }
                    for(auto &nextRoute:mp[stop])
                    {
                        if(!visited[nextRoute])
                        {
                            visited[nextRoute] = true;
                            q.push(nextRoute);
                        }
                    }
                }
            }
            numbus++;
        }

        return -1;
    }
};