    bool isIdentical(TreeNode* root, TreeNode* subRoot){
        if(root == NULL || subRoot == NULL)
            return root == subRoot;
        
        return root->val == subRoot->val &&
            isIdentical(root->left, subRoot->left) &&
            isIdentical(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(subRoot == NULL)
            return true;
        if(root == NULL)
            return false;
        if(isIdentical(root, subRoot))
            return true;
    
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);     
        
        }

Using serialization;
string serialise(TreeNode* root){
        if(root == NULL) return "";
        string l = serialise(root->left);
        string r = serialise(root->right);
        string ret = "(" + l + to_string(root->val) + r + ")";
        return ret;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string x = serialise(t);
        string y = serialise(s);
        if (y.find(x) != string::npos) {
            return true;
        }        
        return false;
    }
