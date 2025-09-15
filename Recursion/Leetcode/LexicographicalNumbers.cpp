class Solution {
public:
    void solve(int i,int n,vector<int>&arr)
    {
        if(i>n)
        {
            return;
        }
        arr.push_back(i);
        for(int j=0;j<=9;j++)
        {
            int num=i*10+j;
            if(num>n)
            {
                return;
            }
            solve(num,n,arr);
        }


    }
    vector<int> lexicalOrder(int n) {
        vector<int>arr;
        for(int i=1;i<=9;i++)
        {
            solve(i,n,arr);
        }

        return arr;
    }
};