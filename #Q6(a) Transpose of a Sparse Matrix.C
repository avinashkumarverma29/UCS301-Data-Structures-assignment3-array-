void transposeMatrix(SparseMatrix a, SparseMatrix *b) {
    b->rows = a.cols;
    b->cols = a.rows;
    b->terms = a.terms;
    
    if (a.terms > 0) {
        int current_idx = 0;
        for (int c = 0; c < a.cols; c++) {
            for (int i = 0; i < a.terms; i++) {
                if (a.data[i].col == c) {
                    b->data[current_idx].row = a.data[i].col;
                    b->data[current_idx].col = a.data[i].row;
                    b->data[current_idx].value = a.data[i].value;
                    current_idx++;
                }
            }
        }
    }
}