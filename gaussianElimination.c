void gaussianElimination(int rows, float matrix[rows][rows], float solution[rows][1]) {
    
    float ratio = 0, sol_aux;

	/* Applying Gauss Elimination */
	for(int i = 0; i < rows-1; i++){

		if(matrix[i][i] == 0.0){

		    printf("Mathematical Error!");
			exit(0);

		  }
          for(int j = i+1; j < rows; j++){

			ratio = matrix[j][i]/matrix[i][i];
			   
			for(int k = 0; k < rows; k++){

			  	matrix[j][k] = matrix[j][k] - ratio*matrix[i][k];
			   
            }
            solution[j][0] = solution[j][0] - ratio*solution[i][0];
		  }
	}

	 /* Obtaining Solution by Back Substitution */

    solution[rows-1][0] = solution[rows-1][0]/matrix[rows-1][rows-1];

    for(int l = rows - 2; l >= 0; l--){
		sol_aux = 0;
        for(int k = rows - 1; k > l; k--){

            sol_aux = sol_aux + matrix[l][k]*solution[k][0];

        }
        solution[l][0] = (solution[l][0] - sol_aux)/matrix[l][l];
    }

}