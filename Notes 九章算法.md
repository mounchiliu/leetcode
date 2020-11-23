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

(因为我们常把问题分为左右儿子的问题即子问题来解决) --- 分治的思想



