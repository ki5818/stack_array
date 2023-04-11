
#define MAX_CAPACITY 100

char stack[MAX_CAPACITY];
int top = -1; // index of the top element

int is_empty() {
	return top == -1;
}

int is_full() {
	return top == MAX_CAPACITY - 1;
}

void push(char ch) { // ch: ���ÿ� �ְ���� ������
	if (is_full()) // ������ �������� ���̻� push�� �� ����.
		return;
	top++;
	stack[top] = ch;
}

char pop() { // pop�� ȣ���ϱ� ���� ���� empty���� �˻��ؾ��Ѵ�.
	char tmp = stack[top];
	top--;
	return tmp;
}

char peek() {
	return stack[top];
}