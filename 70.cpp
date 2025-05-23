/**
155. 最小栈
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:
MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。
 
示例 1:
输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
 */

#include<iostream>
#include<stack>

using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> min_st;
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        if(min_st.empty() || val <= min_st.top())
        {
            min_st.push(val);
        }
    }
    
    void pop() {
        
        if(st.top() == min_st.top())
        {
            min_st.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main()
{
    MinStack* obj = new MinStack();
    obj->push(99);
    obj->push(12);
    obj->push(3);
    obj->push(16);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    cout << param_3 << ' ' << param_4 << endl;
    return 0;
}