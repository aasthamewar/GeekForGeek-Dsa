/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k <= 1) return head;

        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        // Count nodes in the current group
        Node* temp = head;
        int count = 0;
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }

        // Reverse all nodes in this group (even if < k, as per problem)
        curr = head;
        int i = 0;
        while (curr && i < count) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }

        // Recur for the remaining list
        if (next)
            head->next = reverseKGroup(next, k);

        return prev; // new head of the reversed segment
    }
};
