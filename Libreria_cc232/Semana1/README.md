# Semana 1

Temas base reforzados:

- modelo RAM
- costo temporal y espacial basico
- correctitud basica
- recursion vs iteracion
- ADT, interfaz e implementacion
- bubble sort: orden local/global, invariante, monotonicidad, finitud
- eficiencia y robustez con ejemplos pequenos

## Estructura autocontenida

Ya no depende de `externo/`.

### Cabeceras principales

- `include/sum.h`
- `include/power.h`
- `include/Fib.h`
- `include/count_ones.h`
- `include/max_algorithms.h`
- `include/bubble_sort.h`
- `include/reverse_utils.h`
- `include/gcd.h`
- `include/hanoi.h`
- `include/Semana1.h`

### Fuentes

- `src/sum.cpp`
- `src/power.cpp`
- `src/fibonacci.cpp`
- `src/count_ones.cpp`
- `src/max_algorithms.cpp`
- `src/bubble_sort.cpp`
- `src/reverse_utils.cpp`
- `src/gcd.cpp`
- `src/hanoi.cpp`

## Build

Desde la raiz del repo:

```bash
cmake -S . -B build
cmake --build build -j
ctest --test-dir build --output-on-failure
```

## Ejecutables

### Base
- `sem1_demo_sum`
- `sem1_demo_power`
- `sem1_demo_fibonacci`
- `sem1_test_public`
- `sem1_test_internal`
- `sem1_edge_cases`

### Pedagogicos agregados
- `sem1_demo_sum_explicado`
- `sem1_demo_adt_secuencia`
- `sem1_demo_bubblesort`
- `sem1_demo_maximos`
- `sem1_demo_countones`
- `sem1_demo_reverse_shift`
- `sem1_demo_gcd`
- `sem1_demo_hanoi`
- `sem1_test_public_extra`
- `sem1_test_internal_extra`

## Cobertura conceptual

Con estas piezas, la Semana 1 queda mejor preparada para explicar:

- algoritmo, entrada/salida y correctitud
- recursion lineal y recursion con multiples direcciones
- disminuir y conquistar
- orden local vs orden global
- peor caso, mejor caso e intuicion asintotica
- robustez por casos borde y reutilizacion basica
