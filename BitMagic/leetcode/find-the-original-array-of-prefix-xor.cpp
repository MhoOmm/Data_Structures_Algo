// extra space array
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        // arr[i]=prefix[i]^prefix[i-1]
        int n = pref.size();
        vector<int>arr(n);
        arr[0] = pref[0];
        for(int i=1;i<n;i++)
        {
            arr[i] = pref[i]^pref[i-1];
        }

        return arr;
    }
};

// same array solution
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        // arr[i]=prefix[i]^prefix[i-1]
        int n = pref.size();
        int last = pref[0];
        for(int i=1;i<n;i++)
        {
            int temp = pref[i];
            pref[i] = pref[i]^last;
            last = temp;
        }

        return pref;
    }
};