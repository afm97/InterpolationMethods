#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "zeros.c"
#include "printMatrix.c"
#include "gaussianElimination.c"
#include "naturalSpline.c"
#include "fixedSpline.c"

#define e 2.7182818285

int main()
{

    float data[][3] = {{0, 1, 1},
                       {1, e, 0},
                       {2, pow(e, 2), 0},
                       {3, pow(e, 3), pow(e, 3)}};

    int rows = sizeof(data) / sizeof(data[0]);
    int cols = sizeof(data[0]) / sizeof(data[0][0]);

    float constants[rows][3];

    NaturalSpline(rows, cols, data, constants);
    printf("Coeficientes para spline livre\n");
    printMatrix(rows, 3, constants);
    printf("--------------------------------------\n");

    FixedSpline(rows, cols, data, constants);
    printf("Coeficientes para spline fixa\n");
    printMatrix(rows, 3, constants);
    printf("--------------------------------------\n");

}