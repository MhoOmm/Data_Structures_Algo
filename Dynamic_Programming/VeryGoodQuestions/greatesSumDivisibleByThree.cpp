// Greedy + maths
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum=0;
        vector<int>reman1;
        vector<int>reman2;

        for(auto &num:nums){
            sum+=num;
            if(num%3==1)
            {
                reman1.push_back(num);
            }else if(num%3==2)
            {
                reman2.push_back(num);
            }
        }

        if(sum%3==0)
        {
            return sum;
        }

        sort(begin(reman1),end(reman1));
        sort(begin(reman2),end(reman2));

        int result= 0;

        if(sum%3==1)
        {
            int remove1 = reman1.size()>=1 ? reman1[0]:INT_MAX;
            int remove2 = reman2.size()>=2 ? reman2[0]+reman2[1]:INT_MAX;
            result = max(result, sum-min(remove1,remove2));
        }else{
            int remove1 = reman2.size()>=1 ? reman2[0]:INT_MAX;
            int remove2 = reman1.size()>=2 ? reman1[0]+reman1[1]:INT_MAX;
            result = max(result, sum-min(remove1,remove2));
        }

        return result;
    }
};

// Recursion + Memo
class Solution {
public:
    int n;
    int t[100001][3];
    int solve(int i,int rem, vector<int>&nums){

        if(i>=n)
        {
            return rem==0?0:INT_MIN;
        }

        if(t[i][rem]!=-1)
        {
            return t[i][rem];
        }

        int take = nums[i]+solve(i+1,(rem+nums[i])%3,nums);
        int skip = solve(i+1,rem,nums);
        return t[i][rem] = max(take,skip);
    }
    int maxSumDivThree(vector<int>& nums) {
        n = nums.size();
        memset(t,-1,sizeof(t));
        if(n==1)
        {
            return nums[0]%3==0?nums[0]:0;
        }

        return solve(0,0,nums);
    }
};


// BOttom up


class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>>t(n+1, vector<int>(3,INT_MIN));

        t[n][0] = 0;

        t[n][1] = INT_MIN;
        t[n][2] = INT_MIN;

        for(int i =n-1;i>=0;i--)
        {
            for(int rem = 0;rem<3;rem++)
            {
                int newrem = (rem+nums[i])%3;

                int take =nums[i]+ t[i + 1][newrem];
                int skip =t[i+1][rem];

                t[i][rem] = max(take,skip);
            }
        }

        return t[0][0];
        
    }
};
