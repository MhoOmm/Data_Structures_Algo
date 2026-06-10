// TC :- O(N)
// SC :- O(N)
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        stack<int>st; 
        queue<int>q;

        for (int i = 0; i < n; i++) {
            st.push(sandwiches[n - i - 1]);
            q.push(students[i]);
        }

        int start  = 0;

        while(!q.empty() && start<q.size())
        {
            if(st.top() == q.front())
            {
                st.pop();
                q.pop();
                start = 0;
            }else{
                q.push(q.front());
                q.pop();
                start+=1;
            }
        }

        return q.size(); 
    }
};


// TC:- O(N)
// SC:- O(1)

class Solution {
public:
    int countStudents(vector<int>& stud, vector<int>& sand) {

        int n = stud.size();

        int ci = 0;
        int sq = 0;

        for(int i =0;i<n;i++)
        {
            if(stud[i])
            {
                sq ++;
            }else{
                ci++;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(sand[i]==0 && ci>0)
            {
                ci--;
            }else if(sand[i]==1 && sq >0)
            {
                sq--;
            }else{
                return sq==0?ci:sq;
            }  
        }

        return 0;
    }
};