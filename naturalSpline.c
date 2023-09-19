float NaturalSpline(int rows, int cols, float data[rows][cols], float constants[rows][3])
{
    /*A função recebe o numero de linhas e colunas de uma matriz de pontos e retorna uma matriz com as constantes dos polinõmios*/
    /*A matriz constante possui a seguinte estrutura constant[][3] = {coef.b, coef.c, coef.d}*/

    float A[rows][rows];
    A[rows][rows] = zeros(rows, rows, A);
    constants[rows][3] = zeros(rows, 3, constants);

    float h_0, h_1, a_0, a_1, a_2;

    A[0][0] = 1;
    A[rows - 1][rows - 1] = 1;

    for (int i = 0; i < rows - 2; i++)
    {
        h_0 = data[i + 1][0] - data[i][0];
        h_1 = data[i + 2][0] - data[i + 1][0];

        A[i + 1][i] = h_0;
        A[i + 1][i + 1] = 2 * (h_0 + h_1);
        A[i + 1][i + 2] = h_1;

        a_0 = data[i][1];
        a_1 = data[i + 1][1];
        a_2 = data[i + 2][1];

        constants[i + 1][1] = (3 / h_1) * (a_2 - a_1) - (3 / h_0) * (a_1 - a_0);
    }

    /*Obtendo-se os coeficientes "c" mediante solução do sistema linear*/
    gaussianElimination(rows, A, constants);

    /*Calculando-se os coeficientes "b"*/
    for (int j = 0; j < rows - 1; j++)
    {
        h_0 = data[j + 1][0] - data[j][0];
        a_0 = data[j][1];
        a_1 = data[j + 1][1];

        constants[j][0] = (1 / h_0) * (a_1 - a_0) - (h_0 / 3) * (constants[j + 1][1] + 2 * constants[j][1]);
    }

    /*Calculando-se os coeficientes "d"*/
    for (int k = 0; k < rows - 1; k++)
    {
        h_0 = data[k + 1][0] - data[k][0];
        constants[k][2] = (1 / (3 * h_0)) * (constants[k + 1][1] - constants[k][1]);
    }
}