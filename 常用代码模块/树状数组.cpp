// t数组为维护的树状数组
// lowbit function :  a & -a
int t[maxn];

void add(int x, int k)
{
    for(; x <= n; x += (x&-x) ) {
        t[x] += k;
    }
}

int ask(int x) 
{
    int ans;
    for (; i > 0; x -= (x&-x)) {
        ans += t[x]; 
    }
    return ans;
}

// 单点修改、单点查询
add(x, k);
ask(x) - ask(x-1);

// 单点修改，区间查询 
add(x, k);
ask(r) - ask(l-1);      // 区间[l,r]内

// 需要两个树状数组维护
// t1[]维护b[i]前缀和,t2[]维护i*b[i]前缀和
int t1[maxn], t2[maxn]];

void add1(int x, int k) {
    for(; x <= n; x += (x&-x) ) {
        t1[x] += k;
    }
}
int ask1(int x) {
    int ans;
    for (; i > 0; x -= (x&-x)) {
        ans += t1[x]; 
    }
    return ans;
}

void add2(int x, int k) {
    for(; x <= n; x += (x&-x) ) {
        t2[x] += k;
    }
}
int ask2(int x) {
    int ans;
    for (; i > 0; x -= (x&-x)) {
        ans += t2[x]; 
    }
    return ans;
}
// 区间修改，区间查询
// 在区间[l, r]修改
add1(l, d);     add1(r+1, -d);
add2(l, l*d);   add2(r+1, -(r+1)*d);

sum[r] - sum[l-1];   //即为下式
(r+1)*ask1[r] - ask2[r] + (l-1+1)*ask1[l-1] - ask2[l-1];