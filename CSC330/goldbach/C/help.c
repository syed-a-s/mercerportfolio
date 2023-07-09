#include <stdio.h>
#include <cstdlib>

void func(int *var, int size) { 

      for(int i = 0; i < size; i++) { 
            var[i] = i + 5;
      }

}

void Resize(int **p, int size) {
      free(*p);
      *p = (int*)malloc(size * sizeof(int));
} 

int main(void) {

      int size, userInput;
      scanf("%d", &userInput);
      int *a = (int*)malloc(userInput * sizeof(int));
      printf("%d", sizeof(a) / sizeof(a[0]));
      Resize(&a, 20);
      printf("%d", sizeof(a) / sizeof(a[0]));
      
}
