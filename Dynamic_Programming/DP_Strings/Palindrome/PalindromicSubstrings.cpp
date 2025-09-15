

//recursion and memoization well it is iterative only but for clarity 
class Solution {
    public:
    
        int t[1000][1000];
    
        bool recur(string &s,int i,int j)
        {
            if(i>j)return true;
    
            if(t[i][j]!=-1)
            {
                return t[i][j];
            }
            if(s[i]==s[j])
            {
                return t[i][j]=recur(s,i+1,j-1);
            }
            else{
                return t[i][j]=false;
            }
        }
        int countSubstrings(string s) {
    
            int n =s.length();
            int co=0;
    
            memset(t,-1,sizeof(t));
    
            for(int i=0 ;i<n;i++)
            {
                for(int j=i;j<n;j++)
                {
                    if(recur(s,i,j))
                    {
                        co++;
                    }
                }
            }
    
            return co;
            
        }
    };


// bottom up approach -blueprint

class Solution {
    public:
        int countSubstrings(string s) {
    
            int n=s.length();
    
            vector<vector<bool>>t(n,vector<bool>(n,false));
    
            int co=0 ;
    
            for(int L=1;L<=n;L++)
            {
                for(int i=0;(i+L-1)<n;i++)
                {
                    int j=i+L-1;
    
                    if(i==j){//1-length substring
                        t[i][j]=true;
                    }
                    else if(i+1==j){// 2-length substring
                        t[i][j]=(s[i]==s[j]);
                    }
                    else {
                        t[i][j]=(s[i]==s[j]&& t[i+1][j-1]);
                    }
    
    
                    if(t[i][j]==true)
                    {
                        co++;
                    }
                }
            }
    
            return co;
            
        }
    };


// approach 4- one smart approach

class Solution {
    public:
        
        int n;
        int co;
    
        void check(int i,int j,string &s,int n)
        {
            while(i>=0 && j<n && s[i]==s[j])
            {
                co++;
                i--;
                j++;
            }
        }
        int countSubstrings(string s) {
    
            n=s.length();
            co=0;
            
            for(int i=0;i<n ;i++)
            {
              check(i,i,s,n);
              check(i,i+1,s,n);
            }
            return co;       
        }
        
    };