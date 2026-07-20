/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>mp;
    void inorder(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        if(root->left != nullptr )
        {
            mp[root->left] = root;
        }
        if(root->right!=nullptr){
            mp[root->right] = root;
        }
        inorder(root->left);
        inorder(root->right);
    }
    vector<int> bfs(TreeNode* target,int k){
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(target);
        unordered_set<int> visited;
        visited.insert(target->val);
        int level = 0;
        while(!q.empty())
        {
            if(level==k)
            {
                break;
            }
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited.count(node->left->val))
                {
                    visited.insert(node->left->val);
                    q.push(node->left); // left child
                }
                if(node->right && !visited.count(node->right->val))
                {
                    visited.insert(node->right->val);
                    q.push(node->right);// right child
                }
                if(mp[node] && !visited.count(mp[node]->val))
                {
                    visited.insert(mp[node]->val);
                    q.push(mp[node]); // parent
                }
            }
            level++;
        }

        // now insert the values from queue to ans
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        inorder(root);
        return bfs(target,k);
    }
};