float NaturalSpline(int rows, int cols, float data[rows][cols], float b[rows][2]){
    
    float A[rows][cols]; A[rows][cols] = zeros(rows,cols,A);
    b[rows][2] = zeros(rows,2,b); 
    

    float h_0, h_1, a_0, a_1, a_2;

    A[0][0] = 1; A[rows-1][cols-1] = 1;

    for (int i = 0; i < rows-2; i++)
    {
        h_0 = data[i+1][1] - data[i][1];
        h_1 = data[i+2][1] - data[i+1][1];

        A[i+1][i] = h_0;
        A[i+1][i+1] = 2*(h_0 + h_1);
        A[i+1][i+2] = h_1;

        a_0 = data[i][2];
        a_1 = data[i+1][2];
        a_2 = data[i+2][2];

        b[i+1][0] = (3/h_1)*(a_2 - a_1) - (3/h_0)*(a_1 - a_0);
    }

    gaussianElimination(rows,A,b);

    for(int j = 0; j < rows - 2; j++){
        b[j][1] = (1/(data[j+1][1] - data[j][1]))*(b[j+1][0] - b[j][0]);
    }
}