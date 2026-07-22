// BFS APPROACH
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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        int maxVal = INT_MIN;
        if(!root)
        {
            return {};
        }

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {

                TreeNode* node = q.front();
                q.pop();
                if(node->val > maxVal)
                {
                    maxVal = node->val;
                }
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(maxVal);
            maxVal = INT_MIN;
        }
        return ans;
    }
};

// DFS APPROACH


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
    int maxVal;
    void dfs(TreeNode* root,vector<int>&ans,int level){
        if(root==nullptr)
        {
            return;
        }
        int val = root->val;
        if (level == ans.size()) {
            ans.push_back(val);
        }
        else {
            ans[level] = max(ans[level], val);
        }
        dfs(root->left,ans,level+1);
        dfs(root->right,ans,level+1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        dfs(root,ans,0);
        return ans;
    }
};