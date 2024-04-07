#include<iostream>
#include<queue>

using namespace std;

int posx[4] = { -1, 0, 0, 1 };
int posy[4] = { 0, -1, 1, 0 };
int visit[20][20];
int arr[20][20];
int n, sx, sy, newx, newy, ssize = 2, eat, res;

struct node {
	int x;
	int y;
	int level;
};

void bfs(node _node) {
	queue<node>q;
	q.push(_node);
	visit[_node.x][_node.y] = true;
	node cur_node, new_node, default_node = node{ 21, 21, -1 };
	node fish_node = default_node;
	int pre_level = 0;
	while (!q.empty()) {
		cur_node = q.front();
		q.pop();
		if (pre_level < cur_node.level) {
			pre_level = cur_node.level;
			if (fish_node.level > 0) {
				cur_node = fish_node;
				eat++;
				if (eat >= ssize) {
					ssize++;
					eat = 0;
				}
				res = fish_node.level;
				arr[fish_node.x][fish_node.y] = 0;

				while (!q.empty()) q.pop();
				fill(&visit[0][0], &visit[n][n], false);
				fish_node = default_node;
			}
		}

		for (int i = 0; i < 4; i++) {
			newx = cur_node.x + posx[i];
			newy = cur_node.y + posy[i];
			if (newx < 0 || newy < 0 || newx >= n || newy >= n || arr[newx][newy] > ssize || visit[newx][newy])
				continue;

			new_node = node{ newx, newy, cur_node.level + 1 };
			if (arr[newx][newy] != 0 && arr[newx][newy] < ssize) {
				if (newx < fish_node.x)
					fish_node = new_node;
				else if (newx == fish_node.x && newy < fish_node.y)
					fish_node = new_node;
			}
			visit[newx][newy] = true;
			q.push(new_node);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				sx = i; sy = j;
				arr[i][j] = 0;
			}
		}
	}
	bfs(node{ sx, sy, 0 });
	cout << res;
	return 0;
}