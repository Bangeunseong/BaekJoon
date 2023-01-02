//∫Ì∑¢¿Ë
/*#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int GetClosestNumber(int *x, int size, int M) {
	int max = 0;
	for (int i = 0; i < size - 2; i++) {
		for (int j = i + 1; j < size - 1; j++) {
			for (int k = j + 1; k < size; k++) {
				int n = x[i] + x[j] + x[k];
				if (max < n && n <= M) max = n;
			}
		}
	}
	return max;
}
int main() {
	int N, M; scanf("%d%d", &N, &M);
	int *x = (int *)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++) scanf("%d", x + i);
	printf("%d", GetClosestNumber(x, N, M));
}*/
//∫–«ÿ«’
/*#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int Getnumberlength(int n) {
	if (n == 0) return 0;
	return 1 + Getnumberlength(n / 10);
}
int returnMinBase(int base, int n) {
	int start = base;
	while (start < n) {
		int suffixbase = 0; int w = start;
		while (w != 0) { suffixbase += w % 10; w /= 10; }
		suffixbase += start;
		if (suffixbase == n) return start;
		else start++;
	}
	return 0;
}
int main() {
	int n; scanf("%d", &n);
	if (n < 10) printf("%d", returnMinBase(1, n));
	else printf("%d", returnMinBase(pow(10, Getnumberlength(n) - 1) / 2, n));
}*/
//µ¢ƒ°
/*#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct Student {
	int weight, height;
}Student;
int main() {
	int n; scanf("%d", &n);
	Student *list = (Student *)malloc(sizeof(Student)*n);
	int *Grade = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) scanf("%d%d", &list[i].weight, &list[i].height);
	for (int i = 0; i < n; i++) {
		Grade[i] = 1;
		for (int j = 0; j < n; j++) {
			if (list[i].weight < list[j].weight && list[i].height < list[j].height) Grade[i]++;
		}
	}
	for (int i = 0; i < n; i++) printf("%d ", Grade[i]);
}*/
//√ºΩ∫∆« ¥ŸΩ√ ƒ•«œ±‚
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
typedef struct Pnt {
	int x, y;
}Pnt;
void InitializeReplica_B(char **ChessPlate, char **OriginChessPlate, int sptr_x, int sptr_y) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			ChessPlate[i][j] = OriginChessPlate[sptr_y + i][sptr_x + j];
		}
	}
	ChessPlate[0][0] = 'B';
}
void InitializeReplica_W(char **ChessPlate, char **OriginChessPlate, int sptr_x, int sptr_y) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			ChessPlate[i][j] = OriginChessPlate[sptr_y + i][sptr_x + j];
		}
	}
	ChessPlate[0][0] = 'W';
}
int ReplaceChessPlate(char **ChessPlate, char **OriginChessPlate, int sptr_x, int sptr_y) {
	int f = 0, r = -1; int cnt = 0;
	if (ChessPlate[0][0] != OriginChessPlate[sptr_y][sptr_x]) cnt++;
	Pnt *Queue = (Pnt *)malloc(sizeof(Pnt) * 256);
	++r;
	Queue[r % 256].x = Queue[r % 256].y = 0;
	while (f <= r) {
		Pnt elem = Queue[(f++) % 256];
		if (elem.x + 1 < 8) {
			if (ChessPlate[elem.y][elem.x + 1] == ChessPlate[elem.y][elem.x]) {
				if (ChessPlate[elem.y][elem.x] == 'B') ChessPlate[elem.y][elem.x + 1] = 'W';
				else ChessPlate[elem.y][elem.x + 1] = 'B';
				cnt++;
			}
			++r;
			Queue[r % 256].x = elem.x + 1; Queue[r % 256].y = elem.y;
		}
		if (elem.y + 1 < 8) {
			if (ChessPlate[elem.y + 1][elem.x] == ChessPlate[elem.y][elem.x]) {
				if (ChessPlate[elem.y][elem.x] == 'B') ChessPlate[elem.y + 1][elem.x] = 'W';
				else ChessPlate[elem.y + 1][elem.x] = 'B';
				cnt++;
			}
			++r;
			Queue[r % 256].x = elem.x; Queue[r % 256].y = elem.y + 1;
		}
	}
	free(Queue);
	return cnt;
}
int main() {
	int n, m; scanf("%d %d", &n, &m);
	char **ChessPlate = (char **)malloc(sizeof(char*)*n);
	for (int i = 0; i < n; i++) ChessPlate[i] = (char *)malloc(sizeof(char)*m);
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) scanf("%c", &ChessPlate[i][j]);
	}
	
	char **ChessPlate_R = (char **)malloc(sizeof(char*) * 8);
	for (int i = 0; i < 8; i++) ChessPlate_R[i] = (char *)malloc(sizeof(char) * 8);

	int min = n * m;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			InitializeReplica_B(ChessPlate_R, ChessPlate, j, i);
			int result = ReplaceChessPlate(ChessPlate_R, ChessPlate, j, i);
			if (min > result) min = result;
			InitializeReplica_W(ChessPlate_R, ChessPlate, j, i);
			result = ReplaceChessPlate(ChessPlate_R, ChessPlate, j, i);
			if (min > result) min = result;
		}
	}
	printf("%d", min);
}*/
//øµ»≠∞®µ∂ ºÚ
/*#include <stdio.h>
#pragma warning(disable:4996)
int HaveB_Number(int B_num) {
	int w = B_num; int h = 0;
	while (w != 0) {
		if (w % 10 == 6) { h = h * 10 + w % 10; if (h == 666) return 1; }
		else h = 0;
		w /= 10;
	}
	return 0;
}
int GetnthNumber(int n) {
	int base = 666;
	for (int i = 0; i < n; i++) {
		while (!HaveB_Number(++base));
	}
	return base;
}
int main() {
	int n; scanf("%d", &n);
	printf("%d", GetnthNumber(n - 1));
}*/