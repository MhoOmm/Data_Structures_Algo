class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxele = arr[n-1];
        arr[n-1] = -1;
        for(int i=n-2;i>=0;i--)
        {
            int temp = arr[i];
            arr[i] = maxele;
            maxele = max(maxele,temp);
        }
        return arr;
    }
};