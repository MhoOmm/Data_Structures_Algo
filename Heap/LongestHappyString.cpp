class Solution {
public:
    typedef pair<int,char> p;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<p,vector<p>>pq;

        if(a>0)
        {
            pq.push({a,'a'});
        }
        if(b>0)
        {
            pq.push({b,'b'});
        }
        if(c>0)
        {
            pq.push({c,'c'});
        }
        string result="";
        while(!pq.empty())
        {
            int maxnum = pq.top().first;
            char maxchar=pq.top().second;
            pq.pop();

            if(result.length()>=2 && result[result.length()-1]==maxchar && result[result.length()-2]==maxchar )
            {
                if(pq.empty())
                {
                    break;
                }
                
                int nextnum=pq.top().first;
                int nextchar= pq.top().second;
                pq.pop();

                result.push_back(nextchar);
                nextnum--;
                if(nextnum > 0) {
                    pq.push({nextnum, nextchar});
                }
                
            }else{
                result.push_back(maxchar);
                maxnum--;
            }
            if(maxnum > 0) {
                pq.push({maxnum, maxchar});
            }
        }
        return result;
    }
};