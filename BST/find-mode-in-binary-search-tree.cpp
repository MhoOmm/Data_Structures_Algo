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
class Solution {
public:
    int currNum,maxFreq,currFreq;
    vector<int>result;
    void inorder(TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        inorder(root->left);
        if(root->val == currNum)
        {
            currFreq++;
        }else{
            currFreq = 1;
            currNum = root->val;
        }

        if(currFreq>maxFreq)
        {
            maxFreq= currFreq;
            result.clear();
            result.push_back(root->val);
        }
        else if (currFreq==maxFreq){
            result.push_back(root->val);
        }
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        currNum=INT_MIN;
        maxFreq=0;
        currFreq=0;
        inorder(root);
        return result;  
    }
};