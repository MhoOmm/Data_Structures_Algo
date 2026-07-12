class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>temp(arr.begin(),arr.end());
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        int rank = 1;
        // assigning rank
        for(int i=0;i<n;i++)
        {
            if(mp.find(temp[i])==mp.end()) // element not in the map
            {
                mp[temp[i]] = rank;
                rank++;
            }
        }
        // giving rank
        for(int i=0;i<n;i++){
            temp[i] = mp[arr[i]];
        }
        return temp;
    }
};