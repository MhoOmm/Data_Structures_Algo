class Solution {
public:
    bool checkRecord(string s) {
        int consL= 0;
        int abs = 0;
        for(auto &ch:s)
        {
            if(ch=='A')
            {
                abs++;
                consL = 0;
                if(abs>1)
                {
                    return false;
                }
            }
            else if(ch=='P')
            {
                consL = 0;
            }
            else{
                consL++;
                if(consL>=3)
                {
                    return false;
                }
            }
        }
        return true;
    }
};