#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        int v1[m + 1], v2[m + 1];
        for (int j = 0; j < m; j++) {
            scanf("%d", &v1[j]);
            v2[j] = v1[j];
        }
        for (int j = 0; j < m - 1; j++) {
            for (int k = 0; k < m - 1; k++) {
                if (v2[k] < v2[k + 1]) {
                    int aux = v2[k];
                    v2[k] = v2[k + 1];
                    v2[k + 1] = aux;
                }
            }
        }
        int c = 0;
        for (int j = 0; j < m; j++) {
            if (v1[j] == v2[j]) c++;
        }
        printf("%d\n", c);
    }
    return 0;
}
