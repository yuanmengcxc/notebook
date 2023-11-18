#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class QueueStackAndCircularQueue {
public:
    // 直接使用C++内部的队列实现
    // 内部实际上是双向链表，常数操作较慢
    class Queue1 {//内部实现的
    private:
        queue<int> q;

    public:
        //是否为空
        bool isEmpty() { 
            return q.empty();
        }
        //向队列中加数，加到尾
        void offer(int num) {
            q.push(num);
        }
        //从头拿
        int poll() {
            int front = q.front();
            q.pop();
            return front;
        }
        //返回队列头元素，不弹出
        int peek() {
            return q.front();
        }
        //队列大小
        int size() {
            return q.size();
        }
    };

    // 实际应用中更常见的写法，常数时间复杂度较好
    // 如果可以确定加入操作的总次数不超过n，可以使用此方法
    class Queue2 {//自己定义的
    private:
        int* queue;
        int l;
        int r;
        int limit;

    public:
        Queue2(int n) : limit(n) {
            queue = new int[n];
            l = 0;
            r = 0;
        }

        bool isEmpty() {
            return l == r;
        }

        void offer(int num) {
            queue[r++] = num;
        }

        int poll() {
            return queue[l++];
        }

        int head() {
            return queue[l];
        }
        //队尾元素
        int tail() {
            return queue[r - 1];
        }

        int size() {
            return r - l;
        }
    };

    // 直接使用C++内部的栈实现
    // 内部实际上是动态数组，常数操作较慢
    class Stack1 {
    private:
        stack<int> s;

    public:
        bool isEmpty() {
            return s.empty();
        }

        void push(int num) {
            s.push(num);
        }

        int pop() {
            int top = s.top();
            s.pop();
            return top;
        }

        int peek() {
            return s.top();
        }

        int size() {
            return s.size();
        }
    };

    // 实际应用中更常见的写法，常数时间复杂度较好
    // 如果可以保证同时在栈中的元素个数不会超过n，可以使用此方法
    class Stack2 {
    private:
        int* stack;
        int size;

    public:
        Stack2(int n) {
            stack = new int[n];
            size = 0;
        }

        bool isEmpty() {
            return size == 0;
        }

        void push(int num) {
            stack[size++] = num;
        }

        int pop() {
            return stack[--size];
        }

        int peek() {
            return stack[size - 1];
        }

        int Size() {
            return size;
        }
    };

    // 设计循环队列
    class MyCircularQueue {
    private:
        int* queue;
        int l, r, size, limit;

    public:
        MyCircularQueue(int k) : limit(k) {
            queue = new int[k];
            l = r = size = 0;
        }
        //加入数
        bool enQueue(int value) {
            if (isFull()) {//队列满，返回false
                return false;
            }
            else {
                queue[r] = value;//没满，放在r位置
                r = (r + 1) % limit;//r==limit则回到0位置  r = r==(limit - 1) ? 0 : (r+1);
                size++;
                return true;
            }
        }
        //弹出数
        bool deQueue() {
            if (isEmpty()) {
                return false;
            }
            else {
                l = (l + 1) % limit;
                size--;
                return true;
            }
        }
        //返回队列头部数
        int Front() {
            if (isEmpty()) {
                return -1;//没有数
            }
            else {
                return queue[l];
            }
        }

        int Rear() {
            if (isEmpty()) {
                return -1;
            }
            else {  
                 //              r(当前加入的数)
                //       r-1(队尾)
                //r=0                          limit-1(队尾)
                int last = r == 0 ? (limit - 1) : (r - 1);
                return queue[last];
            }
        }
        //是否空
        bool isEmpty() {
            return size == 0;
        }
        //是否满
        bool isFull() {
            return size == limit;
        }
    };
};

int main() {
    QueueStackAndCircularQueue::MyCircularQueue obj = QueueStackAndCircularQueue::MyCircularQueue(5);
    obj.enQueue(6);
    cout << obj.Front() << endl;

    return 0;
}