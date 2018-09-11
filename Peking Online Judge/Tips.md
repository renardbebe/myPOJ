* 用优先队列实现最小堆（最大堆）
  * ***priority_queue\<int, vector\<int>, greater\<int> > minheap;***
  * priority_queue\<int> maxheap;
  * ***q.top()***
  * q.push()
  * q.pop()

* 双向队列 deque
  * q.push_front()
  * q.push_back()
  * q.pop_front()
  * q.pop_back()
  * ***q.front()***: 第一个元素
  * q.back(): 最后一个元素
  * q.at()
  * q.insert()

* 队列queue
  * ***q.front()***
  * q.push()
  * q.pop()

* 贪心问题

* DP：
  * 最长上升子序列
  * 最长公共子序列
  * 背包问题
    * 0-1背包（逆序）
    * 完全背包（正序）
    * 多重背包

* 运算符重载的写法

* 逆序对 模板题
  * 逆序对个数 = *QuickSort* 过程中交换的次数

* 最短路有关算法 **!!!!** 
  * Dijsktra (不能有负边)
  * Floyd (不能有负边)
  * Bellman_ford (基于边)
  * SPFA

* 连通无环图：

  * 连通：并查集。判断没有两个节点属于一个集合。
  * 无环：统计根节点的个数是否为1。

* 注意的坑：
  * 1 ≤ *X,Y* ≤ 10000，并没有确定 *X* 和 *Y* 之间的大小关系

  * 字符串不支持在前部添加字符，会出现编译错误

  * 用 *getchar* 读取 ‘*\n*‘ 出现 *wrong answer* 后可以试试 *getline(cin, s)* 

  * *int* 相加的结果可能为 *long long*

  * 遇到大数乘法、求幂，结果为整数的，可以尝试使用 *double* 直接进行运算

  * 找中位数：

    * $nth\_element()$

    * 头文件：$\#\ include<algorithm>$

    * $nth\_element(first, nth, last, cmp)$

      求$[first, last]​$这个区间中第 $n​$ 大小的元素，按 $cmp​$ 函数的方式比较

    * 中位数：$nth\_element(a, a+n/2, a+n)$   $cout << a[n/2]; $ 

  * 一个数的位数 $digit(n) =\sum ^{n} _{i=1} (log_{10}(i))+1$


