class Solution {
public:

    int removepattern(string &s,const string &matpat,int value){
        stack<char>st;
        int n = s.length();
        int gain = 0;
        for (int i =0;i<n;i++)
        {
            if(!st.empty() && st.top()==matpat[0] && s[i]==matpat[1] )
            {
                gain+=value;
                st.pop();
            }else{
                st.push(s[i]);
            }
        }

        // remaking the String
        s.clear();
        while(!st.empty())
        {
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return gain;
    }
    int maximumGain(string s, int x, int y) {
        int total = 0;
        if(x>y){
            total += removepattern(s,"ab",x);
            total += removepattern(s,"ba",y);
        }else{
            total += removepattern(s,"ba",y);
            total += removepattern(s,"ab",x);
        }

        return total;
    }
};