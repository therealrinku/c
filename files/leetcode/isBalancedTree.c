/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define max(a,b) ((a) > (b) ? (a) : (b))

bool isBalanced(struct TreeNode* root) {
    if(!root) return true;

    int _isBalanced(struct TreeNode* head){
        if(!head) return 0;

        int left = _isBalanced(head->left);
        int right = _isBalanced(head->right);

        if(left == -1 || right == -1 || abs(left-right) > 1){
            return -1;
        }

        return max(left, right) + 1;
    }

    return _isBalanced(root) != -1 ? true : false;
}
