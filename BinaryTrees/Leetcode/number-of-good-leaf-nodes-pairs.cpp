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
    void dfs(unordered_map<TreeNode*,TreeNode*>&mp,TreeNode* root,unordered_set<TreeNode*>&st)
    {
        if(root==nullptr){
            return;
        }

        if(!root->left && !root->right)
        {
            st.insert(root); // leaf node
        }
        if(root->left)mp[root->left] = root;
        if(root->right)mp[root->right] = root;
        dfs(mp,root->left,st);
        dfs(mp,root->right,st);
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*,TreeNode*>mp;
        unordered_set<TreeNode*>st;
        dfs(mp,root,st);
        int count =0;
        for(auto &leaf:st)
        {
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;
            q.push(leaf);
            visited.insert(leaf);
            for(int level = 0; level <= distance; level++) { 
                int size = q.size();
                while(size--) {
                    TreeNode* curr = q.front();
                    q.pop();

                    if(curr != leaf && st.count(curr)) { 
                        count++;
                    }

                    if(curr->left && !visited.count(curr->left))
                    {
                        visited.insert(curr->left) ;
                        q.push(curr->left);
                    }
                    
                    if(curr->right && !visited.count(curr->right))
                    {
                        visited.insert(curr->right) ;
                        q.push(curr->right);
                    }
                    
                    if(mp.count(curr) && !visited.count(mp[curr]))
                    {
                        visited.insert(mp[curr]) ;
                        q.push(mp[curr]);
                    }
                }
            }
        }
        return count/2;
    }
};