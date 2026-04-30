## PC2 - CC232

### Estudiante
- Nombre: Pantoja Limache, Fabio Alberto
- Código: 20152212E
- Problema asignado: Longest Regular Bracket Sequence
- Enlace: https://codeforces.com/problemset/problem/5/C

### Referencia oficial
- Archivo de asignación:
  https://github.com/kapumota/CC-232/blob/main/Practicas/Practica2_CC232/Problemas-Evaluacion2.csv

### Tema principal
- Semana: 2
- Estructura o técnica principal: Algoritmo Optimizado (stack)

### Resumen de la solución
El objetivo de este proyecto es encontrar la longitud de la secuencia de paréntesis regulares (RBS) más larga en una cadena dada y contar cuántas veces aparece dicha longitud máxima. Para ello, se han implementado y comparado dos enfoques distintos:
- Enfoque de Fuerza bruta - $O(n^3)$ 
    - Funcionamiento: utiliza dos bucles anidados para generar los limites de cada subcadena y un tercer proceso, de validacion, que recorre la subcadena par verficar si es regular.
    - Limitacion: debido a su complejidad  cubica. el tiempo de ejecucion se dispara rapidamente.
    - Costo de memoria: se ha contabilizado el costo de asignacion y copiado de memoria al generar cada substring, lo que refleja la ineficiencia real de este metodo. 
- Enfoque optimizado: (basado en pila) - $O(n)$
    - Funcionamiento: se recorre la cadena una sola vez, se mantiene un indice base en la pila para calcular las longitudes de forma instantanea al encontrar un cierre `)`. Si la pila se vacia, el indice actual se convierte en la nueva base.
    - Ventaja: al procesar cada caracter una unica vez y no realizar copias de cadenas, el algoritmo maneja de hasta $10^6$ caracteres de forma instantanea.



### Complejidad

#### solveBracketsNonOptimized (Fuerza Bruta)
- **Tiempo:** $O(n^3)$
  - Dos bucles anidados para generar todas las subcadenas posibles: $O(n^2)$
  - Para cada subcadena: creación con `substr()` en $O(n)$ + validación en `isValid()` en $O(n)$
  - Total: $O(n^2) \times O(n) = O(n^3)$
  
- **Espacio:** $O(n)$
  - La variable `sub` almacena una copia de la subcadena en $O(n)$ en el peor caso
  - Otras variables utilizan espacio $O(1)$

#### solveBracketsOptimized (Stack)
- **Tiempo:** $O(n)$
  - Un único recorrido lineal de la cadena: $O(n)$
  - Operaciones de stack (push/pop) en $O(1)$ cada una
  - Total: $O(n)$
  
- **Espacio:** $O(n)$
  - La pila almacena índices, con máximo $n$ elementos en el peor caso
  - Otras variables utilizan espacio $O(1)$

### Invariante o idea clave

**Método No Optimizado:**
- Invariante: Después de procesar cada par $(i, j)$, se ha validado completamente si `s[i...j]` es una RBS.
- Propiedad: Se examina exhaustivamente toda combinación posible de subcadenas.

**Método Optimizado (Stack):**
- Invariante: La pila siempre contiene los índices de paréntesis no emparejados, manteniendo al fondo el índice "suelo" de la última secuencia válida.
- Propiedad: Cuando se encuentra un `)`, la diferencia entre el índice actual y el tope de la pila proporciona directamente la longitud de la RBS que termina en ese punto.

### Archivos relevantes
- **include/BracketStats.h** - Estructura de datos para almacenar resultados
- **include/mini_bench.h** - Utilities para benchmarking y medición de tiempo
- **src/BracketSolver.cpp** - Implementación de ambos algoritmos
- **src/main.cpp** - Programa principal
- **benchmark/bench_bracket_solver.cpp** - Harness de benchmarking para comparación
- **tests/** - Suite de pruebas unitarias
  - test_bracket_solver_basic.cpp
  - test_bracket_solver_extended.cpp
  - test_bracket_solver_stress.cpp
- **demos/** - Programas demostrativos
  - demo_brackets_optimized.cpp
  - demo_brackets_nonoptimized.cpp
  - demo_brackets_comparison.cpp

### Compilación
```bash
# Desde el directorio practica-calificada2
cmake -S . -B build
cmake --build build
```

### Ejecución

**Programa principal:**
```bash
# Desde el directorio practica-calificada2
# input.txt contiene una cadena de caracteres `(` y `)`
./build/main < input.txt
```

**Benchmarking (con profiling):**
```bash
# Compilar con profiling
g++ -pg -g -O2 -fno-omit-frame-pointer -Iinclude src/BracketSolver.cpp benchmark/bench_bracket_solver.cpp -o benchmark/bench_bracket_solver

# Ejecutar
./benchmark/bench_bracket_solver

# Generar reporte gprof
gprof -b ./benchmark/bench_bracket_solver gmon.out > resultados/gprof_report_bench_bracket_solver.txt
```

**Pruebas:**
```bash
./build/test_bracket_solver_basic.exe
./build/test_bracket_solver_extended.exe
./build/test_bracket_solver_stress.exe
```

### Casos de prueba

1. **Caso simple:** `"(())"`
   - Entrada: cadena balanceada simple
   - Salida esperada: maxLen = 4, count = 1

2. **Caso con no balanceados:** `"(())()(())"`
   - Entrada: múltiples secuencias válidas contiguas
   - Salida esperada: maxLen = 10, count = 1 (toda la cadena es válida)

3. **Caso con caracteres sin pareja:** `"(()()()"`
   - Entrada: paréntesis de apertura sin cerrar
   - Salida esperada: maxLen = 6, count = 1 (la subsecuencia "(()())")

### Historial de commits

El historial completo de commits se puede ver ejecutando:
```bash
git log --oneline
```

Commits principales:
- Implementación de ambos algoritmos
- Adición de suite de pruebas
- Benchmarking y profiling
- Análisis de rendimiento con gprof
- Documentación

### Declaración de autoría
Declaro que entiendo el código entregado, que puedo explicarlo, compilarlo, ejecutarlo y modificarlo sin ayuda externa durante la grabación.