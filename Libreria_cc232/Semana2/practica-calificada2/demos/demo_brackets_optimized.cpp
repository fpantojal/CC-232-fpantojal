#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <iomanip>
#include "BracketStats.h"

/**
 * Demo: Entender el algoritmo optimizado (O(N)) para encontrar
 * la secuencia mas larga de parentesis correctos.
 * 
 * Idea central: Un stack de indices rastrea los parentesis "no emparejados".
 * - Cuando vemos '(', lo metemos al stack.
 * - Cuando vemos ')', sacamos del stack:
 *   - Si queda vacio, este ')' no tiene pareja.
 *   - Si no queda vacio, ya tenemos una secuencia valida.
 */

void demo_step_by_step(const std::string& s) {
    std::cout << "\n=== ANALISIS PASO A PASO ===" << std::endl;
    std::cout << "Entrada: \"" << s << "\"" << std::endl;
    std::cout << "Longitud: " << s.length() << "\n" << std::endl;

    std::stack<int> indices;
    int maxLen = 0;
    int count = 1;
    int currentLen = 0;

    // El "piso" inicial es -1
    indices.push(-1);
    std::cout << "Paso 0: Inicializamos el stack con -1 (piso base)" << std::endl;
    std::cout << "  Stack: [-1]" << std::endl;

    for (int i = 0; i < (int)s.length(); ++i) {
        std::cout << "\n--- Indice " << i << ": Caracter '" << s[i] << "' ---" << std::endl;

        if (s[i] == '(') {
            indices.push(i);
            std::cout << "  Es '(': lo metemos al stack" << std::endl;
            std::cout << "  Stack: [";
            std::stack<int> temp = indices;
            std::vector<int> items;
            while (!temp.empty()) {
                items.push_back(temp.top());
                temp.pop();
            }
            for (int j = items.size() - 1; j >= 0; --j) {
                std::cout << items[j];
                if (j > 0) std::cout << ", ";
            }
            std::cout << "]" << std::endl;
        } else {
            // Es ')'
            std::cout << "  Es ')': lo sacamos del stack" << std::endl;
            indices.pop();

            if (indices.empty()) {
                // Este ')' no tiene pareja
                indices.push(i);
                std::cout << "  -> Stack quedo vacio: este ')' no tiene pareja." << std::endl;
                std::cout << "  -> Lo metemos como nuevo piso: " << i << std::endl;
            } else {
                // Encontramos una secuencia valida
                currentLen = i - indices.top();
                std::cout << "  -> Stack no vacio. Longitud valida encontrada:" << std::endl;
                std::cout << "  -> currentLen = " << i << " - " << indices.top() << " = " << currentLen << std::endl;

                if (currentLen > maxLen) {
                    maxLen = currentLen;
                    count = 1;
                    std::cout << "  -> NUEVA MAXIMA: maxLen = " << maxLen << ", count = " << count << std::endl;
                } else if (currentLen == maxLen && currentLen != 0) {
                    count++;
                    std::cout << "  -> Misma longitud: count = " << count << std::endl;
                }
            }

            std::cout << "  Stack: [";
            std::stack<int> temp = indices;
            std::vector<int> items;
            while (!temp.empty()) {
                items.push_back(temp.top());
                temp.pop();
            }
            for (int j = items.size() - 1; j >= 0; --j) {
                std::cout << items[j];
                if (j > 0) std::cout << ", ";
            }
            std::cout << "]" << std::endl;
        }
    }

    std::cout << "\n=== RESULTADO FINAL ===" << std::endl;
    std::cout << "Longitud maxima: " << maxLen << std::endl;
    std::cout << "Cantidad de veces: " << count << std::endl;
}

void demo_comparison(const std::string& s) {
    std::cout << "\n" << std::string(70, '=') << std::endl;
    std::cout << "COMPARACION: Paso a paso vs. Funcion optimizada" << std::endl;
    std::cout << std::string(70, '=') << std::endl;

    demo_step_by_step(s);

    std::cout << "\n" << std::string(70, '-') << std::endl;
    std::cout << "Resultado de la funcion optimizada:" << std::endl;
    std::cout << std::string(70, '-') << std::endl;

    PC2::BracketStats result = PC2::solveBracketsOptimized(s);
    std::cout << "  maxLen:     " << result.maxLen << std::endl;
    std::cout << "  count:      " << result.count << std::endl;
    std::cout << "  operations: " << result.operations << std::endl;
    std::cout << "  stackOps:   " << result.stackOps << std::endl;
}

int main() {
    std::cout << "\n" << std::string(70, '=') << "\n"
              << "    Demo: Algoritmo Optimizado de Parentesis Balanceados\n"
              << "    Usa Stack para O(N) en lugar de O(N^3)\n"
              << std::string(70, '=') << "\n" << std::endl;

    // Test cases
    std::vector<std::string> tests = {
        "()",        // Caso simple
        "(()",       // No todos emparejados
        "()(()",     // Multiples secuencias
        "",          // Vacio
        "(",         // Solo abiertos
        ")",         // Solo cerrados
        "()()",      // Multiples de igual longitud
        "((()))"     // Anidados
    };

    for (const auto& test : tests) {
        demo_comparison(test);
    }

    return 0;
}
