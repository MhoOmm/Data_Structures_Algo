class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n =  nums.size();
        int maxele = *max_element(nums.begin(),nums.end());
        // making the index map
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        vector<bool>visited(n,false);
        // precomputing prime numbers upto n - sieve of eratothenes
        vector<bool>isPrime(maxele + 1,true);
        isPrime[0]=isPrime[1] = false;
        for(int i=2;i*i<=maxele;i++)
        {
            if(isPrime[i])
            {
                for(int j=i*i;j<=maxele;j+=i) // every multiple of this number
                {
                    isPrime[j]=false;
                }
            }
        }

        // bfs
        queue<int>q;
        visited[0] = true;
        int cost = 0;
        q.push(0);
        unordered_set<int>st;//to store the already visited prime numbers so that in future we dont push all the multiples once again
        while(!q.empty()){

            int size = q.size();
            while(size--)
            {
                int val = q.front();
                int node = nums[val];
                q.pop();
                if(val==n-1)
                {
                    return cost;
                }
                int neigpo = val+1;
                int neigmo = val-1;
                // minus one
                if(neigmo>=0 && !visited[neigmo]){
                    visited[neigmo] = true;
                    q.push(neigmo);
                }
                // plus one
                if(neigpo<n && !visited[neigpo])
                {
                    visited[neigpo] = true;
                    q.push(neigpo);
                }
                // all the multiples of prime number
                if(isPrime[node] && !st.count(node))
                {
                    st.insert(node);
                    for(int multi=node;multi<=maxele;multi+=node)
                    {
                        if(!mp.count(multi))continue;
                        for(int pos:mp[multi])
                        {
                            if(!visited[pos])
                            {
                                visited[pos] = true;
                                q.push(pos);
                            }
                        }
                    }
                }

            }
            cost++;
        }  

        return cost;
    }
};