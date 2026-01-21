class Solution {
public:
    bool isPathCrossing(string path) {
        int x =0;
        int y =0;
        string key = to_string(x)+"_"+to_string(y);
        unordered_set<string>st;
        st.insert(key);
        for(char dir:path)
        {
            if(dir=='N')
            {
                x += 1;
                y += 0;
            }
            else if(dir=='S')
            {
                x += -1;
                y += 0;
            }
            else if(dir == 'E')
            {
                x += 0;
                y += 1;
            }
            else{
                x += 0;
                y += -1;
            }
            key = to_string(x)+"_"+to_string(y);

            if(st.find(key)!=st.end()){
                return true;
            }
            st.insert(key);
        }

        return false;

    }
};