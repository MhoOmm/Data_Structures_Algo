// time complexity of the program is O(V+2E)~TO O(V+E)
//space complexity of the program is O(v) in worst case

//code is for connected graph only 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> BFS_Graph(int v, vector<int>adj[])
{
    queue<int>q;
    vector<bool>visited(v,0);
    vector<int>ans;
    q.push(0);
    visited[0]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(int j=0;j<adj[node].size();j++)
        {
            if(!visited[adj[node][j]]);//agar 1 nhi hai toh
            {
                visited[adj[node][j]]=1;
                q.push(adj[node][j]);

            }
        }
    }
    return ans;

}
int main ()
{

}