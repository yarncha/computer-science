#include <iostream>
using namespace std;

int main(void) {
	// 크기가 10인 Array 선언 및 초기화
	int array_size = 9;		// 배열에 들어간 원소의 개수, 원소를 9개 넣을 것
	int my_array[10] = { 0,1,2,3,4,5,6,7,8, };		// 현재 [0,1,2,3,4,5,6,7,8,0]과 같이 들어있다

	// 삽입 : index가 3인 곳에 원소 999를 넣을 때
	int to_insert = 3;
	int to_insert_value = 999;
	for (int i = array_size; i > to_insert; i--)
	{
		my_array[i] = my_array[i - 1];
	}
	my_array[to_insert] = to_insert_value;
	array_size++;

	// 삭제 : index가 5인 원소를 삭제할 때
	int to_delete = 5;
	for (int j = to_delete; j < array_size - 1; j++)
	{
		my_array[j] = my_array[j + 1];
	}
	my_array[array_size] = 0;
	array_size--;

	// 탐색 : index가 8인 원소를 출력할 때
	cout << my_array[8];		// 8번째에 있는 값인 "7" 출력

	return 0;
}