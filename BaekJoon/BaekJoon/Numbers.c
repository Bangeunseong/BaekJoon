//배수와 약수
/*#include <stdio.h>
#pragma warning(disable:4996)
int FactororMultiple(int a, int b) {
	if (a > b) { if (a%b == 0) return 2; }
	else { if (b%a == 0) return 1; }
	return 0;
}
int main() {
	int a, b; 
	while (1) {
		scanf("%d%d", &a, &b); if (!a && !b) return 0;
		switch (FactororMultiple(a, b)) {
		case 0: printf("neither\n"); break;
		case 1: printf("factor\n"); break;
		case 2: printf("multiple\n"); break;
		}
	}
}*/
//약수
/*#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int returnFromfactors(int *x, int n) {
	int min, max; min = max = x[0];
	for (int i = 1; i < n; i++) { if (min < x[i]) min = x[i]; if (max > x[i]) max = x[i]; }
	return min * max;
}
int main() {
	int n; scanf("%d", &n);
	int *x = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) scanf("%d", x + i);
	printf("%d", returnFromfactors(x, n));
	free(x);
}*/
//최대공약수, 최소공배수
/*#include <stdio.h>
#pragma warning(disable:4996)
int gcd(int n, int m) {
	if (m == 0) return n;
	return gcd(m, n%m);
}
int main() {
	int n, m; scanf("%d%d", &n, &m);
	int G = gcd(n, m);
	int L = n * m / G;
	printf("%d\n%d", G, L);
}*/