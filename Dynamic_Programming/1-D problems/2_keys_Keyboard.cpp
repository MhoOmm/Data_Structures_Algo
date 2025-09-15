// recurr + memoization
class Solution {
    public:
    
        int t[1001][1001];
    
        int solve(int curra,int clipa,int n)
        {
            if(curra>n)
            {
                return 1000000;
            }
            if(curra==n)
            {
                return 0;
            }
            if(t[curra][clipa]!=-1)
            {
                return t[curra][clipa];
            }
    
            int paste=1+solve(clipa+curra,clipa,n);
            int copyall=2+solve(curra+curra,curra,n);
    
            return t[curra][clipa]=min(copyall,paste);
        }
        int minSteps(int n) {
    
            int clipa=1;
            int curra=1;
    
            if(n==1)
            {
                return 0;
            }
            memset(t,-1,sizeof(t));
    
            return 1+solve(curra,clipa,n);
            
        }
    };


    // bottom up

    class Solution {
        public:
            int minSteps(int n) {
        
                vector<int>t(n+1,0);
        
                if(n==1)
                {
                    return 0;
                }
                if( n==2)
                {
                    return 2;
                }
                t[0]=0;
                t[1]=0;
                t[2]=2;
                for(int i=3;i<=n;i++)
                {
                    int factor=i/2;
                    while(factor>=1)
                    {
                        if(i%factor==0)
                        {
                            int steptn=t[factor];
                            int paste=(i/factor -1);
                            int copy=1;
        
                            t[i]=t[factor]+paste+copy;
                            break;
                        }
                        else{
                            factor--;
                        }
                    }
                }
        
                return t[n];
                
            }
        };