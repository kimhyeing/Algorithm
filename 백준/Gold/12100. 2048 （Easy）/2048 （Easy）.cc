#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int left(vector<vector<int> >& v) {
    int empty_pos, v_pos, max_value = 0;
    for(int i=0;i<n;i++) {
        empty_pos = v_pos = -1;
        for(int j=0;j<n;j++) {
            if(empty_pos == -1 && v[i][j] == 0) empty_pos = j;
            else if(v[i][j] > 0) {
                if(v_pos != -1) {
                    if(v[i][j] == v[i][v_pos]) { // 합치기
                        v[i][v_pos] += v[i][j];
                        v[i][j] = 0;
                        if(empty_pos == -1) empty_pos = v_pos+1;
                        max_value = max(max_value, v[i][v_pos]);
                        v_pos = -1;
                        continue;
                    }
                }
                if(empty_pos != -1) {
                    swap(v[i][empty_pos], v[i][j]);
                    v_pos = empty_pos;
                    empty_pos++;
                }
                else {
                    v_pos = j;
                }
                max_value = max(max_value, v[i][v_pos]);
            }
        }
    }
    return max_value;
}
int right(vector<vector<int> >& v) {
    int empty_pos, v_pos, max_value = 0;
    for(int i=0;i<n;i++) {
        empty_pos = v_pos = -1;
        for(int j=n-1;j>=0;j--) {
            if(empty_pos == -1 && v[i][j] == 0) empty_pos = j;
            else if(v[i][j] > 0) {
                if(v_pos != -1) {
                    if(v[i][j] == v[i][v_pos]) { // 합치기
                        v[i][v_pos] += v[i][j];
                        v[i][j] = 0;
                        if(empty_pos == -1) empty_pos = v_pos-1;
                        max_value = max(max_value, v[i][v_pos]);
                        v_pos = -1;
                        continue;
                    }
                }
                if(empty_pos != -1) {
                    swap(v[i][empty_pos], v[i][j]);
                    v_pos = empty_pos;
                    empty_pos--;
                }
                else {
                    v_pos = j;
                }
                max_value = max(max_value, v[i][v_pos]);
            }
        }
    }
    return max_value;
}

int down(vector<vector<int> >& v) {
    int empty_pos, v_pos, max_value = 0;
    for(int j=0;j<n;j++) {
        empty_pos = v_pos = -1;
        for(int i=n-1;i>=0;i--) {
            if(empty_pos == -1 && v[i][j] == 0) empty_pos = i;
            else if(v[i][j] > 0) {
                if(v_pos != -1) {
                    if(v[i][j] == v[v_pos][j]) { // 합치기
                        v[v_pos][j] += v[i][j];
                        v[i][j] = 0;
                        if(empty_pos == -1) empty_pos = v_pos-1;
                        max_value = max(max_value, v[v_pos][j]);
                        v_pos = -1;
                        continue;
                    }
                }
                if(empty_pos != -1) {
                    swap(v[empty_pos][j], v[i][j]);
                    v_pos = empty_pos;
                    empty_pos--;
                }
                else {
                    v_pos = i;
                }
                max_value = max(max_value, v[v_pos][j]);
            }
        }
    }
    return max_value;
}

int up(vector<vector<int> >& v) {
    int empty_pos, v_pos, max_value = 0;
    for(int j=0;j<n;j++) {
        empty_pos = v_pos = -1;
        for(int i=0;i<n;i++) {
            if(empty_pos == -1 && v[i][j] == 0) empty_pos = i;
            else if(v[i][j] > 0) {
                if(v_pos != -1) {
                    if(v[i][j] == v[v_pos][j]) { // 합치기
                        v[v_pos][j] += v[i][j];
                        v[i][j] = 0;
                        if(empty_pos == -1) empty_pos = v_pos+1;
                        max_value = max(max_value, v[v_pos][j]);
                        v_pos = -1;
                        continue;
                    }
                }
                if(empty_pos != -1) {
                    swap(v[empty_pos][j], v[i][j]);
                    v_pos = empty_pos;
                    empty_pos++;
                }
                else {
                    v_pos = i;
                }
                max_value = max(max_value, v[v_pos][j]);
            }
        }
    }
    return max_value;
}

int result = 0;
void solve(vector<vector<int> > v, int c) {
    if(c == 5) return;
    vector<vector<int> >temp_v;
    temp_v = v;
    result = max(result, down(temp_v));
    solve(temp_v, c+1);
    temp_v = v;
    result = max(result, right(temp_v));
    solve(temp_v, c+1);
    temp_v = v;
    result = max(result, up(temp_v));
    solve(temp_v, c+1);
    temp_v = v;
    result = max(result, left(temp_v));
    solve(temp_v, c+1);
}

int main() {
    cin>>n;
    vector<vector<int> > v(n, vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>v[i][j];
        }
    }
    solve(v, 0);
    cout<<result;

    return 0;
}