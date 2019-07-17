#include <functional>

typedef std::function<int(int, int)> func_t;

typedef struct __operation_t {
	char operation;
	func_t func;
} operation_t;

void set_bit(int& value, size_t bitNumber, bool enabled);

int add(int first, int second);
int divide(int first, int second);
int multiply(int first, int second);
int subtract(int first, int second);

