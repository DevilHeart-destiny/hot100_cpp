/**
146. LRU 缓存
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。
如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。


示例：
输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4
 */

#include<iostream>
#include<unordered_map>

using namespace std;

struct dlistnode
{
    int key,val;
    dlistnode* prev;
    dlistnode* next;
    dlistnode() : key(0),val(0),prev(nullptr),next(nullptr) {}
    dlistnode(int key, int val) : key(key),val(val),prev(nullptr),next(nullptr) {}
};

class LRUCache {
    unordered_map<int,dlistnode*> hash;
    dlistnode* head;
    dlistnode* tail;
    int cap;
    int size;

    public:
    LRUCache(int capacity) {
        head = new dlistnode();
        tail = new dlistnode();
        head->next = tail;
        tail->prev = head;
        size = 0;
        cap = capacity;
    }
    
    int get(int key) {
        if(hash.find(key) != hash.end())
        {
            dlistnode* node = hash[key];
            move_to_head(node);
            return node->val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(hash.find(key) != hash.end())
        {
            dlistnode* node = hash[key];
            node->val = value;
            move_to_head(node);
        }
        else{
            dlistnode* node = new dlistnode(key,value);
            hash[key] = node;
            add_to_head(node);
            size++;
            if(size > cap)
            {
                dlistnode* removed = remove_from_tail();
                hash.erase(removed->key);
                delete removed;
                size--;
            }
            
        }
    }

    void move_to_head(dlistnode* node)
    {
        remove_node(node);
        add_to_head(node);
    }

    void add_to_head(dlistnode* node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    dlistnode* remove_from_tail()
    {
        dlistnode* node = tail->prev;
        remove_node(node);
        return node;
    }

    void remove_node(dlistnode* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{
    int capacity = 3;
    int key = 1;
    int value = 2;
    LRUCache* obj = new LRUCache(capacity);
    int param_1 = obj->get(key);
    obj->put(key,value);
    cout << obj->get(key) << endl;
    return 0;
}