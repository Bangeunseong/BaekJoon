//���簢������ Ż��
/*#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int returnmin(int x, int y) { return x < y ? x : y; }
int main() {
	int x, y, w, h; scanf("%d%d%d%d", &x, &y, &w, &h);
	int min_x = returnmin(x, w - x);
	int min_y = returnmin(y, h - y);
	printf("%d", returnmin(min_x, min_y));
}*/
//�׹�° ��
/*#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct ptr {
	int val, weight;
}ptr;
int main() {
	ptr x[2], y[2]; int nx = 0, ny = 0;
	for (int i = 0; i < 3; i++) {
		int a, b; scanf("%d%d", &a, &b);
		int flag1 = 0, flag2 = 0;
		for (int j = 0; j < nx; j++) if (x[j].val == a) { flag1 = 1; x[j].weight++; break; }
		for (int j = 0; j < ny; j++) if (y[j].val == b) { flag2 = 1; y[j].weight++; break; }
		if (!flag1) { x[nx].val = a; x[nx++].weight = 1; }
		if (!flag2) { y[ny].val = b; y[ny++].weight = 1; }
	}

	int ans_x, ans_y;
	for (int i = 0; i < 2; i++) {
		if (x[i].weight < 2) ans_x = x[i].val;
		if (y[i].weight < 2) ans_y = y[i].val;
	}
	printf("%d %d", ans_x, ans_y);
}*/
//�����ﰢ��
/*#include <stdio.h>
#pragma warning(disable:4996)
int Getmax(int x, int y, int z) {
	if (x <= z && y <= z) return z;
	else if (x <= y) return y;
	else return x;
}
int isPythagorasTriangle(int x, int y, int z) {
	int G = Getmax(x, y, z);
	if (G == z) { if (x*x + y * y == z * z) return 1; }
	else if (G == y) { if (x*x + z * z == y * y) return 1; }
	else { if (y*y + z * z == x * x) return 1; }
	return 0;
}
int main() {
	int x, y, z;
	while (1) {
		scanf("%d%d%d", &x, &y, &z); if (!x && !y && !z) return 0;
		if (isPythagorasTriangle(x, y, z)) printf("right\n");
		else printf("wrong\n");
	}
}*/
//���ܹ�
/*#include <stdio.h>
#pragma warning(disable:4996)
typedef struct var {
	int direction, len;
}var;
int CalculateCount(var *v, int percnt) {
	int max_x = 0, max_y = 0, sub_x, sub_y;
	for (int i = 0; i < 6; i++) {
		if (v[i].len > max_x && (v[i].direction == 1 || v[i].direction == 2)) max_x = v[i].len;
		else if (v[i].len > max_y && (v[i].direction == 3 || v[i].direction == 4)) max_y = v[i].len;
	}
	for (int i = 0;;i++) {
		if (v[i % 6].direction == v[(i + 2) % 6].direction) {
			if (v[(i + 1) % 6].direction == v[(i + 3) % 6].direction) { sub_x = v[(i + 1) % 6].len; sub_y = v[(i + 2) % 6].len; }
			else { sub_x = v[i % 6].len; sub_y = v[(i + 1) % 6].len; }
			break;
		}
	}
	return (max_x * max_y - sub_x * sub_y) * percnt;
}
int main() {
	int percnt; scanf("%d", &percnt);
	var v[6];
	for (int i = 0; i < 6; i++) { scanf("%d%d", &v[i].direction, &v[i].len); }
	printf("%d", CalculateCount(v, percnt));
}*/
//�ý� ������
/*#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
#define pi 3.14159265359
double TaxiGeometry(int r) { return 2.0 * r * r; }
int main() {
	int r; scanf("%d", &r);
	printf("%.6lf\n", pi*r*r);
	printf("%.6lf", TaxiGeometry(r));
}*/
//�ͷ�
/*#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
int possiblelocation(int x1, int y1, int r1, int x2, int y2, int r2) {
	if (x1 == x2 && y1 == y2 && r1 == r2) return -1;
	
	double diff = sqrt((double)(x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	if (diff < abs(r1 - r2) || r1 + r2 < diff) return 0;
	else if (diff == abs(r1 - r2) || r1 + r2 == diff) return 1;
	else if (diff > abs(r1 - r2) || r1 + r2 > diff) return 2;
}
int main() {
	int x1, y1, r1, x2, y2, r2;
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
		printf("%d\n", possiblelocation(x1, y1, r1, x2, y2, r2));
	}
}*/
