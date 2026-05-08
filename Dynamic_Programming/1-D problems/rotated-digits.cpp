// Normal approach O(n.log(num))
class Solution {
public:
    bool isGood(int num)
    {
        bool flag = false;
        while(num>0)
        {
            int r = num%10;
            if(r == 3 || r == 4 || r == 7)
            {
                return false;
            }
            if(r == 2 || r == 5 || r == 6 || r == 9)
            {
                flag = true;
            }
            num = num/10;
        }
        return flag ;
    }
    int rotatedDigits(int n) {
        int goodInt = 0;
        for(int i=1;i<=n;i++)
        {
            if(isGood(i))
            {
                goodInt ++;
            }
        }

        return goodInt;
    }
};

// Recursive + memoization method
// takes extra space
class Solution {
public:
    int t[10001];
    int solve(int num)
    {
        if(num==0)
        {
            return 0;
        }
        int r = num%10;
        if(t[num]!=-1)
        {
            return t[num];
        }

        int rem = solve(num/10);
        int digit ;

        if(r==0||r==1||r==8)
        {
            digit = 0;
        }else if(r==2||r==5||r==6||r==9)
        {
            digit = 1;
        }else {
            digit = 2 ;//invalid path
        }

        if(digit ==2 || rem ==2)// invalid path
        {
            return t[num] = 2;
        }
        if(digit ==0 && rem==0)
        {
            return t[num] = 0;
        }
        return t[num] = 1;
    }
    int rotatedDigits(int n) {
        int goodInt = 0;
        memset(t,-1,sizeof(t));
        for(int i=1;i<=n;i++)
        {
            if(solve(i)==1)
            {
                goodInt ++;
            }
        }
        return goodInt;
    }
};

// bottom up approach
class Solution {
public:
    int rotatedDigits(int n) {
        int goodInt = 0;
        vector<int>t(n+1,-1);
        t[0] = 0;
        int count =0;
        for(int i=1;i<=n;i++)
        {
            int remain = t[i/10];
            if (remain == 2){
                t[i]=2;
                continue;
            }
            int r = i%10;
            int digit;
            if(r==0||r==1||r==8){
                digit = 0;
            }else if(r==2||r==5||r==6||r==9)
            {
                digit = 1;
            }else {
                digit = 2 ;//invalid path
            }

            if(digit==2)
            {
                t[i] = 2;
            }else if(digit==0 && remain==0)
            {
                t[i] = 0;
            }else {
                t[i]=1;
            }

            if(t[i]==1)
            {
                count++;
            }
        }
        return count;
    }
};
