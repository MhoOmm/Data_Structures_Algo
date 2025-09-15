class Solution {
public:
    typedef pair<int,int>pp;
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            mp[x[i]]=max(mp[x[i]],y[i]);
        }

        if(mp.size()<=2)
        {
            return -1;
        }
        priority_queue<pp>pq;//max heap
        for(auto &it:mp)
        {
            int yele=it.second;
            int xele=it.first;
            pq.push({yele,xele});
        }
        int sum=0;
        for(int i=0;i<3;i++)
        {
            sum+= pq.top().first;
            pq.pop();
        }

        return sum;

    }
};

// approach 2 better tc
class Solution {
public:
    typedef pair<int,int> pp;
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n=x.size();
        priority_queue<pp>pq;
        for(int i=0;i<n;i++)
        {
            pq.push({y[i],x[i]});
        }
        unordered_set<int>st;
        int sum=0;
        int count=0;
        while(!pq.empty())
        {
            int px = pq.top().second;
            int py = pq.top().first;
            pq.pop();
            if(st.contains(px))continue;
            else{
                sum+=py;
                st.insert(px);
                count++;
            } 
            if(count==3)return sum;
        }
        return -1;
    }
};