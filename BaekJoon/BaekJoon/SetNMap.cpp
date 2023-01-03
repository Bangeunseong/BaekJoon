//숫자 카드
/*#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int H[500001]; int n = 0;
void upHeap(int last) {
	if (last == 1) return;
	if (H[last] >= H[last / 2]) return;
	int tmp = H[last]; H[last] = H[last / 2]; H[last / 2] = tmp;
	upHeap(last / 2);
}
void insertItem(int key) {
	if (n >= 500000) return;
	H[++n] = key;
	upHeap(n);
}
void downHeap(int root) {
	if (n == 1) return;
	if (root >= n) return;
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
int binarySearch(int *x, int start, int end, int key) {
	if (start > end) return 0;

	if (x[(start + end) / 2] == key) return 1;
	else if (x[(start + end) / 2] < key) return binarySearch(x, (start + end) / 2 + 1, end, key);
	else return binarySearch(x, start, (start + end) / 2 - 1, key);
}
int main() {
	int N; scanf("%d", &N);
	int *x = (int *)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++) { int key; scanf("%d", &key); insertItem(key); }
	for (int i = 0; i < N; i++) x[i] = removeMin();

	int M; scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int key; scanf("%d", &key);
		printf("%d ", binarySearch(x, 0, N, key));
	}
}*/
//문자열 집합---(시간초과)---트리를 이용하면 더 빠르게 searchelement 가능
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define TABLESIZE 10001

unsigned long getNextBucket(const char *str) {
	unsigned long hash = 5381;
	int c; int len = strlen(str);
	for (int i = 0; i < len; i++) {
		c = str[i]; hash = (((hash << 5) + hash) + c) % TABLESIZE;
	}
	return hash % TABLESIZE;
}
void InsertItem(char **Bucket, char *key) {
	int i = 0;
	int b = getNextBucket(key);
	while ((b + i) % TABLESIZE != b - 1) {
		if (Bucket[(b + i) % TABLESIZE] == NULL) { Bucket[(b + i) % TABLESIZE] = (char *)malloc(sizeof(char)*strlen(key) + 1); strcpy(Bucket[(b + i) % TABLESIZE], key); return; }
		else i++;
	}
}
int findElement(char **Bucket, char *key) {
	int i = 0;
	int b = getNextBucket(key);
	while ((b + i) % TABLESIZE != b - 1) {
		if (Bucket[(b + i) % TABLESIZE] == NULL) return 0;
		else if (strcmp(Bucket[(b + i) % TABLESIZE], key) == 0) return 1;
		else i++;
	}
	return 0;
}
int main() {
	int n, m; scanf("%d%d", &n, &m);
	char **Bucket = (char **)malloc(sizeof(char *)*(TABLESIZE));
	for (int i = 0; i < TABLESIZE; i++) Bucket[i] = NULL;

	char str[501]; int cnt = 0;
	for (int i = 0; i < n; i++) { scanf("%s", str); InsertItem(Bucket, str); }
	for (int i = 0; i < m; i++) { scanf("%s", str); cnt += findElement(Bucket, str); }
	printf("%d", cnt);
}*/
//포켓몬 도감
