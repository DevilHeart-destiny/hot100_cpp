/**
295. 数据流的中位数
中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。

例如 arr = [2,3,4] 的中位数是 3 。
例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
实现 MedianFinder 类:
MedianFinder() 初始化 MedianFinder 对象。
void addNum(int num) 将数据流中的整数 num 添加到数据结构中。
double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10-5 以内的答案将被接受。

示例 1：
输入
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
输出
[null, null, null, 1.5, null, 2.0]

解释
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
提示:
-105 <= num <= 105
在调用 findMedian 之前，数据结构中至少有一个元素
最多 5 * 104 次调用 addNum 和 findMedian
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> max_heap; // store fist half
    priority_queue<int, vector<int>, greater<int>> min_heap; // store another half
public:
    
    MedianFinder() {
       
    }
    
    void addNum(int num) {
        if(max_heap.empty() || max_heap.top() > num)
        {
            max_heap.push(num);
        }
        else
        {
            min_heap.push(num);
        }
        
        if(max_heap.size() > min_heap.size() + 1)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if(min_heap.size() > max_heap.size() + 1)
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        
    }
    
    double findMedian() {
        if(max_heap.size() == min_heap.size())
        {
            return 0.5 * (max_heap.top() + min_heap.top());
        }
        else
        {
            return max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    cout << obj->findMedian() << endl;
    obj->addNum(3);
    cout << obj->findMedian() << endl;
    return 0;
}