#include <cassert>
#include "BracketStats.h"

int main() {
    // Test caso simple: "()"
    {
        PC2::BracketStats result = PC2::solveBracketsOptimized("()");
        assert(result.maxLen == 2);
        assert(result.count == 1);
    }

    // Test caso simple no optimizado
    {
        PC2::BracketStats result = PC2::solveBracketsNonOptimized("()");
        assert(result.maxLen == 2);
        assert(result.count == 1);
    }

    // Test casos incompletos: "(()"
    {
        PC2::BracketStats result = PC2::solveBracketsOptimized("(()");
        assert(result.maxLen == 2);
        assert(result.count == 1);
    }

    // Test vacio: ""
    {
        PC2::BracketStats result = PC2::solveBracketsOptimized("");
        assert(result.maxLen == 0);
        assert(result.count == 1);
    }

    // Test solo abiertos: "("
    {
        PC2::BracketStats result = PC2::solveBracketsOptimized("(");
        assert(result.maxLen == 0);
        assert(result.count == 1);
    }

    // Test solo cerrados: ")"
    {
        PC2::BracketStats result = PC2::solveBracketsOptimized(")");
        assert(result.maxLen == 0);
        assert(result.count == 1);
    }

    // Test multiples secuencias validas: "()()"
    {
        PC2::BracketStats result = PC2::solveBracketsOptimized("()()");
        assert(result.maxLen == 4);
        assert(result.count == 1);
    }

    // Test anidados: "((()))"
    {
        PC2::BracketStats result = PC2::solveBracketsOptimized("((()))");
        assert(result.maxLen == 6);
        assert(result.count == 1);
    }

    // Validar que ambos metodos dan el mismo resultado para casos pequenos
    {
        const std::string tests[] = {"()", "(()","()()","((()))", "", "(", ")", "()(()"};
        for (const auto& test : tests) {
            PC2::BracketStats opt = PC2::solveBracketsOptimized(test);
            PC2::BracketStats nonopt = PC2::solveBracketsNonOptimized(test);
            assert(opt.maxLen == nonopt.maxLen);
            assert(opt.count == nonopt.count);
        }
    }

    // Test que operations sea positivo para optimizado
    {
        PC2::BracketStats result = PC2::solveBracketsOptimized("()()()");
        assert(result.operations > 0);
    }

    // Test que stackOps sea positivo para optimizado
    {
        PC2::BracketStats result = PC2::solveBracketsOptimized("((()))");
        assert(result.stackOps > 0);
    }

    return 0;
}
