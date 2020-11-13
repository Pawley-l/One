#ifndef ONE_ONE_H
#define ONE_ONE_H

#include <cstdint>
#include <string>
#include <stdexcept>

#define LOG(X) printf("log: %s \n", X);
#define ERROR(X) printf("error: %s \n", std::string(X).c_str());

typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

#define oneIMPLEMENT_APP(X)                             \
int main()                                              \
{                                                       \
        X project;                                      \
        project.StartApplication();                     \
                                                        \
        return 0;                                       \
}

class NotImplementedException : public std::logic_error
{
public:
	NotImplementedException() : logic_error("NotImplementedException")
	{}

	virtual char const *what()
	{ return "Call to unimplemented function or method! \n"; }
};

#endif //ONE_ONE_H
