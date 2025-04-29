/**
用于实现经典的排序算法
八大排序算法主要分为五大类：插入排序(直接插入排序，希尔排序)，选择排序(直接选择排序，堆排序)，交换排序(冒泡排序，快速排序)，归并排序，计数排序
 */

#include<iostream>
#include<vector>
#include<stack>


using namespace std;

class my_sort
{
public:
    // 插入排序
    // 1 直接插入排序 O(N*N)
    // 直接插入排序是一种简单明了的插入排序法，其基本思想是：把待排序的数据按其关键码值的大小逐个插入到一个已经排好序的有序序列中，直到所有数据插入完为止。
    void zhijie_charu_sort(vector<int>& nums)
    {
        for(int i = 0; i < nums.size()-1; i++)
        {
            int end = i;
            int tmp = nums[end+1];
            while(end >= 0)
            {
                if(tmp < nums[end])
                {
                    nums[end+1] = nums[end];
                    end--;
                }
                else break;
            }
            nums[end+1] = tmp;
        }
    }
    // 2 希尔排序 O(NLOGN)
    // 希尔排序法又称缩小增量法。希尔排序其实是直接插入排序的改进。其基本思想是：先选定一个整数gap，把待排序文件中所有记录分成数组，
    // 所有距离为gap的记录分在同一组内，并对每一组内的记录进行排序。然后缩小gap，重复上述步骤，当gap == 1时，所有记录在统一组内已经排好序。
    void xier_sort(vector<int>& nums)
    {
        int gap = nums.size();
        while(gap > 1)
        {
            gap /= 2;
            for(int i = 0; i < nums.size() - gap; i++)
            {
                int end = i;
                int tmp = nums[end+gap];
                while(end >= 0)
                {
                    if(tmp < nums[end])
                    {
                        nums[end+gap] = nums[end];
                        end -= gap;
                    }
                    else break;
                }
                nums[end+gap] = tmp;
            }
        }
    }
    // 选择排序
    // 3 直接选择排序 O(N*N)
    // 3.1 //利用直接交换数组元素，从小到大排列数组
    void zhijie_xuanze_sort_v1(vector<int>& nums)
    {
        for(int i = 0; i < nums.size()-1; i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[i] > nums[j])
                {
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
            }
        }
    }
    // 3.2 利用元素下标间接交换数组元素，从大到小排列数组
    void zhijie_xuanze_sort_v2(vector<int>& nums)
    {
        for(int i = 0; i < nums.size()-1; i++)
        {
            int max = i;
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[j] > nums[max]) max = j;
            }
            if(max != i)
            {
                int tmp = nums[i];
                nums[i] = nums[max];
                nums[max] = tmp;
            }
        }
    }
    // 3.3 双指针改进 上面的直接选择排序每一次只能选出一个数据，但是，我们可以用双指针的方法进行改进，做到每一次可以选出两个数据
    void zhijie_xuanze_sort_v3(vector<int>& nums)
    {
        int begin = 0;
        int end = nums.size()-1;
        while(begin < end)
        {
            int min_index = begin;
            int max_index = end;
            for(int i = begin; i <= end; i++)
            {
                if(nums[i] < nums[min_index]) min_index = i;
                if(nums[i] > nums[max_index]) max_index = i;
            }
            // swap min
            swap(nums[begin],nums[min_index]);
            
            //对max_index进行修正 !!!!
            if(begin == max_index)
            {
                max_index = min_index;
            }

            // swap max
            swap(nums[end],nums[max_index]);
            
            begin++;
            end--;
        }
    }
    // 4 堆排序 O(NLOGN)
    // 先构建大顶堆，每次选择堆顶的元素作为最大的数，每次选择后将最后一个元素替补到堆顶并进行移动，使得堆顶变为当前序列中最大的
    // 构建大堆
    void AdjustDown(vector<int>& nums, int numsize, int root)
    {
        int parent = root;
        int child = parent * 2 + 1;
        while(child < numsize)
        {
            if(child+1 < numsize && nums[child] < nums[child+1])
            {
                child++;
            }
            if(nums[parent] < nums[child])
            {
                swap(nums[parent],nums[child]);
                parent = child;
                child = parent * 2 + 1;
            }
            else break;
        }
    }
    // 堆排序
    void dui_sort(vector<int>& nums)
    {
        // 建堆
        for(int i = (nums.size()-2)/2; i >= 0; i--)
        {
            AdjustDown(nums,nums.size(),i);
        }
        // 排序
        int end = nums.size() - 1;
        while(end > 0)
        {
            swap(nums[0],nums[end]);
            AdjustDown(nums,end,0);
            end--;
        }
    }
    // 交换排序
    // 5 冒泡排序 O(N*N)
    // 以升序排序为例：比较相邻元素，如果前面的比后面的元素大，则两元素交换位置;对每一对相邻元素进行比较，大的放后，这样最后的元素将是最大的元素
    // 对越来越少的混乱元素重复上述步骤（最后的元素已经有序，不需比较），直到没有元素需要交换位置
    // 5.1经典版本，每次找到最大的那个数
    void maopao_sort_v1(vector<int>& nums)
    {
        for(int i = 0; i < nums.size()-1; i++)
        {
            for(int j = 0; j < nums.size()-1-i; j++)
            {
                if(nums[j] > nums[j+1])
                {
                    swap(nums[j],nums[j+1]);
                }
            }
        }
    }
    // 5.2稍加优化 如果在一趟遍历中未发生交换，就可以说明数组已经有序
    void maopao_sort_v2(vector<int>& nums)
    {
        bool is_changed;
        for(int i = 0; i < nums.size()-1; i++)
        {
            is_changed = false;
            for(int j = 0; j < nums.size()-1-i; j++)
            {
                if(nums[j] > nums[j+1])
                {
                    swap(nums[j],nums[j+1]);
                    is_changed = true;
                }
            }
            if(!is_changed) return;
        }
    }
    // 6 快速排序 O(NLOGN)
    // 任取待排序元素序列中的某个元素作为基准值，按照该排序码将待排序集合分割成两个子序列，
    // 左子序列中所有元素均小于基准值，右子序列中所有元素均大于基准值，然后左右子序列重复该过程，直到所有元素都排列在相应位置上为止。
    // 6.1 挖坑法
    void quick_sort_v1(vector<int>& nums, int begin, int end)
    {
        if(begin >= end) return;

        int key = nums[begin];
        int pivot = begin;
        int left = begin;
        int right = end;

        while(left < right)
        {
            while(left < right && nums[right] >= key)
            {
                right--;
            }
            nums[pivot] = nums[right];
            pivot = right;

            while(left < right && nums[left] <= key)
            {
                left++;
            }
            nums[pivot] = nums[left];
            pivot = left;
        }
        nums[pivot] = key;

        quick_sort_v1(nums,begin,pivot-1);
        quick_sort_v1(nums,pivot+1,end);
    }
    // 6.2 左右指针法
    // 不同点在于：左右指针法不会挖坑，而是在在右边的right找到小于key的数后，直接让左边的left找大于key的数，然后交换这两个值
    void quick_sort_v2(vector<int>& nums, int begin, int end)
    {
        if(begin >= end) return;

        int key = nums[begin];
        int left = begin;
        int right = end;

        while(left < right)
        {
            while(left < right && nums[right] >= key)
            {
                right--;
            }
            while(left < right && nums[left] <= key)
            {
                left++;
            }
            swap(nums[left],nums[right]);
        }
        swap(nums[begin],nums[left]);

        quick_sort_v2(nums,begin,left-1);
        quick_sort_v2(nums,left+1,end);
    }
    // 6.3 前后指针法
    // 前后指针法和前面两种方法不同，这里要定义指针prev指向待排区域的起始位置，指针cur指向prev的后一个位置
    // 令cur不断向右移动遍历待排区域，当碰到小于基准值key的数就停止，同时让prev也向右移动一个（即prev++），交换prev和cur位置的数据不断循环，直到cur遍历完整个数组
    // 最后，再将基准值放到正确的位置，即将最后prev和begin位置的元素交换位置
    void quick_sort_v3(vector<int>& nums, int begin, int end)
    {
        if(begin >= end) return;

        int key = nums[begin];
        int prev = begin;
        int cur = prev;

        while(cur <= end)
        {
            if(nums[cur] < key && ++prev != cur)
            {
                swap(nums[prev],nums[cur]);
            }
            cur++;
        }
        swap(nums[begin],nums[prev]);

        quick_sort_v3(nums,begin,prev-1);
        quick_sort_v3(nums,prev+1,end);
    }
    // 6.4 非递归法
    // 利用数据结构中的栈，来进行模拟递归,其中每一趟排序使用挖坑法
    int wakeng_yitang(vector<int>& nums, int begin, int end)
    {
        int key = nums[begin];
        int pivot = begin;
        int left = begin;
        int right = end;

        while(left < right)
        {
            while(left < right && nums[right] >= key)
            {
                right--;
            }
            nums[pivot] = nums[right];
            pivot = right;

            while(left < right && nums[left] <= key)
            {
                left++;
            }
            nums[pivot] = nums[left];
            pivot = left;
        }
        nums[pivot] = key;
        return pivot;
    }
    void quick_sort_v4(vector<int>& nums, int begin, int end)
    {
        stack<int> st;
        st.push(end);
        st.push(begin);
        while(!st.empty())
        {
            int b = st.top();
            st.pop();
            int e = st.top();
            st.pop();
            int pivot = wakeng_yitang(nums,b,e);

            if(e-pivot > 0)
            {
                st.push(e);
                st.push(pivot+1);
            }
            if(pivot-b > 0)
            {
                st.push(pivot-1);
                st.push(b);
            }
        }
    }
    // 6.5 优化：三数取中
    // 三数取中：比较待排区间两端点和中间的数，选择不大不小的那一个，和左端点的值交换，再将左端点的值作为基准值key
    int GetMid(vector<int>& nums, int left, int right)
    {
        int mid = (right - left) / 2 + left;
        if (nums[left] <= nums[mid])
        {
            if (nums[right] > nums[mid])
                return mid;
            else if (nums[right] > nums[left])
                return right;
            else
                return left;
        }
        else    //nums[left] > nums[mid]
        {
            if (nums[right] > nums[left])
                return left;
            else if (nums[right] > nums[mid])
                return right;
            else
                return mid;
        }
    }
    void quick_sort_v5(vector<int>& nums, int begin, int end)
    {
        if (begin >= end)
         return;
 
        /*
            为了不改变后序代码的逻辑
            三数取中后，应交换中间数和开头数
        */
        int index = GetMid(nums, begin, end);
        swap(nums[index], nums[begin]);
    
        int key = nums[begin];  //基准值
        int pivot = begin;      //坑的位置
        int left = begin;       //区间最左边
        int right = end;    //区间最右边
        while (left < right)
        {
            //right不断向左移动，找到小于key的数
            while (left < right && nums[right] >= key)
                right--;
            //将满足条件的数“挖走”，并填入坑pivot中
            nums[pivot] = nums[right];
            //被挖走数字的区域变成新的坑
            pivot = right;
    
            //left不断向右移动，找到大于key的数
            while (left < right && nums[left] <= key)
                left++;
            //将满足条件的数“挖走”，并填入坑pivot中
            nums[pivot] = nums[left];
            //被挖走数字的区域变成新的坑
            pivot = left;
        }

        //将基准值填入最后坑的位置
        nums[pivot] = key;

        quick_sort_v5(nums, begin, pivot - 1);
        quick_sort_v5(nums, pivot + 1, end);

    }
    // 7 归并排序 O(NLOGN)
    // 归并排序是建立在归并操作上的一种有效的排序算法，该算法是采用分治法的一个非常典型的应用：
    // 将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。
    // 7.1 递归写法
    void sub_guibing(vector<int>& nums, vector<int>& tmp, int left, int right)
    {
        if(left >= right) return;

        int mid = (right-left)/2+left;
        sub_guibing(nums,tmp,left,mid);
        sub_guibing(nums,tmp,mid+1,right);

        int begin1 = left;
        int end1 = mid;
        int begin2 = mid+1;
        int end2 = right;
        int index = left;

        while(begin1 <= end1 && begin2 <= end2)
        {
            if(nums[begin1]<nums[begin2])
            {
                tmp[index++] = nums[begin1++];
            }
            else{
                tmp[index++] = nums[begin2++];
            }
        }
        while(begin1 <= end1)
        {
            tmp[index++] = nums[begin1++];
        }
        while(begin2 <= end2)
        {
            tmp[index++] = nums[begin2++];
        }

        for(int i = left; i <= right; i++)
        {
            nums[i] = tmp[i];
        }
    }
    void guibing_sort_v1(vector<int>& nums)
    {
        vector<int> tmp;
        tmp.resize(nums.size());
        sub_guibing(nums,tmp,0,nums.size()-1);
    }
    // 7.2 非递归
    // 两个单个数字可以直接合并成一个有序序列。
    // 因此我们定义gap，表示每次合并的两个序列长度为gap，gap从1递增，直到不能满足条件gap < numsSize，然后就进行和递归相同的合并操作就可以了
    void guibing_sort_v2(vector<int>& nums)
    {
        vector<int> tmp(nums.size());

        int gap = 1;

        while(gap < nums.size())
        {
            /*
             因为每次是对两个有序序列进行合并
             因此每次合并过后i应该跳过两个序列长度
            */
            for(int i = 0; i < nums.size(); i += 2*gap)
            {
                int begin1 = i;
                int end1 = i+gap-1;
                int begin2 = i+gap;
                int end2 = i+2*gap-1;
                int index = begin1;

                /*
                 如果右半区间不存在，只有左半区间
                 说明待合并的只有一个区间
                 显然没有合并的必要，直接退出合并循环即可
                */
                if (begin2 >= nums.size()) break;

                //如果右半区间算多了，那么对end2进行修正
                if (end2 >= nums.size()) end2 = nums.size() - 1;
         
                //归并
                while (begin1 <= end1 && begin2 <= end2)
                {
                    if(nums[begin1] < nums[begin2])
                    {
                        tmp[index++] = nums[begin1++];
                    }
                    else{
                        tmp[index++] = nums[begin2++];
                    }
                }
                while(begin1 <= end1)
                {
                    tmp[index++] = nums[begin1++];
                }
                while(begin2 <= end2)
                {
                    tmp[index++] = nums[begin2++];
                }
                for(int j = i; j <= end2; j++)
                {
                    nums[j] = tmp[j];
                }
            }
            gap *= 2;
        }
    }
    // 8 计数排序 O(N + K)，其中N为待排序列元素个数，K为待排序列数据范围（即range）
    // 计数排序是一个基于非比较的排序算法
    // 思路：根据待排序列的最大值和最小值，向系统申请一块空间，空间内每个位置就代表着待排序列最小值到最大值每个数据的映射
    // 遍历待排序序列，统计每个数据出现的次数，并记录于申请的空间内,最后根据空间中记录的每个数据出现的次数，实现对待排序列的排序
    void jishu_sort(vector<int>& nums)
    {
        int max = nums[0];
        int min = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > max) max = nums[i];
            if(nums[i] < min) min = nums[i];
        }

        vector<int> count(max-min+1,0);

        for(int i = 0; i < nums.size(); i++)
        {
            count[nums[i]-min]++;
        }

        int cur = 0;
        for(int i = 0; i < count.size(); i++)
        {
            while(count[i]--)
            {
                nums[cur++] = min+i;
            }
        }
    }
};

int main()
{
    my_sort m;
    // 1
    // vector<int> nums = {3,2,5,8,7,1,6,4};
    // m.zhijie_charu_sort(nums);
    // 2
    // vector<int> nums = {3,2,5,8,7,1,6,4};
    // m.xier_sort(nums);
    // 3
    // vector<int> nums = {3,2,5,8,7,1,6,4};
    // m.zhijie_xuanze_sort_v3(nums);
    // 4
    // vector<int> nums = {3,2,5,8,7,1,6,4};
    // m.dui_sort(nums);
    // 5
    // vector<int> nums = {3,2,5,8,7,1,6,4};
    // m.maopao_sort_v2(nums);
    // 6
    // vector<int> nums = {3,2,5,8,7,1,6,4};
    // m.quick_sort_v4(nums,0,nums.size()-1);
    // 7
    // vector<int> nums = {3,2,5,8,7,1,6,4};
    // m.guibing_sort_v2(nums);
    // 8
    vector<int> nums = {3,2,5,8,7,1,6,4};
    m.jishu_sort(nums);
    for(auto& n : nums)
    {
        cout << n << ' ';
    }
    return 0;
}

/**
 * @brief 总结
 *   排序方法	        时间复杂度	    空间复杂度	    稳定性
    直接插入排序	    O(N^2)	        O(1)	        稳定
    希尔排序	        O(NLogN)	    O(1)	        不稳定
    直接选择排序	    O(N^2)	        O(1)	        不稳定
    堆排序	            O(NLogN)	    O(1)	        不稳定
    冒泡排序	        O(N^2)	        O(1)	        稳定
    快速排序	        O(NLogN)	    O(LogN)~O(N)	不稳定
    归并排序	        O(NLogN)	    O(N)	        稳定
    计数排序	        O(N)	        O(N)	        稳定

 */