#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct VectorInt{
	int data;
	int size;
	int capacity;
	int front;
	int back;
	int * start;
}VectorInt;

VectorInt * new(int size){
	VectorInt * new = malloc(sizeof(VectorInt));
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

void insert(VectorInt * vec, int index, int data){
	if(index < vec->size)
		vec->start[index] = data;
	else{
		printf("Invalid index value\n");
	}
}

void push(VectorInt * vec, int index, int data){
	if(index < vec->size){
		if(vec->size + 1 <= vec->capacity){
			vec->size+=1;
			int * newArr = malloc(vec->capacity * sizeof(int));
			int i = 0;
			for(i = 0; i < index; i++){
				newArr[i] = vec->start[i];
				printf("Start element #%d is %d\n", i, newArr[i]);
			}
			printf("Start element #%d is %d\n", i, newArr[i]);
			newArr[i] = data;
			for(int j = i + 1; j < vec->size; j++){
				newArr[j] = vec->start[j - 1];
				printf("Start element #%d is %d\n", j, newArr[j]);
			}
			free(vec->start);
			vec->start = newArr;
		}
		else if(index < vec->capacity){
			vec->size+=1;
			vec->capacity += 5;
			int * newArr = malloc(vec->capacity * sizeof(int));
			int i = 0;
			for(i = 0; i < index; i++){
				newArr[i] = vec->start[i];
				printf("Start element #%d is %d\n", i, newArr[i]);
			}
			newArr[i] = data;
			printf("Start element #%d is %d\n", i, newArr[i]);
			for(int j = i + 1; j < vec->size; j++){
				newArr[j] = vec->start[j - 1];
				printf("Start element #%d is %d\n", j, newArr[j]);
			}
			free(vec->start);
			vec->start = newArr;
		}
		else{
			printf("Invalid push index %d\n", index);
		}
	}
}


void addBack(VectorInt * vec, int data){
	if(vec->size+1 <= vec->capacity){
		vec->start[vec->size] = data;
		vec->size += 1;
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
		vec->size += 1;
	}
}

void addFront(VectorInt * vec, int data){
	if(vec->size + 1 <= vec->capacity){
		vec->size += 1;
		int * newArr = malloc(vec->capacity * sizeof(int));
		int i = 0;
		newArr[0] = data;
		for(i = 1; i < vec->size; i++){
			newArr[i] = vec->start[i - 1];
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
			newArr[i] = vec->start[i - 1];
		}
		free(vec->start);
		vec->start = newArr;
	}
}

void delete(VectorInt * vec, int index){
	int i = 0;
	int * newArr = malloc(vec->capacity * sizeof(int));
	if(index < vec->size){
		for(i = 0; i < index; i++){
			newArr[i] = vec->start[i];
		}
		for(int j = i + 1; j < vec->size; j++){
			newArr[j] = vec->start[j + 1];
		}
		free(vec->start);
		vec->start = newArr;
		vec->size -= 1;
	}
	else{
		printf("Delete index is invalid\n");
	}
}

void removeElements(VectorInt * vec, int item){
	int * newArr = malloc(vec->capacity * sizeof(VectorInt));
	int size = vec->size;
	int index = 0;
	for(int i = 0; i < vec->size; i++){
		if(vec->start[i] == item){
			printf("Removed element %d at index %d\n", vec->start[i], i);
			size -= 1;
			continue;
		}
		else{
			printf("Added element %d to index %d\n", vec->start[i], index);
			newArr[index] = vec->start[i];
			index += 1;
		}
	}
	free(vec->start);
	vec->start = newArr;
	vec->size = size;
}

int find(VectorInt * vec, int item){
	for(int i = 0; i < vec->size; i++){
		if(vec->start[i] == item)
			return i;
	}
}

int * findAll(VectorInt * vec, int item){
	int * items = malloc(vec->size * sizeof(int));
	int index = 0;
	for(int i = 0; i < vec->size; i++){
		if(vec->start[i] == item){
			items[index] = i;
			index+=1;
		}
	}
	return items;
}

void printVec(VectorInt * vector, int size){
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
}

void printArray(int * array, int size){
	printf("[");
	for(int i = 0; i < size; i++){
		if(i + 1 == size){
			printf("%d", array[i]);
			break;
		}
		printf("%d, ", array[i]);
	}
	printf("]\n");
}

int size(VectorInt * vec){
	return vec->size;
}

int capacity(VectorInt * vec){
	return vec->capacity;
}

bool isEmpty(VectorInt * vec){
	if(vec->size > 0){
		return true;
	}
	else{
		return false;
	}
}


int main(){
	VectorInt * vector = new(5);
	addBack(vector, 11);
	addBack(vector, 11);
	addBack(vector, 6);
	addBack(vector, 7);
	addBack(vector, 8);
	addBack(vector, 9);

	printf("Current size: %d\n", vector->size);

	printVec(vector, vector->size);

	push(vector, 2, 5);
	addFront(vector, 22);

	printf("Current size: %d\n", vector->size);

	printVec(vector, vector->size);

	printf("At index 5: %d\n", get(vector, 5));

	delete(vector, 5);

	printVec(vector, vector->size);

	printf("Indeces of elements with value 11\n");
	printArray(findAll(vector, 11), 2);

	removeElements(vector, 11);

	printVec(vector, vector->size);

	printf("Index of 9: %d\n", find(vector, 9));


}
