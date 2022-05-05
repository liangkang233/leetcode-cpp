# 介绍

用于记录刷题笔记本，总结刷题技巧。

## 主题

| Topic                                | Description                                                       |
|--------------------------------------|-------------------------------------------------------------------|
| [刷题记录](#题目分析)           | leetcode题目中的刷题记录                          |
| [关键点记录](#关键)      | 一些常见的题目技巧、问题、记录                                     |
| [liangkang233's blog](https://liangkang233.github.io/)      | 个人博客主页                                     |

# 题目分析

- [x] [1.两数之和](https://github.com/liangkang233/leetcode-cpp/blob/main/1.两数之和.cpp)	**[array , hash table]**	

  ​	注意题意，每个输入问题只有一组解

- [x] [2.两数相加](https://github.com/liangkang233/leetcode-cpp/blob/main/2.两数相加.cpp)	**[linked-list , math]**	

  ​	看懂题目即可

- [ ] [3.无重复字符的最长子串](https://github.com/liangkang233/leetcode-cpp/blob/main/3.无重复字符的最长子串.cpp)	**[hash-table , two-pointers , string , sliding-window ]**	

  ​	做法挺多 滑动窗口挺不错 类似题目 [438.找到字符串中所有字母异位词](https://github.com/liangkang233/leetcode-cpp/blob/main/438.找到字符串中所有字母异位词.cpp)  

- [ ] [4.寻找两个正序数组的中位数](https://github.com/liangkang233/leetcode-cpp/blob/main/4.寻找两个正序数组的中位数.cpp)	**[ array , binary-search , divide-and-conquer]**

  ​	使用二分法做，效率很高。注意：无论总个数是奇数还是偶数，其中位数都是第size/2 + 1 和 (size+1)/2)个元素的平均数

- [ ] [5.最长回文子串](https://github.com/liangkang233/leetcode-cpp/blob/main/5.最长回文子串.cpp)	**[array , binary-search , divide-and-conquer]**	

  ​	动态规划经典题 扩展题[516.最长回文子序列](https://github.com/liangkang233/leetcode-cpp/blob/main/516.最长回文子序列.cpp)

- [x] [6.z-字形变换](https://github.com/liangkang233/leetcode-cpp/blob/main/6.z-字形变换.cpp)	**[string]**

- [ ] [7.整数反转](https://github.com/liangkang233/leetcode-cpp/blob/main/7.整数反转.cpp)	**[math]**

  ​	不难，但是写的像shit 下次做优雅

- [ ] [8.字符串转换整数-atoi](https://github.com/liangkang233/leetcode-cpp/blob/main/8.字符串转换整数-atoi.cpp)	**[math , string]**

  ​	能想出状态机法确实很难，普通做法类似题目7

- [x] [9.回文数](https://github.com/liangkang233/leetcode-cpp/blob/main/9.回文数.cpp) **[math]**

  ​    判断一个数(非string)是否回文的高效方法

- [ ] [10.正则表达式匹配](https://github.com/liangkang233/leetcode-cpp/blob/main/10.正则表达式匹配.cpp)	**[string , dynamic-programing , backtracking]**

  ​	经典动态规划，值得多刷

- [ ] [11.盛最多水的容器](https://github.com/liangkang233/leetcode-cpp/blob/main/11.盛最多水的容器.cpp)    **[array , two-pointers]**

  ​	这个双指针是真的难顶，直觉的做法就是对的 证明好好理解

- [x] [12.整数转罗马数字](https://github.com/liangkang233/leetcode-cpp/blob/main/12.整数转罗马数字.cpp)	**[math , string]**

- [x] [13.罗马数字转整数](https://github.com/liangkang233/leetcode-cpp/blob/main/13.罗马数字转整数.cpp)	**[math , string]**

- [ ] [14.最长公共前缀](https://github.com/liangkang233/leetcode-cpp/blob/main/14.最长公共前缀.cpp)    **[string]**

- [ ] [15.三数之和](https://github.com/liangkang233/leetcode-cpp/blob/main/15.三数之和.cpp)    **[array , two-pointers]**

  ​	双指针，排序后 遍历 确定第一个字符， 剩下的两个 i+1 size-1指针遍历判断 可以证明 这样找不会重复，记得去重

  

- [x] [17.电话号码的字母组合](https://github.com/liangkang233/leetcode-cpp/blob/main/17.电话号码的字母组合.cpp)    **[string , backtracking]**

  

- [ ] [19.删除链表的倒数第-n-个结点](https://github.com/liangkang233/leetcode-cpp/blob/main/19.删除链表的倒数第-n-个结点.cpp)    **[linked-list , two-pointers]**

  ​	常规方法使用栈，只扫描一次的方法: 快指针到达队尾后 慢指针再行动即可。

  

- [ ] [22.括号生成](https://github.com/liangkang233/leetcode-cpp/blob/main/22.括号生成.cpp)	**[string , backtracking]**

  ​	我理解回溯就是采用了剪枝的最终变量是传参的dfs（普通dfs最终变量不可回溯输出变量）

- [ ] [23.合并k个升序链表](https://github.com/liangkang233/leetcode-cpp/blob/main/23.合并k个升序链表.cpp)	**[linked-list , divide-and-conquer , heap]**

  ​	经典分治、优先队列做法，值得多刷

- [ ] [24.两两交换链表中的节点](https://github.com/liangkang233/leetcode-cpp/blob/main/24.两两交换链表中的节点.cpp)    **[linked-list]**

  ​	构建虚拟头 节省操作

- [ ] [25.k-个一组翻转链表](https://github.com/liangkang233/leetcode-cpp/blob/main/25.k-个一组翻转链表.cpp)    **[linked-list]**

  ​	链表翻转操作的进阶题 [206.反转链表](https://github.com/liangkang233/leetcode-cpp/blob/main/206.反转链表.cpp)

  

- [x] [29.两数相除](https://github.com/liangkang233/leetcode-cpp/blob/main/29.两数相除.cpp)	**[math , binary-search]**

  ​	此题有问题，慎做  可以复习下二进制补码的知识

  

- [ ] [30.串联所有单词的子串](https://github.com/liangkang233/leetcode-cpp/blob/main/30.串联所有单词的子串.cpp)    **[hash-table , two-pointers , string]**

  ​	#TODO

- [ ] [31.下一个排列](https://github.com/liangkang233/leetcode-cpp/blob/main/31.下一个排列.cpp)    **[array]**

  ​	又是一道全排列题目 注意反转的起点 与判断条件加等号，太粗心了..

- [ ] [32.最长有效括号](https://github.com/liangkang233/leetcode-cpp/blob/main/32.最长有效括号.cpp)	**[string , dynamic-programing]**

  ​	可以使用栈的典型题目，也可以用动态规划，值得多刷。还有其他取巧的方法如正序扫一遍再逆序扫一遍。

- [ ] [33.搜索旋转排序数组.](https://github.com/liangkang233/leetcode-cpp/blob/main/33.搜索旋转排序数组.cpp)	**[array , binary-search]**

  ​	二分搜索的经典题，类似[题目153、154](https://github.com/liangkang233/leetcode-cpp/blob/main/153.寻找旋转排序数组中的最小值.cpp)。**二分**搜索每次都要舍弃一半，从留下的一半中寻找目标；而**分治**法把一个大问题分成两个或多个小问题

- [ ] [34.在排序数组中查找元素的第一个和最后一个位置](https://github.com/liangkang233/leetcode-cpp/blob/main/34.在排序数组中查找元素的第一个和最后一个位置.cpp)    **[array , binary-search]**

  ​	**好题 多刷** 二分怎么老是死在边界上，我靠。注意题中有可能输入为空，34 35可用同种二分做法

- [ ] [35.搜索插入位置](https://github.com/liangkang233/leetcode-cpp/blob/main/35.搜索插入位置.cpp)    **[array , binary-search]**

  ​	小心边界，标准二分      看看[二分的自实现](https://github.com/liangkang233/leetcode-cpp/blob/main/常用代码模块/bound.cpp) 学习学习

- [ ] [36.有效的数独](https://github.com/liangkang233/leetcode-cpp/blob/main/36.有效的数独.cpp)    **[hash-table]**

  ​	注意 & 优先级比 == 低 比&&高，这里吃了忘加括号的坑，   一道不错的测试bitmap题目

- [ ] [37.解数独](https://github.com/liangkang233/leetcode-cpp/blob/main/37.解数独.cpp)    **[hash-table , backtracking]**

  ​	一开始需要填入已经存在的值作为初始值，其次回溯要注意的点这题都有，很经典 n皇后 类似

  

- [ ] [39.组合总和](https://github.com/liangkang233/leetcode-cpp/blob/main/39.组合总和.cpp)    **[array , backtracking]**

  ​	dfs回溯记得要添加剪枝

- [ ] [40.组合总和-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/40.组合总和-ii.cpp)    **[array , backtracking]**

  ​	需要去重和减枝 去重思路跟[90.子集-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/90.子集-ii.cpp)一样

- [ ] [43.字符串相乘](https://github.com/liangkang233/leetcode-cpp/blob/main/43.字符串相乘.cpp)    [math , string]

  ​	直接按照模拟的运算法则，num2的每一位乘上num1的每一位 再用[415.字符串相加](https://github.com/liangkang233/leetcode-cpp/blob/main/415.字符串相加.cpp)将数字相加，效果不好，而且代码量很大。官方直接用数组位来做 会好很多  之前的加法也应该这么做，真菜啊

- [ ] [44.通配符匹配](https://github.com/liangkang233/leetcode-cpp/blob/main/44.通配符匹配.cpp)    **[string , dynamic-programming , backtracking , greedy]**

  ​	与[10.正则表达式匹配](https://github.com/liangkang233/leetcode-cpp/blob/main/10.正则表达式匹配.cpp)类似的做法，多刷 好题 自实现的匹配方案，这里引申下KMP算法:[字符串匹配KMP](https://github.com/liangkang233/leetcode-cpp/blob/main/编程之法/字符串匹配KMP.cpp)	

- [ ] [45.跳跃游戏-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/45.跳跃游戏-ii.cpp)    **[array , greedy]**

  ​	系列题目[55.跳跃游戏](https://github.com/liangkang233/leetcode-cpp/blob/main/55.跳跃游戏.cpp) 贪心即可不要想复杂了用dp

- [ ] [46.全排列](https://github.com/liangkang233/leetcode-cpp/blob/main/46.全排列.cpp)    **[backtracking]**

  ​	典型回溯，不要混淆了全排列和全子集的区别（全子集可以有重复，全排列不可，题中元素无重复 可以做全子集的）

- [ ] [47.全排列-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/47.全排列-ii.cpp)    **[backtracking]**

  ​	其实c++std库里有全排列的函数 *next_permutation()* 这两题要二刷，当时写的时候没想清楚。也可以递归回溯 去重思路跟[90.子集-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/90.子集-ii.cpp)一样

- [ ] [48.旋转图像](https://github.com/liangkang233/leetcode-cpp/blob/main/48.旋转图像.cpp)    **[array]**

  ​	题目不难，写的很繁琐。实际上翻转操作可以 分解为 水平对转 主对角线反转。

- [ ] [49.字母异位词分组](https://github.com/liangkang233/leetcode-cpp/blob/main/49.字母异位词分组.cpp)    **[hash-table , string]**

  ​	直接暴力做 map记录 记录同一字母异位字符的 数组下标，key是遍历元素的字符串排序后的值。优化点主要在转化的key上，我这种思路key对应的value是数组下标 效果还行。

- [ ] [50.pow-x-n](https://github.com/liangkang233/leetcode-cpp/blob/main/50.pow-x-n.cpp)    **[math , binary-search]**

  ​	以位做运算统计累乘，用位来记录 temp[i] 代表 x^(2^i)，（其实不需要保存这个数组）	递归二分的做法也许更好理解 写也方便

- [ ] [51.n-皇后](https://github.com/liangkang233/leetcode-cpp/blob/main/51.n-皇后.cpp)    **[backtracking]**

- [ ] [52.n皇后-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/52.n皇后-ii.cpp)    **[backtracking]**

  ​	经典回溯问题，跟51相同

- [ ] [53.最大子序和](https://github.com/liangkang233/leetcode-cpp/blob/main/53.最大子序和.cpp)    **[array , divide-and-conquer , dynamic-programming]**

  ​	用分治的线段树或是动态规划(推荐)来做都不错，多刷几次

- [ ] [54.螺旋矩阵](https://github.com/liangkang233/leetcode-cpp/blob/main/54.螺旋矩阵.cpp)    **[array]**

  ​	这个判断条件没想到写的这么恼火

- [ ] [55.跳跃游戏](https://github.com/liangkang233/leetcode-cpp/blob/main/55.跳跃游戏.cpp)    **[array , greedy]**

  ​	系列题目[45.跳跃游戏-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/45.跳跃游戏-ii.cpp) 贪心即可不要想复杂了用dp

- [ ] [56.合并区间](https://github.com/liangkang233/leetcode-cpp/blob/main/56.合并区间.cpp)    **[binary-search , dynamic-programming]**

  ​	官方写法更加优雅，下次刷尝试优化

- [ ] [57.插入区间](https://github.com/liangkang233/leetcode-cpp/blob/main/57.插入区间.cpp)    **[arrary , sort]**

  ​	**好题** 用二分走了不少弯路，最后还是要遍历push，不如一开始就找遍历合并区间的方法

- [x] [58.最后一个单词的长度](https://github.com/liangkang233/leetcode-cpp/blob/main/58.最后一个单词的长度.cpp)    **[string]**

  ​	正确率只有38%，搞得有点慌以为有啥坑

- [ ] [59.螺旋矩阵-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/59.螺旋矩阵-ii.cpp)    **[array]**

  ​	[54.螺旋矩阵](https://github.com/liangkang233/leetcode-cpp/blob/main/54.螺旋矩阵.cpp) 类似题，解法差不多  此题用count下标似乎效果好些

- [ ] [60.排列序列](https://github.com/liangkang233/leetcode-cpp/blob/main/60.排列序列.cpp)    **[math , backtracking]**

  ​	以为又是一道全排列的题递归后发现不是字典序，修改后会超时  最后还是直接用k计算字典序来输出对应字符没用到回溯。

- [ ] [61.旋转链表](https://github.com/liangkang233/leetcode-cpp/blob/main/61.旋转链表.cpp)    **[linked-list , two-pointers]**

  ​	先生成环链表再操作即可，k向右移动等于 head 向左移动 `size - (k % size)`

- [x] [62.不同路径](https://github.com/liangkang233/leetcode-cpp/blob/main/62.不同路径.cpp)    **[array , dynamic-programming]**

- [x] [63.不同路径-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/63.不同路径-ii.cpp)    **[array , dynamic-programming]**

- [ ] [64.最小路径和](https://github.com/liangkang233/leetcode-cpp/blob/main/64.最小路径和.cpp)    **[array , dynamic-programming]**

  ​	62-64都是动态规划典型题，可以刷下这几个练手复习

  

- [x] [67.二进制求和](https://github.com/liangkang233/leetcode-cpp/blob/main/67.二进制求和.cpp)    **[math , string]**

  

- [ ] [71.简化路径](https://github.com/liangkang233/leetcode-cpp/blob/main/71.简化路径.cpp)    **[string , stack]**

  ​	用栈记录上次的路径，尾部手动补一个'/' 省得判断  自己写的很烂，不好看  推荐使用 双端队列 [*deque*](http://c.biancheng.net/view/6860.html)

- [ ] [72.编辑距离](https://github.com/liangkang233/leetcode-cpp/blob/main/72.编辑距离.cpp)    **[string , dynamic-programming]**

  ​	动态规划 YYDS [583.两个字符串的删除操作](https://github.com/liangkang233/leetcode-cpp/blob/main/583.两个字符串的删除操作.cpp) 字符匹配问题 进阶题

  

- [ ] [74.搜索二维矩阵](https://github.com/liangkang233/leetcode-cpp/blob/main/74.搜索二维矩阵.cpp)    **[array , binary-search]**

  ​	二维二分 [这道题的强化版](https://github.com/liangkang233/leetcode-cpp/blob/main/常用代码模块/二维二分法.cpp)  下1行第1个 不一定大于上1行最后1个 upper_bound 重载 进阶题[240.搜索二维矩阵-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/240.搜索二维矩阵-ii.cpp)

- [ ] [75.颜色分类](https://github.com/liangkang233/leetcode-cpp/blob/main/75.颜色分类.cpp)    **[array , two-pointers , sort]**

  ​	自实现归并版 快排，如果用双指针 时间复杂度为O(n)

- [ ] [76.最小覆盖子串](https://github.com/liangkang233/leetcode-cpp/blob/main/76.最小覆盖子串.cpp)    **[hash-table , two-pointers , string , sliding-window]**

  ​	滑动窗口做的，之前做过好几道类似的。

  

- [ ] [78.子集](78.子集.cpp)    **[array , backtracking , bit-manipulation]**

  ​	数位操作 还真是奇思妙想，这题也算是典型的dfs回溯  类似题目[90.子集-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/90.子集-ii.cpp)

- [ ] [79.单词搜索](https://github.com/liangkang233/leetcode-cpp/blob/main/79.单词搜索.cpp)    **[array , backtracking]**

  ​	看到这种直接只要判断是否成立的题下意识的想用bfs。思考下觉得写的比dfs麻烦很多，因为初始状态还是需要遍历之后加队列。直接dfs 回溯标记数组效果不错快双百了。

  ​	这次学乖了，直接将四个方向的代码拆开写，不是之前那样for循环 时间会慢很多，缺点是代码看着冗余不简洁。

  

- [ ] [82.删除排序链表中的重复元素-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/82.删除排序链表中的重复元素-ii.cpp)    **[linked-list]**

  ​	链表难处理时，推荐添加一个虚拟头。加了delete 就很慢 刷题不考虑内存泄漏也太 👶🌶

- [x] [83.删除排序链表中的重复元素](https://github.com/liangkang233/leetcode-cpp/blob/main/83.删除排序链表中的重复元素.cpp)    **[linked-list]**

- [ ] [84.柱状图中最大的矩形](https://github.com/liangkang233/leetcode-cpp/blob/main/84.柱状图中最大的矩形.cpp)    **[array , stack]**

  ​	单调栈 [739.每日温度](https://github.com/liangkang233/leetcode-cpp/blob/main/739.每日温度.cpp) 的进阶题

- [ ] [85.最大矩形](https://github.com/liangkang233/leetcode-cpp/blob/main/85.最大矩形.cpp)    **[array , hash-table , dynamic-programming , stack]**

  ​	84进阶 真想不出来还能二维加单调栈

  

- [ ] [89.格雷编码](https://github.com/liangkang233/leetcode-cpp/blob/main/89.格雷编码.cpp)    **[backtracking]**

  ​	一刷写的跟屎一样，有点怀疑人生 回溯硬解时间空间都花费的很大。还是得用位运算做啊。。 背公式

- [ ] [90.子集-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/90.子集-ii.cpp)    **[array , backtracking]**

  ​	回溯题，使用[78.子集](78.子集.cpp)的二进制迭代法做的话考虑去重没想出来，建议二刷。

- [ ] [91.解码方法](https://github.com/liangkang233/leetcode-cpp/blob/main/91.解码方法.cpp)    **[dynamic-programming]**

  ​	这道题动态规划的状态转移方程很好找 就是处理边界和特殊情况有点头疼，通过率居然只有31%

  

- [x] [94.二叉树的中序遍历](https://github.com/liangkang233/leetcode-cpp/blob/main/94.二叉树的中序遍历.cpp)    **[hash-table , stack , tree]**

  

- [ ] [98.验证二叉搜索树](https://github.com/liangkang233/leetcode-cpp/blob/main/98.验证二叉搜索树.cpp)    **[tree , depth-first-search]**

  ​	中序深度递归，Solution3值得思考(二叉搜索树中序一定升序)

  

- [x] [101.对称二叉树](https://github.com/liangkang233/leetcode-cpp/blob/main/101.对称二叉树.cpp)    **[tree , depth-first-search , breadth-first-search]**

- [x] [102.二叉树的层序遍历](https://github.com/liangkang233/leetcode-cpp/blob/main/102.二叉树的层序遍历.cpp)    **[tree , breadth-first-search]**

- [ ] [103.二叉树的锯齿形层序遍历](https://github.com/liangkang233/leetcode-cpp/blob/main/103.二叉树的锯齿形层序遍历.cpp)    **[stack , tree , breadth-first-searchnode.]**

  ​	可以使用栈来做，注意需要切换 入栈左右节点顺序每层遍历后需切换。官方使用queue来bfs，双端队列来存入数据。

  

- [ ] [105.从前序与中序遍历序列构造二叉树](https://github.com/liangkang233/leetcode-cpp/blob/main/105.从前序与中序遍历序列构造二叉树.cpp)    **[array , tree , depth-first-search]**

  ​	使用分治递归的思想，此题结果唯一。类似题目[889.根据前序和后序遍历构造二叉树](https://github.com/liangkang233/leetcode-cpp/blob/main/889.根据前序和后序遍历构造二叉树)，该题结果不唯一。

  

- [ ] [108.将有序数组转换为二叉搜索树](https://github.com/liangkang233/leetcode-cpp/blob/main/108.将有序数组转换为二叉搜索树.cpp)    **[tree , depth-first-search]**

  ​	中点确定的不同 优先生成左右子树不同

  

- [ ] [113.路径总和-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/113.路径总和-ii.cpp)    **[tree , depth-first-search]**

  ​	题目不难 蠢到用了个全局变量 导致测试案例 一直没过

  

- [ ] [117.填充每个节点的下一个右侧节点指针-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/117.填充每个节点的下一个右侧节点指针-ii.cpp)    **[tree , depth-first-search , breadth-first-search]**

  ​	一般的做法是层序遍历的bfs，官方答案 能够节省空间复杂度 优秀

  

- [x] [119.杨辉三角-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/119.杨辉三角-ii.cpp)    **[array]**

  ​	杨辉三角的规律 等价排列组合

- [x] [120.三角形最小路径和](https://github.com/liangkang233/leetcode-cpp/blob/main/120.三角形最小路径和.cpp)    **[array , dynamic-programming]**

- [x] [121.买卖股票的最佳时机](https://github.com/liangkang233/leetcode-cpp/blob/main/121.买卖股票的最佳时机.cpp)    **[array , dynamic-programming]**

- [x] [122.买卖股票的最佳时机-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/122.买卖股票的最佳时机-ii.cpp)    **[array , greedy]**

- [ ] [123.买卖股票的最佳时机-iii](https://github.com/liangkang233/leetcode-cpp/blob/main/123.买卖股票的最佳时机-iii.cpp)    **[array , dynamic-programming]**

  ​	虽然题目是动态规划，但是难点不在这。要结合121 来做，把整个区间分为两部分。对于遍历的从右往左，寻找规律与121就刚好相反。

- [ ] [124.二叉树中的最大路径和](https://github.com/liangkang233/leetcode-cpp/blob/main/124.二叉树中的最大路径和.cpp)    **[tree , depth-first-search]**

  ​	后序dfs遍历即可，观察可知最大路径一定为某一节点下的左右子树的大于0的最大路径与自身相加，dfs下去将每个子树的最大路径求出，并更新对比ans。

- [ ] [125.验证回文串](https://github.com/liangkang233/leetcode-cpp/blob/main/125.验证回文串.cpp)    **[two-pointers , string]**

  ​	没啥意思，遍历判断即可 这个判断条件写的很蠢

  

- [x] [129.求根节点到叶节点数字之和](https://github.com/liangkang233/leetcode-cpp/blob/main/129.求根节点到叶节点数字之和.cpp)    **[tree , depth-first-search]**

- [ ] [130.被围绕的区域](https://github.com/liangkang233/leetcode-cpp/blob/main/130.被围绕的区域.cpp)    **[depth-first-search , breadth-first-search , union-find]**

  ​	dfs写的很差妄想用set结果反向优化了，这种dfs都不推荐用set，看看官方的吧。。。

- [ ] [131.分割回文串](https://github.com/liangkang233/leetcode-cpp/blob/main/131.分割回文串.cpp)    **[backtracking]**

  ​	这道题需要考虑优化问题，可惜测试样例没有给大量的数据使用普通回文判断不会超时

  

- [x] [136.只出现一次的数字](https://github.com/liangkang233/leetcode-cpp/blob/main/136.只出现一次的数字.cpp)    **[hash-table , bit-manipulation]**

  ​	貌似是第一次做leetcode的题，印象深刻

- [ ] [137.只出现一次的数字-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/137.只出现一次的数字-ii.cpp)    **[bit-manipulation]**

  ​	数字电路的做法超级秀，常规哈希，高级点做法就是将数位拆分

  

- [ ] [139.单词拆分](https://github.com/liangkang233/leetcode-cpp/blob/main/139.单词拆分.cpp)    **[dynamic-programming]**

  ​	用kmp做的话，例如s中为”abca“，给出字典中有 "a" 重复情况难做，感觉效果也不是很好。结果答案直接用个set动态规划，TNND。

  

- [x] [141.环形链表](https://github.com/liangkang233/leetcode-cpp/blob/main/141.环形链表.cpp)    **[linked-list , two-pointers]**

  ​	快慢指针判断是否有环

- [ ] [142.环形链表-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/142.环形链表-ii.cpp)    **[linked-list , two-pointers]**

  ​	141进接题目，需要找到循环点。建议再做一遍，**链表**是否相等 需要判断指针(地址)是否相等。非常巧妙的再次排序 得到终点值。

- [ ] [143.重排链表](https://github.com/liangkang233/leetcode-cpp/blob/main/143.重排链表.cpp)    **[linked-list]**

  ​	算是链表的综合应用，快慢指针找中点，再链表反转、合并。参考[876.链表的中间结点](https://github.com/liangkang233/leetcode-cpp/blob/main/876.链表的中间结点.cpp) [206.反转链表](https://github.com/liangkang233/leetcode-cpp/blob/main/206.反转链表.cpp)

  

- [ ] [146.lru-缓存](https://github.com/liangkang233/leetcode-cpp/blob/main/146.lru-缓存.cpp)    **[design]**

  ​	这道题有意思，map记录节点key，实际cache用双向链表。答案中使用自己实现的双向链表，最好直接用std的list。这里有个技巧：**双向链表加一个伪头 伪尾，可以减少很多判断左右为空的操作 和 初始化赋值的操作**

  

- [ ] [148.排序链表](https://github.com/liangkang233/leetcode-cpp/blob/main/148.排序链表.cpp)    **[linked-list , sort]**

  ​	经典排序题，考虑链表只能向后遍历的特殊性，用快慢指针找中点后归并排序。写的很烂 看看官方的

- [ ] [149.直线上最多的点数](https://github.com/liangkang233/leetcode-cpp/blob/main/149.直线上最多的点数.cpp)    **[hash-table , math]**

  ​	蓝桥杯省赛时做过这道题，当时只考虑到计算斜率，下考场后发现思路不对。现在添加双重hashmap记录尝试。可以优化为k与坐标的pair为键，需要自己添加 key 的hash函数。

- [ ] [150.逆波兰表达式求值](https://github.com/liangkang233/leetcode-cpp/blob/main/150.逆波兰表达式求值.cpp)    **[stack]**

  ​	理解题意即可

  

- [ ] [153.寻找旋转排序数组中的最小值](https://github.com/liangkang233/leetcode-cpp/blob/main/153.寻找旋转排序数组中的最小值.cpp)    **[array , binary-search]**

  ​	153 154 引导的不是很好，sort直接排序效果也很好。应该要求限制时间复杂度为logn，这里使用二分的前提是要各个元素不相同。

- [ ] [154.寻找旋转排序数组中的最小值-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/154.寻找旋转排序数组中的最小值-ii.cpp)    **[array , binary-search]**

  ​	此题给出数组允许了数据重复，不能直接如上做。 类似二分题目 [33.搜索旋转排序数组.](https://github.com/liangkang233/leetcode-cpp/blob/main/33.搜索旋转排序数组.cpp)

  

- [ ] [160.相交链表](https://github.com/liangkang233/leetcode-cpp/blob/main/160.相交链表.cpp)    **[linked-list]**

  ​	一般做法是 set 记录遍历，双指针 重复遍历 真的妙  类似题目 [142.环形链表-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/142.环形链表-ii.cpp) 

  

- [ ] [162.寻找峰值](https://github.com/liangkang233/leetcode-cpp/blob/main/162.寻找峰值.cpp)    **[array , binary-search]**

  ​	二分应用题

  

- [ ] [167.两数之和-ii-输入有序数组](https://github.com/liangkang233/leetcode-cpp/blob/main/167.两数之和-ii-输入有序数组.cpp)    **[array , two-pointers , binary-search]**

  ​	两数之和，双指针 二分查排序数组 老套路了

  

- [ ] [169.多数元素](https://github.com/liangkang233/leetcode-cpp/blob/main/169.多数元素.cpp)    **[array , divide-and-conquer , bit-manipulation]**

  ​	题目不难，但是解法很多，其中时间复杂度O(n) 空间复杂度O(1) 的 Boyer-Moore 投票算法 很具有启发性。

  

- [ ] [172.阶乘后的零](172.阶乘后的零.cpp)    **[math]**

  ​	妙，计算尾数的零就是找2和5的乘积，也就是找 n! 的所有数的5的因数（2是因数的个数必定多余5）。

- [ ] [173.二叉搜索树迭代器](173.二叉搜索树迭代器.cpp)    **[stack , tree , design]**

  ​	题解题意即可，树的中序题目，若是使用O(h)空间复杂度需要用 中序的栈用法。好好思考

- [ ] [174.地下城游戏](174.地下城游戏.cpp)    **[binary-search , dynamic-programming]**

  ​	一开始按照这个思路写[64.最小路径和](https://github.com/liangkang233/leetcode-cpp/blob/main/64.最小路径和.cpp)，发现不对。*最小值* 和 *累加和* 两个因素不能在从左上到右下中等价 会出现矛盾。应该从右下往左上走（绝）。

  

- [ ] [187.重复的dna序列](https://github.com/liangkang233/leetcode-cpp/blob/main/187.重复的dna序列.cpp)    **[hash-table , bit-manipulation]**

  ​	自己写的是朴素的滑动串口 将字符串转义为 7进制数据 用map记录出现次数。时间慢空间还行。答案是拿两位二进制做的 四个字符正好占用二进制的 00 01 10 11 思路一样 效果好些。

  

- [ ] [189.轮转数组](https://github.com/liangkang233/leetcode-cpp/blob/main/189.轮转数组.cpp)    **[array]**

  ​	翻转字符串的方法做的，时间n 空间1

  

- [ ] [198.打家劫舍](https://github.com/liangkang233/leetcode-cpp/blob/main/198.打家劫舍.cpp)    **[dynamic-programming]**

  ​	动态规划 找出转移式

  

- [ ] [200.岛屿数量](https://github.com/liangkang233/leetcode-cpp/blob/main/200.岛屿数量.cpp)    **[depth-first-search , breadth-first-search , union-find]**

  ​	注意题目的数据元素是char 搞了半天找不到错，少用嵌套数组查 速度会慢很多  更不要用*forrange:* `for(auto &&i : v)`直接超时就离谱。

- [ ] [201.数字范围按位与](https://github.com/liangkang233/leetcode-cpp/blob/main/201.数字范围按位与.cpp)    **[bit-manipulation]**

  ​	看错题目了，一位是求范围内异或。若是求范围内与 就是两个数字的最大相同前缀

- [ ] [202.快乐数](https://github.com/liangkang233/leetcode-cpp/blob/main/202.快乐数.cpp)    **[hash-table , math]**

  ​	没有比较好的思路，由题意可易证，结果一定不会到达无穷，所以试试暴力 用set判断是否循环，感觉效果还行。看了答案，惊呼此处可以用快慢指针来检测是否会出现循环。第三种方法是打表，记录会出现快乐数的一些中间值。

  


- [ ] [204.计数质数](https://github.com/liangkang233/leetcode-cpp/blob/main/204.计数质数.cpp)    **[hash-table , math]**

  ​	质因数经典题了，用[埃拉托色尼筛选法](https://baike.baidu.com/item/%E5%9F%83%E6%8B%89%E6%89%98%E8%89%B2%E5%B0%BC%E7%AD%9B%E9%80%89%E6%B3%95/4524938) 其原理也十分易懂:从1到n遍历，假设当前遍历到m,则把所有小于n的、且是m的倍数的整数标为和数;

- [ ] [205.同构字符串](https://github.com/liangkang233/leetcode-cpp/blob/main/205.同构字符串.cpp)	**[hash-table]**

  ​	不需要两个哈希表，用一个数组的空间就可以做到一一对应，系列题目[890.查找和替换模式](https://github.com/liangkang233/leetcode-cpp/blob/main/890.查找和替换模式.cpp)

- [x] [206.反转链表](https://github.com/liangkang233/leetcode-cpp/blob/main/206.反转链表.cpp)    **[linked-list]**

  

- [ ] [209.长度最小的子数组](https://github.com/liangkang233/leetcode-cpp/blob/main/209.长度最小的子数组.cpp)    **[array , two- pointers , binary- search , sliding-window]**

  ​	滑动窗口时间复杂度为O(n)，前缀和的二分可以做到 log(n)

  

- [ ] [213.打家劫舍-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/213.打家劫舍-ii.cpp)    **[dynamic-programming]**

  ​	[198.打家劫舍](https://github.com/liangkang233/leetcode-cpp/blob/main/198.打家劫舍.cpp)加了个头尾相连的限制条件，如果直接做213会比较困难

  

- [ ] [215.数组中的第k个最大元素](https://github.com/liangkang233/leetcode-cpp/blob/main/215.数组中的第k个最大元素.cpp)    **[divide-and-conquer , heap]** 

  ​	类似[378.有序矩阵中第-k-小的元素](https://github.com/liangkang233/leetcode-cpp/blob/main/378.有序矩阵中第-k-小的元素.cpp) 可以试试修改快排来做，堆排 优先队列也可 **TOP K问题** 先考虑堆的做法

  ​	

- [ ] [230.二叉搜索树中第k小的元素](https://github.com/liangkang233/leetcode-cpp/blob/main/230.二叉搜索树中第k小的元素.cpp)    **[binary-search , tree]**

  ​	二叉搜索树 经常会和中序遍历 (恰节点元素正序) 串联。

  

- [ ] [234.回文链表](https://github.com/liangkang233/leetcode-cpp/blob/main/234.回文链表.cpp)    **[linked-list , two-pointers]**

  ​	找中点回文对比 效果巨差 写的还心累。不如直接放到数组中做。正确做法是 翻转后半段链表对比。

  

- [ ] [236.二叉树的最近公共祖先](https://github.com/liangkang233/leetcode-cpp/blob/main/236.二叉树的最近公共祖先.cpp)    **[tree]**

  ​	直接dfs查找节点 对比其路径 效果比较差。高效方法是递归左右子树对比。

  

- [ ] [238.除自身以外数组的乘积](https://github.com/liangkang233/leetcode-cpp/blob/main/238.除自身以外数组的乘积.cpp)    **[array]**

  ​	类似双指针的思路 统计前后缀和即可

- [ ] [239.滑动窗口最大值](https://github.com/liangkang233/leetcode-cpp/blob/main/239.滑动窗口最大值.cpp)    **[heap , sliding-window]**

  ​	用 multiset 速度慢，堆的话 元素为pair对应元素和下标 以免top元素不符合条件需要弹出。 单调队列 使用deque 比较难想到 效果不错。

- [ ] [240.搜索二维矩阵-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/240.搜索二维矩阵-ii.cpp)    **[array , binary-search , divide-and-conquer]**

  ​	相关题目[74.搜索二维矩阵](https://github.com/liangkang233/leetcode-cpp/blob/main/74.搜索二维矩阵.cpp) 一般的做法就是z字查询 或者二维二分

  ​	 没想到 官方的Z字寻找 时间复杂度 O(n*m) 跑出来效果比二维二分好。可能是样本数据量大部分比较小 这个二维效果不太好。

  
  
- [x] [242.有效的字母异位词](https://github.com/liangkang233/leetcode-cpp/blob/main/242.有效的字母异位词.cpp)    **[hash-table , sort]**

  


- [ ] [258.各位相加.cpp](258.各位相加.cpp)    **[math]**

  ​	O(1)的方法是真的难想到

  


- [x] [263.丑数](https://github.com/liangkang233/leetcode-cpp/blob/main/263.丑数.cpp)	**[math]**

  ​	系列题目 264、265、[313.超级丑数](https://github.com/liangkang233/leetcode-cpp/blob/main/313.超级丑数.cpp)

- [ ] [264.丑数II](https://github.com/liangkang233/leetcode-cpp/blob/main/264.丑数-ii.cpp)	**[math , dynamic-programming , heap]]**

  ​	直接用两个容器动态规划会超时，需要优化。也可以使用堆(优先队列)

  

- [ ] [285.二叉树的中序后继](https://github.com/liangkang233/leetcode-cpp/blob/main/285.二叉树的中序后继.cpp)    **[tree]**

  ​	恶心人的plus会员题

  

- [ ] [290.单词规律](https://github.com/liangkang233/leetcode-cpp/blob/main/290.单词规律.cpp)    **[hash-table]**

  ​	不得不说 c++没有 split 不太方便，用c字符指针的 strtok不优雅。相关题目[205.同构字符串](https://github.com/liangkang233/leetcode-cpp/blob/main/205.同构字符串.cpp)

  

- [ ] [297.二叉树的序列化与反序列化](https://github.com/liangkang233/leetcode-cpp/blob/main/297.二叉树的序列化与反序列化.cpp)    **[tree , design]**

  ​	用中序代码很累赘 用dfs好看些, 注意题中是先使用 自定义的反序列化生成string 再序列化成树。所以为了便于转化 生成的string 可以不为[1,23,45,null] 这类格式。

  

- [ ] [300.最长递增子序列](https://github.com/liangkang233/leetcode-cpp/blob/main/300.最长递增子序列.cpp)    **[dynamic-programming]**

  ​	动态规划 二分(牛的) 都可，直接看进接题的做法[673.最长递增子序列的个数](https://github.com/liangkang233/leetcode-cpp/blob/main/673.最长递增子序列的个数.cpp)

  

- [ ] [304.二维区域和检索-矩阵不可变](https://github.com/liangkang233/leetcode-cpp/blob/main/304.二维区域和检索-矩阵不可变.cpp)    **[dynamic-programming]**

  ​	使用动态规划 构建一个二维前缀数组即可  官方的题解一维前缀也不错。

  

- [ ] [306.累加数](https://github.com/liangkang233/leetcode-cpp/blob/main/306.累加数.cpp)    **[backtracking]**

  ​	基础的回溯做法，但是要考虑的细节比较多 思路就是 整个累加数列的值由前面 第1 2项目决定，所以只需对前两个回溯，后面的值只需要递归判断。注意题目中的 '0' 开头的数字必为0 还有输入数字个数会小于3等问题。过大的数字可以用long限定17位等来做。有位大佬使用 long double 来做，代码很简洁。

  

- [ ] [310.最小高度树](https://github.com/liangkang233/leetcode-cpp/blob/main/310.最小高度树.cpp)    **[breadth-first-search , graph]**

  ​	证明比较复杂，直接记结论好了。

  ​	dfs法1：随机选取1点p，找出p最长路径的终点x(有重复任取1点)，以x为最长的路径的终点y(有重复任取1点)。最小高度树的根即为 xy 的中点 1 个 或 2 个。

  ​	bfs法2：将所有度为1的节点删除，不断重复后，最后只剩度为1的节点即为最小数的根

  

- [ ] [313.超级丑数](https://github.com/liangkang233/leetcode-cpp/blob/main/313.超级丑数.cpp)	**[math , heap]**

  ​	题目[264](https://github.com/liangkang233/leetcode-cpp/blob/main/264.丑数-ii.cpp)的升级做法，使用官方的优先队列会超时？？

  

- [ ] [318.最大单词长度乘积](https://github.com/liangkang233/leetcode-cpp/blob/main/318.最大单词长度乘积.cpp)    **[bit-manipulation]**

  ​	位运算制作字母匹配表 确保是存在相同字母，优化方法是使用 hashmap 记录所有相同字母的 免去重复计算。

  

- [ ] [322.零钱兑换](https://github.com/liangkang233/leetcode-cpp/blob/main/322.零钱兑换.cpp)    **[dynamic-programming]**

  ​	还记得是来实验室做的第一道动态规划 梦开始的地方 经典

  

- [ ] [334.递增的三元子序列](https://github.com/liangkang233/leetcode-cpp/blob/main/334.递增的三元子序列.cpp)    **[unknow]**

  ​	把问题想的过于简单了。。。  其实只要思路 如此也很快解决：贪心遍历 维护 三元中的最小值 中值

  

- [ ] [338.比特位计数](https://github.com/liangkang233/leetcode-cpp/blob/main/338.比特位计数.cpp)    **[dynamic-programming , bit-manipulation]**

  ​	可以采用动态规划或是位运算的方法 只扫一遍 队列计算出答案

  

- [ ] [343.整数拆分](https://github.com/liangkang233/leetcode-cpp/blob/main/343.整数拆分.cpp)    **[math , dynamic-programming]**

  ​	基本的动态规划

  

- [x] [344.反转字符串](https://github.com/liangkang233/leetcode-cpp/blob/main/344.反转字符串.cpp)    **[two-pointers , string]**

  ​	

- [ ] [346.数据流中的移动平均值](https://github.com/liangkang233/leetcode-cpp/blob/main/346.数据流中的移动平均值.cpp)    **[queue]**

  ​	plus会员题... 映射至 [剑指 Offer II 041. 滑动窗口的平均值](https://leetcode-cn.com/problems/qIsx9U/)

- [ ] [347.前-k-个高频元素](https://github.com/liangkang233/leetcode-cpp/blob/main/347.前-k-个高频元素.cpp)    **[hash-table , heap]**

  ​	这里优先队列的pair 重载运算符比较麻烦，所以重载了() 的mycmp。

  

- [x] [349.两个数组的交集](https://github.com/liangkang233/leetcode-cpp/blob/main/349.两个数组的交集.cpp)    **[hash-table , two-points , binary-search]**

- [x] [350.两个数组的交集-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/350.两个数组的交集-ii.cpp)    **[hash-table , two-points , binary-search]**

  

- [ ] [371.两整数之和](https://github.com/liangkang233/leetcode-cpp/blob/main/371.两整数之和.cpp)    **[bit-manipulation]**

  ​	很有意思的题目 哈哈 不用加法算加法  使用位运算 。

  ​	由于计算机中处理 负数使用补码 所以无论正负数 相加 都可以用 普通正数加法来做处理 **需要注意负数的位置溢出** 在 C++ 的实现中，当我们赋给带符号类型一个超出它表示范围的值时，结果是 undefined；而当我们赋给无符号类型一个超出它表示范围的值时，结果是初始值对无符号类型表示数值总数取模的余数。因此，我们可以使用无符号类型来防止溢出报错。

  

- [ ] [373.查找和最小的k对数字](https://github.com/liangkang233/leetcode-cpp/blob/main/373.查找和最小的k对数字.cpp)    **[heap]**

  ​	[264.丑数II](https://github.com/liangkang233/leetcode-cpp/blob/main/264.丑数-ii.cpp)有类似做法。此题先找前k对，因为最小值必然只会找到数组的前 min(k, size) 个元素，之后用堆 set去重。注意pair无法直接用于unordered_set，需要传入哈希函数。另一种做法是直接 `set<tuple<int, int, int>> s;` 做排序去重

  


- [ ] [378.有序矩阵中第-k-小的元素](https://github.com/liangkang233/leetcode-cpp/blob/main/378.有序矩阵中第-k-小的元素.cpp)    **[binary-search , heap]**

  ​	最优解是二分法，当然也可使用优先队列（较差） 归并（最差）也可。类似 [215.数组中的第k个最大元素](https://github.com/liangkang233/leetcode-cpp/blob/main/215.数组中的第k个最大元素.cpp) 

  

- [ ] [380.o-1-时间插入、删除和获取随机元素](https://github.com/liangkang233/leetcode-cpp/blob/main/380.o-1-时间插入、删除和获取随机元素.cpp)    **[array , hash-table , design]**

  ​	srand的正确用法，非常有意思，vector map结合

  

- [ ] [382.链表随机节点](https://github.com/liangkang233/leetcode-cpp/blob/main/382.链表随机节点.cpp)    **[reservoir-sampling]**

  ​	**水塘抽样**问题 妙不可言 有空多复习

  ​	

- [ ] [384.打乱数组](https://github.com/liangkang233/leetcode-cpp/blob/main/384.打乱数组.cpp)    **[unknow]**

  ​	一道随机题目，让我想到 全排列 题目的挑选方案，每次从未挑选元素中寻找添加到确定元素中，此处做法直接是放到数组尾端。

- [ ] [385.迷你语法分析器](https://github.com/liangkang233/leetcode-cpp/blob/main/385.迷你语法分析器.cpp)    **[string , stack]**

  ​	没找规律 就硬做递归 写的不好。用该特殊类做stack做遍历判断。

- [ ] [386.字典序排数](https://github.com/liangkang233/leetcode-cpp/blob/main/386.字典序排数.cpp)    **[unknow]**

  ​	找规律直接遍历生成字典序即可，规律为 默认*10 否则/10 到+1 不会进位或超出即可

  

- [ ] [388.文件的最长绝对路径](https://github.com/liangkang233/leetcode-cpp/blob/main/388.文件的最长绝对路径.cpp)    **[unknow]**

  ​	理解错题意，只有路劲包含. 代表是文件

  

- [ ] [393.utf-8-编码验证](https://github.com/liangkang233/leetcode-cpp/blob/main/393.utf-8-编码验证.cpp)    **[bit-manipulation]**

  ​	就硬解，考虑的东西还蛮多的。 注意4字节上限不是1FFFFF 是10FFFF   题目有问题，没有考虑其unicode码不在取值范围内

  

- [x] [409.最长回文串](https://github.com/liangkang233/leetcode-cpp/blob/main/409.最长回文串.cpp)    **[hash-table]**

- [ ] [410.分割数组的最大值](https://github.com/liangkang233/leetcode-cpp/blob/main/410.分割数组的最大值.cpp)    **[binary-search , dynamic-programming]**

  ​	又是一道二分最优解 动态规划也可

  

- [x] [413.等差数列划分](https://github.com/liangkang233/leetcode-cpp/blob/main/413.等差数列划分.cpp)    **[math , dynamic-programming]**

  

- [x] [415.字符串相加](https://github.com/liangkang233/leetcode-cpp/blob/main/415.字符串相加.cpp)    **[string]**

  ​	做这个题让我想起以前本科做的单片机计算器

  ​	

- [ ] [429.n-叉树的层序遍历](https://github.com/liangkang233/leetcode-cpp/blob/main/429.n-叉树的层序遍历.cpp)    **[unknow]**

  ​	二叉树的层次遍历bfs的稍变形

  

- [ ] [430.扁平化多级双向链表](https://github.com/liangkang233/leetcode-cpp/blob/main/430.扁平化多级双向链表.cpp)    **[list , depth-first-search]**

  ​	做的时候一直认为感觉像是链表的深度遍历，多了些链表的切换操作，注意操作时先判断是否为空 这里被坑了下

  

- [ ] [435.无重叠区间](https://github.com/liangkang233/leetcode-cpp/blob/main/435.无重叠区间.cpp)    **[greedy]**

  ​	贪心 先按照区间首元素排序后 遍历有重合时删除 尾部更长的 降低后续的区间重复的可能

  

- [ ] [437.路径总和-iii](https://github.com/liangkang233/leetcode-cpp/blob/main/437.路径总和-iii.cpp)    **[tree]**

  ​	直接穷举遍历 显然会很慢，优化：用map做前缀和记录 遍历 [560.和为-k-的子数组](https://github.com/liangkang233/leetcode-cpp/blob/main/560.和为-k-的子数组.cpp) 进阶

- [ ] [438.找到字符串中所有字母异位词](https://github.com/liangkang233/leetcode-cpp/blob/main/438.找到字符串中所有字母异位词.cpp)    **[hash-table , sliding-window]**

  ​	典型的滑动窗口，难度适中。类似题目[209](https://github.com/liangkang233/leetcode-cpp/blob/main/209.长度最小的子数组.cpp)

  

- [ ] [440.字典序的第k小数字](https://github.com/liangkang233/leetcode-cpp/blob/main/440.字典序的第k小数字.cpp)    **[unknow]**

  ​	以字典树的思想分层查找

  

- [ ] [445.两数相加-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/445.两数相加-ii.cpp)    **[linked-list]**

  ​	写的很shit 直接stack 反向加，其他做法是转成string 两数相加

  


- [ ] [450.删除二叉搜索树中的节点](https://github.com/liangkang233/leetcode-cpp/blob/main/450.删除二叉搜索树中的节点.cpp)    **[tree]**

​			注意 节点 释放内存 需要把上层节点的指向 子树指针 置空。写遍历写成一坨shit。。。  建议二刷


- [ ] [451.根据字符出现频率排序](https://github.com/liangkang233/leetcode-cpp/blob/main/451.根据字符出现频率排序.cpp)    **[hash-table , heap]**

  ​	桶排序效果也不错

  ​	

- [ ] [464.我能赢吗](https://github.com/liangkang233/leetcode-cpp/blob/main/464.我能赢吗.cpp)    **[dynamic-programming , minimax]**

  ​	[292.nim-游戏](https://github.com/liangkang233/leetcode-cpp/blob/main/292.nim-游戏.cpp)的扩展，一道很经典的博弈题，动态规划

  ​	

- [ ] [479.最大回文数乘积](https://github.com/liangkang233/leetcode-cpp/blob/main/479.最大回文数乘积.cpp)    **[unknow]**

  ​	暴力枚举 的hard题 绝了，还是打表🐂

  

- [ ] [513.找树左下角的值](https://github.com/liangkang233/leetcode-cpp/blob/main/513.找树左下角的值.cpp)    **[tree , depth-first-search , breadth-first-search]**

  ​	[199.二叉树的右视图](https://github.com/liangkang233/leetcode-cpp/blob/main/199.二叉树的右视图.cpp) 进阶题，dfs不太好想 

  

- [ ] [515. 在每个树行中找最大值](https://github.com/liangkang233/leetcode-cpp/blob/main/515.在每个树行中找最大值.cpp)    **[tree , depth-first-search , breadth-first-search]**

  ​	同513 dfs的话就是每一个深度的放一个下标 每次到达相同深度 取最大值即可 推荐bfs

- [ ] [516.最长回文子序列](https://github.com/liangkang233/leetcode-cpp/blob/main/516.最长回文子序列.cpp)    **[dynamic-programming]**

  ​	[5.最长回文子串](https://github.com/liangkang233/leetcode-cpp/blob/main/5.最长回文子串.cpp)扩展，这个动态规划可以压缩为一维的做优化。不过能ac就行，没必要为了这点空间做优化。

  

- [ ] [521.最长特殊序列-i](https://github.com/liangkang233/leetcode-cpp/blob/main/521.最长特殊序列-ⅰ.cpp)    **[string]**

  ​	把题目理解错了... 好好反思这种都能错

- [ ] [522.最长特殊序列-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/521.最长特殊序列-ii.cpp)    **[string]**

  ​	没啥好办法，排序后暴力穷举

  

- [ ] [525.连续数组](https://github.com/liangkang233/leetcode-cpp/blob/main/525.连续数组.cpp)    **[hash-table]**

  ​	与 [560.和为-k-的子数组](https://github.com/liangkang233/leetcode-cpp/blob/main/560.和为-k-的子数组.cpp) 类似，使用前缀和的哈希表

  

- [ ] [537.复数乘法](https://github.com/liangkang233/leetcode-cpp/blob/main/537.复数乘法.cpp)    **[math , string]**

  ​	写起来不太舒服，sscanf sprintf 格式化的做法，答案用正则表达式 查字符 切割字符(split=>strtok)皆可

- [ ] [538.把二叉搜索树转换为累加树](https://github.com/liangkang233/leetcode-cpp/blob/main/538.把二叉搜索树转换为累加树.cpp)    **[tree]**

  ​	与 [1038.从二叉搜索树到更大和树](https://github.com/liangkang233/leetcode-cpp/blob/main/1038.从二叉搜索树到更大和树.cpp) 相同， 先序创节点，中序填入节点即可。或者算出全部节点和后 中序直接在节点上修改。

- [x] [539.最小时间差](https://github.com/liangkang233/leetcode-cpp/blob/main/539.最小时间差.cpp)    **[string]**

  ​	用哈希去重后 直接枚举找最小值

- [ ] [540.有序数组中的单一元素](https://github.com/liangkang233/leetcode-cpp/blob/main/540.有序数组中的单一元素.cpp)    **[binary-search  , bit-manipulation]**

  ​	忘记了题目中声明数组为有序 依此二分，要对奇数位区分判断是否为成对的数 （情人节的每日一题，来自制作者的恶意）


- [x] [541.反转字符串-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/541.反转字符串-ii.cpp)    **[string]**

  ​	


- [ ] [547.省份数量](https://github.com/liangkang233/leetcode-cpp/blob/main/547.省份数量.cpp) 	**[depth-first-search , union-find]**

  ​	经典的并查集问题，注意路径压缩与按秩归并。使用dfs bfs注意剪枝否则效果差

  

- [ ] [553.最优除法](https://github.com/liangkang233/leetcode-cpp/blob/main/553.最优除法.cpp)    **[math , string , dynamic-programming]**

  ​	考虑到题中确定所有数大于等于2 那结果必然就只有一种。若是没有这个限制就用动态规划，还得考虑字符串，很困难。

  

- [x] [557.反转字符串中的单词-iii](https://github.com/liangkang233/leetcode-cpp/blob/main/557.反转字符串中的单词-iii.cpp)    **[string]**

  

- [ ] [560.和为-k-的子数组](https://github.com/liangkang233/leetcode-cpp/blob/main/560.和为-k-的子数组.cpp)    **[array , hash-table]**

  ​	nums[i] 包含0 边界处理很棘手 且有正有负 说明滑动窗口不可行。使用前缀和 map记录查询很好 学到新活！

  

- [ ] [567.字符串的排列](https://github.com/liangkang233/leetcode-cpp/blob/main/567.字符串的排列.cpp)    **[two-pointers , sliding-window]**

  ​	滑动窗口 字符串题 类似题有 [438.找到字符串中所有字母异位词.cpp](https://github.com/liangkang233/leetcode-cpp/blob/main/438.找到字符串中所有字母异位词.cpp)

  

- [ ] [572.另一棵树的子树](https://github.com/liangkang233/leetcode-cpp/blob/main/572.另一棵树的子树.cpp)    **[tree]**

  ​	dfs做的话没啥难度，关键在于 前序遍历数组kmp对比 树哈希做法(字节面试)

  

- [ ] [583.两个字符串的删除操作](https://github.com/liangkang233/leetcode-cpp/blob/main/583.两个字符串的删除操作.cpp)    **[string , dynamic-programming]**

  ​	相关题目[1143.最长公共子序列](https://github.com/liangkang233/leetcode-cpp/blob/main/1143.最长公共子序列.cpp)

  

- [x] [599.两个列表的最小索引总和](https://github.com/liangkang233/leetcode-cpp/blob/main/599.两个列表的最小索引总和.cpp)    **[hash-table]**

  ​	哈希表典型应用

  


- [x] [605.种花问题](https://github.com/liangkang233/leetcode-cpp/blob/main/605.种花问题.cpp)    **[array]**

  ​	vivo面试题

  


- [ ] [621.任务调度器](https://github.com/liangkang233/leetcode-cpp/blob/main/621.任务调度器.cpp)    **[array , greedy , queue]**

  ​	先取出并以出现次数频率作为排序依据，解题需要穷举几次发现规律，比较难想到

  

- [ ] [623.在二叉树中增加一行](https://github.com/liangkang233/leetcode-cpp/blob/main/623.在二叉树中增加一行.cpp)    **[tree , dfs]**

  ​	dfs的应用，一定按照题意对 depth-1 行操作，吃了这个亏花了很长时间才发现题目理解错了，添加的那行树的左右子树顺序是有要求的

  

- [ ] [647.回文子串](https://github.com/liangkang233/leetcode-cpp/blob/main/647.回文子串.cpp)    **[string , dynamic-programming]**

  ​	与 [5.最长回文子串](https://github.com/liangkang233/leetcode-cpp/blob/main/5.最长回文子串.cpp) 一样

  

- [ ] [673.最长递增子序列的个数](https://github.com/liangkang233/leetcode-cpp/blob/main/673.最长递增子序列的个数.cpp)    **[dynamic-programming]**

  ​	[300.最长递增子序列](https://github.com/liangkang233/leetcode-cpp/blob/main/300.最长递增子序列.cpp) 进阶题，常规做法 :维护一个 dp[i] 为 以i为起点(一定包含i)到达尾部的最大递增子序列长度 first 以及其个数 second 的数组做动态规划，还有 贪心二分 做法(妙)。

  

- [x] [680.验证回文字符串-ⅱ](https://github.com/liangkang233/leetcode-cpp/blob/main/680.验证回文字符串-ⅱ.cpp)    **[string]**

  

- [ ] [688.马-在棋盘上的概率](https://github.com/liangkang233/leetcode-cpp/blob/main/688.马-在棋盘上的概率.cpp)    **[dynamic-programming]**

  ​	动态规划，维护一个 n*n dp容器记录每个位置的成功概率。进行k次遍历更新dp每个格子的概率，其每个格子的当前概率为对应8个方向的格子上一次遍历概率。若是第一次进行遍历则格子对应初始概率为1.0。

  

- [x] [693.交替位二进制数](https://github.com/liangkang233/leetcode-cpp/blob/main/693.交替位二进制数.cpp)    **[bit-manipulation]**

  


- [ ] [705.设计哈希集合](https://github.com/liangkang233/leetcode-cpp/blob/main/705.设计哈希集合.cpp)    **[Unknown]**

  ​	有意思，设计list容器。list使用std就好，自己写要维护链表头尾比较麻烦。

- [ ] [706.设计哈希映射](https://github.com/liangkang233/leetcode-cpp/blob/main/706.设计哈希映射.cpp)    **[Unknown]**

  ​	list链表数组

- [ ] [707.设计链表](https://github.com/liangkang233/leetcode-cpp/blob/main/707.设计链表.cpp)    **[Unknown]**

  ​	设计 链表 使用单向链表 需要虚拟头 使用双向链表 需要虚拟头、尾

- [ ] [708.循环有序链表](https://github.com/liangkang233/leetcode-cpp/blob/main/708.循环有序链表.cpp)    **[link-list]**

  ​	原题要会员就离谱 替代品: [剑指 Offer II 029. 排序的循环链表 ](https://leetcode-cn.com/problems/4ueAj6/)

  

- [ ] [713.乘积小于k的子数组](https://github.com/liangkang233/leetcode-cpp/blob/main/713.乘积小于k的子数组.cpp)    **[array , two-pointers , sliding-window]**

  ​	这个滑动窗口要考虑到子数组如何计算和缩减的问题，不妨假设窗口遍历时前面的子数组统计完备，那之后的子数据计入必需包含右边界则可以很容器的解决该问题。

  

- [x] [717.1-比特与-2-比特字符.cpp](https://github.com/liangkang233/leetcode-cpp/blob/main/717.1-比特与-2-比特字符.cpp)    **[array]**

  ​	推敲下，确定一个数组排序唯一。顺序遍历的判断即可，官方答案的逆序做法不错，想不到！

  

- [x] [724.寻找数组的中心下标](https://github.com/liangkang233/leetcode-cpp/blob/main/724.寻找数组的中心下标.cpp)    **[array]**

  ​	简单前缀和应用

  

- [x] [735.行星碰撞](https://github.com/liangkang233/leetcode-cpp/blob/main/735.行星碰撞.cpp)    **[stack]**

  ​	用数组构造栈，好活

  

- [ ] [738.单调递增的数字](https://github.com/liangkang233/leetcode-cpp/blob/main/738.单调递增的数字.cpp)    **[greedy]**

  ​	找规律后贪心即可，一开始居然打算用dfs 回溯做。

- [ ] [739.每日温度](https://github.com/liangkang233/leetcode-cpp/blob/main/739.每日温度.cpp)    **[hash-table , stack]**

  ​	单调栈理解不透彻 写成这个样子  答案是正向遍历 绝了 需要二刷

  

- [x] [747.至少是其他数字两倍的最大数](https://github.com/liangkang233/leetcode-cpp/blob/main/747.至少是其他数字两倍的最大数.cpp)    **[array , dynamic-programming]**

  ​	

- [ ] [763.划分字母区间](https://github.com/liangkang233/leetcode-cpp/blob/main/763.划分字母区间.cpp)    **[string , recursion]**

  ​	自己做是贪心的维护了一个数组map 记录每个字符所在区间的左界下标，最后遍历一遍出的答案。官方的答案是维护右界。。少进行一次遍历。

  

- [ ] [779.第k个语法符号](https://github.com/liangkang233/leetcode-cpp/blob/main/779.第k个语法符号.cpp)    **[array]**

  ​	找规律即可

  

- [ ] [784.字母大小写全排列](https://github.com/liangkang233/leetcode-cpp/blob/main/784.字母大小写全排列.cpp)    **[ordered-map]**

  ​	与[46.全排列](https://github.com/liangkang233/leetcode-cpp/blob/main/46.全排列.cpp)  [47.全排列-ii](https://github.com/liangkang233/leetcode-cpp/blob/main/47.全排列-ii.cpp) 有点像，注意要保留无变化的

  

- [x] [797.所有可能的路径](https://github.com/liangkang233/leetcode-cpp/blob/main/797.所有可能的路径.cpp)    **[math , depth-first-search]**

  ​	dfs回溯减枝

- [ ] [798.得分最高的最小轮调](https://github.com/liangkang233/leetcode-cpp/blob/main/798.得分最高的最小轮调.cpp)    **[math , array]**

  ​	差分数组 很难区分区间越界 答案用取余 秒

  ​	

- [ ] [814.二叉树剪枝](https://github.com/liangkang233/leetcode-cpp/blob/main/814.二叉树剪枝.cpp)    **[tree , depth-first-search]**

  ​	有时不必急着delete内存，也许测试案例给的是 局部变量非new的堆空间 不需要delete （delete会报错）

  

- [ ] [821.字符的最短距离](https://github.com/liangkang233/leetcode-cpp/blob/main/821.字符的最短距离.cpp)    **[union-find]**

  ​	遍历两遍 第一遍记录特定字符位置。想节约空间的话 将这两步合并。

  

- [ ] [838.推多米诺](https://github.com/liangkang233/leetcode-cpp/blob/main/838.推多米诺.cpp)    **[linked-list , design]**

  ​	走弯路了，看完官方 豁然开朗。模拟多米诺 只要找中间全为竖立状态的 进行判断： 

  ​	若骨牌同向 此区间全为该方向

  ​    若骨牌反向 此区间向中间倒

  ​    若骨牌背向 此区间不变

  

- [x] [841.钥匙和房间](https://github.com/liangkang233/leetcode-cpp/blob/main/841.钥匙和房间.cpp)    **[depth-first-search]**

  

- [ ] [844.比较含退格的字符串](https://github.com/liangkang233/leetcode-cpp/blob/main/844.比较含退格的字符串.cpp)    **[stack , two-pointers]**

  ​	用双指针写的很烦，像shit一样，用栈写非常香。

  

- [ ] [876.链表的中间结点](https://github.com/liangkang233/leetcode-cpp/blob/main/876.链表的中间结点.cpp)    **[ordered-map , linked-list , two-pointers]**

  ​	注意题中输出要求，使用双指针做

  

- [ ] [887.鸡蛋掉落](https://github.com/liangkang233/leetcode-cpp/blob/main/887.鸡蛋掉落.cpp)    **[heap]**

  ​	双蛋问题，google经典面试题，2020 vivo提前批。第一次做思路出了问题，解决部分。这道题常规做法用到 二分法 + 动态规划。官方解法3的逆向思维可以了解下。

  

- [ ] [889.根据前序和后序遍历构造二叉树](https://github.com/liangkang233/leetcode-cpp/blob/main/889.根据前序和后序遍历构造二叉树.cpp)	**[string , tree]**

  ​	先回顾二叉树前中后序列区别，注意题中说明 二叉树中的各个值不相同,不需要考虑不成立的情况

- [ ] [890.查找和替换模式](https://github.com/liangkang233/leetcode-cpp/blob/main/890.查找和替换模式.cpp)	**[greedy]**

  ​	题目[205](https://github.com/liangkang233/leetcode-cpp/blob/main/205.同构字符串.cpp)、类似做法直接双重映射或者单重映射搭配数组记录次数，（单重映射只能保证一对多，不能一一对应）

  ​	第一次做时打算用个数来做少考虑了部分情况。直接用数组下标做映射也是可以的（推荐）

- [ ] [891.子序列宽度之和](https://github.com/liangkang233/leetcode-cpp/blob/main/891.子序列宽度之和.cpp)	**[greedy]**	

  ​	有难度，找公式。
  
  
  
- [ ] [897.递增顺序搜索树](https://github.com/liangkang233/leetcode-cpp/blob/main/897.递增顺序搜索树.cpp)    **[math]**

  ​	官方解是直接改原链表指向。是否原地修改 看情况而定 
  
  
  
- [ ] [917.仅仅反转字母](https://github.com/liangkang233/leetcode-cpp/blob/main/917.仅仅反转字母.cpp)    **[two-pointers , greedy]**

  ​	双指针简单应用  判断是否为字符使用 isalpha()

  


- [ ] [925.长按键入](https://github.com/liangkang233/leetcode-cpp/blob/main/925.长按键入.cpp)    **[tree]**

  ​	第一次写的很烂，思路跟答案差不多，很多情况没考虑到。
  
  
  
- [ ] [919.完全二叉树插入器](https://github.com/liangkang233/leetcode-cpp/blob/main/919.完全二叉树插入器.cpp)    **[math , queue]**

  ​	层序遍历 补充父节点队列即可
  
  
  
- [ ] [933.最近的请求次数](https://github.com/liangkang233/leetcode-cpp/blob/main/933.最近的请求次数.cpp)    **[tree , depth-first-search]**

  ​	网络仿真软件的事件也是如此实现，按照时间顺序push入事件队列 处理事件。
  
  
  
- [x] [953.验证外星语词典](https://github.com/liangkang233/leetcode-cpp/blob/main/953.验证外星语词典.cpp)    **[string]**

  ​	

- [x] [969.煎饼排序](https://github.com/liangkang233/leetcode-cpp/blob/main/969.煎饼排序.cpp)    **[queue]**

  ​	直觉做的方案效果还不错，直接暴力的迭代对当前最大的数转置

  

- [x] [973.最接近原点的-k-个点](https://github.com/liangkang233/leetcode-cpp/blob/main/973.最接近原点的-k-个点.cpp)    **[string , greedy]** 

  ​	实现想不到啥好方法，直接暴力排序看看居然ac了。仔细想想用堆排序应该更好些

  

- [x] [986.区间列表的交集](https://github.com/liangkang233/leetcode-cpp/blob/main/986.区间列表的交集.cpp)    **[math , two-points]**

  ​	虽然题目简单，但是写的不好 太慢了

  

- [ ] [997.找到小镇的法官](https://github.com/liangkang233/leetcode-cpp/blob/main/997.找到小镇的法官.cpp)    **[graph]**

  ​	理解题意即可 注意 空数组边界。本质上是图论题目的出度 入度

  


- [ ] [1006.笨阶乘](https://github.com/liangkang233/leetcode-cpp/blob/main/1006.笨阶乘.cpp)    **[hash-table , string]**

  

- [ ] [1024.视频拼接](https://github.com/liangkang233/leetcode-cpp/blob/main/1024.视频拼接.cpp)    **[greedy , dynamic-programming]**

  

- [ ] [1038.从二叉搜索树到更大和树](https://github.com/liangkang233/leetcode-cpp/blob/main/1038.从二叉搜索树到更大和树.cpp)    **[math , backtracking , graph]**

  ​	与[538.把二叉搜索树转换为累加树](https://github.com/liangkang233/leetcode-cpp/blob/main/538.把二叉搜索树转换为累加树.cpp) 相同

  

- [ ] [1091.二进制矩阵中的最短路径](https://github.com/liangkang233/leetcode-cpp/blob/main/1091.二进制矩阵中的最短路径.cpp)    **[depth-first-search , breadth-first-search]**

  ​	dfs容易超时，**找寻一个解或答案时bfs有效，比较全部路径时一般用dfs更好** ，这题还要注意起点会有坑...

  ​	bfs只要找到路就可以return 最先找到的必定等于最短值, 标记走过的路直接赋值原数组1 **(bfs，dfs少用set)**

  

- [ ] [1111.有效括号的嵌套深度](https://github.com/liangkang233/leetcode-cpp/blob/main/1111.有效括号的嵌套深度.cpp)    **[dynamic-programming]**

  ​	第一想法就是用栈做，没想到这题也可以动态规划

  

- [ ] [1143.最长公共子序列](https://github.com/liangkang233/leetcode-cpp/blob/main/1143.最长公共子序列.cpp)    **[dynamic-programming]**

  ​	典型二维动态规划 等价题目[583.两个字符串的删除操作](https://github.com/liangkang233/leetcode-cpp/blob/main/583.两个字符串的删除操作.cpp) 

  

- [ ] [1163.按字典序排在最后的子串](https://github.com/liangkang233/leetcode-cpp/blob/main/1163.按字典序排在最后的子串.cpp)    **[unknow]**

  ​	思路容易想到，就是实现时总是忘考虑各种情况。容易知道ans的头一定为string中最大的元素，设计两个string 一个为输出的答案。一个为遍历过程中string缓存ans1，出现当前字符最大值后，迭代的与ans比较来确定该ans1是补上ans还是重新定义为ans。

  

- [ ] [1220.统计元音字母序列的数目](https://github.com/liangkang233/leetcode-cpp/blob/main/1220.统计元音字母序列的数目.cpp)    **[dynamic-programming]**

  ​	这个找规律 蛮有意思的

  

- [ ] [1249.移除无效的括号](https://github.com/liangkang233/leetcode-cpp/blob/main/1249.移除无效的括号.cpp)    **[stack]**

  ​	fdjk

  

- [ ] [1332.删除回文子序列](https://github.com/liangkang233/leetcode-cpp/blob/main/1332.删除回文子序列.cpp)    **[unkown]**

  ​	想复杂了，注意题目中删除回文字符串不一定为连续。给的案例拿来误导的。

  

- [ ] [1353.最多可以参加的会议数目](https://github.com/liangkang233/leetcode-cpp/blob/main/1353.最多可以参加的会议数目.cpp)    **[unkown]**

  ​	贪心优先队列，算是应用题了

  

- [ ] [1557.可以到达所有点的最少点数目](https://github.com/liangkang233/leetcode-cpp/blob/main/1557.可以到达所有点的最少点数目.cpp)    **[graph]**

  ​	简单问题复杂化了，属于是

  

- [ ] [1568.使陆地分离的最少天数](https://github.com/liangkang233/leetcode-cpp/blob/main/1568.使陆地分离的最少天数.cpp)	**[unkown]**

  ​	脑经急转弯。。 

  

- [ ] [1594.矩阵的最大非负积](https://github.com/liangkang233/leetcode-cpp/blob/main/1594.矩阵的最大非负积.cpp)    **[unkown]**

  ​	万能的DP

  

- [x] [1629.按键持续时间最长的键](https://github.com/liangkang233/leetcode-cpp/blob/main/1629.按键持续时间最长的键.cpp)    **[unkown]**

  

- [ ] [1664.生成平衡数组的方案数](https://github.com/liangkang233/leetcode-cpp/blob/main/1664.生成平衡数组的方案数.cpp)    **[unkown]**

  

- [ ] [1706.球会落何处](https://github.com/liangkang233/leetcode-cpp/blob/main/1706.球会落何处.cpp)    **[unkown]**

  ​	让我想到了[多米诺题目](https://github.com/liangkang233/leetcode-cpp/blob/main/838.推多米诺.cpp)，也是左右判断是否停止。

  

- [x] [1716.计算力扣银行的钱](https://github.com/liangkang233/leetcode-cpp/blob/main/1716.计算力扣银行的钱.cpp)    **[unkown]**

  

- [x] [1791.找出星型图的中心节点](https://github.com/liangkang233/leetcode-cpp/blob/main/1791.找出星型图的中心节点.cpp)    **[unkown]**

  ​	

- [ ] [1823.找出游戏的获胜者](https://github.com/liangkang233/leetcode-cpp/blob/main/1823.找出游戏的获胜者.cpp)    **[unknow]**

  ​	想不出好方法，直接拿链表硬做的。[约瑟夫环问题](https://blog.csdn.net/u011500062/article/details/72855826) 

  

- [ ] [1935.可以输入的最大单词数](https://github.com/liangkang233/leetcode-cpp/blob/main/1935.可以输入的最大单词数.cpp)    **[unkown]**

  ​	注意边界和最后一个单词

  

- [x] [1953.你可以工作的最大周数](https://github.com/liangkang233/leetcode-cpp/blob/main/1953.你可以工作的最大周数.cpp)    **[unkown]**

  

- [ ] [2016.增量元素之间的最大差值](https://github.com/liangkang233/leetcode-cpp/blob/main/2016.增量元素之间的最大差值.cpp)    **[unkown]**

  ​	一开始想着用堆做导致问题后面解析复杂了。只需要维护一个前缀即可

  

- [ ] [2024.考试的最大困扰度](https://github.com/liangkang233/leetcode-cpp/blob/main/2024.考试的最大困扰度.cpp)    **[sliding-window]**

  ​	滑动窗口题，被自己蠢到了，居然遍历左边界 而不滑动窗口里来满足k

  

- [ ] [2034.股票价格波动](https://github.com/liangkang233/leetcode-cpp/blob/main/2034.股票价格波动.cpp)    **[unkown]**

  ​	很有意思的题 结构设计 注意multiset erase 的坑，有条件尽量用无序的来做
  
  
  
- [x] [2038.如果相邻两个颜色均相同则删除当前颜色](https://github.com/liangkang233/leetcode-cpp/blob/main/2038.如果相邻两个颜色均相同则删除当前颜色.cpp)    **[unkown]**

  ​	
  
- [ ] [2055.蜡烛之间的盘子](https://github.com/liangkang233/leetcode-cpp/blob/main/2055.蜡烛之间的盘子.cpp)    **[binary-search]**

  ​	二分题目真的是每次都会在边界问题上卡好久，还是得多练。将盘子前缀记录在数组中，然后二分的查相减即可
  
  
  
- [ ] [2100.适合打劫银行的日子](https://github.com/liangkang233/leetcode-cpp/blob/main/2100.适合打劫银行的日子.cpp)    **[dynamic-programming , two-pointers]**

  ​	望文生义，直接找出并记录所有满足时间的长度递减和递增下标 重合时间下标即为适合打劫的日子，省时间费空间 注意，time可以为0， 所以建立下标时要考虑 ``i==0 i==size-1``  看看官方的动态规划 和 大佬的双指针（推荐）
  
  
  
- [ ] [2104.子数组范围和](https://github.com/liangkang233/leetcode-cpp/blob/main/2104.子数组范围和.cpp)    **[stack , sliding-window]**

  ​	直接暴力的滑动窗口 时间复杂度O(n^2) 容易超时，使用[单调栈](https://www.bilibili.com/video/BV1Y441117gR?from=search&seid=16970796620628411939&spm_id_from=333.337.0.0)来做

# 关键

- 序列：

  1. 子序列元素相同并不代表是 **同一子序列** ，只要子序列元素索引不同即为不同子序列，**子集合** 才是考虑元素不同（题目 891）

  2. **子序列** 是不要求连续的，而 **子数组** 和 **子串** 一样，是需要连续的 

  ​	例如 *12345678* 的子序列 可以是 *1345678* 子数组 只能是 *45678* 之类的

- 二叉树：

  1. 前序/后序+中序序列可以唯一确定一棵二叉树，只知道前序和后序不唯一确定 参考 [105.从前序与中序遍历序列构造二叉树](https://github.com/liangkang233/leetcode-cpp/blob/main/105.从前序与中序遍历序列构造二叉树.cpp) [蓝桥杯例题](https://github.com/liangkang233/leetcode-cpp/blob/main/test_tools/由前(后)序和中序 推导至后(中)序.cpp) 和 [889.根据前序和后序遍历构造二叉树](https://github.com/liangkang233/leetcode-cpp/blob/main/889.根据前序和后序遍历构造二叉树.cpp)

  2. 创建树的模板 [createTree](https://github.com/liangkang233/leetcode-cpp/blob/main/test_tools/createTree.cpp) [297.二叉树的序列化与反序列化](https://github.com/liangkang233/leetcode-cpp/blob/main/297.二叉树的序列化与反序列化.cpp)

  3. 二叉搜索树使用中序遍历为 升序或者降序

- 链表题目注意:

  1. 舍得用变量，千万别想着节省变量，否则容易被逻辑绕晕
  2. head 有可能需要改动时，先增加一个 假head，返回的时候直接取 假head.next，这样就不需要为修改 head 增加一大堆逻辑了。

- leetcode输入测试：

  1. 若是例如[44.通配符匹配](https://github.com/liangkang233/leetcode-cpp/blob/main/44.通配符匹配.cpp)的类似多个string时外面还要加""，例如输入```s="io" p="io*" ```时，应该是输入 ```""io"\n"io*""```

     即测试内容包含字符串 外面再包一个``""`` 类似的还有 `""***|**|*****|**||**|*"\n[[1,17]]\n"`

  2. 非文件的话多个参数使用\n分隔，文件的话直接回车分行即可。

- 常用函数 表达式

  1. distance(first, last) 函数 求迭代器之间的距离 **非随机访问迭代器 例如set map 事件复杂度为 O(n)** [739.每日温度](https://github.com/liangkang233/leetcode-cpp/blob/main/739.每日温度.cpp) 此列题 用map 做下标查找二分下标
  2. 判断是否为字符使用 isalpha()
  3. C++ 科学计数法表达数字(double)  `0.01 => 1e-2;  100 => 1e2;`
  4. [C++ std库实现的二分查找](https://github.com/liangkang233/leetcode-cpp/blob/main/常用代码模块/bound.cpp) lower_bound()返回第一个大于等于 upper_bound()返回第一个大于
  5. 随机值问题：[382.链表随机节点](https://github.com/liangkang233/leetcode-cpp/blob/main/382.链表随机节点.cpp) 无需注入srand随机种子   [rand使用方法](https://github.com/liangkang233/leetcode-cpp/blob/main/常用代码模块/rand.cpp) ***srand正确用法应该放在类的构造函数内***，只初始化一次。

- size() 返回值为无符号数，其与负数相比较时负数会转为无符号数，所以判断结果会出问题。一定要在判断前转为int。

- 顺序容器中关于 [emplace_back](https://github.com/liangkang233/leetcode-cpp/blob/main/test_tools/emplace_back.cpp) 用法 还包含了vector 的 size reserver

- 找寻全部解时dfs效果比bfs效果好或者差不多，只需要一条路径或判断是否有效时 推荐bfs。bfs(队列) dfs(栈)的具体实现可采用递归 迭代，一般用递归好写点也好理解。dfs栈的状态如果会返回上次递归 则算法就是回溯。

- multiset是元素可以重复的有序队列，非常好用，会自动排序队内元素。（set是不会出现元素重复的有序数组底层红黑树，所以元素无需排序时尽量hash实现的unordered_set）跟优先队列的区别，这个分析的不错 [优先队列能否被set或multiset（c++语法）替换？ - 知乎 (zhihu.com)](https://www.zhihu.com/question/491514115)

- multiset erase 删除值时会将所有相等值删除，erase单个迭代器才是删单个元素。查询该值范围时可用 equal_range 返回一个pair 指向头 和末尾的后一个元素 erase输入两个迭代器删范围。

- unordered_set 不能直接用pair做key，需要传入hash函数 例如下 [参考1](https://blog.csdn.net/hxy1996520/article/details/105876960) [参考2](https://blog.csdn.net/hxy1996520/article/details/105876960)

  ```cpp
  struct SimpleHash {
      size_t operator()(const std::pair<int, int>& p) const {
          return hash<int>{}(p.first) ^ hash<int>{}(p.second);
      }
  };
  
  unordered_set<pair<int, int>, SimpleHash> myset; 
  ```

- [greater less 模板解析](https://github.com/liangkang233/leetcode-cpp/blob/main/常用代码模块/greater等模板类的用法.cpp)

- [字符串相关](https://github.com/liangkang233/leetcode-cpp/blob/main/常用代码模块/读字符串.cpp)     [stringstream、istringstream、ostringstream 三者的区别](https://www.cnblogs.com/alking1001/p/11766002.html)

- [常见容器 queue stack hashmap](https://github.com/liangkang233/leetcode-cpp/blob/main/常用代码模块/常见语法备注.cpp) 双端队列:[*deque*](http://c.biancheng.net/view/6860.html) 双向链表 [*list*](http://c.biancheng.net/view/6892.html)

- [基本类构造 重载 priority forrange 使用](https://github.com/liangkang233/leetcode-cpp/blob/main/常用代码模块/基本类构造、重载、priority使用.cpp)

- [C++格式的转换: **static_cast**  **dynamic_cast**]([static_cast 运算符](https://docs.microsoft.com/zh-cn/cpp/cpp/static-cast-operator?view=msvc-170)) 比c的强转安全

- C++ 类定义的函数方法要在类内使用 需要 static 修饰 [举例](https://github.com/liangkang233/leetcode-cpp/blob/main/705.设计哈希集合.cpp) 102行  此处的自定义比较函数一般使用匿名函数

- 在声明时可以不加 形参名，定义时再加。且在类内声明static函数，类外定义时不要加static [示例](https://blog.csdn.net/sinat_36053757/article/details/72636903) (声明时需要告诉编译器这是什么类型， 但定义时， 编译器会自己找声明C++中有很多类似语法：比如， 默认参数列表， 是声明的时候加默认参数， 定义函数的时候不需要; 定义inline函数也是声明的时候加inline， 定义的时候不加

