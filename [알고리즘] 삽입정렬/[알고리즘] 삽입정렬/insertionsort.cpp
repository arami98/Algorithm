#include <stdio.h>
// 삽입 정렬: 각 숫자를 적절한 위치에 삽입하는 방법
// 거의 정렬되어 있을 때 유리함

int main(void) {
	int i, j, temp;
	int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	for (int i = 0; i < 9; i++) {
		j = i;
		while (array[j] > array[j + 1]) {
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--;
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}