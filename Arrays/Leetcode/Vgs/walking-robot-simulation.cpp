class Solution {
public:
    // North -> 0,1
    // East -> 1,0
    // South -> 0,-1
    // West -> -1,0
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        // set to contain all the obstacles
        unordered_set<string>st;
        for(auto &obs:obstacles)
        {
            int x = obs[0];
            int y = obs[1];
            st.insert(to_string(x)+"_"+to_string(y));
        }
        // initial direction is north
        pair<int,int>dir = {0,1};
        int maxDist = 0;
        int x = 0;
        int y = 0;

        for(int i=0;i<n;i++)
        {
            if(commands[i]==-1)
            {
                // turn right
                dir = {dir.second,-dir.first};
            }
            else if(commands[i]==-2)
            {
                // turn left
                dir = {-dir.second,dir.first};
            }
            else{
                int step  = commands[i];
                for(int j=0;j<step;j++)
                {
                    int nx = x+dir.first;
                    int ny = y+dir.second;
                    string n_key = to_string(nx)+"_"+to_string(ny);
                    if(st.count(n_key))
                    {
                        break;
                    }
                    x = nx;
                    y = ny;
                }
                maxDist = max(maxDist,x*x + y*y);
            }
        }
        return maxDist;
    }
};