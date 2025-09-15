#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int vertex,edge;
    cout<<"enter the vertex and edges";
    cin>>vertex>>edge;
    cout<<endl;

    //non weighted un directed

    // int u,v;
    // vector<vector<bool> >adj_mat(vertex,vector<bool>(vertex,0));

    // for(int i=0;i<edge;i++)
    // {
    //     cin>>u>>v;

    //     adj_mat[u][v]=1;
    //     adj_mat[v][u]=1;

    // }

    // for (int i=0;i<vertex;i++)
    // {
    //     for ( int j=0;j<vertex;j++)
    //     {
    //         cout<<adj_mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    //weighted undirected
    // int u,v,weight;
    // vector<vector<int> >adj_mat(vertex,vector<int>(vertex,0));

    // for(int i=0;i<edge;i++)
    // {
    //     cin>>u>>v>>weight;

    //     adj_mat[u][v]=weight;
    //     adj_mat[v][u]=weight;

    // }

    // for (int i=0;i<vertex;i++)
    // {
    //     for ( int j=0;j<vertex;j++)
    //     {
    //         cout<<adj_mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }



    // for directed unweighted graph
    int u,v,weight;
    vector<vector<bool> >adj_mat(vertex,vector<bool>(vertex,0));

    for(int i=0;i<edge;i++)
    {
        cin>>u>>v>>weight;

        adj_mat[u][v]=weight;
        adj_mat[v][u]=weight;

    }

    for (int i=0;i<vertex;i++)
    {
        for ( int j=0;j<vertex;j++)
        {
            cout<<adj_mat[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}