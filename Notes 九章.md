#九章算法笔记
[toc]
## BFS适用情况 

### 1. 图的遍历 Traversal in Graph 

图的遍历，比如给出无向连通图(Undirected Connected Graph)中的一个点，找到这个图里的所有点。这就是一个常见的场景。

LintCode 上的 Clone Graph 就是一个典型的练习题。

更细一点的划分的话，这一类的问题还可以分为：

-  **层级遍历  Level Order Traversal** e.g. 二叉树、图中层级遍历(clone graph)
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
- **ummy Node:** 方便清楚找到每一层的结尾
- **双向BFS（最常用）：** 使用时需要同时满足下面3条件：无向图、简单图、同时给出了起点终点 e.g.KnightShortedPath


## Binary Tree
### 1. 时间复杂度： O(log_2 N)
面试中问比O（N）更优的时间复杂度只能是**O(logn)的二分法**

NP问题或全排列问题（e.g. 求出所有的情况）只能用**DFS（深度优先搜索）**来解决

### 2. 适用情况
- 找到满足某个条件的**第一个位置**或**最后一个位置**
- 保留**有解的一半**，或者去掉**无解的一半**
- **二分答案**并验证答案偏大偏小

