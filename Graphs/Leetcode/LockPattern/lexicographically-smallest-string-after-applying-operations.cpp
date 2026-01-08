class Solution {
public:
    string reverFunc(string s,int b)
    {
        reverse(begin(s),end(s));
        reverse(begin(s),begin(s)+b);
        reverse(begin(s)+b,end(s));

        return s;
    }
    string findLexSmallestString(string s, int a, int b) {

        int n = s.length();
        queue<string>q;
        unordered_set<string>visited;
        string result = s;
        q.push(s);
        visited.insert(s);

        while(!q.empty())
        {
            string curr = q.front();
            q.pop();
            if(curr < result)
            {
                result = curr;
            } 

            // apply a
            string temp = curr;
            for(int i=1;i<temp.length();i+=2)
            {
                temp[i] = (((temp[i]-'0')+a)%10) + '0'; 
            }
            if(!visited.count(temp))
            {
                q.push(temp);
                visited.insert(temp);
            }
            temp = curr;
            // apply b
            temp = reverFunc(temp,b);
            if(!visited.count(temp))
            {
                q.push(temp);
                visited.insert(temp);
            }
        }

        return result;
    }
};