#ifndef ONE_ONE_H
#define ONE_ONE_H

#include <cstdint>
#include <string>

#define LOG(X) printf("log: %s \n", X);
#define ERROR(X) printf("error: %s \n", X);

typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

#define sizeof_16 2;
#define sizeof_32 4;
#define sizeof_64 8;

#define oneIMPLEMENT_APP(X)                             \
int main()                                              \
{                                                       \
	X project;                                      \
	project.StartApplication();                     \
							\
	return 0;                                       \
}

#endif //ONE_ONE_H
