SparseMatrix multiplyMatrices(SparseMatrix a, SparseMatrix b) {
    SparseMatrix result;
    result.rows = a.rows;
    result.cols = b.cols;
    result.terms = 0;

    if (a.cols != b.rows) {
        result.terms = -1; // Multiplication not possible
        return result;
    }

    int k = 0;
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            int sum = 0;
            for (int p = 0; p < a.terms; p++) {
                if (a.data[p].row == i) {
                    int col_a = a.data[p].col;
                    for (int q = 0; q < b.terms; q++) {
                        if (b.data[q].row == col_a && b.data[q].col == j) {
                            sum += a.data[p].value * b.data[q].value;
                        }
                    }
                }
            }
            if (sum != 0) {
                result.data[k].row = i;
                result.data[k].col = j;
                result.data[k].value = sum;
                k++;
            }
        }
    }
    result.terms = k;
    return result;
}