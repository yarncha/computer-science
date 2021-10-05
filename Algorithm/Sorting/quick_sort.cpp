#include <iostream>

void QuickSort(int * input_array, int start, int end) {
	// input_array에서 start부터 end까지 정렬해주는 코드

	if (start >= end) {
		// 원소가 1개이거나 엇갈릴 때는 그냥 리턴
		return;
	}

	int pivot = start;
	int find_big = start + 1;
	int find_small = end;

	while (true)
	{
		while (find_big <= end && input_array[find_big] < input_array[pivot])
		{
			// input_array[pivot]보다 큰 원소를 왼쪽에서 오른쪽으로 이동하며 찾는다
			find_big++;
		}

		while (find_small > start && input_array[find_small] > input_array[pivot])
		{
			// input_array[pivot]보다 작은 원소를 오른쪽에서 왼쪽으로 이동하며 찾는다
			find_small--;
		}

		if (find_big < find_small) {
			// find_big과 find_small이 엇갈리지 않았을 경우에는 각자 원하는 것을 찾은 것이므로 둘이 바꿈
			int temp = input_array[find_big];
			input_array[find_big] = input_array[find_small];
			input_array[find_small] = temp;
		}
		else {
			// 둘이 엇갈렸을 경우에는 반복문 나와서 pivot이랑 find_small 바꿔주기
			break;
		}
	}

	// pivot과 find_small바꿔줌
	int temp = input_array[pivot];
	input_array[pivot] = input_array[find_small];
	input_array[find_small] = temp;


	// 현재 pivot 위치 기준으로 양쪽에 대해 재귀적으로 퀵정렬 수행
	QuickSort(input_array, start, find_small - 1);
	QuickSort(input_array, find_small + 1, end);
}

int main(void) {
	int input[9] = { 2,1,6,33,28,18,9,46,4 };
	QuickSort(input,0,8);
	return 0;
}