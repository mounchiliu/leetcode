# 九章算法笔记

## 【ResultType (Java、C++)】

ResultType通常是我们定义在某个文件内部使用的一个类。

```
class ResultType {
    int maxValue, minValue;
    public ResultType(int maxValue, int minValue) {
        this.maxValue = maxValue;
        this.minValue = minValue;
    }
}
```

当我们定义的**函数需要返回多个值**供调用者计算时，就可以使用ResultType.

（并不是所有函数都需要定义ResultType，像python支持返回多个return value则不需要）

使用ResultType返回多个值，而不用c++的引用作为函数参数来返回是因为：工业上如果以后需要更改代码，这样代码**可读性更强**且**方便修改**。

## 【递归的三要素】 

写递归函数的时需要注意的三点：**递归定义、递归拆解、递归出口**

### 1. 递归的定义 

包括函数的参数有哪些，return的值是什么，以及递归函数和各参数的含义

### 2. 递归的拆解

递归的拆解即把一个**大问题**如何拆解成若干个**小问题**去解决。

### 3. 递归出口

递归的出口，即递归何时结束，也就是什么时候可以直接知道答案return，不用再拆解

## 【BFS适用情况】 

### 1. 图的遍历 Traversal in Graph 

图的遍历，比如给出无向连通图(Undirected Connected Graph)中的一个点，找到这个图里的所有点。这就是一个常见的场景。

LintCode 上的 Clone Graph 就是一个典型的练习题。

更细一点的划分的话，这一类的问题还可以分为：

-  **层级遍历  Level Order Traversal** e.g. 二叉树层序遍历、图中层级遍历(e.g. clone graph)
-  **由点及面  Connected Component** e.g. number of island 
-  **拓扑排序  Topological Sorting**

 层级遍历，也就是说我不仅仅需要知道从一个点出发可以到达哪些点，还需要知道这些点，分别离出发点是第几层遇到的，比如 Binary Tree Level Order Traversal 就是一个典型的练习题。

### 2. 最短路径 Shortest Path in Simple Graph
简单图（每条边的长度都是1或边的长度均相等）中求最短路径

**对比-求最长路径：**

- 图可以分层 -> Dynamic Programming
  （分层：比如走到第i一定会经过第i-1层）
- 图不可分层：DFS

### 3. 面试中可能问道如何优化BFS：
- **使用两个队列：** 适用于单项BFS会产生大量中间状态，此时可以使用另一个队列存放目前结点相连的下一层结点。
- **Dummy Node:** 方便清楚找到每一层的结尾
- **双向BFS（最常用）：** 使用时需要同时满足下面3条件：无向图、简单图、同时给出了起点终点 e.g.KnightShortedPath


### 4. 选择DFS还是BFS：
面试中，如果一个问题既可以使用DFS又可以使用BFS，优先选择BFS，因为他是非递归的，更容易实现


## 【Binary Search】
### 1. 时间复杂度： O(log_2 N)
面试中问比O（N）更优的时间复杂度只能是**O(logn)的二分法**

NP问题或全排列问题（e.g. 求出所有的情况）只能用 **DFS（深度优先搜索）** 来解决

### 2. 适用情况
- 找到满足某个条件的**第一个位置**或**最后一个位置**
- 保留**有解的一半**，或者去掉**无解的一半**
- **二分答案**并验证答案偏大偏小 --- 给定一个假定的答案，验证是否可以，再移动区间


## 【Binary Tree】

### 1. Binary Search Tree

- **定义：**

 1.若它的左子树不为空，则左子树上的所有结点的值都小于根节点的值；
 2.若它的右子树不为空，则右子树上的所有节点的值都大于根节点的值；
 3.左子树和右子树都是二搜索树。

- **BST的特性：**

按照 **中序遍历** 打印各节点数值，会得到由小到大的顺序

- **作用: 便于查找、添加、删除节点**

将代寻值与节点值比较，若不相等则可通过大于或者小于，判断target在左子树还是右子树，然后继续在子树进行上述查找

在balanced BST中查找某值的时间复杂度为O（logN），所以在BST中查找、添加、删除元素，平均情况下时间复杂度为O（logN）

- **和有序数组对比：** 有序数组查找某元素可以使用*二分法*，时间复杂度为O（logN）， 但是插入新元素，维护数组有序性要耗时O（N）


### 2. Balenced Binary Tree

- **定义：**

任意节点的子树的高度差都小于等于1。即：（1）空数 （2）左右子树都是平衡二叉树、且左右子树的高度之差不超过1

- **作用：**

平衡二叉树改进二叉查找树的性能：保证查找的最坏时间复杂度为O（logN） 即**树的高度**，而且较浅的树对插入和删除等操作也很快

### 3. Binary Tree 考点

- 二叉树上求值、求路径（比如：Maximum/Minimum/Average/Sum/Path） e.g. 例题 subtree with maximum average、Minimum subtree、Lowest Common Ancestor (考点本质：DFS)
- 二叉树结构变化 e.g. invert binary tree (DFS)
- 二叉查找树 e.g. valid binary search tree (DFS)
- 二叉树层级遍历 BFS

对于前三点考点都是基于树的深度优先搜索（DFS）

需要思考整棵树在该问题上的**结果**和**左右儿子**在该问题上的结果的联系是什么 

(因为我们常把问题分为左右儿子的问题即子问题来解决) —— **分治**的思想

## 【Two pointers】 --- 需要注意 时时刻刻检查两个指针是否符合要求

### 1. 相向指针：

**指针一头一尾，向中间靠拢直到相遇，时间复杂度一般为O(n)**

- **Reverse类(较少)：** e.g. 三步翻转法

- **判断回文串：** http://www.lintcode.com/problem/valid-palindrome/

  Follow up： 允许删掉一个字母（类似的，允许插入一个字母） http://www.lintcode.com/problem/valid-palindrome-ii/

- **两数之和(哈希表 or 双指针)：** https://www.lintcode.com/problem/two-sum/description

  哈希表:时间复杂度O(n)、空间复杂度O(n)

  双指针：时间复杂度O(nlogn)、空间复杂度 O(n)；【如果是已排序数组】时间复杂度O(n)、空间复杂度O(1),不需要额外空间
  
  【变形：】
  
  https://www.lintcode.com/problem/two-sum-ii-input-array-is-sorted/description 使用Two pointers 更快(因为已排序)
  
  https://www.lintcode.com/problem/two-sum-iii-data-structure-design/description 只能使用哈希表
   
  https://www.lintcode.com/problem/two-sum-unique-pairs/description 相当于找出所有的pair，上面的只是找一对 [重点在于去重]
      
  https://www.lintcode.com/problem/3sum/description for枚举一个数的值，其余两个数用双指针解 时间复杂度O(n^2)
  
- Partition 问题(e.g. quickSort/quickSelect)

### 1.2 背向指针

- Longest Palindromic Substring，中心线枚举算法

- Find k closest elements

### 2. 同向指针 （滑动窗口、快慢指针...）

- 数组去重问题 Remove duplicates in an array http://www.lintcode.com/problem/remove-duplicate-numbers-in-array/ 
- 滑动窗口问题 Window Sum http://www.lintcode.com/problem/window-sum/
- 两数之差问题 Two Difference http://www.lintcode.com/problem/two-sum-difference-equals-to-target/
- 链表中点问题 Middle of Linked List http://www.lintcode.com/problem/middle-of-linked-list/ 
- 带环链表问题 Linked List Cycle  https://www.lintcode.com/problem/linked-list-cycle-ii/?_from=ladder&&fromId=1

### 3. 经典排序算法 

https://www.lintcode.com/problem/sort-integers-ii/description

- **快排** 

  1.先整体有序，后局部有序

  2.时间复杂度最差O(n^2)、平均O(nlogn)

  3.空间复杂度O(1)

  4.稳定性对比归并排序，较差

- **归并**

  1.先切一刀，局部有序，后整体有序

  2.时间复杂度最差O(nlogn)、平均O(nlogn)

  3.空间复杂度O(n)

  4.稳定性对比快速排序，较好

### 4. 快速选择算法 (使用快排的思想)

https://www.lintcode.com/problem/kth-largest-element/ 找第k大的数/同理第k小的数 （使用快选、可避免先排序再找数值）

https://www.lintcode.com/problem/median/ (第n/2大的数)

平均时间复杂度O(n)、最差O(n^2)

```
class Solution {
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int k, vector<int> &nums) {
        // write your code here
         if (nums.size() == 0 || k < 1 || k > nums.size()){
            return -1;
        }
        return partition(nums, 0, nums.size() - 1, nums.size() - k); // 最后一个参数若写(k-1) 对应第k小
        //从小到大排，第nums.size() - k个数(e.g.第1大， 对于nums.size()-1)
    }
    
private:
    int partition(vector<int> &nums, int start, int end, int k) {
        //condition for end
        if (start >= end) {
            return nums[k]; //start和end交错，表明已排好，返回第k个数即可
        }
        
        //start partition
        int left = start, right = end;
        int pivot = nums[(start + end) / 2];
        
        while (left <= right) {
            while (left <= right && nums[left] < pivot) {
                left++;
            }
            while (left <= right && nums[right] > pivot) {
                right--;
            }
            if (left <= right) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        //end partition, check which part we need to choose
        //while循环出来后 left和right错位，right在左，left在右
        //且left与right之间有可能隔了一个数(left=right时 left++，right--，中间隔开一个数)
        //所以数组被分成左边、中间(可能不存在)、右边
        //所以，如果比right小于等于，则选择左侧
        //大于等于left，选择右侧
        //对比左右的index和k的大小
        if (k <= right) { //注意包含等于，因为如果start + k - 1=right，也是选start~right之间的数
            return partition(nums, start, right, k);//找左边第k个数
        }
        if (k >= left) {
            return partition(nums, left, end, k);//找右边第k个数
        }
        return nums[k];//左右都不行，中间那个数
    }
};
```

### 4. 三指针算法

**Sort Colors ：** https://www.lintcode.com/problem/sort-colors/description

https://www.lintcode.com/problem/sort-colors-ii

## 【DFS】
DFS搜索类的问题中, 大致分为组合类问题、排列类问题


