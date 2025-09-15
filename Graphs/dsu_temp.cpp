#include<iostream>
using namespace std;
#include<vector>


class dsu
{
    public:
    vector<int>parent;
    vector<int>size;
    vector<int>rank;

    // path compressed find function 
    int find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=find(parent[x]);

    }

    // union by rank
    void union_rank(int x,int y)
    {
        int  px=find(x);
        int py=find(y);
        if(px==py)
        {
            return;

        }
        if(rank[px]>rank[py])
        {
            parent[py]=px;
        }
        else if(rank[px]<rank[py])
        {
            parent[px]=py;
        }
        else{
            parent[px]=py;
            rank[py]++;
        }


    }

    // union by size
    void union_size(int x,int y)
    {
        int  px=find(x);
        int py=find(y);
        if(px==py)
        {
            return;

        }
        if(rank[px]>rank[py])
        {
            parent[py]=px;
            size[px]+=size[py];
        }
        else if(rank[px]<rank[py])
        {
            parent[px]=py;
            size[py]+=size[px];
        }
        else{
            parent[px]=py;
            size[py]+=size[px];
        }
    }

};