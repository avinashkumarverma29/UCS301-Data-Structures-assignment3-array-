SparseMatrix addMatrices(SparseMatrix a, SparseMatrix b) {
    SparseMatrix result;
    if (a.rows != b.rows || a.cols != b.cols) {
        result.terms = -1; // Invalid dimension match
        return result;
    }
    
    result.rows = a.rows;
    result.cols = a.cols;
    int i = 0, j = 0, k = 0;
    
    while (i < a.terms && j < b.terms) {
        if (a.data[i].row < b.data[j].row || 
           (a.data[i].row == b.data[j].row && a.data[i].col < b.data[j].col)) {
            result.data[k++] = a.data[i++];
        } else if (b.data[j].row < a.data[i].row || 
                  (b.data[j].row == a.data[i].row && b.data[j].col < a.data[i].col)) {
            result.data[k++] = b.data[j++];
        } else {
            // Same indices, add values
            result.data[k] = a.data[i];
            result.data[k].value = a.data[i].value + b.data[j].value;
            if (result.data[k].value != 0) {
                k++;
            }
            i++;
            j++;
        }
    }
    
    while (i < a.terms) result.data[k++] = a.data[i++];
    while (j < b.terms) result.data[k++] = b.data[j++];
    
    result.terms = k;
    return result;
}