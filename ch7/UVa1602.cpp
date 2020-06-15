//UVa1602.cpp


#include <set>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Ceil {
	int x, y;
	Ceil(int x, int y): x(x), y(y) { }
	bool operator<(const Ceil &rhs) const {
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}
};
typedef set<Ceil> Polyomino;
const int maxn = 10;
int ans[maxn + 1][maxn + 1][maxn + 1];

//#define FOR_CELL(c, p) for(Polyomino::const_iterator c = (p).begin(); c != (p).end(); ++c)

inline
Polyomino normalize(const Polyomino &p) {
	int min_x = p.begin()->x, min_y = p.begin()->y;
	for(auto it = p.begin(); it != p.end(); ++it) {
		min_x = min(min_x, it->x);
		min_y = min(min_y, it->y); 
	}
	Polyomino ret;
	for(auto it = p.begin(); it != p.end(); ++it) {
		ret.insert(Ceil(it->x - min_x, it->y - min_y));
	}
	return ret;
}


inline
Polyomino rotate(const Polyomino &p) {
	Polyomino p2;
	for(auto it = p.begin(); it != p.end(); ++it) {
		p2.insert(Ceil(it->y, -it->x));
	}
	return normalize(p2);
}

inline
Polyomino flip(const Polyomino &p) {
	Polyomino p2;
	for(auto it = p.begin(); it != p.end(); ++it) {
		p2.insert(Ceil(it->x, -it->y));
	}
	return normalize(p2);
}


int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
set<Polyomino> poly[maxn + 1];
void check_poloymino(const Polyomino &p0, const Ceil &c) {
	Polyomino p = p0;
	p.insert(c);
	p = normalize(p);

	int n = p.size();
	for(int i = 0; i < 4; ++i) {
		if(poly[n].count(p) != 0) return;
    	p = rotate(p);
	}

	p = flip(p);

	for(int i = 0; i < 4; ++i) {
		if(poly[n].count(p) != 0) return ;
		p = rotate(p);
	}

	poly[n].insert(p);
}

void generate() {
	Polyomino p1;
	p1.insert(Ceil(0, 0));
	poly[1].insert(p1);


	for(int i = 2; i <= maxn; ++i) {
		for(auto it1 = poly[i - 1].begin(); it1 != poly[i - 1].end(); ++it1) {
			for(auto it2 = it1->begin(); it2 != it1->end(); ++it2) {
				for(int j = 0; j < 4; ++j) {
					Ceil t(it2->x + dx[j], it2->y + dy[j]);
					if(it1->count(t) == 0) {
						check_poloymino(*it1, t);
					}
				}
			}
		}
	}


	for(int n = 1; n <= maxn; ++n) {
		for(int w = 1; w <= maxn; ++w) {
			for(int h = 1; h <= maxn; ++h) {
				int cnt = 0;
				for(auto p = poly[n].begin(); p != poly[n].end(); ++p) {
					int max_x = 0, max_y = 0;
					for(auto it = p->begin(); it != p->end(); ++it) {
						max_x = max(max_x, it->x);
						max_y = max(max_y, it->y);
					}
					if(min(max_x, max_y) < min(h, w) && max(max_x, max_y) < max(h, w)) {
						++cnt;
					}
				}
				ans[n][h][w] = cnt;
			}
		}
	}

}

int main() {
	generate();
	int n, w, h;
	while(scanf("%d %d %d", &n, &w, &h) != EOF) {
		printf("%d\n", ans[n][w][h]);
	}
	return 0;
}