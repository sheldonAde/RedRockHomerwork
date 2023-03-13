#include <iostream>
#include <cmath>
using namespace std;
int n, mx = 0, my = 0;
double ans;
int map[201][201];
bool b[201][201];

int fx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int fy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
void search(int nx, int ny, int now, double anss) {
	b[nx][ny] = true;
	for (int i = 1; i < 8; i++) {
		int xx = nx + fx[i], yy = ny + fy[i];
		if (b[xx][yy] && xx >= 0 && xx <= mx && yy >= 0 && yy <= my) {
			if (map[xx][yy])
				search(xx, yy, now + 1, anss + 1);
			else
				search(xx, yy, now, anss + 1);
		}
	}
	b[nx][ny] = false;
	if (now == n) {
		ans = min(ans, anss);
		return ;
	}
	return ;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		mx = max(mx, x);
		my = max(my, y);
	}
	search(0, 0, 0, 0);
	return 0;
}