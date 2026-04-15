class Solution {
public:
    int closestTarget(vector<string>& words, string target, int si) {

        int n = words.size();
        int ans = INT_MAX;
        if(words[si]==target)
        {
            return 0;
        }
        // forward pass
        int i = (si+1)%n;
        int count=1;
        while(i!=si)
        {
            if(words[i] == target)
            {
                ans = min(ans,count);
                break;
            }
            count++;
            i = (i+1)%n;
        }
        // backward pass
        int j = (si-1+n)%n;
        count=1;
        while(j!=si)
        {
            if(words[j] == target)
            {
                ans = min(ans,count);
                break;
            }
            count++;
            j = (j-1+n)%n;
        }

        return ans==INT_MAX?-1:ans;
        
    }
};