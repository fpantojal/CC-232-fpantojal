#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "BracketStats.h"

/**
 * Demo: Comparacion entre el algoritmo optimizado y el no optimizado.
 *
 * Usa el mismo conjunto de pruebas para verificar que ambas funciones
 * producen el mismo resultado sobre entradas pequenas.
 */

void imprimir_resultado(const std::string& titulo, const PC2::BracketStats& stats) {
    std::cout << std::left << std::setw(22) << titulo
              << std::setw(10) << stats.maxLen
              << std::setw(10) << stats.count
              << std::setw(14) << stats.operations
              << std::setw(12) << stats.stackOps
              << std::endl;
}

void comparar_caso(const std::string& s) {
    const PC2::BracketStats optimizado = PC2::solveBracketsOptimized(s);
    const PC2::BracketStats no_optimizado = PC2::solveBracketsNonOptimized(s);

    std::cout << "\n" << std::string(74, '-') << std::endl;
    std::cout << "Entrada: " << (s.empty() ? "<vacia>" : s) << std::endl;
    std::cout << std::string(74, '-') << std::endl;
    std::cout << std::left << std::setw(22) << "Metodo"
              << std::setw(10) << "MaxLen"
              << std::setw(10) << "Count"
              << std::setw(14) << "Operations"
              << std::setw(12) << "StackOps"
              << std::endl;
    std::cout << std::string(74, '-') << std::endl;

    imprimir_resultado("Optimizado", optimizado);
    imprimir_resultado("No optimizado", no_optimizado);

    const bool mismo_resultado =
        optimizado.maxLen == no_optimizado.maxLen &&
        optimizado.count == no_optimizado.count;

    std::cout << std::string(74, '-') << std::endl;
    std::cout << "Coinciden resultados: " << (mismo_resultado ? "SI" : "NO") << std::endl;
}

int main() {
    std::cout << "\n" << std::string(74, '=') << "\n"
              << "    Demo: Comparacion de soluciones de parentesis balanceados\n"
              << "    Optimizado vs No optimizado\n"
              << std::string(74, '=') << "\n" << std::endl;

    // Mismos casos de prueba que las otras demos
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
        comparar_caso(test);
    }

    return 0;
}
