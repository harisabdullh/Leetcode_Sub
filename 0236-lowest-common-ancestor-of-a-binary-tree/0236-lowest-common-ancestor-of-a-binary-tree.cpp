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
bool solve(TreeNode*root, TreeNode*x,vector<TreeNode*>&arr){
    if(root==NULL)return false;
    arr.push_back(root);
    if(root==x){
        return true;

    }

    bool f1=solve(root->left,x,arr);
    bool f2=solve(root->right,x,arr);
    if(f1 || f2){
        return true;
    }
    arr.pop_back();
    return false;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //p path,
        //q path,
        //return the recent integer when they are getting differ
        vector<TreeNode*>parr;
        vector<TreeNode*>qarr;
        solve(root,p,parr);
        solve(root,q,qarr);
        // if(parr.size()<qarr.sizz())return parr[parr.size()-1];
        // if(parr.size()>qarr.sizz())return qarr[qarr.size()-1];
        // if(parr.size()==qarr.size()){



        // }
        int i=0;
        while(i<parr.size() && i<qarr.size()){
            if(parr[i]==qarr[i]){
                i++;
                continue;
            }
            else{
                return parr[i-1];
            }
        }
        if(i==parr.size())return parr[i-1];
        if(i==qarr.size())return qarr[i-1];
return root;
    }
};