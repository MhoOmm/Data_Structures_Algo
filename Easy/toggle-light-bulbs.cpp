class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool>freq(101,false);
        for(int bulb : bulbs)
        {
            if(freq[bulb]==true)
            {
                freq[bulb]=false;
            }
            else{
                freq[bulb]=true;
            } 
        }
        vector<int>result;
        for(int i=0;i<101;i++)
        {
            if(freq[i])
            {
                result.push_back(i);
            }
        }

        return result;
        
    }
};