/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* temp=head;
        int zero=0,ones=0,twos=0;
        while(temp){
            if(temp->data == 0){
                zero++;
            }
            else if(temp->data == 1){
                ones++;
            }
            else{
                twos++;
            }
            temp=temp->next;
        }
        
        temp=head;
        while(zero--){
            temp->data=0;
            temp=temp->next;
        }
        while(ones--){
            temp->data=1;
            temp=temp->next;
        }
        while(twos--){
            temp->data=2;
            temp=temp->next;
        }
        return head;
    }
};