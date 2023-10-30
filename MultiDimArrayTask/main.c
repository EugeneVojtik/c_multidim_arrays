#include <stdio.h>
#include <stdlib.h>


int** allocate_array(int rows){
    return (int**)malloc(rows * sizeof(int*));
}

int** create_linear_array(int **array, int rows, int columns) {
    int* data = (int*)malloc(rows * columns * sizeof(int));

    for (int i = 0; i < rows; i++) {
        array[i] = data + i * columns;
    }
    return array;
}

int** create_dynamic_array(int** array,int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(columns * sizeof(int));
    }
    return array;
}


int** allocate_memory(int rows, int columns, int option) {
    int **array = allocate_array(rows);

    if (option == 1) {
        return create_linear_array(array, rows, columns);
    } else if (option == 2) {
        return create_dynamic_array(array, rows, columns);
    } else {
        printf("Invalid options has been chosen.\n");
        return NULL;
    }
}

void fill_array(int** array, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Please enter num:\n");
            scanf("%d", &array[i][j]);
        }
    }
}


void print_array(int** array, int rows, int columns) {
    printf("Array is: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d -> ", array[i][j]);
        }
    }
    printf("\n");
}


void print_row(int** array, int row, int columns) {
    for (int j = 0; j < columns; j++) {
        printf("%d -> ", array[row][j]);
    }
    printf("\n");
}


void print_column(int** array, int rows, int column) {
    for (int i = 0; i < rows; i++) {
        printf("%d -> ", array[i][column]);
    }
    printf("\n");
}


void free_memory(int** array, int rows, int option) {
    if (option == 1) {
        free(array[0]);
    } else {
        for (int i = 0; i < rows; i++) {
            free(array[i]);
        }
    }
    free(array);
}


void print_memory_addresses(int** array, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Address of element (%d, %d): %p\n", i, j, &array[i][j]);
        }
    }
}


int main() {
    int rows, columns;
    int allocation_option;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    printf("Choose memory allocation option:\n");
    printf("1) Linear\n");
    printf("2) Dynamic\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &allocation_option);

    int** array = allocate_memory(rows, columns, allocation_option);
    if (array == NULL){
        return 1;
    }

    fill_array(array, rows, columns);

    printf("Array contents:\n");
    print_array(array, rows, columns);
    print_memory_addresses(array, rows, columns);


    free_memory(array, rows, allocation_option);

    return 0;
}
