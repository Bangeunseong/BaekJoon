//N과 M - 1
/*#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
void BackTracking(int *x, int *result, int n, int m, int depth) {
	if (depth == m) { 
		for (int i = 0; i < m; i++) printf("%d ", result[i]);
		printf("\n"); return;
	}

	for (int i = 0; i < n; i++) {
		if (x[i] == 0) { result[depth] = i + 1; x[i] = 1; BackTracking(x, result, n, m, depth + 1); x[i] = 0; }
	}
}
int main() {
	int n, m; scanf("%d%d", &n, &m);
	int *x = (int *)malloc(sizeof(int)*n); for (int i = 0; i < n; i++) x[i] = 0;
	int *result = (int *)malloc(sizeof(int)*n);
	BackTracking(x, result, n, m, 0);
}*/
//N과 M - 2
/*#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
void BackTracking(int *x, int *result, int n, int m, int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) printf("%d ", result[i]);
		printf("\n"); return;
	}

	for (int i = 0; i < n; i++) {
		if (x[i] == 0) {
			if (result[depth - 1] < i + 1) {
				result[depth] = i + 1; x[i] = 1; BackTracking(x, result, n, m, depth + 1); x[i] = 0;
			}
		}
	}
}
int main() {
	int n, m; scanf("%d%d", &n, &m);
	int *x = (int *)malloc(sizeof(int)*n); for (int i = 0; i < n; i++) x[i] = 0;
	int *result = (int *)malloc(sizeof(int)*n);
	BackTracking(x, result, n, m, 0);
}*/
//N과 M - 3
/*#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
void BackTracking(int *result, int n, int m, int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) printf("%d ", result[i]);
		printf("\n"); return;
	}

	for (int i = 0; i < n; i++) {
		result[depth] = i + 1; BackTracking(result, n, m, depth + 1);
	}
}
int main() {
	int n, m; scanf("%d%d", &n, &m);
	int *result = (int *)malloc(sizeof(int)*n);
	BackTracking(result, n, m, 0);
}*/
//N-Queens Game
/*#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct Queen {
	int x, y;
}Queen;
int Checkthereisotherqueen(Queen *Q, int depth, int x, int y) {
	for (int i = 0; i < depth; i++) {
		if (Q[i].x == x || Q[i].y == y) { if (Q[i].x == x && Q[i].y == y) break; else return 1; }
		if (abs(Q[i].x - x) == abs(Q[i].y - y)) return 1;
	}
	return 0;
}
void N_QueensGame(Queen *Q, int n, int depth, int *cnt) {
	if (depth == n) { (*cnt)++; return; }
	for (int i = 0; i < n; i++) {
		if (!Checkthereisotherqueen(Q, depth, i, depth)) { Q[depth].x = i; Q[depth].y = depth; N_QueensGame(Q, n, depth + 1, cnt); }
	}
}
int main() {
	int n; scanf("%d", &n);
	Queen *Q = (Queen *)malloc(sizeof(Queen)*n);

	int cnt = 0;
	N_QueensGame(Q, n, 0, &cnt);
	printf("%d", cnt);
}*/
//스도쿠
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
void FillupSudokuBoard(int **SudokuBoard, int depth) {
	if (depth >= 81) return;

	int x = depth % 9, y = depth / 9; int Q[9] = { 0, };
	if (!SudokuBoard[y][x]) FillupSudokuBoard(SudokuBoard, depth + 1);
	else {
		for (int i = 0; i < 9; i++) {
			if (!SudokuBoard[y][i]) Q[SudokuBoard[y][i] - 1] = 1;
			if (!SudokuBoard[i][x]) Q[SudokuBoard[i][x] - 1] = 1;
		}
		for (int i = y / 3 * 3; i < y / 3 * 3 + 3; i++) {
			for (int j = x / 3 * 3; j < x / 3 * 3 + 3; j++) if (!SudokuBoard[i][j]) Q[SudokuBoard[i][j] - 1] = 1;
		}
		for (int i = 0; i < 9; i++) {
			printf(" %d", Q[i]);
			if (!Q[i]) { SudokuBoard[y][x] = i + 1; FillupSudokuBoard(SudokuBoard, depth + 1); }
		}
	}
}
int main() {
	int **SudokuBoard = (int **)malloc(sizeof(int*) * 9);
	for (int i = 0; i < 9; i++) SudokuBoard[i] = (int *)malloc(sizeof(int) * 9);
	for (int i = 0; i < 9; i++) { for (int j = 0; j < 9; j++) scanf("%d", &SudokuBoard[i][j]); }
	FillupSudokuBoard(SudokuBoard, 0);
	for (int i = 0; i < 9; i++) { for (int j = 0; j < 9; j++) printf("%d ", SudokuBoard[i][j]); printf("\n"); }
}