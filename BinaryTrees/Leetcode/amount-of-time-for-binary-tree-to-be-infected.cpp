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
    int start;
    void dfs(unordered_map<TreeNode*,TreeNode*>&mp,TreeNode* root,queue<TreeNode*>&q,unordered_set<TreeNode*>&visited)
    {
        if(root==nullptr)
        {
            return;
        }
        if(root->val == start){
            q.push(root);
            visited.insert(root);
        }
        if(root->left)
        {
            mp[root->left] = root;
            dfs(mp,root->left,q,visited);
        }
        if(root->right)
        {
            mp[root->right] = root;
            dfs(mp,root->right,q,visited);
        }
    }

    int amountOfTime(TreeNode* root, int shuru) {
        unordered_map<TreeNode*,TreeNode*>mp;
        start = shuru;
        queue<TreeNode*>q;
        unordered_set<TreeNode*>visited;
        dfs(mp,root,q,visited);
        int time = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited.count(node->left)){
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && !visited.count(node->right)){
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if(mp.count(node) && !visited.count(mp[node]))
                {
                    visited.insert(mp[node]);
                    q.push(mp[node]);
                }
            }
            time++;
        }

        return time-1;
    }
};