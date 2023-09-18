#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "zeros.c"
#include "printMatrix.c"
#include "gaussianElimination.c"
#include "naturalSpline.c"

int main(){

    int rows = 3, cols = 3;

    float solution[rows][2];

    float data[][3] = { {1.3, 0.6200860, -0.5220232},
                         {1.6, 0.4554022, -0.5698959},
                         {1.9, 0.2818186, -0.5811571} };

    NaturalSpline(rows,cols,data,solution);
    printMatrix(rows,2,solution);

    //printf("O tamanho da matrix é: %d \n",N_Collums);
    //printf("O endereco da matrix data é: %p\n",&data);
}

