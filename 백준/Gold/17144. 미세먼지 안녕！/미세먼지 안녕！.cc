#include "iostream"
#include "algorithm"
#include "stack"

using namespace std;

int R,C,T, upx;
int arr[50][50];
int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, 1, 0, -1};

void input() {
    cin>>R>>C>>T;
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cin>>arr[i][j];
            if(upx == 0 && arr[i][j] == -1) {
                upx = i;
            }
        }
    }
}

void spread() {
    int temp[50][50];
    fill(&temp[0][0],&temp[49][50], 0);

    int newx, newy, st_size, s_value;
    stack<pair<int,int> > st;
    for(int i=0;i<R;i++) {
        for (int j = 0; j < C; j++) {
            for(int d=0;d<4;d++) {
                newx = i+dirx[d];
                newy = j+diry[d];
                if(newx < 0 || newy < 0 || newx >= R || newy >= C) continue;
                if(arr[newx][newy] == -1) continue;
                st.push(make_pair(newx, newy));
            }
            st_size = st.size();
            s_value = arr[i][j]/5;
            arr[i][j] -= (st_size*s_value);
            while(!st.empty()) {
                newx = st.top().first;
                newy = st.top().second;
                st.pop();
                temp[newx][newy] += s_value;
            }
        }
    }

    for(int i=0;i<R;i++) {
        for (int j = 0; j < C; j++) {
            arr[i][j] += temp[i][j];
        }
    }
}

int getD(int d, bool isUp) {
    if(isUp) return (d+1)%4;
    d -= 1;
    if(d<0) d = 3;
    return d;
}

void run(bool isUp) {
    int d = 0;
    if(!isUp) {
        d = 2;
        upx++;
    }
    int curx = upx, cury = 0, newx, newy;
    while(true) {
        if(curx == upx && cury == (C-1)) {
            d = getD(d, isUp);
        }
        newx = curx + dirx[d];
        newy = cury + diry[d];

        if(newx < 0 || newy < 0 || newx >= R || newy >= C) {
            d = getD(d, isUp);
            newx = curx + dirx[d];
            newy = cury + diry[d];
        }
        if(newx == upx && newy == 0) {
            arr[curx][cury] = 0;
            break; // 종료
        }
        if(curx == upx && cury == 0) arr[newx][newy] = 0;
        else {
            arr[curx][cury] = arr[newx][newy];
        }
        curx = newx;
        cury = newy;
    }
}

int getResult() {
    int res = 2;
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            res += arr[i][j];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    while(T--) {
        spread();
        run(true);
        run(false);
        upx--;
    }
    cout<<getResult();
    return 0;
}