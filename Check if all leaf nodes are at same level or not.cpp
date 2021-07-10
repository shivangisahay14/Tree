int levelOfleaf=0;
    bool leavesAtSameLevel(Node *root,int level){
        if(root==NULL) return true;
        
        if(root->left == NULL && root->right== NULL){
            if(levelOfleaf==0){
                levelOfleaf=level;
                return true;
            }
            return levelOfleaf==level;
        }
        return leavesAtSameLevel(root->left,level+1) && leavesAtSameLevel(root->right,level+1);
    }
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        int level=0;
        return leavesAtSameLevel(root,level);
    }
