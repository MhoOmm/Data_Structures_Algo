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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;// node->address
        unordered_set<int>st;

        for(auto &desc:descriptions)
        {
            int par = desc[0];
            int child = desc[1];
            int side = desc[2];
            if(mp.find(par)==mp.end())
            {
                mp[par] = new TreeNode(par);
            }
            if(mp.find(child)==mp.end())
            {
                mp[child] = new TreeNode(child);
            }
            st.insert(child);
            if(side==0)
            {
                mp[par]->right = mp[child];
            }else{
                mp[par]->left = mp[child];
            }
        }

        // to check who has no parent
        TreeNode* root = nullptr;
        for(auto &desc:descriptions){
            int par = desc[0];
            if(!st.count(par))
            {
                root = mp[par];
            }
        }

        return root;
    }
};