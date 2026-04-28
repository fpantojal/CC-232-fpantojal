#pragma once

#include <string>
namespace PC2
{
    struct BracketStats
    {
        int maxLen = 0;      // La longitud máxima encontrada
        int count = 1;       // Cuántas veces aparece esa longitud
        long long operations = 0; // Conteo total de operaciones (comparaciones/iteraciones)
        long long stackOps = 0;   // Para el método óptimo: push/pops realizados
    };

    BracketStats solveBracketsOptimized(const std::string& s);
    BracketStats solveBracketsNonOptimized(const std::string& s);

} // namespace PC2

