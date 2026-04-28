#include <cassert>
#include <string>
#include <vector>
#include <random>
#include "BracketStats.h"

int main() {
    // Casos explícitos extendidos
    std::vector<std::string> cases = {
        "()()()",
        "(()())",
        "())(())(())",
        "((()()))()",
        "()(()())(())",
        ")()()(()",
        "((()()((())))())"
    };

    for (const auto& s : cases) {
        PC2::BracketStats opt = PC2::solveBracketsOptimized(s);
        PC2::BracketStats nonopt = PC2::solveBracketsNonOptimized(s);
        assert(opt.maxLen == nonopt.maxLen);
        assert(opt.count == nonopt.count);
    }

    // Pruebas aleatorias deterministas (longitud pequeña para que nonopt termine)
    std::mt19937_64 rng(123456);
    std::uniform_int_distribution<int> lenDist(0, 20);
    std::uniform_int_distribution<int> charDist(0,1);

    for (int t = 0; t < 1000; ++t) {
        int L = lenDist(rng);
        std::string s; s.reserve(L);
        for (int i = 0; i < L; ++i) s.push_back(charDist(rng) ? '(' : ')');

        PC2::BracketStats opt = PC2::solveBracketsOptimized(s);
        PC2::BracketStats nonopt = PC2::solveBracketsNonOptimized(s);
        assert(opt.maxLen == nonopt.maxLen);
        assert(opt.count == nonopt.count);
    }

    // Verificaciones adicionales sobre propiedades
    {
        PC2::BracketStats r = PC2::solveBracketsOptimized("()()()()");
        assert(r.maxLen == 8);
    }

    return 0;
}
