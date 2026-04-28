#include <iostream>
#include <string>
#include <iomanip>
#include "BracketStats.h"

void imprimirFila(const std::string& metodo, const PC2::BracketStats& stats) {
    std::cout << std::left << std::setw(20) << metodo 
              << std::setw(10) << stats.maxLen 
              << std::setw(10) << stats.count 
              << std::setw(20) << stats.operations 
              << std::setw(15) << stats.stackOps << std::endl;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string input;
    if (!(std::cin >> input)) return 0;

    PC2::BracketStats statsOpt = PC2::solveBracketsOptimized(input);
    
    PC2::BracketStats statsNonOpt;
    bool ejecutóNonOpt = false;
    if (input.length() < 2000) { 
        statsNonOpt = PC2::solveBracketsNonOptimized(input);
        ejecutóNonOpt = true;
    }

    // salida de codeforces
    // Lo que pide el problema: maxLen count
    std::cout << statsOpt.maxLen << " " << statsOpt.count << "\n\n";

    // estadisticas
    std::cout << "Resumen de Analisis de Complejidad:" << std::endl;
    std::cout << std::string(75, '-') << std::endl;
    std::cout << std::left << std::setw(20) << "Metodo" 
              << std::setw(10) << "MaxLen" 
              << std::setw(10) << "Count" 
              << std::setw(20) << "Operations" 
              << std::setw(15) << "StackOps" << std::endl;
    std::cout << std::string(75, '-') << std::endl;

    imprimirFila("Optimizado (O(N))", statsOpt);
    
    if (ejecutóNonOpt) {
        imprimirFila("No Optimizado", statsNonOpt);
    } else {
        std::cout << "No Optimizado: Saltado (Cadena demasiado larga para O(N^3))" << std::endl;
    }
    std::cout << std::string(75, '-') << std::endl;

    return 0;
}