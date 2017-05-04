/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> node;
    TreeNode* head;
    TreeNode* current;
    TreeNode *prev;
    BSTIterator(TreeNode *root) {
        head = root;
        current = root;
        prev = NULL;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !(current==NULL && node.empty());
    }

    /** @return the next smallest number */
    int next() {        
        while(current!=NULL){
            cout<<current->val;
            node.push(current);
            current = current->left;
        }

        prev = node.top();
        node.pop();
        current = prev->right;
        return prev->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
