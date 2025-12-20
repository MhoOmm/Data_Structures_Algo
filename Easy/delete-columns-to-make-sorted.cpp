class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int time  = strs.size();
        int n = strs[0].size();
        int count =0;

        for(int i=0;i<n;i++)
        {
            for(int j=1;j<time;j++)
            {
                if(strs[j][i]<strs[j-1][i])
                {
                    count++;
                    break;
                }

            }
        }

        return count;
    }
};