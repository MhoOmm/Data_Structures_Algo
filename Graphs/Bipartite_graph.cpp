#include<iostream>
#include <vector>
#include <queue>
using namespace std;


bool bipartite_graph(int v, vector<int>adj[])
{
    vector<int>colour(v,-1);
    queue<int>q;


    for(int j=0;j<v;j++)
    {

        if (colour[j]==-1)
        {
            q.push(j);
            colour[j]=0;

            while(!q.empty())
            {
                int node=q.front();
                q.pop();

                for (int i=0;i<adj[node].size();i++)
                 {
                    //not coloured

                    if (colour[adj[node][i]]==-1)
                    {
                        colour[adj[node][i]]=(colour[colour[node]]+1)%2;
                        q.push(adj[node][i]);
                    }

                    //colour assigned

                    else{
                         if (colour[node]== colour[adj[node][i]])
                            {
                                 return 0;
                            }
                        }
                    }

                return 1;

                }
        }
    }
}
int main()
{
    
    return 0;
}