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

// clean code
class Solution {
public:
    unordered_set<string>visited;
    int bfs(unordered_set<string>&dead,string target,string start){
        queue<string>q;
        q.push(start);
        int turns = 0;
        visited.insert(start);
        
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                string str = q.front();
                q.pop();
                if(str == target)
                {
                    return turns;
                }
                for(int i=0;i<4;i++)
                {
                    string temp = str;
                    // forward move
                    temp[i] = temp[i]=='9'?'0':temp[i]+1;
                    if(!dead.count(temp) && !visited.count(temp))
                    {
                        visited.insert(temp);
                        q.push(temp);
                    }
                    // backward move
                    temp = str;
                    temp[i] = temp[i]=='0'?'9':temp[i]-1;
                    if(!dead.count(temp) && !visited.count(temp))
                    {
                        visited.insert(temp);
                        q.push(temp);
                    }
                }
            }
            turns++;
        }

        return -1;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>dead(deadends.begin(),deadends.end());
        if(dead.count("0000"))
        {
            return -1;
        }
        return bfs(dead,target,"0000");
    }
};