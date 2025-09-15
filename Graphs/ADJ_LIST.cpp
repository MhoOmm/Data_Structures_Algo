#include<iostream>
#include<vector>
using namespace std;

int main()
{

    // //undirected unweighted graph
    // int vertex,edge;

    // cout<<"enter the vertex and edge\n";
    // cin>>vertex>>edge;

    // int u,v ;

    // vector<int>adj_list[vertex];

    // for(int i=0;i<edge;i++)
    // {
    //     cin>>u>>v;
    //     adj_list[u].push_back(v);
    //     adj_list[v].push_back(u);

    // }

    // //to print

    //  for(int i=0;i<vertex;i++)
    // {
    //     cout<<i<<"->";
    //     for ( int j=0;j<adj_list[i].size();j++)
    //     {
    //         cout<<adj_list[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //weighted graph undirected

     //undirected unweighted graph
    int vertex,edge;

    cout<<"enter the vertex and edge\n";
    cin>>vertex>>edge;

    int u,v,weight;

    vector<pair<int,int>>adj_list[vertex];

    for(int i=0;i<edge;i++)
    {
        cin>>u>>v>>weight;
        adj_list[u].push_back(make_pair(v,weight));
        adj_list[v].push_back(make_pair(u,weight));

    }

    //to print

     for(int i=0;i<vertex;i++)
    {
        cout<<i<<"->";
        for ( int j=0;j<adj_list[i].size();j++)
        {
            cout<<adj_list[i][j].first<<" "<<adj_list[i][j].second<<" " ;
        }
        cout<<endl;
    }  
    return 0;
}