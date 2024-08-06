/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    *returnSize = n;
	char ** returnArr = (char**)malloc(sizeof(char*)*n);
    
	for (int i = 1; i <= n; i++) {
		if ((i % 3 == 0) && (i % 5 == 0)) {
            returnArr[i-1] = (char*)malloc(sizeof(char) * 9);
			strcpy(&returnArr[i - 1][0], "FizzBuzz");
		}
		else if (i % 5 == 0) {
            returnArr[i-1] = (char*)malloc(sizeof(char) * 5);
			strcpy(&returnArr[i-1][0],  "Buzz");;
		}
		else if (i % 3 == 0) {
            returnArr[i-1] = (char*)malloc(sizeof(char) * 5);
			strcpy(&returnArr[i - 1][0], "Fizz");;
		}
		else {
            returnArr[i-1] = (char*)malloc(sizeof(char) * 5);
			sprintf(&returnArr[i-1][0], "%d", i);
		}
	}
	return returnArr;
}