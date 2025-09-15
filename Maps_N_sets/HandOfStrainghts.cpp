class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        map<int,int>mp;
        if(n % groupSize) {
            return false;
        }

        for(int i=0;i<n;i++)
        {
            mp[hand[i]]++;
        }

        while(!mp.empty())
        {
            int curr= mp.begin()->first;
            for(int i=0;i<groupSize;i++)
            {
                if(mp[curr+i]==0)
                {
                    return false;
                }

                mp[curr+i]--;
                if(mp[curr+i] < 1) {
                    mp.erase(curr+i);
                }
            }
        }

        return true;
    }
};