#include <iostream>

using namespace std;

int number = 15;

// 하나의 노드 정보를 선언
typedef struct node *treePointer;
typedef struct node{
	int data;
	treePointer leftChild, rightChild;
}node;

// 전위 순회
void preorder(treePointer ptr) {
	if (ptr) { // 해당 포인터가 값을 가지고 있는 경우
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

// 중위 순회
void inorder(treePointer ptr) {
	if (ptr) { // 해당 포인터가 값을 가지고 있는 경우
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

// 후위 순회
void postorder(treePointer ptr) {
	if (ptr) { // 해당 포인터가 값을 가지고 있는 경우
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main(void) {
	node nodes[16];
	for (int i = 1; i <= number; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}

	for (int i = 1; i <= number; i++) {
		if (i % 2 == 0) { // 짝수
			nodes[i / 2].leftChild = &nodes[i];
		}
		else // 홀수
			nodes[i / 2].rightChild = &nodes[i];
	}
	preorder(&nodes[1]);
	cout << "\n";

	inorder(&nodes[1]);
	cout << "\n";


	postorder(&nodes[1]);
	cout << "\n";
	return 0;
}