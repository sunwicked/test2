/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    
public:
    
    void preorder(TreeNode *root, string &s){
        if(root == NULL) return ;
        s = s+ to_string(root->val)+" ";
        preorder(root->left,s);
        preorder(root->right,s);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string str = "";
        preorder(root,str);
        str.pop_back();
      //  cout<<str;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserializeHelper(vector<int> &data, int &index,int &len, int lo, int hi){
        if(index>=len-1) return NULL;
        TreeNode* root = NULL;
        int x = data[index+1];
        if(x >= lo && x<= hi){
            root = new TreeNode(data[++index]);
            root->left = deserializeHelper(data,index,len,lo,data[index]);
            root->right = deserializeHelper(data,index,len,data[index],hi);
        }
        return root;
    }
    
    TreeNode* deserialize(string data) {
        if (data.size()==0) return NULL;
        stringstream ss(data);
        vector<int> dat;
        string s;
        while(getline(ss,s,' ')){
            int x = stoi(s);
            dat.push_back(x);
        }
        int len = dat.size();
        int index = -1;
        return deserializeHelper(dat,index,len,INT_MIN,INT_MAX);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));