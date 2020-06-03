//Link: https://leetcode.com/problems/design-skiplist/ 
struct Node{
    Node *right;
    Node *down;
    int val;
    Node(int num = INT_MIN) {
        right = nullptr;
        down = nullptr;
        val = num;
    }
};
class Skiplist {
public:
    Node* head;
    Skiplist() {
        head = new Node();
    }
    
    bool search(int target) {
        auto node = head;
        while(node) {
            while(node->right && node->right->val < target)
                node = node->right;
            if(node->right && node->right->val == target) return true;
            node = node->down;
        }
        return false;
    }
    
    Node* help(int num, Node* prev) {
        while(prev->right && prev->right->val < num) 
            prev = prev->right;
        auto right = prev->right;
        if(prev->down) {
            auto newDownNode = help(num, prev->down);
            if(newDownNode) {
                prev->right = new Node(num);
                prev->right->down = newDownNode;
                prev->right->right = right;
                return rand() % 2 ? prev->right :NULL;
            }
            return NULL;
        }else {
            prev->right = new Node(num);
            prev->right->right = right;
            return rand() % 2 ? prev->right: NULL;
        }
    }
    void add(int num) {
        auto newDownNode = help(num, head);
        if(newDownNode) {
            auto newHead = new Node();
            newHead->right = new Node(newDownNode->val);
            newHead->down = head;
            newHead->right->down = newDownNode;
            head = newHead;
        }
    }
    
    bool erase(int num) {
        auto node = head;
        while(node) {
            while(node->right && node->right->val < num)
                node = node->right;
            if(node->right && node->right->val == num) break;
            node = node->down;
        }
        if(!node) return false;
        auto deleteNode = node->right;
        while(deleteNode) {
            node->right = deleteNode->right;
            auto nextDown = deleteNode->down;
            node = node->down;
            while(node && node->right != nextDown)
                node = node->right;
            delete deleteNode;
            deleteNode = nextDown;
        }
        return true;
        
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */