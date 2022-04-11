/*
 * meituan-012. 小美的书架
 *
 * https://leetcode-cn.com/problems/FvoBGh/
 */

#include <iostream>
#include <vector>
using namespace std;

// 一开始书都是放在地上的（没放在书架上）；小美心情好的时候可能会将书本 x 放到 y 行上；
// 小团借书时，如果 书本不在书架上 或该书架上锁 ，或 书本在小团手里，都要输出 -1；
// 小团还书时，都是直接往地上一扔，不会放回到书架上；如果再借，就找不着了，要输出 -1；
// 除非在此期间，小美把它放回到书架上。

// 感觉有很久没有写 switch 语句了
int main () 
{
    int M, N, Q, instr; // 书架 1-N 行， 书共有 1-M 本
    cin >> M >> N >> Q;
    vector<bool> lock(N+1, false); // lock[i] i代表书架编号i 值表示是否书架上锁 book 
    vector<int> book(M+1, 0);      // book[i] i代表书编号i 值为0表示表示书在小美手上 值为-1表示在小团手上 值为1-N编号表示书在1-N行
    for (int i = 0; i < Q; i++) {
        int temp, y;
        cin >> instr >> temp;
        switch (instr) {
            case 1: {
                cin >> y; // temp 书 y 书架
                if(!lock[y] && book[temp]>=0  && !lock[book[temp]]) {
                    book[temp] = y;
                }
                break;
            }
            case 2:
            case 3: {
                lock[temp] = instr == 2;
                break;
            }
            case 4: {
                if(book[temp] > 0 && !lock[book[temp]]) {
                    cout << book[temp] << endl;
                    book[temp] = -1;
                }
                else
                    cout << -1 << endl;
                break;
            }
            case 5: {
                if(book[temp] == -1)
                    book[temp] = 0;
                break;
            }
        }
    }
    return 0;
}


/* 输入：
- 第一行三个正整数 M，N，Q，表示小美书架有 N 行编号 1 到 N ，书本编号从 1 到 M ，接下来有 Q 个操作
- 接下来 Q 行，每行是下列操作中的一种：
  1. x y : x 是书本的编号，y 是书架的行编号，代表小美将编号为 x 的书本放置到 y 行上。
           若该书本在小团手上则放置无效，若原来该书在书架上且原行上锁则放置无效，若该书被放置到一个锁了的行上则放置无效。
  2. y : y 是书架的行编号，代表小美将行编号为 y 的书架加锁，对已经上锁的书架行该操作无效。
  3. y : y 是书架的行编号，代表小美将行编号为 y 的书架锁去掉，对无锁的书架行该操作无效。
  4. x : x 是书本的编号，代表小团想借编号为 x 的书本，对该操作若可以借到输出一行正整数在哪一行，借不到输出一行 -1
  5. x : x 是书本的编号，代表小团还回来编号为 x 的书本。若该书本不在小团手上该操作无效。
输出：
- 对于每个操作 4 ，若可以借到输出一行正整数在哪一行，借不到输出一行 -1 。

输入：
5 5 10
1 1 4
1 2 3
1 3 1
2 1
4 1
5 2
4 3
4 5
3 1
4 2
输出：
4
-1
-1
3
 */