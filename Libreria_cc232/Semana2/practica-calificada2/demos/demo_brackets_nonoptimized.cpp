#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "BracketStats.h"

/**
 * Demo: Entender el algoritmo no optimizado para encontrar
 * la secuencia mas larga de parentesis correctos.
 *
 * Idea central: probar todas las subcadenas pares posibles y verificar
 * si son secuencias correctas.
 */

void imprimir_resultado(const std::string& entrada, const PC2::BracketStats& stats) {
    std::cout << std::string(70, '-') << std::endl;
    std::cout << "Entrada: " << (entrada.empty() ? "<vacia>" : entrada) << std::endl;
    std::cout << "maxLen:     " << stats.maxLen << std::endl;
    std::cout << "count:      " << stats.count << std::endl;
    std::cout << "operations: " << stats.operations << std::endl;
    std::cout << "stackOps:   " << stats.stackOps << std::endl;
}

void demo_test(const std::string& s) {
    std::cout << "\n=== PRUEBA NO OPTIMIZADA ===" << std::endl;
    PC2::BracketStats result = PC2::solveBracketsNonOptimized(s);
    imprimir_resultado(s, result);
}

int main() {
    std::cout << "\n" << std::string(70, '=') << "\n"
              << "    Demo: Algoritmo No Optimizado de Parentesis Balanceados\n"
              << "    Prueba todas las subcadenas pares posibles\n"
              << std::string(70, '=') << "\n" << std::endl;

    // Mismos casos de prueba que la demo optimizada
    std::vector<std::string> tests = {
        "()",
        "(()",
        "()(()",
        "",
        "(",
        ")",
        "()()",
        "((()))"
    };

    for (const auto& test : tests) {
        demo_test(test);
    }

    return 0;
}
