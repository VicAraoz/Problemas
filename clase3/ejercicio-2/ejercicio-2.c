#include <stdio.h>

int find_min_distance(int* nums, int nums_size) {
  int min_d = nums_size;
  for(int i = 0; i < nums_size; i++){ // O(n^2) peor caso

    for(int j = i+1; j < nums_size; j++){
      if(nums[i] == nums[j] && min_d > j - i){
          min_d = j-i;
          printf("%d\tJ: %d\tI: %d\n",min_d, j, i);
      }
    }

}
    return min_d == nums_size ? -1: min_d; // si es igual, da -1, si no, min
}

// TESTS
typedef struct {
  int *array;
  int size;
  int expected;
} TestCase;
void run_tests() {
  int test_1[] = {1, 2, 3, 5, 6};
  int test_2[] = {1, 1, 1, 1, 1};
  int test_3[] = {3, 2, 1, 2, 3};
  int test_4[] = {};
  int test_5[] = {1, 2, 3, 1, 2, 3};

  TestCase tests[] = {
      {test_1, sizeof(test_1) / sizeof(test_1[0]), -1},
      {test_2, sizeof(test_2) / sizeof(test_2[0]), 1},
      {test_3, sizeof(test_3) / sizeof(test_3[0]), 2},
      {test_4, sizeof(test_4) / sizeof(test_4[0]), -1},
      {test_5, sizeof(test_5) / sizeof(test_5[0]), 3}
  };

  int num_tests = sizeof(tests) / sizeof(tests[0]);

  for (int i = 0; i < num_tests; i++) {
      printf("Prueba %d: Distancia mínima obtenida = %d (Esperado: %d) \n", 
             i + 1, find_min_distance(tests[i].array, tests[i].size), tests[i].expected);
  }
}

int main() {
    run_tests();
    return 0;
}
