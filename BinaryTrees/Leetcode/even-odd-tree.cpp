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
    bool isEvenOddTree(TreeNode* root) {
        if(!root)
        {
            return false;
        }
        queue<TreeNode*>q;
        q.push(root);
        int prev = INT_MIN; // for first level -> odd value;
        bool isEven = true;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                TreeNode* node = q.front();
                q.pop();
                if(isEven)
                {
                    int num = node->val;
                    if(num%2 == 0)
                    {
                        return false;
                    }
                    if(num<=prev)
                    {
                        return false;
                    }
                    prev = num;
                    if(node->left)q.push(node->left);
                    if(node->right)q.push(node->right);
                }else{
                    int num = node->val;
                    if(num%2 != 0)
                    {
                        return false;
                    }
                    if(num>=prev)
                    {
                        return false;
                    }
                    prev = num;
                    if(node->left)q.push(node->left);
                    if(node->right)q.push(node->right);
                }
            }
            isEven = !isEven;
            if(!isEven){
                prev = INT_MAX;
            }else{
                prev = INT_MIN;
            }
        }
        return true;
    }
};