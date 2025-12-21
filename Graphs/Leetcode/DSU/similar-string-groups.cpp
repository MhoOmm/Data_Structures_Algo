// DSU approach
class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int i)
    {
        if(i==parent[i])
        {
            return i;
        }

        return parent[i] = find(parent[i]);
    }

    void Union(int x,int y)
    {
        int parx = find(x);
        int pary = find(y);

        if(parx==pary)
        {
            return ;
        }

        if(rank[parx]>rank[pary])
        {
            parent[pary] = parx;
        }
        else if(rank[pary]>rank[parx])
        {
            parent[parx] = pary;
        }
        else{
            parent[parx] = pary;
            rank[pary]++;
        }
    }

    bool similar(string &s1,string &s2)
    {
        int length = s1.length();
        int ns = 0;
        for(int i =0;i<length;i++)
        {
            if(s1[i]!=s2[i])
            {
                ns++;
            }
        }

        return ns==0 || ns==2;
    }
    int numSimilarGroups(vector<string>& strs) {

        int n = strs.size();
        int group =0;

        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i] = 0;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(similar(strs[i],strs[j]))
                {
                    Union(i,j);
                }
            }
        }

        for(int i =0;i<n;i++)
        {
            if(parent[i]==i)
            {
                group++;
            }
        }

        return group;
    }
};

// Dfs approach

class Solution {
 public:
  bool similar(string &s1, string &s2) {
    int length = s1.length();
    int count = 0;
    for (int i = 0; i < length; i++) {
      if (s1[i] != s2[i]) {
        count++;
      }
    }

    return count == 0 || count == 2;
  }

  void dfs(vector<vector<int>>&adj,int i,vector<int>&visited)
  {
    visited[i]=true;
    for(int neig:adj[i])
    {
        if(!visited[neig])
        {
            dfs(adj,neig,visited);
        }
    }
  }
  int numSimilarGroups(vector<string> &strs) {
    int n = strs.size();

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (similar(strs[i], strs[j])) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

    int group = 0;
    vector<int> visited(n, false);

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        group++;
        dfs(adj,i,visited);
      }
    }

    return group;
  }
};

// Bfs Approach

class Solution {
 public:
  bool similar(string &s1, string &s2) {
    int length = s1.length();
    int count = 0;
    for (int i = 0; i < length; i++) {
      if (s1[i] != s2[i]) {
        count++;
      }
    }

    return count == 0 || count == 2;
  }
  int numSimilarGroups(vector<string> &strs) {
    int n = strs.size();

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (similar(strs[i], strs[j])) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

    int group = 0;
    vector<int> visited(n, false);

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        group++;
        queue<int> q;
        q.push(i);
        visited[i] = true;

        while (!q.empty()) {
          int top = q.front();
          q.pop();
          for (auto &neig : adj[top]) {
            if (!visited[neig]) {
              visited[neig] = true;
              q.push(neig);
            }
          }
        }
      }
    }

    return group;
  }
};