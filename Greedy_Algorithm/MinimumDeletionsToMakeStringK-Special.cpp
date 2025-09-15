class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.length();

        vector<int>vec(26);
        for(char &ch:word)
        {
            vec[ch-'a']++;
        }
        int result = word.length();
        for(int i=0;i<26;i++)
        {
            int del =0;
            for(int j=0;j<26;j++)
            {
                if(i==j)continue;

                if(vec[j]<vec[i])
                {
                    del+=vec[j];
                }else if(abs(vec[j]-vec[i])>k){
                    del+=abs(vec[j]-vec[i]-k);
                }
            }
            result=min(result,del);
        }

        return result;
    }
};