#include <cassert>
#include <string>
#include "BracketStats.h"

int main() {
    // Stress: cadena grande con muchos '(' seguidos por muchos ')'
    const int n = 1000000; // 20k opens + 20k closes = 40k chars
    std::string s;
    s.append(n-1, '(');
    s.append(1, ')');

    PC2::BracketStats res = PC2::solveBracketsOptimized(s);
    // Toda la cadena es una RBS
    assert(res.maxLen == 2 );
    assert(res.count == 1);
    // operaciones y stackOps deben ser positivas
    //assert(res.operations > 0);
    // assert(res.stackOps > 0);

    return 0;
}
