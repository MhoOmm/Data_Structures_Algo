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
    int maxSum;
    int solve(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);

        int root_left = root->val + max(0, left);
        int root_right = root->val + max(0, right);

        int best_for_above = max(root_left, root_right);
        int sum = root->val + max(0,left) + max(0,right);

        maxSum = max(maxSum,sum);
        return max(root->val,best_for_above);
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};