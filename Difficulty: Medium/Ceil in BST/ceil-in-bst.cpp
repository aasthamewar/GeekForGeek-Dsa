/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int slove(Node* root, int input,int &parent){
    if(root->data == input)
        return root->data;
    else if(root->data >input && root->left){
        parent = root->data;
        return slove(root->left,input,parent);
    }
    else if(root->data >input && root->left==NULL)
        return root->data;
    else if(root->data <input && root->right)
        return slove(root->right,input,parent);
    else if(root->data <input && root->right==NULL)
        return parent;
}

int findCeil(Node* root, int input) {
    // Your code here
    int a=-1;
    return slove(root,input,a);
}