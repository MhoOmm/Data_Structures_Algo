class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        int n = ast.size();
        long long curr = mass;
        sort(ast.begin(),ast.end());

        for(int i =0;i<n;i++)
        {
            if(curr < ast[i])
            {
                return false;
            }
            curr+=ast[i];
        }
        return true;
    }
};