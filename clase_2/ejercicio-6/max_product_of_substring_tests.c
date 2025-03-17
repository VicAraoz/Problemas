#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_product_of_substring(const char* str, int k) {
    int counter;
    int max = 0;
    long unsigned int length = strlen(str);
    for(int i = 0; i < length; i++){
        
        counter = 1;

        for(int j = i; j < i + k; j++){
            if(i + k <= length){
                // printf("%d\n", (str[j] - '0'));
                counter *=  (str[j] - '0');
            }
        }

        if (counter > max){
            max = counter;
        }
    }
    return max;
}

// TESTS
void run_tests() {
    char* str1 = "123456789";
    int k1 = 3;
    printf("Input: %s, k = %d\n", str1, k1);
    printf("Output: %d\n", max_product_of_substring(str1, k1));
    printf("Expected Output: 504\n");
    printf("\n");

    char* str2 = "11111";
    int k2 = 2;
    printf("Input: %s, k = %d\n", str2, k2);
    printf("Output: %d\n", max_product_of_substring(str2, k2));
    printf("Expected Output: 1\n");
    printf("\n");

    char* str3 = "987654321";
    int k3 = 4;
    printf("Input: %s, k = %d\n", str3, k3);
    printf("Output: %d\n", max_product_of_substring(str3, k3));
    printf("Expected Output: 3024\n");
    printf("\n");

    char* str4 = "0000";
    int k4 = 1;
    printf("Input: %s, k = %d\n", str4, k4);
    printf("Output: 0\n");
    printf("Expected Output: 0\n");
    printf("\n");
}

int main() {
    run_tests();
    return 0;
}
