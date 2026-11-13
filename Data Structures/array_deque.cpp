class Deque {
private:
    int* a;
    int front;
    int end;
    int capacity;

public:
    Deque(int cap = 1000000) {
        capacity = cap;
        a = new int[capacity];
        front = 0;
        end = 0;
    }

    // Insert at the front of the deque: O(n)
    void pushFront(int val) {
        if (end >= capacity) return;
        for (int i = end; i > front; i--) {
            a[i] = a[i - 1];
        }
        a[front] = val;
        end++;
    }

    // Insert at the back of the deque: O(1)
    void pushBack(int val) {
        if (end >= capacity) return;
        a[end] = val;
        end++;
    }

    // Remove and return from the front: O(1)
    int popFront() {
        if (front == end) {
            return -1;
        }
        int d = a[front];
        front++;
        return d;
    }

    // Remove and return from the back: O(1)
    int popBack() {
        if (front == end) {
            return -1;
        }
        end--;
        return a[end];
    }

    bool isEmpty() {
        return front == end;
    }

    ~Deque() {
        delete[] a;
        front = 0;
        end = 0;
    }
};
