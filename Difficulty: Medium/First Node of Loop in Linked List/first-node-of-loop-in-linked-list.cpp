/*
class Node {
public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int cycleStart(Node* head) {
        // code here
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                break;
            }
        }
        if(slow!=fast){
            return -1;
        }
        Node* temp=head;
        while(temp!=slow){
            temp=temp->next;
            slow=slow->next;
        }
        return temp->data;
        
    }
};