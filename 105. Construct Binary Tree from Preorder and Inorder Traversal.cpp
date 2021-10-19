 TreeNode* buildTree( vector<int> inorder,vector<int> preorder,int psi,int pei,int isi,int iei){
        if(isi>iei or psi>pei) return NULL;
        
        TreeNode *node=new TreeNode(preorder[psi]);
        if(isi==iei){
            return node;
        }
        
        int idx=isi;
        while(inorder[idx]!=preorder[psi]){
            idx++;
        }
        int countLSE=idx-isi;        
        
        node->left=buildTree(inorder,preorder,psi+1,psi+countLSE,isi,idx-1);
        node->right=buildTree(inorder,preorder,psi+countLSE+1,pei,idx+1,iei);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n= preorder.size();
        return buildTree(inorder,preorder,0,n-1,0,n-1);        
        
    }
