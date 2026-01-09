class Solution {
  public: 
  int openLock(vector < string > & deadends, string target) {
    unordered_set < string > dead;
    for (int i = 0; i < deadends.size(); i++) {
      dead.insert(deadends[i]);
    }
    unordered_set < string > visited;
    visited.insert("0000");
    queue < string > q;
    q.push("0000");
    int moves = 0;
    if (dead.count("0000")) {
      return -1;
    }
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        string curr = q.front();
        q.pop();
        if (curr == target) {
          return moves;
        }
        string temp = curr;
        for (int i = 0; i < 4; i++) {
          string next = curr;
          next[i] = (curr[i] - '0' + 1) % 10 + '0';
          if (!dead.count(next) && !visited.count(next)) {
            visited.insert(next);
            q.push(next);
          }
          next = curr;
          next[i] = (curr[i] - '0' + 9) % 10 + '0';
          if (!dead.count(next) && !visited.count(next)) {
            visited.insert(next);
            q.push(next);
          }
        }
      }
      moves++;
    }

    return -1;

  }
};