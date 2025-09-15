class Solution {
public:
    int partitionString(string s) {
        vector<int>visited(26,-1);
        int substr=0;
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            int it=s[i]-'a';
            if(visited[it]>=substr)
            {
                count++;
                substr=i;
            }
            visited[it]=i;
        }
        return count+1;
    }
};