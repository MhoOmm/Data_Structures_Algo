class Solution {
public:
    int countCollisions(string dir) {
        
        int n = dir.length();
        int i = 0 ;
        int j = n-1;
        while(i<n && dir[i]=='L')
        {
            i++;
        }
        while( j>=0 &&dir[j]=='R')
        {
            j--;
        }
        int count =0;
        while(i<=j)
        {
           if(dir[i]!='S')
           {
            count++;
           }
           i++;
        }
        return count;
    }
};