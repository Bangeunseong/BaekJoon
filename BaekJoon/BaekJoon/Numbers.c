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
/*#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main() {
	int n, k; scanf("%d%d", &n, &k);
	int **dp = (int **)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i <= n; i++) dp[i] = (int *)malloc(sizeof(int) * (n + 1));

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) dp[i][j] = 1;
			else { dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007; }
		}
	}
	printf("%d", dp[n][k]);
}*/
//다리 놓기
/*#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main() {
	int m; scanf("%d", &m); 
	for (int p = 0; p < m; p++) {
		int n, k; scanf("%d%d", &k, &n);
		unsigned long **dp = (unsigned long **)malloc(sizeof(unsigned long*) * (n + 1));
		for (int i = 0; i <= n; i++) dp[i] = (unsigned long *)malloc(sizeof(unsigned long) * (n + 1));

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0 || j == i) dp[i][j] = 1;
				else { dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]); }
			}
		}
		printf("%d\n", dp[n][k]);
		for (int i = 0; i <= n; i++) free(dp[i]); free(dp);
	}
}*/
//패션왕 신해빈
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct Cloth {
	char *name, *use; int visited;
}Cloth;
int PossibleFashionCount(Cloth *C, int m) {
	int x[30] = { 0, }; int n = 0;
	for (int i = 0; i < m; i++) {
		if (!C[i].visited) {
			for (int j = i; j < m; j++) if (strcmp(C[i].use, C[j].use) == 0) { C[j].visited = 1; x[n]++; }
			n++;
		}
	}

	int sum = 1;
	for (int i = 0; i < n; i++) { sum = sum * (x[i] + 1); }
	return sum - 1;
}
int main() {
	int n, P_num = 0; scanf("%d", &n); Cloth *C = NULL;
	for (int i = 0; i < n; i++) {
		int m; scanf("%d", &m); C = (Cloth *)malloc(sizeof(Cloth)*m);

		for (int j = 0; j < m; j++) {
			char name[21]; char use[21]; scanf("%s %s", name, use);
			C[j].name = (char *)malloc(sizeof(char)*(strlen(name) + 1)); strcpy(C[j].name, name);
			C[j].use = (char *)malloc(sizeof(char)*(strlen(use) + 1)); strcpy(C[j].use, use);
			C[j].visited = 0;
		}
		
		printf("%d\n", PossibleFashionCount(C, m));

		for (int j = 0; j < m; j++) { free(C[j].name); free(C[j].use); }
		free(C);
	}
}*/
//팩토리얼 0의 개수 --- 0이 나오는 경우의 수는 주로 짝수와 5의 곱으로 인해 생김 --- 5의 배수 생각 25의 배수 생각 125의 배수 생각 625의 배수 생각 ....
/*#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main() {
	int n; scanf("%d", &n);
	printf("%d", n / 5 + n / 25 + n / 125);
}*/
