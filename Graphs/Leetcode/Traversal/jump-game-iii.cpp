// got the intuition from the hints of lc
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        int n = arr.size();
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(arr[node]==0)
            {
                return true;
            }
            int po = node + arr[node];//plus 
            int mo = node - arr[node];//minus
            arr[node]=-1;
            if(po>=0 && po<n && arr[po]!=-1)
            {
                q.push(po);
            }
            if(mo>=0 && mo<n && arr[mo]!=-1)
            {
                q.push(mo);
            }
        }
        return false;
    }
};