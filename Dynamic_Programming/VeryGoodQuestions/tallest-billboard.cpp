// recursive solution
class Solution {
public:
    int solve(int i,int l1,int l2,vector<int>&rods){
        if(i>=rods.size())
        {
            if(l1==l2)
            {
                return l1;
            }else{
                return INT_MIN;
            }
        }
        // take as l1
        int addl1 = solve(i+1,l1+rods[i],l2,rods);
        // take as l2
        int addl2 = solve(i+1,l1,l2+rods[i],rods);

        // not take this one
        int nt = solve(i+1,l1,l2,rods);

        return max({addl1,addl2,nt});
    }
    int tallestBillboard(vector<int>& rods) {
        return solve(0,0,0,rods);
    }
};
// memoization(Good Technique) we dont need l1 and l2 every time
// we can just track their diffrence and add them in the way 
// at last we will get l1+l2 so we divide /2

class Solution {
public:
    int t[21][10001];
    int solve(int i,int diff,vector<int>&rods){
        if(i>=rods.size())
        {
            if(diff==0)
            {
                return 0;
            }else{
                return INT_MIN;
            }
        }
        if(t[i][diff+5000]!=-1)
        {
            return t[i][diff+5000];  
        }
        // take as l1
        int addl1 = rods[i] + solve(i+1,diff+rods[i],rods);
        // take as l2
        int addl2 = rods[i] + solve(i+1,diff-rods[i],rods);

        // not take this one
        int nt = solve(i+1,diff,rods);

        return t[i][diff+5000] = max({addl1,addl2,nt});
    }
    int tallestBillboard(vector<int>& rods) {
        memset(t,-1,sizeof(t));
        return solve(0,0,rods)/2;
    }
};