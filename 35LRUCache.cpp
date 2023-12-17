#include<iostream>
#include<unordered_map>

class LRUCache {
private:
    struct DoubleNode {
        int key;
        int value;
        DoubleNode* last;
        DoubleNode* next;
        DoubleNode(int k, int v) :key(k), value(v), last(nullptr), next(nullptr) {}
    };
    //双链表的操作
    class DoubleList {
    private:
        DoubleNode* head;
        DoubleNode* tail;
    public:
        DoubleList():head(nullptr),tail(nullptr){}
        //添加节点
        void addNode(DoubleNode* newNode) {
            if (newNode == nullptr) {
                return;
            }
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                newNode->last = tail;
                tail = newNode;
            }
        }
        //移动节点到tail（尾）
        void moveNodeToTail(DoubleNode* node) {
            if (tail == node) {
                return;
            }
            if (head == node) {
                head = head->next;
                head->last = nullptr;
            }
            else {
                node->last->next = node->next;
                node->next->last = node->last;
            }
            node->last = tail;
            tail->next = node;
            node->next = nullptr;
            tail = node;
        }
        //移除头节点，并返回移除的头节点
        DoubleNode* removeHead() {
            if (head == nullptr) {
                return nullptr;
            }
            DoubleNode* ans;
            ans = head;
            if (head == tail) {
                head = nullptr;
                tail = nullptr;
            }
            else {
                head = head->next;
                head->last = nullptr;
                ans->next = nullptr;
            }
            return ans;
        }
    };

    std::unordered_map<int, DoubleNode*> keyNodeMap;
    DoubleList nodeList;
    int cap;//双链表上限

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (keyNodeMap.count(key)) {
            DoubleNode* ans = keyNodeMap[key];
            nodeList.moveNodeToTail(ans);
            return ans->value;
        }
        else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (keyNodeMap.count(key)) {
            DoubleNode* node = keyNodeMap[key];
            node->value = value;
            nodeList.moveNodeToTail(node);
        }
        else {
            if (keyNodeMap.size() == cap) {
                int headKey = nodeList.removeHead()->key;
                keyNodeMap.erase(headKey);
            }
            DoubleNode* newNode = new DoubleNode(key, value);
            keyNodeMap[key] = newNode;
            nodeList.addNode(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */