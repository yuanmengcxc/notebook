#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class QueueStackAndCircularQueue {
public:
    // ֱ��ʹ��C++�ڲ��Ķ���ʵ��
    // �ڲ�ʵ������˫������������������
    class Queue1 {//�ڲ�ʵ�ֵ�
    private:
        queue<int> q;

    public:
        //�Ƿ�Ϊ��
        bool isEmpty() { 
            return q.empty();
        }
        //������м������ӵ�β
        void offer(int num) {
            q.push(num);
        }
        //��ͷ��
        int poll() {
            int front = q.front();
            q.pop();
            return front;
        }
        //���ض���ͷԪ�أ�������
        int peek() {
            return q.front();
        }
        //���д�С
        int size() {
            return q.size();
        }
    };

    // ʵ��Ӧ���и�������д��������ʱ�临�ӶȽϺ�
    // �������ȷ������������ܴ���������n������ʹ�ô˷���
    class Queue2 {//�Լ������
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
        //��βԪ��
        int tail() {
            return queue[r - 1];
        }

        int size() {
            return r - l;
        }
    };

    // ֱ��ʹ��C++�ڲ���ջʵ��
    // �ڲ�ʵ�����Ƕ�̬���飬������������
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

    // ʵ��Ӧ���и�������д��������ʱ�临�ӶȽϺ�
    // ������Ա�֤ͬʱ��ջ�е�Ԫ�ظ������ᳬ��n������ʹ�ô˷���
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

    // ���ѭ������
    class MyCircularQueue {
    private:
        int* queue;
        int l, r, size, limit;

    public:
        MyCircularQueue(int k) : limit(k) {
            queue = new int[k];
            l = r = size = 0;
        }
        //������
        bool enQueue(int value) {
            if (isFull()) {//������������false
                return false;
            }
            else {
                queue[r] = value;//û��������rλ��
                r = (r + 1) % limit;//r==limit��ص�0λ��  r = r==(limit - 1) ? 0 : (r+1);
                size++;
                return true;
            }
        }
        //������
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
        //���ض���ͷ����
        int Front() {
            if (isEmpty()) {
                return -1;//û����
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
                 //              r(��ǰ�������)
                //       r-1(��β)
                //r=0                          limit-1(��β)
                int last = r == 0 ? (limit - 1) : (r - 1);
                return queue[last];
            }
        }
        //�Ƿ��
        bool isEmpty() {
            return size == 0;
        }
        //�Ƿ���
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