//-mrdrnd -lstdc++

#include "rdrand.h"

#include <array>
#include <immintrin.h>

#ifdef _MSC_VER
#include <intrin.h>
	uint32_t rdrand_avilable(){
		std::array<int, 4> buffer{0};
		__cpuid(buffer.data(), 0);
		if (buffer[0] >= 1) {
			__cpuidex(buffer.data(), 1, 0);
			bool rdrand = (buffer[2] & (1 << 30)) != 0;
			return rdrand;
		}
		return false;
	}
#else
#include <cpuid.h>
	uint32_t rdrand_avilable()
	{
		std::array<int, 4> id{0};
		__cpuid(0, id[0], id[1], id[2], id[3]);
		if (id[0] >= 1) {
			__cpuid_count(0, 1, id[0], id[1], id[2], id[3]);
			bool rdrand = (id[2] & (1 << 30)) != 0;
			return rdrand;
		}
		return false;
	}
#endif


uint32_t rdrand_next()
{
	unsigned int number;
	while (1 != _rdrand32_step(&number)) {}
	return number;
}
