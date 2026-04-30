# Reporte de Profiling - Bracket Solver Benchmark

Se realizó un análisis de profiling mediante gprof para comparar el rendimiento de dos algoritmos diseñados para encontrar la secuencia válida más larga de paréntesis en una cadena de caracteres.

**Tiempo Total de Ejecución:** 7.34 segundos  
**Pruebas Realizadas:** 6 benchmark (3 tests × 2 algoritmos, con repeticiones)

### Hallazgo Principal

El algoritmo no optimizado (`solveBracketsNonOptimized`) consume **99.73% del tiempo total de ejecución**, mientras que el algoritmo optimizado (`solveBracketsOptimized`) es prácticamente imperceptible.

---

## Resultados: Flat Profile

### Distribución de Tiempo por Función

| Rango | % CPU | Tiempo (s) | Función | Llamadas | ms/Llamada |
|-------|-------|-----------|---------|----------|-----------|
| 1 | **99.73%** | **7.32** | `solveBracketsNonOptimized()` | 9 | **813.33** |
| 2 | 0.27% | 0.02 | `_init` (inicialización) | - | - |
| 3 | **0.00%** | **0.00** | `solveBracketsOptimized()` | 9 | **< 0.01** |

### Interpretación

- **Algoritmo No Optimizado:** 7.32 segundos (99.73%)
  - 9 ejecuciones totales (3 tests × 3 repeticiones)
  - Promedio: 813.33 ms por ejecución
  - Clasificación: **Hotspot crítico**

- **Algoritmo Optimizado:** ~0.01 segundos (0.00%)
  - 9 ejecuciones totales (3 tests × 3 repeticiones)
  - Promedio: < 0.01 ms por ejecución
  - Clasificación: **Imperceptible**

---

### Llamadas Totales

| Función | Llamadas | Tiempo Individual | Tiempo Total |
|---------|----------|------------------|-------------|
| `solveBracketsNonOptimized` | 9 | 813.33 ms | 7.32 s |
| `solveBracketsOptimized` | 9 | < 0.01 ms | < 0.01 s |

---