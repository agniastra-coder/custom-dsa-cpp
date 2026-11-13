#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Linked List Node to hold TreeNode pointers inside the Queue
class QueueNode {
public:
    TreeNode* treeNode;
    QueueNode* next;

    QueueNode(TreeNode* node) {
        treeNode = node;
        next = nullptr;
    }
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;
    int count;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    bool isEmpty() { return front == nullptr; }

    int getSize() { return count; }

    void enqueue(TreeNode* node) {
        QueueNode* newNode = new QueueNode(node);
        count++;
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    TreeNode* dequeue() {
        if (isEmpty()) {
            return nullptr;
        }
        QueueNode* temp = front;
        TreeNode* poppedNode = front->treeNode;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        count--;
        return poppedNode;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
