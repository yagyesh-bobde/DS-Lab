#include <stdio.h>

void display(int arr[3][3]) {
  printf("The Matrix is: \n");
  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

void transpose(int arr[3][3]) {
  printf("The Transpose Matrix is: \n");
  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      printf("%d ", arr[j][i]);
    }
    printf("\n");
  }
}

void row_wise(int arr[3][3]) {
  printf("The Row Wise Matrix is: \n");
  for(int i=0; i<3; i++) {
    printf("%d row: ", i+1);
    for(int j=0; j<3; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

void col_wise(int arr[3][3]) {
  printf("The Column Wise Matrix is: \n");
  for(int i=0; i<3; i++) {
    printf("%d column: ", i+1);
    for(int j=0; j<3; j++) {
      printf("%d ", arr[j][i]);
    }
    printf("\n");
  }
}


void add(int arr[3][3]){
  printf("Enter the dimension of the second matrix: ");
  int r,c;
  scanf("%d %d", &r, &c);
  if(r != c || r != 3 || c != 3) {
    printf("Invalid Dimensions");
    printf("...Aborting");
    return;
  }
  int arr2[3][3];
  printf("Enter the elements of the second matrix: ");
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      scanf("%d", &arr2[i][j]);
    }
  }
  printf("The sum of the matrices is: \n");
  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      printf("%d ", arr[i][j] + arr2[i][j]);
    }
    printf("\n");
  }
}

void multiply(int arr[3][3]){
  printf("Enter the dimension of the second matrix: ");
  int r,c;
  scanf("%d %d", &r, &c);
  if(r != c || r != 3 || c != 3) {
    printf("Invalid Dimensions");
    printf("...Aborting");
    return;
  }
  int arr2[3][3];
  printf("Enter the elements of the second matrix: ");
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      scanf("%d", &arr2[i][j]);
    }
  }
  printf("The product of the matrices is: \n");
  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      int sum = 0;
      for(int k=0; k<3; k++) {
        sum += arr[i][k] * arr2[k][j];
      }
      printf("%d ", sum);
    }
    printf("\n");
  }
}

int main() {
  int arr[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} }; 
  printf("Choose the operation: \n");
  printf("1. Display the Matrix \n");
  printf("2. Transpose\n");
  printf("3. Row Wise Display\n");
  printf("4. Column Wise Display\n");
  printf("5. Add 2 matrices\n");
  printf("6. Multiply 2 matrices\n");
  printf("7. Exit\n");
  int ch; 
  scanf("%d", &ch);
  switch(ch) {
    case 1: 
      display(arr);
      break;
    case 2: 
      transpose(arr);
      break;
    case 3: 
      row_wise(arr);
      break;
    case 4: 
      col_wise(arr);
      break;
    case 5: 
      add(arr);
      break;
    case 6: 
      multiply(arr);
      break;
    default: 
      printf("Invalid Choice");
      printf("Exiting...");
  }
  
  return 0;
}