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
    void inorder(TreeNode* node,unordered_map<TreeNode*,int>&mp,int depth)
    {
        if(node==NULL){
            return;
        }
        inorder(node->left,mp,depth+1);
        mp[node] = depth;
        inorder(node->right,mp,depth+1);
    }
    TreeNode* lcadeep(TreeNode* node,unordered_map<TreeNode*,int>&mp,int maxDepth)
    {
        if(node==NULL)
        {
            return NULL;
        }
        // if the node is the deepest leaf node
        if(mp[node]==maxDepth)
        {
            return node;// will return myself
        }
        // right subtree se value
        TreeNode* left = lcadeep(node->left,mp,maxDepth);
        // right subtree se value
        TreeNode* right = lcadeep(node->right,mp,maxDepth);

        if(left!=NULL && right!=NULL)
        {
            return node;// this node is the lca
        }
        if(left!=NULL){
            return left;
        }
        return right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL)
        {
            return NULL;
        }
        unordered_map<TreeNode*,int>mp;
        inorder(root,mp,0);
        int maxDepth = INT_MIN;
        for(auto &it:mp)
        {
            maxDepth = max(maxDepth,it.second);
        }
        return lcadeep(root,mp,maxDepth);
    }
};