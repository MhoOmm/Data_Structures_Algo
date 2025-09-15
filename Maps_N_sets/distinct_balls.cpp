#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        int n=queries.size();
        vector<int>result(n);
        unordered_map<int,int>colourmp;
        unordered_map<int,int>ballmp;

        for(int i=0;i<n;i++)
        {
            int ball=queries[i][0];
            int colour=queries[i][1];

            if(ballmp.count(ball))// if the ball already has a colour
            {
                int prev=ballmp[ball];
                colourmp[prev]--;

                if(colourmp[prev]==0)
                {
                    colourmp.erase(prev);
                }
            }

            // if it doesnt have a colour

            ballmp[ball]=colour;
            colourmp[colour]++;

            result[i]=colourmp.size();

        }

        return result;
        
    }
};