class Solution {
public:
    int mod = 1e9 + 7;
    int t[100001];
    int solve(string &s,int k,int i){
        if(i>=s.length())
        {
            return 1; // count this one and further
        }
        if(s[i] == '0')
        {
            return 0; // no preceding zeros for a number
        }
        if(t[i]!=-1){
            return t[i];
        }
        long long num =0;// num from now
        int count =0; // iska aur beta ka count
        for(int start=i;start<s.length();start++){
            num = num*10 + (s[start]-'0');
            if(num>k)
            {
                break; // further explore karke bhi bade hi milenge
            }

            count = (count + solve(s,k,start+1))%mod;
        }

        return t[i]= count;
    }
    int numberOfArrays(string s, int k) {
        memset(t,-1,sizeof(t));
        return solve(s,k,0);
    }
};