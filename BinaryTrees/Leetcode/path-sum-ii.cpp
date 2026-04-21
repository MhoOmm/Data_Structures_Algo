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
    vector<vector<int>>ans;
    void inorder(TreeNode* root, int target,int sum,vector<int>&temp){
        if(root==nullptr)
        {
            return;
        }
        sum+=root->val;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==target)
            {
                ans.push_back(temp);
            }
        }
        inorder(root->left,target,sum,temp);
        inorder(root->right,target,sum,temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int>temp;
        inorder(root,target,0,temp);
        return ans;
    }
};