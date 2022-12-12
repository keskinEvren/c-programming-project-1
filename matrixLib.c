/**
* @File: matrixLib.c
* @Description: Matrix operations
* @Assignment: 1
* @Date: 09/12/2022
* @Author and Mail: Evren Keskin - evren.keskin@stu.fsm.edu.tr
*/
#include <stdio.h>
#include <stdlib.h>
#include "matrixLib.h" 
#include "math.h"

#include <time.h>


float *returnVector(int size, int seed){
	srand(seed);
	
	float *vector = (float *)malloc(size * sizeof(float));

	int i;
	for(i = 0; i < size; i++){
		float element = ((float)((rand() % 10) + 1));
		vector[i] = element;
	}
	return vector;
}


float **returnMatrix(int row, int col, int seed){
	srand(seed);

    float** matrix = (float**)malloc(row * sizeof(float*));
    
    int i, j;
    
    for (i = 0; i < row; i++){
    	matrix[i] = (float*)malloc(col * sizeof(float));
	}
  
    for (i = 0; i < row; i++){
    	for (j = 0; j < col; j++){
    		float element = ((float)((rand() % 10) + 1));
    		matrix[i][j] = element;
		}
	}

	return matrix;
}


void freeMatrix(float **mat, int row){
	
	int i;
	for(i = 0; i < row; i++){
        free(mat[i]);
    }
    free(mat);
}

// Vektörün ortalamasini bulur
float mean(float *vec, int size){
	int i, total = 0;
	for(i = 0; i < size; i++){
		total = total + vec[i];
	}
	return total / (float)size;
}

float covariance(float *vec1, float *vec2, int size){

	int i;
	float sumOfVec1 = 0, sumOfVec2 = 0;
	
	float vec1Mean = 0;
	float vec2Mean = 0;
	
	// Vektörlerin ortolamasini bulur
	for(i = 0; i < size; i++){
		sumOfVec1 = sumOfVec1 + vec1[i];
		sumOfVec2 = sumOfVec2 + vec2[i];
	}
	
	vec1Mean = sumOfVec1 / size;
	vec2Mean = sumOfVec2 / size;
	
		
	printf("vec1 mean = %4.2f \n", vec1Mean);
	printf("vec2 mean = %4.2f \n", vec2Mean);
	
	for(i = 0; i < size; i++){
		vec1[i] = vec1[i] - vec1Mean;
		vec2[i] = vec2[i] - vec2Mean;
	}

	
	float covAddResult = 0;
	
	for(i = 0; i < size; i++){
		covAddResult = covAddResult + (vec1[i] * vec2[i]);
	}
	
	printf("covAddResult %4.2f \n", covAddResult);
	
	return covAddResult / (size - 1);
	
}


float **matrixMultiplication(float **mat1, float **mat2, int row1, int col1,  int row2, int col2){

    if(col1 != row2){
        return NULL;
    }
	int i, j, k;
    float **resultMatrix = (float**)malloc(row1 * sizeof(float*));
    for( i = 0; i < row1; i++){
        resultMatrix[i] = (float*)malloc(col2 * sizeof(float));
    }

    int counter = 0;

    for(i = 0; i < row1; i++){
        for(j = 0; j < col2; j++){
            float sum = 0;
            for(k = 0; k < row2; k++){
                sum += mat1[i][k] * mat2[k][j];
                counter++;
            }
            resultMatrix[i][j] = sum;
        }
    }

    return resultMatrix;
}



float** matrixTranspose(float **mat, int row, int col){
	
	int i, j;
	
	float **resultMatrix = (float**)malloc(row * sizeof(float*));
    for(i = 0; i < row; i++){
        resultMatrix[i] = (float*)malloc(col * sizeof(float));
    }
    
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			// sütun ve satir yerlerini degistirdim.
			resultMatrix[j][i] = mat[i][j];
		}
	}		
	
	return resultMatrix;
}

float *rowMeans(float **mat, int row, int col){
	
	float *resultVector = (float *)malloc(col * sizeof(float));
	
	
	int i, j;
	for(i = 0; i < row; i++){
		int sum = 0;
		for(j = 0; j < col; j++){
			sum = sum + mat[i][j];		
		}
		resultVector[i] = sum;
	}
	
	for(i = 0; i < row; i++){
		resultVector[i] = resultVector[i] / (float)col;
	}
	
	return resultVector;
	
}

float *columnMeans (float **mat, int row, int col){
	
	float *vector = (float *)calloc(col, sizeof(float));
	
  	int i, j;

    for (i = 0; i < row; i++){
  		for (j = 0; j < col; j++){
  			vector[j] += mat[i][j];
	  	}
  	}

  	for (i = 0; i < col; i++){
  		vector[i] = vector[i] / (float)row;
  	} 
  	
  	return vector;

} 

float **covarianceMatrix(float **mat, int row, int col){
	
	float **covMatrix = (float**)malloc(row * sizeof(float*));
	float *mean = (float*) malloc(col * sizeof(float));
    int i, j, k;
    for (i = 0; i < row; i++){
    	covMatrix[i] = (float*)malloc(col * sizeof(float));
	}
	  

  	// Sütunlarin ortalamasini hesapladim.
  	for (j = 0; j < col; j++) {
    	mean[j] = 0.0;
    	for (i = 0; i < row; i++) {
      		mean[j] += mat[i][j];
    	}
    	mean[j] /= row;
  	}

  
  	float **dev = (float**)malloc(row * sizeof(float*));
    for (i = 0; i < row; i++){
    	dev[i] = (float*)malloc(col * sizeof(float));
	}
	// Deviasyonu bulma
  	for (i = 0; i < row; i++) {
    	for (j = 0; j < col; j++) {
      		dev[i][j] = mat[i][j] - mean[j];
   		}
  	}

  	// Covariance matrixi hesaplama
  	for (i = 0; i < col; i++) {
    	for (j = 0; j < col; j++) {
      		covMatrix[i][j] = 0.0;
      		for (k = 0; k < row; k++) {
        		covMatrix[i][j] += dev[k][i] * dev[k][j];
      		}
      		covMatrix[i][j] /= row;
    	}
  	}

  	return covMatrix;
}

float determinant(float **mat, int row){
	
	float result = 
		mat[0][0] * ((mat[1][1] * mat[2][2]) - (mat[2][1] * mat[1][2])) - 
		mat[0][1] * (mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2]) + 
		mat[0][2] * (mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1]);
	
	return result;
	
}

void printVector(float *vec, int N){
	int i;
	for(i = 0; i < N; i++){
		printf("%2.2f - ", vec[i]);
	}
	printf("\n");
}

void printMatrix(float **mat, int row, int col){
	int i,j;
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			printf("%2.2f - ", mat[i][j]);
		}
		printf("\n");
	}
}



// Standart deviasyonu bulma
float stddev(float *vec, int size) {
  float meanValue = mean(vec, size);
  float sum_square_diff = 0;
  
  int i;
  for (i = 0; i < size; i++) {
    sum_square_diff += (vec[i] - meanValue) *(vec[i] - meanValue);
  }
  
  float result = (float)(sqrt(sum_square_diff / (size - 1)));
  
  return result;
  
  
}
// Korelasyonu hesaplama
float correlation(float *vec1, float *vec2, int size) {
  float sum = 0;
  
  int i;
  for (i = 0; i < size; i++) {
    sum = sum + (vec1[i] - mean(vec1, size)) * (vec2[i] - mean(vec2, size));
  }
  
  float rounded_sum = floorf(sum * 100) / 100; 
  
  
  float result = rounded_sum / ((float)size * stddev(vec1, size) * stddev(vec2, size));
  
  return result;
}




