/**
* @File: main.c
* @Description: Matrix operations
* @Assignment: 1
* @Date: 09/12/2022
* @Author and Mail: Evren Keskin - evren.keskin@stu.fsm.edu.tr
*/

#include <stdio.h>
#include <stdlib.h>
#include "matrixLib.h"



int main(int argc, char **argv) {
	
	int seed = atoi(argv[1]);

	float* vector = returnVector(3, seed);
	float** matrix = returnMatrix(3,3, seed);
	
	printf("---------\n");

	printf("\ PRINT VECTOR \n");
	
	printVector(vector, 3);
	
	printf("\ PRINT VECTOR \n");
	
	printf("---------\n");
	
	printf("\ PRINT MATRIX \n");
	
	printMatrix(matrix, 3, 3);
	
	printf("\ PRINT MATRIX \n");
	
	
	printf("---------\n");
	
	printf(" PRINT MEAN OF THE VECTOR\n");
	
	float total = mean(vector, 3);
	printf("mean of the vector = %2.2f", total);
	
	printf("\n PRINT MEAN OF THE VECTOR\n");
	
    printf("\n---------\n");  
            
	printf("\n PRINT MATRIX MULTIPLICATION RESULT \n");
	
	float** matrix11 = returnMatrix(3,3, seed);
	float** matrix22 = returnMatrix(3,3, seed);
	float** result = matrixMultiplication(matrix11, matrix22, 3, 3, 3, 3);
	printMatrix(result, 3, 3);
	
	printf("\n PRINT MATRIX MULTIPLICATION RESULT \n");
	
	printf("\n---------\n"); 
	 
	printf("\n TRANSPOSE \n");  
	
	float **transposeMatrix = matrixTranspose(matrix11, 3, 3);
	printMatrix(transposeMatrix, 3, 3);
	
	printf("\n TRANSPOSE \n"); 
	
	printf("\n---------\n");  
	
	printf("\n ROW MEANS \n"); 
	
	float **rowMeansMatrix = returnMatrix(5, 2, seed);
	printMatrix(rowMeansMatrix, 5, 2);
	float *rowMeansVectorResult = rowMeans(rowMeansMatrix, 5, 2);
	printVector(rowMeansVectorResult, 5);
	
	printf("\n ROW MEANS \n"); 
	
	printf("\n---------\n"); 
	
	
	printf("\n COLUMN MEANS \n"); 
	
	float **columnMeansMatrix = returnMatrix(5, 2, 12412);
	printMatrix(columnMeansMatrix, 4, 2);
	float *columnMeansVectorResult = columnMeans(columnMeansMatrix, 4, 2);
	printVector(columnMeansVectorResult, 2);
	
	printf("\n COLUMN MEANS \n"); 
	
	printf("\n---------\n"); 
	
	printf("\n DETERMINANT \n"); 
	
	float **determinantMatrix = returnMatrix(3,3, 177);
	printMatrix(determinantMatrix, 3, 3);
	float determinantResult = determinant(determinantMatrix, 3);
	printf("%4.2f", determinantResult);
	
	printf("\n DETERMINANT \n"); 
	
	printf("\n---------\n"); 
	
	printf("\n COVARIANCE \n"); 
	
	float *covarianceVector1 = returnVector(4, seed);
	float *covarianceVector2 = returnVector(4, seed);
	printVector(covarianceVector1, 4);
	printVector(covarianceVector2, 4);
	
	float covarianceResult = covariance(covarianceVector1, covarianceVector2, 4); 
	printf(" Covariance = %4.2f", covarianceResult);
	printf("\n COVARIANCE \n"); 
	
	printf("\n---------\n"); 
	
	printf("\n CORRELATION \n"); 
	
	float *corrVector1 = returnVector(4, seed);
  	float *corrVector2 = returnVector(4, seed);
  	float corr_val = correlation(corrVector1, corrVector2, 4);
  	printf("Correlation = %4.2f \n", corr_val);
	
	printf("\n CORRELATION \n"); 
	
	printf("\n---------\n"); 
	
	printf("\n COVARIANCE MATRIX \n"); 
	
	float **matrixForCov = returnMatrix(3, 3, seed);
	
	printf("Matrix => \n");
	printMatrix(matrixForCov, 3, 3);
	printf("\n");
	
	float **covMatrix = covarianceMatrix(matrixForCov, 3, 3);
	
	printf("Covariance Matrix => \n");
	printMatrix(covMatrix, 3, 3);
	
	printf("\n COVARIANCE MATRIX \n");
	
	return 0;
}











