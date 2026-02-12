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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>answer;
        queue<TreeNode*>q;
        if(root == nullptr){
            return {};
        }
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            int lastn = 0;
            while(n--)
            {
                TreeNode* node = q.front();
                q.pop();
                lastn = node->val;
                if(node->left != nullptr)
                {
                    q.push(node->left);
                }
                if(node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            answer.push_back(lastn);
        }
        return answer;
    }
};