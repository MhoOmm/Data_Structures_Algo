int findLCA(int u,int v)
    {
        int du = depthNode[u];
        int dv = depthNode[v];
        if(du<dv)
        {
            swap(u,v);
            swap(du,dv);
        }
        if(du!=dv)
        {
            int diff = du-dv;
            u = findKth(u,diff);
        }
        if(u == v) return u;

        for(int j=cols-1;j>=0;j--)
        {
            if(ancestor[u][j]==-1)
            {
                continue;
            }
            // after they are at the same level
            if(ancestor[u][j]!=ancestor[v][j])
            {
                u = ancestor[u][j];
                v = ancestor[v][j];
            }
        }
        return ancestor[u][0];
    }