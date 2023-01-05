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
//최소공배수
/*#include <stdio.h>
#pragma warning(disable:4996)
int gcd(int n, int m) {
	if (m == 0) return n;
	return gcd(m, n%m);
}
int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int n, m; scanf("%d%d", &n, &m);
		int G = gcd(m, n);
		int L = n * m / G;
		printf("%d\n", L);
	}
}*/
//검문 --- n개의 숫자가 m으로 나뉘어졌을 때 나머지가 같을 때 m 출력 --- 시간초과(잘모르겠다)
/*#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
void PrintPossibleNumber(int *x, int n, int secmin) {
	for (int i = 2;i <= secmin; i++) {
		int base = x[0] % i; int flag = 1; int cnt = 0;
		for (int j = 1; j < n; j++) { if (x[j] % i != base) { flag = 0; break; } }
		if (flag) printf("%d ", i);
	}
}
int main() {
	int n; scanf("%d", &n);
	int *x = (int *)malloc(sizeof(int)*n); int min, secmin = 1000000000;
	for (int i = 0; i < n; i++) { 
		scanf("%d", x + i); 
		if (i == 0) min = x[i];
		else { 
			if (min > x[i]) { if (secmin > min) secmin = min; min = x[i]; }
			else { if (secmin > x[i]) secmin = x[i]; }
		}
	}
	PrintPossibleNumber(x, n, secmin);
	free(x);
}*/
//링
/*#include <stdio.h>
#pragma warning(disable:4996)
int gcd(int n, int m) {
	if (m == 0) return n;
	return gcd(m, n%m);
}
void GetRotationCount(int firstring, int secondring) {
	int G = gcd(firstring, secondring);
	printf("%d/%d\n", firstring / G, secondring / G);
}
int main() {
	int n; scanf("%d", &n); int firstring; int radius;
	for (int i = 0; i < n; i++) {
		scanf("%d", &radius);
		if (i == 0) firstring = radius;
		else GetRotationCount(firstring, radius);
	}
}*/
//이항계수 1
/*#include <stdio.h>
#pragma warning(disable:4996)
int factorial(int n, int k) {
	if (n == k) return 1;
	return n * factorial(n - 1, k);
}
int GetCombination(int n, int k) {
	if (k > n - k) return factorial(n, k) / factorial(n - k, 0);
	else return factorial(n, n - k) / factorial(k, 0);
}
int main() {
	int n, k; scanf("%d%d", &n, &k);
	printf("%d", GetCombination(n, k));
}*/
//이항계수 2
#include <stdio.h>
#pragma warning(disable:4996)
int main() {
	int n, k; scanf("%d%d", &n, &k);
	int dp[1001][1001] = { 0, };
	/*for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) dp[i][j] = 1;
			else { dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007; }
		}
	}*/
	printf("%d", dp[n][k]);
}