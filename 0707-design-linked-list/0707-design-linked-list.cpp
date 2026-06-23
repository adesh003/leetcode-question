class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
    }
};

class MyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

    // O(K)
    Node* getKthNode(int k) {
        if(k >= size) return NULL;
        auto ptr = head;
        for(int i = 0; i < k; i++) {
            ptr = ptr->next;
        }   
        return ptr;
    }

public:    

    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // O(K)
    int get(int index) {
        auto node = getKthNode(index);
        return node == NULL ? -1 : node->val;
    }
    
    // O(1)
    void addAtHead(int val) {
        auto newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
        if(size == 1) {
            tail = head;
        }
    }
    
    // O(1)
    void addAtTail(int val) {
        if(size == 0) {
            addAtHead(val);   
        } else {
            auto newNode = new Node(val);
            tail->next = newNode;
            tail = newNode;
            size++;
        }
    }
    
    // O(K)
    void addAtIndex(int index, int val) {
        if(index > size) {
            return;
        }
    
        if(index == 0) {
            addAtHead(val);
            return;
        }

        if(index == size) {
            addAtTail(val);
            return;
        }

        auto newNode = new Node(val);
        auto prev = getKthNode(index - 1);
        newNode->next = prev->next;
        prev->next = newNode;

        size++;
    }
    
    // O(K)
    void deleteAtIndex(int index) {
        if(index >= size) { 
            return;
        }

        Node* temp;

        if(index == 0) {
            temp = head;
            head = head->next;
        } else {
            auto prev = getKthNode(index - 1);
            temp = prev->next;
            prev->next = temp->next;
            if(index == size - 1) {
                tail = prev;
            }
        }

        size--;
        delete temp;
    }
};
