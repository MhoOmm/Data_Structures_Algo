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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        queue<pair<TreeNode*,string>>q;
        string curr = "";
        q.push({root,curr});
        while(!q.empty()){
            auto [node,curr] = q.front();
            q.pop();
            if(curr=="")
            {
                curr = to_string(node->val);
            }else{
                curr = curr + "->" + to_string(node->val);
            }
            
            if(!node->left && !node->right) // leaf node 
            {
                ans.push_back(curr);
            }
            if(node->left)
            {
                q.push({node->left,curr});
            }
            if(node->right){
                q.push({node->right,curr});
            }
        }

        return ans;
    }
};