#include <iostream> 

using namespace std;

struct Node { 
    int data; 
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};



// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    Node *p = new Node(data);
    if(head == NULL) return p;
    p -> next = head;
    return p;

}

// print the list content on a line
void print(Node* head) {
    Node *p = head;
    for(; p -> next != NULL; p = p -> next)
        std::cout << p -> data <<" ";
    std::cout << p -> data << endl;

}

// return the new head of the reversed list
Node* reverse(Node* head) {
    if(head -> next == NULL)    
        return head;

    Node *k;
    Node* p = head -> next;
    Node* temp = new Node(head -> data);
    while(p != NULL){
        k = new Node(p -> data);
        k -> next = temp;
        temp = k;
        p = p -> next;
    }
    return k;

}
  
int main() {
    int n, u;
    std::cin >> n;
    Node* head = NULL;

    for (int i = 0; i < n; ++i){
        std::cin >> u;
        head = prepend(head, u);
    } 
    
    std::cout << "Original list: ";
    print(head);

    head = reverse(head);
    
    std::cout << "Reversed list: ";
    print(head);

    return 0; 
}