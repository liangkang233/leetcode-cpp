/*
 * meituan-015. 十字路口
 *
 * https://leetcode-cn.com/problems/KLwc3e/
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pi;
int m, n, xt, yt;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

//计算需要的等待时间 dir来设定该节点 上下左右移动轨迹
int canMove(vector<vector<int>>& a, vector<vector<int>>& b, int x, int y, int d, int dir) {
    int nowTime = d % (a[x][y] + b[x][y]);
    if (dir < 2) {
        if (nowTime < a[x][y]) //直接上下移动 
            return 0;
        else
            return a[x][y] + b[x][y] - nowTime; // 原地等待这个时间后才可上下移动
    }
    else {
        if (nowTime < a[x][y] + b[x][y] && nowTime >= a[x][y])  //直接左右移动 
            return 0;
        else
            return a[x][y] - nowTime; // 原地等待这个时间后才可左右移动
    }
}
//执行SPFA算法 
int spfa(vector<vector<int>>& a, vector<vector<int>>& b, int X, int Y) {   
    queue<pi> q;
    q.push(pi{X, Y});
    vector<vector<int>> dis(n, vector<int>(m, INT_MAX)); // 记录到达每个点的最短时间
    dis[X][Y] = 0;
    while (!q.empty()) {
        pi node = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {     //检查node的所有邻居 
            pi next;
            next.first = node.first + dir[i][0];
            next.second = node.second + dir[i][1];
            if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m)
                continue; //保证求出的下标都在合法的范围内 
            int p = canMove(a, b, node.first, node.second, dis[node.first][node.second], i);
            if (dis[node.first][node.second] + p + 1 < dis[next.first][next.second]) {   
                dis[next.first][next.second] = dis[node.first][node.second] + p + 1; //更新状态
                q.push(next);
            }
        }
    }
    return dis[xt][yt];
}

int main () 
{
    int xs, ys;
    cin >> n >> m >> xs >> ys >> xt >> yt;
    xs--, ys--, xt--, yt--;
    vector<vector<int>> a(n, vector<int>(m)), b(a);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> b[i][j];
    }
    cout << spfa(a, b, xs, ys) << endl;
    return 0;
}


// 1 ≤ n, m, xs, ys, xt, yt, a[i][j], b[i][j] ≤ 100

/* 输入：
- 第一行六个正整数 n,m,xs,ys,xt,yt ，含义如上文所示。
- 以样例第一行【5、5、2、4、4、3】 共计 6 个数字为例：
- 前两位数字代表有 5*5 的二维数组
- 三、四位数字代表小美处在 2 行 4 列的十字路口处
- 五、六位数字代表要去 4 行 3 列的十字路口找小团。
- 接下来 n 行每行 m 个正整数，在样例中为第一个 5*5 的二维数组，
- 第 i 行第 j 个数代表 i 行 j 列十字路口的属性 a[i][j] 。
- 接下来 n 行每行 m 个正整数，在样例中为第二个 5*5 的二维数组，
- 第 i 行第 j 个数代表 i 行 j 列十字路口的属性 b[i][j]。
输出：
- 输出 1 行 1 个整数代表答案。


/* https://leetcode-cn.com/problems/KLwc3e/solution/spfazui-duan-lu-suan-fa-qiu-jie-by-zhui-823m3/ 
SPFA算法的执行步骤如下：
（1）起点s入队，计算它所有邻居到s的最短路径（当前最短距离，不是全局最短距离。
    把计算一个结点到起点s的最短路径简称为更新状态。最后的“状态”就是SPFA的计算结果）。
    把s出队，状态有更新的邻居入队，没更新的不入队。也就是说，队列中都是状态有变化的结点，
    只有这些结点才会影响最短路径的计算。
（2）现在队列的头部是s的一个邻居u。弹出u，更新其所有邻居的状态，把其中有状态的变化的邻居入队列。
（3）这里有一个问题，弹出u之后，在后面的计算中u可能会再次更新状态（后来发现，u借道其他结点去s，路更近）。
    所以，u可能需要重新入队列。这一点很容易做到：在处理一个新的结点u时，
    它的邻居可能就是以前处理过的u，如果u的状态变化了，把u重新加入队列就行了。
（4）继续以上过程，直到队列空。这也意味着所有结点的状态不再更新。最后的状态就是到起点s的最短路径。
注意本题的数据范围全为正整数，不需要判断负圈。
进一步分析题目，对于任意非负整数k，我们取k=0，则：
当时间处在[0,a[i][j])时，行人可以选择走到 i±1 行 j 列的路口。
当时间处在[a[i][j],a[i][j]+b[i][j])，行人可以选择走到 i 行 j±1 列的路口。
再取k=1：
当时间处在[a[i][j]+b[i][j],2a[i][j]+b[i][j])时，行人可以选择走到 i±1 行 j 列的路口。
当时间处在[2a[i][j]+b[i][j],2a[i][j]+2b[i][j])，行人可以选择走到 i 行 j±1 列的路口。
我们不难发现其中的规律，令当前时间为nowTime，行人想走到 i±1 行 j 列的路口，如果不在规定的时间范围内，需要额外花费k*(a[x][y] + b[x][y])-nowTime(取k值保证该式非负)的时间等待，同理，行人想走到 i 行 j±1 列的路口，如果不在规定的时间范围内，需要额外花费k*a[x][y]-nowTime(取k值保证该式非负)的时间等待。
如果将题目所给的条件抽象成一个周期性函数（比如函数值y只用1和-1表示，
1代表行人可以选择走到 i±1 行 j 列的路口，-1代表行人可以选择走到 i 行 j±1 列的路口，
则函数值随着时间x的增加在1和-1之间来回摆动），可以认为函数周期是a[x][y] + b[x][y]。 */


/* // 超时
int mybfs(vector<vector<int>>& a, vector<vector<int>>& b, int XY) 
{
    unordered_set<int> myset; // 由于限制条件与时间有关 所以不能单纯的用 坐标去重
    queue<pi> que; // 记录步骤花费 时间，位置 x y 转化为 100*X + Y
    que.push(pi{0, XY});
    while (!que.empty()) {
        pi now = que.front();
        que.pop();
        // if(myset.find(now.second) != myset.end())
        //     continue;
        // myset.insert(now.second);
        int t = now.first, x = now.second / 100, y = now.second - 100 * x;
        if(x == xt && y == yt)
            return t;
        int temp = t % (a[x][y] + b[x][y]); // 翻译题意要求
        que.push(pi{t+1, x*100 + y}); // 遍历的时候可以在原地等待!!!   所以按照节点移动去做时间复杂度很高
        if(temp < a[x][y]) {
            if(x+1 < n)
                que.push(pi{t+1, (x+1)*100 + y});
            if(x-1 > 0)
                que.push(pi{t+1, (x-1)*100 + y});
        }
        else {
            if(y+1 < m)
                que.push(pi{t+1, x*100 + y + 1});
            if(y-1 >= 0)
                que.push(pi{t+1, x*100 + y - 1});
        }
    }
    return -1;
} */