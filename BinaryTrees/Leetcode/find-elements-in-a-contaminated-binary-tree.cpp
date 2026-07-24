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
class FindElements {
public:
    unordered_set<int>st;
    void dfs(TreeNode* root,int num){
        if(root == nullptr)
        {
            return ;
        }
        root->val = num;
        st.insert(num);
        dfs(root->left,num*2+1);
        dfs(root->right,num*2+2);
    }
    FindElements(TreeNode* root) {
        st.clear();
        dfs(root,0);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};
