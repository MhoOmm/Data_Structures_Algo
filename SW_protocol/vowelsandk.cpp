#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
    public:
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int vowels=5;
        long long countOfSubstrings(string word, int k) {
        
        int len = word.size();
        int num = 0;

        for (int i = 0; i <= len - k; ++i) {
            int vowel_count = 5;
            for (int j = i; j < i + k; ++j) {
                if (vowels.count(word[j])) {
                    vowel_count--;
                    len--;
                }
            }
            if (vowel_count != 0) {
                continue;
            }
            else{
                if(len==k)
                {
                    num++;
                }

            }
        }
        return num;
            
        }
    };