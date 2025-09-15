class Solution {
public:
    typedef pair<char,int> pc;
    struct lambda {
        bool operator()(pc &p1 , pc &p2)
        {
            if(p1.first==p2.first)
            {
                return p1.second<p2.second;
            }else{
                return p1.first>p2.first;
            }
        }
    };
    string clearStars(string s) {
        priority_queue<pc,vector<pc>,lambda>pq;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='*')
            {
                int idx=pq.top().second;
                pq.pop();
                s[idx]='*';
            }
            else {
                pq.push({s[i], i});
            }
        }
        string ans= "";
        for(int i=0;i< s.length();i++)
        {
            if(s[i]!='*'){
                ans+=s[i];
            }       
        }

        return ans;
    }
};