
#define MAX_CAPACITY 100

char stack[MAX_CAPACITY];
int top = -1; // index of the top element

int is_empty() {
	return top == -1;
}

int is_full() {
	return top == MAX_CAPACITY - 1;
}

void push(char ch) { // ch: 스택에 넣고싶은 데이터
	if (is_full()) // 스택이 가득차면 더이상 push할 수 없다.
		return;
	top++;
	stack[top] = ch;
}

char pop() { // pop을 호출하기 전에 먼저 empty인지 검사해야한다.
	char tmp = stack[top];
	top--;
	return tmp;
}

char peek() {
	return stack[top];
}