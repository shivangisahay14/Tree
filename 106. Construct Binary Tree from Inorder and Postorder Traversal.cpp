TreeNode* buildTree(vector<int>inorder,vector<int>postorder,int psi,int pei,int isi,int iei){
    
        if(isi>iei ) return NULL;
        
        TreeNode *node=new TreeNode(postorder[pei]);
        int idx=isi;
        while(inorder[idx]!=postorder[pei]){
            idx++;
        }
        int countLSE=idx-isi;
        
        
        if(isi==iei){
            return node;
        }
        node->left=buildTree(inorder,postorder,psi,psi+countLSE-1,isi,idx-1);
        node->right=buildTree(inorder,postorder,psi+countLSE,pei-1,idx+1,iei);
        
        return node;
    
    
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
         if(n==0) return NULL;
        
        return buildTree(inorder,postorder,0,n-1,0,n-1);
        
    }
