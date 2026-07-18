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
    string getDupli(TreeNode* node,unordered_map<string,int>& mp,vector<TreeNode*>&ans)
    {
        if(node==nullptr)
        {
            return "N";
        }

        string subtree = to_string(node->val) + "_" + getDupli(node->left,mp,ans) + "_" + getDupli(node->right,mp,ans);

        if(mp[subtree]==1)
        {
            ans.push_back(node);
        }
        mp[subtree]++;

        return subtree;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        unordered_map<string,int> mp;
        getDupli(root,mp,ans);
        return ans;
    }
};