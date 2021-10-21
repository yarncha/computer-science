#include <iostream>
using namespace std;

class Node {		// 연결 리스트를 구성할 노드 클래스
public:
	int value;		// 노드의 값
	Node* next;		// 다음 노드의 주소

	Node(int new_value) {
		value = new_value;
		next = NULL;
	}
};

class SingleLinkedList {
public:
	SingleLinkedList(int init_value) {
		// 생성자 (init_value을 가진 노드를 head로 생성해줌)
		head = tail = new Node(init_value);
		size = 1;
	};

	SingleLinkedList(int init_value, Node* next_node) {
		// 생성자 (init_value을 가진 노드를 head로 생성해주고, 다음 노드도 설정해 줌)
		head = new Node(init_value);
		head->next = next_node;
		tail = next_node;
		size = 2;
	}

	~SingleLinkedList() {
		// 소멸자
		Node* current_node = head;
		while (current_node->next != NULL)
		{
			Node* to_delete = current_node;
			current_node = current_node->next;
			delete to_delete;
		}
		delete current_node;
	};

	void InsertNode(int new_value, int to_insert) {
		// 원하는 위치(head에서 to_insert만큼 떨어진 위치)에 노드를 삽입하는 함수
		if (to_insert == 0) {
			InsertNodeToFront(new_value);
		}
		else if (to_insert == size) {
			InsertNodeToBack(new_value);
		}
		else {
			Node* prev_node = head;
			Node* current_node = head;
			for (int i = 0; i < to_insert; i++)
			{
				prev_node = current_node;
				current_node = current_node->next;
			}

			Node* new_node = new Node(new_value);
			new_node->next = current_node;
			prev_node->next = new_node;
			size++;
		}
		return;
	}

	void InsertNodeToFront(int new_value) {
		// 링크드리스트의 head에 노드를 삽입하는 함수
		Node* new_node = new Node(new_value);
		new_node->next = head;
		head = new_node;
		size++;
	}

	void InsertNodeToBack(int new_value) {
		// 링크드리스트의 tail에 노드를 삽입하는 함수
		Node* new_node = new Node(new_value);
		tail->next = new_node;
		tail = new_node;
		size++;
	}

	void DeleteNode(int to_delete) {
		// 원하는 위치에 있는 노드를 삭제하는 함수
		if (to_delete == 0) {
			DeleteNodeFromFront();
			return;
		}
		if (to_delete == size - 1) {
			DeleteNodeFromBack();
			return;
		}

		Node* prev_node = head;
		Node* current_node = head;
		for (int i = 0; i < to_delete; i++)
		{
			prev_node = current_node;
			current_node = current_node->next;
		}
		prev_node->next = current_node->next;
		delete current_node;
		size--;
	}

	void DeleteNodeFromFront() {
		// 링크드리스트의 head에 있는 노드를 삭제하는 함수
		Node* current_node = head;
		head = current_node->next;
		delete current_node;
		size--;
	}

	void DeleteNodeFromBack() {
		// 링크드리스트의 tail에 있는 노드를 삭제하는 함수
		Node* prev_node = head;
		Node* current_node = head;
		while (current_node->next != NULL)
		{
			prev_node = current_node;
			current_node = current_node->next;
		}

		prev_node->next = NULL;
		tail = prev_node;
		delete current_node;
		size--;
	}

	int FindNode(int value_to_find) {
		// value_to_find을 가지고 있는 노드중 가장 앞에 있는 노드를 찾아서 그 노드의 인덱스 반환, 없을 경우 -1리턴
		int index = 0;
		Node* current_node = head;
		while (current_node->next != NULL) {
			if (current_node->value == value_to_find) {
				return index;
			}
			current_node = current_node->next;
			index++;
		}

		if (current_node->value == value_to_find) {
			return index;
		}
		return -1;
	}

	void PrintList() {
		// 리스트의 노드를 출력해줌
		Node* current_node = head;
		while (current_node->next != NULL)
		{
			cout << current_node->value << " -> ";
			current_node = current_node->next;
		}
		cout << current_node->value << "\n";
	}

	int GetSize() {
		// 리스트의 사이즈를 리턴
		return size;
	}

private:
	Node* head;
	Node* tail;
	int size;

};

int main(void) {
	SingleLinkedList* list = new SingleLinkedList(1);
	for (int i = 2; i <= 5; i++)
	{
		list->InsertNodeToBack(i);
	}
	list->PrintList();
	cout << list->GetSize() << "\n";
	list->DeleteNode(2);
	list->PrintList();
	cout << list->GetSize() << "\n";

	return 0;
}