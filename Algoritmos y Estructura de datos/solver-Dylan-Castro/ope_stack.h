#ifndef OPE_STACK_H
#define OPE_STACK_H
#include <stack>
#include <string>
using namespace std;
template <typename T>
struct Ope_stack {
    stack<string> operator_stack;
};

#endif
