#include <iostream>
#include <stack>
using namespace std;

class QueueWithStack
{
	// stack 2개로 queue를 구현한 class입니다.
public:
	int FrontOfQueue() {
		// Queue의 앞(front)에 존재하는 원소를 print한다
		if (stack_for_output.empty()) {
			MoveElements();
		}

		return stack_for_output.top();
	}

	int SizeOfQueue() {
		// 큐의 사이즈를 출력한다.
		return stack_for_input.size() + stack_for_output.size();
	}

	bool QueueIsEmpty() {
		// 큐가 비었는지를 확인한다.
		if (stack_for_input.empty() && stack_for_output.empty()) {
			return true;
		}
		return false;
	}

	void PushToQueue(int value) {
		// 큐의 back에 원소를 넣는다.
		stack_for_input.push(value);
	}

	void PopFromQueue() {
		// 큐의 front에서 원소를 삭제한다.
		if (stack_for_output.empty()) {
			MoveElements();
		}

		stack_for_output.pop();
	}

private:
	stack<int> stack_for_input;
	stack<int> stack_for_output;

	void MoveElements() {
		// pop연산을 한다던가 할 때, output 스택이 비어 있으면 input에 있는 원소를 하나씩 꺼내서 pop할 수 있도록 옮겨줌
		while (!stack_for_input.empty())
		{
			stack_for_output.push(stack_for_input.top());
			stack_for_input.pop();
		}
	}
};

int main(void) {
	QueueWithStack test;
	test.PushToQueue(1);
	test.PushToQueue(2);
	test.PushToQueue(3);
	cout << test.FrontOfQueue();
	test.PopFromQueue();
	cout << test.FrontOfQueue();

	return 0;
}