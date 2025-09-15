class Solution {
public:

    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n=words.size();
        vector<int>result;
        auto lambda=[x](char ch){
            return ch==x;
        };
        for (int i = 0; i < n; i++) {
            if (any_of(begin(words[i]), end(words[i]), lambda)) {
                result.push_back(i);
            }
        }
      

        return result;
    }
};
                

// Brute force: approach

// class Solution {
// public:

//     vector<int> findWordsContaining(vector<string>& words, char x) {
//         vector<int>result;
//         for(int i =0;i<words.size();i++)
//         {
//             bool flag=false;
//             int l=words[i].length();
//             string str=words[i];
//             for(int j=0;j<l;j++)
//             {
//                 if(str[j]==x)
//                 {
//                     flag=true;
//                     break;
//                 }
//             }
//             if(flag){
//                 result.push_back(i);
//             }
//         }
//         return result;
        
//     }
// };