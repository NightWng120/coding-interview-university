#include <stdio.h>
#include <stdlib.h>

typedef struct VectorInt{
	int data;
	int size;
	int capacity;
	int front;
	int back;
	int * start;
}VectorInt;

VectorInt * new(int size){
	VectorInt newInit;
	VectorInt * new = &newInit;
	if(size > 0){
		new->size = 0;
		new->capacity = size;
		int * newArr = malloc(size * sizeof(int));
		new->start = newArr;
	}
	else{
		new->size = 0;
		new->capacity = 5;
		int * newArr = malloc(5 * sizeof(int));
		new->start = newArr;
	}
	return new;
}

int get(VectorInt * vec, int index){
	if(index < vec->size && index >= 0)
		return vec->start[index];
	else
		return NULL;
}

VectorInt * insert(VectorInt * vec, int index, int data){
	if(index < vec->size)
		vec->start[index] = data;
	else{
		printf("Invalid index value\n");
	}
	return vec;
}

VectorInt * push(VectorInt * vec, int index, int data){
	if(index < vec->size){
		if(vec->size + 1 <= vec->capacity){
			vec->size+=1;
			int * newArr = malloc(vec->capacity * sizeof(int));
			int i = 0;
			for(i = 0; i < (vec->size - index); i++){
				newArr[i] = vec->start[i];
			}
			newArr[i] = data;
			for(int j = i + 1; j < vec->size; j++){
				newArr[i] = vec->start[i];
			}
			vec->start = newArr;
		}
		else{
			vec->size+=1;
			vec->capacity += 5;
			int * newArr = malloc(vec->capacity * sizeof(int));
			int i = 0;
			for(i = 0; i < (vec->size - index); i++){
				newArr[i] = vec->start[i];
			}
			newArr[i] = data;
			for(int j = i + 1; j < vec->size; j++){
				newArr[i] = vec->start[i];
			}
			vec->start = newArr;
		}
	}
	return vec;
}


VectorInt * addBack(VectorInt * vec, int data){
	int buffer = vec->size;
	if(vec->size+1 <= vec->capacity){
		vec->start[buffer] = data;
		vec->size = buffer + 1;
	}
	else{
		vec->capacity += 5;
		int * newArr = malloc(vec->capacity * sizeof(int));
		int i = 0;
		for(i = 0; i < vec->size; i++){
			newArr[i] = vec->start[i];
		}
		newArr[i] = data;
		free(vec->start);
		vec->start = newArr;
	}
}

VectorInt * addFront(VectorInt * vec, int data){
	if(vec->size + 1 <= vec->capacity){
		vec->size += 1;
		int * newArr = malloc(vec->capacity * sizeof(int));
		int i = 0;
		newArr[0] = data;
		for(i = 1; i < vec->size; i++){
			newArr[i] = vec->start[i];
		}
		free(vec->start);
		vec->start = newArr;
	}
	else{
		vec->capacity += 5;
		vec->size += 1;
		int * newArr = malloc(vec->capacity * sizeof(int));
		int i = 0;
		newArr[0] = data;
		for(i = 1; i < vec->size; i++){
			newArr[i] = vec->start[i];
		}
		free(vec->start);
		vec->start = newArr;
	}
	return vec;
}

void printVec(VectorInt * vector, int size){
}


int main(){
	VectorInt * vector = new(4);
	int size = 4;
	vector = addBack(vector, 6);
	vector = addBack(vector, 7);
	vector = addBack(vector, 8);
	vector = addBack(vector, 9);

	vector->size = 4;
	printf("Current size: %d\n", vector->size);
	printf("[");
	for(int i = 0; i < vector->size; i++){
		if(i + 1 == vector->size)
			printf(", %d]", vector->start[i]);
		else if(i == 0)
			printf("%d", vector->start[i]);
		else{
			printf(", %d", vector->start[i]);
		}
	}
	printf("\n");
	fflush(stdout);

	insert(vector, 2, 5);
	vector->size = 5;
	printf("Current size: %d\n", vector->size);
	printf("[");
	for(int i = 0; i < vector->size; i++){
		if(i + 1 == vector->size){
			printf(", %d]", vector->start[i]);
		}
		else if(i == 0)
			printf("%d", vector->start[i]);
		else{
			printf(", %d", vector->start[i]);
		}
	}
	printf("\n");
	fflush(stdout);

	printf("At index 2: %d\n", get(vector, 2));
}
