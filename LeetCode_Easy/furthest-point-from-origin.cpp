class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.length();
        int maxLength = INT_MIN;
        // left pass
        int count =0;
        for(auto &ch:moves)
        {
            if(ch=='L' || ch=='_')
            {
                count++;
            }else{
                count--;
            }
        }
        count = abs(count);
        maxLength = max(maxLength,count);
        // right pass
        count=0;
        for(auto &ch:moves)
        {
            if(ch=='R'||ch=='_')
            {
                count++;
            }else{
                count--;
            }
        }
        count = abs(count);
        maxLength = max(maxLength,count);
        return maxLength;
    }
};