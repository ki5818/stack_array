#include <stdio.h>
#include <string.h>
#include "stack.h"
#pragma warning(disable:4996)

#define MAX_LENGTH 100

char OPEN[] = "([{";
char CLOSE[] = ")]}";

int is_balanced(char* expr);
int is_open(char ch);
int is_close(char ch);

int main() {
	char expr[MAX_LENGTH];
	
	scanf("%s", expr);

	if (is_balanced(expr))
		printf("%s: balanced.\n", expr);
	else
		printf("%s: unbalanced.\n", expr);

	

	return 0;
}

int is_balanced(char* expr) {
	int balanced = 1;
	int index = 0;
	while (balanced && index < strlen(expr)) {
		char ch = expr[index];
		if (is_open(ch) > -1) { // 여는 괄호는 스택에 push한다.
			push(ch);
		}
		else if (is_close(ch) > -1) {
			if (is_empty()) {
				balanced = 0;
				break;
			}
			char top_ch = pop(); // 닫는 괄호가 나오면 스택에서 pop하여
			if (is_open(top_ch) != is_close(ch)) { // 같은 유형의 괄호인지 검사한다. 
				balanced = 0;
			}
		}
		index++;
	}
	return (balanced == 1 && is_empty() == 1);

}

int is_close(char ch) {
	for (int i = 0; i < strlen(CLOSE); i++) {
		if (CLOSE[i] == ch) // 소괄호는 0, 대괄호는 1, 중괄호는 2를 반환하고
			return i;
	}
	return -1; // 여는 괄호가 아니면 -1을 반환한다.
}

int is_open(char ch) {
	for (int i = 0; i < strlen(OPEN); i++) {
		if (OPEN[i] == ch) 
			return i;
	}
	return -1;
}
