#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

const long long INF = 1e16;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector< vector<int> > d(n + 1), dl(n + 1);
    for(int i = 0; i < m; ++i){
        int a, b, dln;
        scanf("%d %d %d", &a, &b, &dln);
        if (a != b){
            d[a].push_back(b);
            d[b].push_back(a);
            dl[a].push_back(dln);
            dl[b].push_back(dln);
        }
    }
    vector<long long>  point(n + 1, INF), p(n + 1, -1);
	point[1] = 0;
	priority_queue < pair<int,int> > q;
	q.push (make_pair (0, 1));
	while (!q.empty()){
		int v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > point[v]){
            continue;
		}
		for (size_t j = 0; j < d[v].size(); ++j) {
			int to = d[v][j], len = dl[v][j];
			if (point[v] + len < point[to]) {
				point[to] = point[v] + len;
				p[to] = v;
				q.push(make_pair (-point[to], to));
			}
		}
	}
	if(point[n] == INF){
        	printf("-1");
        	return 0;
	}
    vector<int> ans;
    for (int v = n; v != 1; v = p[v]){
        ans.push_back(v);
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i){
        printf("%d ", ans[i]);
    }

    return 0;
}
