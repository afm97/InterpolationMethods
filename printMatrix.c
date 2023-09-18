void printMatrix(int rows, int cols, float matrix[rows][cols]){
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%f     ", matrix[i][j]);
        }
        printf("\n");
    }
}