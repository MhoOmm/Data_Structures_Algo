/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minSwaps(vector<int>&vec)
    {
        vector<int>sorted(vec.begin(),vec.end());
        sort(sorted.begin(),sorted.end());
        unordered_map<int,int>mp;
        int swaps =0;
        for(int i=0;i<vec.size();i++)
        {
            mp[vec[i]]=i;
        }

        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]==sorted[i])
            {
                continue;
            }
            int idx = mp[sorted[i]];
            mp[vec[i]] = idx;
            mp[vec[idx]] = i;
            swap(vec[i],vec[idx]);
            swaps++;
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int swapsTotal = 0;
        while(!q.empty())
        {
            int size = q.size();
            vector<int>temp;
            while(size--)
            {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            int swapsLevel = minSwaps(temp);
            swapsTotal += swapsLevel;
        }
        return swapsTotal;
    }
};