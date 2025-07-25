class Temp{
public:
    int sum;
    bool isBST;
    int count;
    int maxi;
    int mini;
    Temp()
    {
        sum=0;
        isBST=true;
        count=0;
        maxi=INT_MIN;
        mini=INT_MAX;
    }
};

class Solution {
    Temp* solve(int target, Node *root, int &mini)
    {
        if(root==NULL)
        {
            return new Temp();
        }
        Temp* left=solve(target, root->left, mini);
        Temp* right=solve(target, root->right, mini);
        
        Temp* curr=new Temp();
        curr->sum=left->sum+right->sum+root->data;
        curr->isBST=left->isBST && right->isBST && root->data>left->maxi && root->data<right->mini;
        curr->count=left->count+right->count+1;
        curr->maxi=max(root->data, right->maxi);
        curr->mini=min(root->data, left->mini);
        
        if(curr->isBST && curr->sum==target)
        {
            mini=min(mini, curr->count);
        }
        return curr;
    }
public:
    int minSubtreeSumBST(int target, Node *root) {
        // code here
        int mini=INT_MAX;
        solve(target, root, mini);
        if(mini==INT_MAX)
            return -1;
        return mini;
    }
};