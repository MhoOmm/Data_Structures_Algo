class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int, int> loss;
        unordered_set<int> players;

       
        for (int i = 0; i < n; i++) {
            int winner = matches[i][0];
            int loser = matches[i][1];
            loss[loser]++;
            players.insert(winner);
            players.insert(loser);
        }

        vector<vector<int>> result;
        vector<int> winarr;
        vector<int> lossarr;

        for (int player : players) {
            if (loss.find(player) == loss.end()) {
                winarr.push_back(player);         
            } else if (loss[player] == 1) {
                lossarr.push_back(player);        
            }
        }

        sort(begin(winarr), end(winarr));
        sort(begin(lossarr), end(lossarr));

        result.push_back(winarr);
        result.push_back(lossarr);

        return result;
    }
};
