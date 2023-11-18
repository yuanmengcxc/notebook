#include <deque>

class MyCircularDeque1 {
public:
    std::deque<int> deque;
    int size;
    int limit;

    MyCircularDeque1(int k) {
        size = 0;
        limit = k;
    }
    //头部插入
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        else {
            deque.push_front(value);
            size++;
            return true;
        }
    }
    //尾部插入
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        else {
            deque.push_back(value);
            size++;
            return true;
        }
    }
    //头部删除
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        else {
            size--;
            deque.pop_front();
            return true;
        }
    }
    //尾部删除
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        else {
            size--;
            deque.pop_back();
            return true;
        }
    }
    //得到头部数
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        else {
            return deque.front();
        }
    }
    //得到尾部数
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        else {
            return deque.back();
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == limit;
    }
};

// 使用数组实现
class MyCircularDeque2 {
public:
    int* deque;
    int l, r, size, limit;

    MyCircularDeque2(int k) {
        deque = new int[k];
        l = r = size = 0;
        limit = k;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        else {
            if (isEmpty()) {
                l = r = 0;
                deque[0] = value;
            }
            else {
                l = l == 0 ? (limit - 1) : (l - 1);
                deque[l] = value;
            }
            size++;
            return true;
        }
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        else {
            if (isEmpty()) {
                l = r = 0;
                deque[0] = value;
            }
            else {
                r = r == limit - 1 ? 0 : (r + 1);
                deque[r] = value;
            }
            size++;
            return true;
        }
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        else {
            l = (l == limit - 1) ? 0 : (l + 1);
            size--;
            return true;
        }
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        else {
            r = r == 0 ? (limit - 1) : (r - 1);
            size--;
            return true;
        }
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        else {
            return deque[l];
        }
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        else {
            return deque[r];
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == limit;
    }

    ~MyCircularDeque2() {
        delete[] deque; // 释放动态分配的内存
    }
};

int main() {
    return 0;
}