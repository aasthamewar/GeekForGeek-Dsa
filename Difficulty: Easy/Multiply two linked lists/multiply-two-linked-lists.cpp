/* Linked list node structure
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

/*The method multiplies
two  linked lists l1 and l2
and returns their product*/

/* Multiply contents of two linked lists */
class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long MOD = 1000000007;

        long long num1=0;
        while(first){
            num1=num1*10+first->data;
            first=first->next;
        }
        long long num2=0;
        while(second){
            num2=num2*10+second->data;
            second=second->next;
        }
        long long ans=(num1*num2)%MOD;
        return ans;
    }
};