// using binary tree property and bfs 
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                indegree[leftChild[i]]++;
                if (indegree[leftChild[i]] > 1) return false;
            }
            if (rightChild[i] != -1) {
                indegree[rightChild[i]]++;
                if (indegree[rightChild[i]] > 1) return false;
            }
        }
        
        
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (root != -1) return false;
                root = i;
            }
        }
        
        if (root == -1) return false;
        
    
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(root);
        visited[root] = true;
        
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            if (leftChild[node] != -1) {
                if (visited[leftChild[node]]) return false;
                visited[leftChild[node]] = true;
                q.push(leftChild[node]);
            }
            
            if (rightChild[node] != -1) {
                if (visited[rightChild[node]]) return false;
                visited[rightChild[node]] = true;
                q.push(rightChild[node]);
            }
        }
    
        return count == n;
    }
};

// using dsu


class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int i)
    {
        if(i==parent[i])return i;

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
        if(rank[parx]>rank[pary]){
            parent[pary] = parx;
        }else if(rank[pary]>rank[parx])
        {
            parent[parx] = pary;
        }
        else{
            parent[parx] = pary;
            rank[pary]++;
        }
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        parent.resize(n);
        rank.resize(n);
        vector<int>inDeg(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            rank[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
            {
                inDeg[leftChild[i]]++;
                Union(i,leftChild[i]);
                if(inDeg[leftChild[i]]>1){
                    return false;
                }
            }
            if(rightChild[i]!=-1)
            {
                inDeg[rightChild[i]]++;
                Union(i,rightChild[i]);
                if(inDeg[rightChild[i]]>1){
                    return false;
                }
            } 
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (inDeg[i] == 0) {
                if (root != -1) return false;
                root = i;
            }
        }
        if (root == -1) return false;

        
        int rootParent = find(root);
        for (int i = 0; i < n; i++) {
            if (find(i) != rootParent)
                return false;
        }

        return true;
    }
};