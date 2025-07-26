/*
struct LNode { //Linked List
    int data;
    struct LNode* next;
    LNode(int x){
        data = x;
        next = NULL; }
};
struct TNode {   //Tree
    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x){
        data=x;
        left=right=NULL; }
}; */
class Solution {
  public:
    LNode* current;

    // Count the total number of nodes in the linked list
    int countNodes(LNode* head) {
        int count = 0;
        while (head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }

    // Recursive helper function to construct BST
    TNode* convertListToBST(int n) {
        if (n <= 0) return NULL;

        // Recursively build the left subtree
        TNode* left = convertListToBST(n / 2);

        // Current list node becomes the root
        TNode* root = new TNode(current->data);
        root->left = left;

        // Move to the next list node
        current = current->next;

        // Recursively build the right subtree
        root->right = convertListToBST(n - n / 2 - 1);

        return root;
    }

    // Main function
    TNode* sortedListToBST(LNode* head) {
        int n = countNodes(head);
        current = head;
        return convertListToBST(n);
    }
};