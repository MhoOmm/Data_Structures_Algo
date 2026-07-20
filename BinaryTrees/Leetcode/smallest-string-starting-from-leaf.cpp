// bfs approach O(n^2)
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
    string smallestFromLeaf(TreeNode* root) {
        string result = "";
        string curr = "";
        if(root == nullptr)return "";
        queue<pair<TreeNode*,string>>q;
        q.push({root,curr});
        while(!q.empty())
        {
            auto [node,currs] = q.front();
            q.pop();
            currs = char(node->val + 'a') + currs;
            if(!node->left && !node->right)
            {
                if(result=="" || result>currs)
                {
                    result = currs;
                }
            }
            if(node->left)
            {
                q.push({node->left,currs});
            }
            if(node->right)
            {
                q.push({node->right,currs});
            }
        }
        return result;
    }
};
// dfs approach O(n^2)
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
    string result;
    void dfs(TreeNode* root,string curr)
    {
        if(root==nullptr)
        {
            return;
        }
        curr = char(root->val+'a') + curr;
        if(!root->left && !root->right)
        {
            if(result== "" || result>curr)
            {
                result = curr;
            }
            return;
        }
        dfs(root->left,curr);
        dfs(root->right,curr);
    }
    string smallestFromLeaf(TreeNode* root) {
        result = "";
        string curr = "";
        dfs(root,curr);
        return result;
    }
};