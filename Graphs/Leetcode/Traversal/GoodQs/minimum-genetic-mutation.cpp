class Solution {
public:
    vector<char>options{'A','G','T','C'};
    bool belongs(string temp, vector<string>& bank)
    {
        for(int i=0;i<bank.size();i++)
        {
            if(bank[i]== temp)
            {
                return true;
            }
        }

        return false;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        queue<string>q;
        int n = startGene.length();
        int level=0;

        unordered_set<string>visited;
        visited.insert(startGene);
        if(startGene==endGene)
        {
            return 0;
        }
        q.push(startGene);

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                string top = q.front();
                q.pop();

                if(top == endGene)
                {
                    return level;
                }
                string temp = top;
                for(char &ch:options){
                    for(int i=0;i<n;i++)
                    {
                        char org = temp[i];
                        if(org == ch)continue;
                        temp[i] = ch;
                        if(belongs(temp,bank) && !visited.count(temp)){
                            q.push(temp);
                            visited.insert(temp);
                        }
                        temp[i] = org;
                    }
                }
            }
            level++;
        }
        return -1;  
    }
};