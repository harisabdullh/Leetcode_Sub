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
        vector<int>fnf;
        if(root==NULL)return fnf;
        //LEVEL ORDER TRAVERSAL
        //each element ka last element return krdenge
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>t;
            for(int i=0;i<n;i++){
            TreeNode*temp=q.front();
            t.push_back(temp->val);
            if(temp->left!=NULL){
                q.push(temp->left);

            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }

            q.pop();
            }
            if(!t.empty()){
                ans.push_back(t);
            }
        }
        for(int i=0;i<ans.size();i++){
            fnf.push_back(ans[i][ans[i].size()-1]);
        }
        return fnf;

        
    }
};