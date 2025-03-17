#include <stdio.h>

int find_missing_number(int* nums, int nums_size) {
    for (int i = 0; i < nums_size; i++){
        if(nums[nums_size -1 - i] != nums[nums_size - 1] - i){
            return nums[nums_size-1] - i;
        }

    }
    if( nums[0] != 1){
        return 1;
    }
    return nums_size + 1;
}

// TESTS
void run_tests() {
    int test_1[] = {1, 2, 3, 5, 6};
    int size_1 = sizeof(test_1) / sizeof(test_1[0]);
    printf("Prueba 1: Primer número faltante = %d (Esperado: 4) \n", find_min_distance(test_1, size_1));
    
    int test_2[] = {1, 2, 3, 4, 5};
    int size_2 = sizeof(test_2) / sizeof(test_2[0]);
    printf("Prueba 2: Primer número faltante = %d (Esperado: 6) \n", find_min_distance(test_2, size_2));
    
    int test_3[] = {2, 3, 4, 5, 6};
    int size3 = sizeof(test_3) / sizeof(test_3[0]);
    printf("Prueba 3: Primer número faltante = %d (Esperado: 1) \n", find_min_distance(test_3, size3));
    
    int test_4[] = {3, 4, 5, 6, 7};
    int size_4 = sizeof(test_4) / sizeof(test_4[0]);
    printf("Prueba 4: Primer número faltante = %d (Esperado: 1) \n", find_min_distance(test_4, size_4));
}

int main() {
    run_tests();
    return 0;
}
