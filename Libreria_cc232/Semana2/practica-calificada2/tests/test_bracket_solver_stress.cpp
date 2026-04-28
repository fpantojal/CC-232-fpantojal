#include <cassert>
#include <string>
#include "BracketStats.h"

int main() {
    // Stress: cadena grande con muchos '(' seguidos por muchos ')'
    const int n = 20000; // 20k opens + 20k closes = 40k chars
    std::string s;
    s.append(n, '(');
    s.append(n, ')');

    PC2::BracketStats res = PC2::solveBracketsOptimized(s);
    // Toda la cadena es una RBS
    assert(res.maxLen == 2 * n);
    assert(res.count == 1);
    // operaciones y stackOps deben ser positivas
    assert(res.operations > 0);
    assert(res.stackOps > 0);

    return 0;
}
