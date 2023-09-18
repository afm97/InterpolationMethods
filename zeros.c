float zeros(int rows, int cols, float matrix[rows][cols]){
    
    for(int i = 0; i< rows; i++){
        for(int j = 0; j< cols; j++){
            matrix[i][j] = 0.0;
        }
    }
    return matrix[rows][cols];
}