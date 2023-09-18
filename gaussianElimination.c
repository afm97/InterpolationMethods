void gaussianElimination(int rows, float matrix[rows][rows], float solution[rows][1]) {
    
    float ratio;
	/* Applying Gauss Elimination */
	for(int i = 0; i < rows-1; i++){

		if(matrix[i][i] == 0.0){

		    printf("Mathematical Error!");
			exit(0);

		  }for(int j = i+1; j < rows-2;j++){

			ratio = matrix[j][i]/matrix[i][i];
			   
			for(int k = 0; k < rows-1; k++){

			  	matrix[j][k] = matrix[j][k] - ratio*matrix[i][k];
			   
            }solution[j][0] = solution[j][0] - ratio*matrix[i][i];
		  }
	 }

	 /* Obtaining Solution by Back Subsitution */



}