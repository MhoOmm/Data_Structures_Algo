// using set
class Solution {
public:
    int commonFactors(int a, int b) {
        set<int> st;
        for (int i = 1; i * i <= a; i++) {
            if (a % i == 0) {
                st.insert(i);
                if (i != a / i)
                    st.insert(a / i);
            }
        }

        int count = 0;
        for (int i = 1; i * i <= b; i++) {
            if (b % i == 0) {
                if (st.find(i) != st.end())
                    count++;

                if (i != b / i && st.find(b / i) != st.end())
                    count++;
            }
        }

        return count;
    }
};
// optimised Solution
class Solution {
public:
    int commonFactors(int a, int b) {
        int count =0;
        for(int i=1;i<=1000;i++){
            if(a%i==0 && b%i==0)
            {
                count++;
            }
        }
        return count;
    }
};