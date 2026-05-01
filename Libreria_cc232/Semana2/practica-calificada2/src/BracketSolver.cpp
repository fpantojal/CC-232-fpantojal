#include "BracketStats.h"
#include <stack>
#include <string>

namespace PC2
{
    bool isValid(const std::string& sub, long long& ops) {
        int balance = 0;
        for (char c : sub) {
            ops++; // Cada carácter revisado cuenta como operación
            if (c == '(') balance++;
            else balance--;
            
            if (balance < 0) return false; // Se cerró uno que no se abrió
        }
        return balance == 0;
    }
    // Implementación no optimizada: búsqueda exhaustiva
    BracketStats solveBracketsNonOptimized(const std::string& s)
    {
        BracketStats stats;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; j += 2) { // j+=2 porque solo longitudes pares son RBS
                stats.operations++; // Contamos cada subcadena intentada
                int subLen = j - i + 1;
                std::string sub = s.substr(i, subLen);
                stats.operations += subLen; // Contamos las operaciones de validación dentro de isValid
                if (isValid(sub, stats.operations)) {
                    int currentLen = sub.length();
                    
                    if (currentLen > stats.maxLen) {
                        stats.maxLen = currentLen;
                        stats.count = 1;
                    } else if(currentLen == stats.maxLen && currentLen != 0){
                        stats.count++;
                    }
                }
            }
        }
        return stats;
    }

    // Implementación optimizada: usando stack
    BracketStats solveBracketsOptimized(const std::string& s)
    {
        BracketStats stats;
        std::stack<int> indices;
        
        // El "piso" inicial es -1. Si cerramos un paréntesis en el índice 0, 
        // la longitud será 0 - (-1) = 1 (pero como son pares, el primero válido será en el índice 1).
        indices.push(-1); 
        stats.stackOps++; // Contamos el push inicial

        for (int i = 0; i < (int)s.length(); ++i) {
            stats.operations++; // Una operación por cada carácter del string

            if (s[i] == '(') {
                indices.push(i);
                stats.stackOps++;
            } else {
                // Es un ')'
                indices.pop();
                stats.stackOps++;

                if (indices.empty()) {
                    // Si se vacía, este ')' no tiene pareja y se vuelve el nuevo "suelo"
                    indices.push(i);
                    stats.stackOps++;
                } else {
                    // ¡Encontramos una secuencia válida!
                    // La longitud es la distancia desde el índice actual 
                    // hasta el último índice que no pudimos emparejar.
                    int currentLen = i - indices.top();
                    
                    if (currentLen > stats.maxLen) {
                        stats.maxLen = currentLen;
                        stats.count = 1;
                    } else if (currentLen == stats.maxLen && currentLen != 0) {
                        stats.count++;
                    }
                }
            }
        }
        
        // Si maxLen sigue siendo 0, count debe ser 1 (ya inicializado en el struct)
        return stats;
    }
} // namespace PC2
