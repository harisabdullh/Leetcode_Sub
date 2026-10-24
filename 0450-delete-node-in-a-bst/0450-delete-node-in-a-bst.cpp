class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp = root;
        TreeNode* prev = root;

        while (temp != NULL) {
            if (temp->val == key) break;
            prev = temp;
            if (temp->val > key) temp = temp->left;
            else temp = temp->right;
        }
        if (temp == NULL) return root; // key not found

        TreeNode* r = temp->right;
        TreeNode* l = temp->left;

        // the subtree that will replace temp
        TreeNode* replacement;
        if (r == NULL) {
            replacement = l;            // covers leaf and only-left-child
        } else {
            TreeNode* t = r;
            while (t->left != NULL) t = t->left;
            t->left = l;                // attach left subtree to leftmost of right subtree
            replacement = r;
        }

        if (temp == prev) return replacement;   // root is being deleted

        if (prev->left == temp) prev->left = replacement;
        else prev->right = replacement;

        return root;
    }
};