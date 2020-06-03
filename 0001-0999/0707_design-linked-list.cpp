//Link: https://leetcode.com/problems/design-linked-list/ 
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    struct Node{
        
        Node* next;
        int val;
        Node(int val){this->val = val;this->next = NULL;}
    };
    Node* head;
    int count;
    MyLinkedList() {
        head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    
    Node* getNode(int index ){
        auto node = head;
        while(node && index-->0)
            node = node->next;
        return node;
    }
    int get(int index) {
        auto node = this->getNode(index);
        return node == NULL?-1:node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto node = new Node(val);
        node->next = this->head;
        this->head = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        
        auto node = head;
        while(node && node->next)
            node = node->next;
        if( node ){
            node->next = new Node(val);
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if( index == 0 ){
            this->addAtHead(val);
            return;
        }
        auto node = this->getNode(index-1);
        
        if( node ){
            auto nn = new Node(val);
            nn->next = node->next;
            node->next = nn;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if( index == 0 ){
            if( !head ) return;
            auto tmp = head;
            head = head->next;
            delete tmp;
            return;
        }
        auto node =this->getNode(index-1);
        if( node){
         
            auto tmp = node->next;
            if( tmp ){
                node->next = tmp->next;
                delete tmp;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */