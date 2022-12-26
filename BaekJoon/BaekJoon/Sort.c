//정렬
/*#include <stdio.h>
#pragma warning(disable:4996)
void sort(int *x, int n) { //insertion sort
	for (int i = 1; i < n; i++) {
		int val = x[i];
		int j = i - 1;
		while (j >= 0 && x[j] > val) { x[j + 1] = x[j]; j--; }
		x[j + 1] = val;
	}
}
int main() {
	int n; scanf("%d", &n); int x[1000];
	for (int i = 0; i < n; i++) scanf("%d", &x[i]);
	sort(x, n);
	for (int i = 0; i < n; i++) printf("%d\n", x[i]);
}*/
//대표값2(평균 및 중앙값)
/*#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int SortnReturnavg(int *x, int n) {
	int sum = x[0];
	for (int i = 1; i < n; i++) {
		int val = x[i]; sum += val;
		int j = i - 1;
		while (j >= 0 && x[j] > val) { x[j + 1] = x[j]; j--; }
		x[j + 1] = val;
	}
	return sum / n;
}
int main() {
	int x[5];
	for (int i = 0; i < 5; i++)scanf("%d", &x[i]);
	int avg = SortnReturnavg(x, 5);
	printf("%d\n%d", avg, x[2]);
}*/
//수 정렬하기 2(O(n*logn) 시간에 완수)---합병 정렬 또는 힙 정렬
/*#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int H[1000001] = { 0, }, n = 0;
void upHeap(int last) {
	if (last == 1) return;
	if (H[last] >= H[last / 2]) return;
	int tmp = H[last]; H[last] = H[last / 2]; H[last / 2] = tmp;
	upHeap(last / 2);
}
void insertItem(int key) {
	if (n >= 1000000) return;
	H[++n] = key;
	upHeap(n);
}
void downHeap(int root) {
	if (n == 1) return;
	if(root >= n) return;
	int smaller = root * 2;
	if (smaller > n) return;
	if (2 * root + 1 <= n) {
		if (H[smaller] > H[2 * root + 1]) smaller = 2 * root + 1;
	}
	if (H[root] <= H[smaller]) return;
	int tmp = H[root]; H[root] = H[smaller]; H[smaller] = tmp;
	downHeap(smaller);
}
int removeMin() {
	int key = H[1];
	H[1] = H[n--];
	downHeap(1);
	return key;
}
int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) { int key; scanf("%d", &key); insertItem(key); }
	for (int i = 0; i < N; i++) printf("%d\n", removeMin());
}*/
//수 정렬하기 3(O(n + k) -> 카운팅 정렬)) -> 자세한 내용은 인터넷에 정보가 많음

