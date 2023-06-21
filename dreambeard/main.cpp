#include "Past.hpp"
#include "signal.hpp"
#include "types.hpp"

int main()
{
	constexpr auto max_n = 19;
	for (auto n = 0; n <= max_n; ++n) {
		if (n == 0) {
			std::cout << "0 : 0" << std::endl;
			continue;
		}

		auto sum = Past(1);
		auto outer_i = Signal<i32>(0, [&sum, n](Signal<i32>& i) {
			if (i < n) {
				sum = sum + sum.previous();
				i++;
			}
		});
		outer_i++;
		std::cout << outer_i << " : " << sum << std::endl;
	}

	return 0;
}
