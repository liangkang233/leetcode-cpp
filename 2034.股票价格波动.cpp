/*
 * @lc app=leetcode.cn id=2034 lang=cpp
 *
 * [2034] 股票价格波动
 */

#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

// 用无序map 和优先队列来做 稍微省时间 空间占用小了很多
// @lc code=start
typedef pair<int,int> pii;

class StockPrice {
public:
    StockPrice() {
        this->maxTimestamp = 0;
    }
    
    void update(int timestamp, int price) {
        maxTimestamp = max(maxTimestamp, timestamp);
        timePriceMap[timestamp] = price;
        pqMax.emplace(price, timestamp);
        pqMin.emplace(price, timestamp);
    }
    
    int current() {
        return timePriceMap[maxTimestamp];
    }
    
    int maximum() {
        while (true) {
            int price = pqMax.top().first, timestamp = pqMax.top().second;
            if (timePriceMap[timestamp] == price) {
                return price;
            }
            pqMax.pop();
        }
    }
    
    int minimum() {
        while (true) {
            int price = pqMin.top().first, timestamp = pqMin.top().second;
            if (timePriceMap[timestamp] == price) {
                return price;
            }
            pqMin.pop();
        }
    }
private:
    int maxTimestamp;
    unordered_map<int, int> timePriceMap;
    priority_queue<pii, vector<pii>, less<pii>> pqMax;
    priority_queue<pii, vector<pii>, greater<pii>> pqMin;
};
/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// @lc code=end

// ["StockPrice","update","update","current","maximum","update","maximum","update","minimum","update","update","update","update","update","maximum"]\n[[],[1,10],[2,5],[],[],[1,3],[],[4,2],[],[3,123],[3,1],[4,5],[4,56],[4,12],[]]\n

// 空间大 时间慢 不推荐
class StockPrice {
public:
    // set multiset map底层由红黑树构建 是有序的 multi前缀可使元素重复
    // 切记 C++ multiset按value的erase会删除所有相同的元素
    multiset<int> prices;
    map<int, int> stockmap;
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        if(stockmap.find(timestamp) != stockmap.end()) {
            // prices.erase(stockmap[timestamp]);
            prices.erase(prices.find(stockmap[timestamp]));
            stockmap[timestamp] = price;
            prices.insert(price);
        }
        else {
            stockmap.insert(make_pair(timestamp, price));
            prices.insert(price);
        }
        cout << stockmap.rbegin()->second << endl;
    }
    
    int current() {
        return stockmap.rbegin()->second;
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
};
