class Solution {
public:
    int calcSum(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int calcNum(int n)
    {
        string str = to_string(n);
        string st = "";

        for(char ch : str)
        {
            if(ch != '0')
                st += ch;
        }

        if(st.empty())
            return 0;

        return stoi(st);
    }

    long long sumAndMultiply(int n)
    {
        long long sum = calcSum(n);
        long long num = calcNum(n);
        return sum * num;
    }
};