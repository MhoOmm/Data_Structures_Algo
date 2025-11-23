class Solution {
public:
    int minOperations(vector<string>& logs) {

        int n = logs.size();
        int count =0;

        for(auto &str :logs)
        {
            if(str=="./")
            {
                continue;
            }else if(str=="../"){
                if(count<=0)continue;
                count--;
            }else{
                count++;
            }
        }

        return count;
        
    }
};