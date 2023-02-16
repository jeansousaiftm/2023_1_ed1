void bubbleSort(int v[], int n) {
    for (int i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (v[j] > v[j+1]) {
                int tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
}
