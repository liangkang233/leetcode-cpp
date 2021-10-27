#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// #include <cstdio>

using namespace std;

int main () {
    int tian = 365, temp;
    string run;
    cin >> run;
    if(run == "true")
        tian = 366;
    
    vector<int> que, time;
    char temp_char;
    do {
        // cin >> temp >> temp_char;
        scanf("%d%c", &temp, &temp_char);
        que.push_back(temp);
    }
    while (temp_char != '\n');
    sort(que.begin(),que.end());

    if(que.size()==1 && que[0]==0) {
        time.push_back(tian);
    }
    else {
        int last = 1;
        for (int i = 0; i < que.size(); i++) {
            time.push_back(que[i]-last);
            // cout << " test1   "<< que[i]-last << endl;
            last = que[i] + 1;
        }
        // cout << " test1   "<< tian - last + 1<< endl;
        time.push_back(tian - last + 1);
    }
    
    int count = 0;
    for (int i = 0; i < time.size(); i++) {
        count += time[i] / 30 * 100;
        // cout << " test1   "<< time[i] / 30 * 100 << endl;
        count += time[i] / 7 * 20;
        // cout << " test2   "<< time[i] / 7 * 20 << endl;

        if (time[i] > 2) {
            count += (time[i] - 2) * 8;
            // cout << "8fen " << time[i] - 2 << endl;
            count += 6;
        }
        else if (time[i] == 2) {
            count += 6;
        }
        else if (time[i] == 1) {
            count += 2;
        }
    }
    


    cout << count;
    
    return 0;
}