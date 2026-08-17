int dfs(int* stoneValue, int left, int right, int** f) {
    if (left == right) {
        return 0;
    }
    if (f[left][right] != 0) {
        return f[left][right];
    }

    int sum = 0;
    for (int i = left; i <= right; i++) {
        sum += stoneValue[i];
    }
    int suml = 0;
    for (int i = left; i < right; ++i) {
        suml += stoneValue[i];
        int sumr = sum - suml;
        if (suml < sumr) {
            f[left][right] =
                fmax(f[left][right], dfs(stoneValue, left, i, f) + suml);
        } else if (suml > sumr) {
            f[left][right] =
                fmax(f[left][right], dfs(stoneValue, i + 1, right, f) + sumr);
        } else {
            f[left][right] =
                fmax(f[left][right], fmax(dfs(stoneValue, left, i, f),
                                          dfs(stoneValue, i + 1, right, f)) +
                                         suml);
        }
    }
    return f[left][right];
}

int stoneGameV(int* stoneValue, int stoneValueSize) {
    int n = stoneValueSize;
    int** f = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        f[i] = (int*)calloc(n, sizeof(int));
    }
    int result = dfs(stoneValue, 0, n - 1, f);
    for (int i = 0; i < n; i++) {
        free(f[i]);
    }
    free(f);
    return result;
}