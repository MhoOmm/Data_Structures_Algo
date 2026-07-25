// BFS approach
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            vector<TreeNode*>vec;
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(level%2==1)
            {
                int l =0;
                int r = vec.size()-1;
                while(l<=r)
                {
                   TreeNode* n1 = vec[l];
                   TreeNode* n2 = vec[r];
                   int temp  = n2->val;
                   n2->val = n1->val;
                   n1->val = temp;
                   l++;
                   r--;
                }
            }
            level++;
        }
        return root;
    }
};

// DFS approach
class Solution {
public:
    void dfs(TreeNode* leftnode, TreeNode* rightnode,int level){
        if(leftnode== nullptr || rightnode == nullptr )
        {
            return;
        }
        if(level%2==1)
        {
            // odd level
            int temp = leftnode->val;
            leftnode->val = rightnode->val;
            rightnode->val = temp;
        }
        dfs(leftnode->left,rightnode->right,level+1);
        dfs(leftnode->right,rightnode->left,level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left,root->right,1);
        return root;
    }
};