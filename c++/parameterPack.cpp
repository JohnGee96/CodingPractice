// Problem link: 
// https://www.hackerrank.com/challenges/cpp-variadics/problem
#include <iostream>
using namespace std;

// Variadic Templates recursion, less efficient:

template <bool a> 
int reversed_binary_value() { return a; }

template <bool a, bool b, bool... d>
int reversed_binary_value() {
  return (reversed_binary_value<b, d...>() << 1) + a;
}

// shorter version, without recursion
template<bool... digits>
int reversed_binary_value()
{
    uint64_t pos = 1;
    uint64_t result = 0;
    auto _ = { (result += digits * pos, pos <<= 1)... };
    return result;
}

template<bool... digits>
int reversed_binary_value()
{
    int result = 0;
    int pos = 1;
    auto list = {digits...};
    for (auto digit: list) {
        result += digit * pos;
        pos <<= 1;
    }
    return result;
}

template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
}