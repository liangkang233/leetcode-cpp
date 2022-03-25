// https://mp.weixin.qq.com/s?__biz=MzUyMTY4MTk2OA==&mid=2247534006&idx=4&sn=d8f729032ad9a092195559f2c7ec2e81&chksm=f9d568e9cea2e1ff8b75dc5a0dd9e92bbf09278b59f0fff230448a6f28b1decc672826e7836f&mpshare=1&scene=23&srcid=0408opPxKvrQ4m8E6GiP2zyd&sharer_sharetime=1617875186889&sharer_shareid=b1b06917bfd8bbf227ba3eb69539816a#rd


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string filename = "test.txt";

// 法1：线性缩小
bool solve1(vector<vector<int>> &matrix, ofstream &cout, int x) {
    int i, j;
    i = 0;
    j = matrix[0].size() - 1;
    bool flag = false;
    while (i < matrix[0].size() && j >= 0) {
        if (matrix[i][j] > x) {
            --j;
        } else if (matrix[i][j] < x) {
            ++i;
        } else {
            return true;
        }
    }
    return false;
}

// 固定行二分，缩小列
int searchColumn(vector<vector<int>> &matrix, int up, int right, int x) {
    int i, j, mid;
    i = 0;
    j = right;
    while (i < j) {
        mid = (i + j) / 2;
        if (x < matrix[up][mid]) {
            j = mid - 1;
        } else if (x > matrix[up][mid]) {
            i = mid + 1;
        } else {
            i = j = mid;
        }
    }
    if (matrix[up][i] > x) --i; //判断下次二分是否在该列查找
    return i;
}
// 固定列二分，缩小行
int searchRow(vector<vector<int>> &matrix, int up, int right, int x) {
    int i, j, mid;
    i = up;
    j = matrix.size() - 1;
    while (i < j) {
        mid = (i + j) / 2;
        if (x < matrix[mid][right]) {
            j = mid - 1;
        } else if (x > matrix[mid][right]) {
            i = mid + 1;
        } else {
            i = j = mid;
        }
    }
    if (matrix[i][right] < x) ++i;  //判断下次二分是否在该行查找
    return i;
}
// 法2：二分推荐
bool solve2(ifstream &fin, int x) {
    vector<vector<int>> matrix;
    for (int i = 0,a,b,c; fin >> a >> b >> c; i++)
        matrix.push_back(vector<int>{a, b, c});
    fin.close();
    
    int up = 0, right = matrix[0].size() - 1;
    // while (up != matrix.size() || right >= 0) {
    while (1) {
        right = searchColumn(matrix, up, right, x);
        if (right < 0) 
            break;

        up = searchRow(matrix, up, right, x);
        if (up == matrix.size())
            break;

        if (matrix[up][right] == x)
            return true;
    }
    return false;
}

// 数据生成
void dataInit() {
    ofstream out(filename);
    int s = 0;
    // 5000 * 5000 太大了 生成的文本有200+mb
    for (int i = 0; i < 500; ++i) {
        for (int j = 0; j < 500; ++j) {
            out << s + i + j << " ";
        }
        s += 4999;
        out << endl;
    }
    out.close();
}

int main()
{
    dataInit();
    ifstream fin(filename);
    solve2(fin, 243);
    return 0;
}
