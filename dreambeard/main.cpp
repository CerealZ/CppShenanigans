#include "past.hpp"
#include "signal.hpp"
#include "types.hpp"

void WriteLine(const i32 i, const i32 sum) {
	std::cout << i << " : " << sum << std::endl;
}

void Fibonacci(i32 n) {
	auto sum = Past(1);
	auto i = Signal<i32>(0, [&sum, n](Signal<i32>& i) {
		if (i < n) {
			sum = sum + sum.previous();
			i++;
		}
	});
	i++;
	WriteLine(i, sum);
}

int main()
{
	constexpr auto max_n = 19;

	auto n = Signal<i32>(-1, [max_n](Signal<i32>& n) {
		if (n == 0) {
			WriteLine(0, 0);
			n++;
			return;
		}
		if (n > max_n) {
			return;
		}
		Fibonacci(n);
		n++;
		});
	n++;

	return 0;
}
