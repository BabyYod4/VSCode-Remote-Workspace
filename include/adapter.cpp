#include "adapter.h"

class SUM{
public:
    SUM() = default;
    int add10(int i){ return i+10; }
};

static class SUM sum;

void test(int i){
    printf( "Hello %i", sum.add10(i) );
}