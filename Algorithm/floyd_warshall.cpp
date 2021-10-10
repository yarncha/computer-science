#include <iostream>
#include <vector>
#define INF 99999
using namespace std;

void FloydWarshall() {
	// 플로이드 워셜 알고리즘

	// 1. 다음과 같이 초기 거리가 주어져 있음
	// distance_of_points : i번째 점에서 j번째 점으로 갈 때의 거리
	int distance_of_points[5][5] = {
		{0, INF, 1, INF, 5},
		{3, 0, 9, 2, INF},
		{4, 4, 0, INF, INF},
		{INF, 8, 6, 0, INF},
		{INF, INF, INF, 2, 0}
	};

	// 2. 각 점을 거쳐 가는 거리를 계산해서 distance_of_points업데이트
	int num_of_points = 5;
	for (int point = 0; point < num_of_points; point++) {
		for (int i = 0; i < num_of_points; i++) {
			for (int j = 0; j < num_of_points; j++) {
				if (distance_of_points[i][j] > distance_of_points[i][point] + distance_of_points[point][j]) {
					distance_of_points[i][j] = distance_of_points[i][point] + distance_of_points[point][j];
				}
			}
		}
	}
}

int main(void) {
	FloydWarshall();
	return 0;
}