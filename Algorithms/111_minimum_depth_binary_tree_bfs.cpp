#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        Queue Q;
        Q.enqueue(root);
        int depth = 1;

        while (!Q.isEmpty()) {
            int levelSize = Q.getSize(); // Number of nodes at the current level

            for (int i = 0; i < levelSize; i++) {
                TreeNode* temp = Q.dequeue();

                // The first time we hit a leaf node, that's our minimum depth!
                if (temp->left == nullptr && temp->right == nullptr) {
                    return depth;
                }

                if (temp->left != nullptr) {
                    Q.enqueue(temp->left);
                }
                if (temp->right != nullptr) {
                    Q.enqueue(temp->right);
                }
            }
            depth++; // Move to the next level
        }

        return depth;
    }
};
