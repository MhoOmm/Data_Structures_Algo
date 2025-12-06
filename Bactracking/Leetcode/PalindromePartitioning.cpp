class Solution {
public:
    int n ;
    bool ispalindrome(string s){
        int i = 0;
        int j = s.length()-1;
        while(i<j){
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(string &s,int i,vector<vector<string>>&result,vector<string>&curr){

        if(i>=n){
            result.push_back(curr);
            return;
        }

        for(int idx=i;idx<n;idx++)
        {
            if(ispalindrome(s.substr(i,idx-i+1)))
            {
                curr.push_back(s.substr(i,idx-i+1));
                solve(s,idx+1,result,curr);
                curr.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        n = s.length(); 
        vector<vector<string>>result;
        vector<string>curr;

        solve(s,0,result,curr);
        return result;
        
    }
};