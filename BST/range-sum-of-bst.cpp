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


//  brute force solution
class Solution {
public:
    int sum;
    void inorder(TreeNode* root, int low, int high)
    {
        if(root==nullptr)
        {
            return;
        }

        // left child
        inorder(root->left,low,high);

        // ops
        int value = root->val;
        if(low<=value && value<=high)sum+=value;
        // right child
        inorder(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0;
        inorder(root,low,high);
        return sum;
    }
};


// optimal solution

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
//  brute force solution
class Solution {
public:
    int sum;
    void inorder(TreeNode* root, int low, int high)
    {
        if(root==nullptr)
        {
            return;
        }
        int value = root->val;
        if(low<=value)
        {
            inorder(root->left,low,high);
        }

        // ops
        if(low<=value && value<=high)sum+=value;

        
        if(value<=high)
        {
            inorder(root->right,low,high);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0;
        inorder(root,low,high);
        return sum;
    }
};