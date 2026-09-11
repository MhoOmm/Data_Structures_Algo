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
    int count ;
    pair<int,int> dfs(TreeNode* root)
    {
        if(root==nullptr)
        {
            return {0,0};
        }
        // left child sum and number
        int sum = root->val;
        int num = 1;
        if(root->left)
        {
            auto [leftsum,leftnum] = dfs(root->left);
            sum += leftsum;
            num += leftnum;
        }
        if(root->right)
        {
            auto [rightsum,rightnum] = dfs(root->right);
            sum += rightsum;
            num += rightnum;
        }
        if(sum/num == root->val)
        {
            count++;
        }

        return {sum,num};
    }
    int averageOfSubtree(TreeNode* root) {
        count = 0;
        if(root==nullptr)
        {
            return 0;
        }
        auto [sum,num] = dfs(root);
        return count;
    }
};