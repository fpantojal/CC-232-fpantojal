## Actividad 3 - Semana3

### Estudiante

- Nombre: Pantoja Limache, Fabio Alberto

#### Bloque 1

1. Al pasar de almacenamiento contiguo a dinámico, dejamos de depender de un bloque continuo y pasamos a nodos enlazados por punteros. Eso facilita crecimiento local sin mover todo, pero cambia la forma de acceso.
2. Acceso por rango (arreglo) usa índice directo y suele ser O(1). Acceso por posición/enlace (listas) requiere recorrer nodos hasta llegar al índice, por eso depende de la posición.
3. En listas enlazadas, insertar/eliminar localmente solo ajusta punteros (luego de ubicar posición). En arreglos, insertar/eliminar en medio desplaza muchos elementos.
4. `SLList` implementa bien Stack y Queue porque tiene operaciones eficientes en extremos: `push/pop` en cabeza y `add` al final con `tail`, más `remove` en cabeza.
5. Un `Deque` pide eficiencia simétrica en ambos extremos; en `SLList` quitar por el final no es natural porque no hay puntero al anterior de `tail`.
6. El nodo centinela `dummy` en `DLList` elimina casos borde de vacío/primer/último nodo: las operaciones siempre enlazan alrededor de un nodo válido.
7. `DLList` usa `getNode(i)` empezando desde inicio o fin según convenga. Por eso el costo se justifica como O(1 + min(i, n-i)).
8. La idea espacial de `SEList` es agrupar elementos en bloques (`BDeque`) enlazados: no es ni nodo por elemento puro ni arreglo global puro.
9. `SEList` reutiliza `ArrayDeque` dentro de cada bloque para tener operaciones locales eficientes (insertar/quitar dentro del bloque) sin reimplementar toda la lógica del deque de bloque.
10. `DengList` aporta operaciones de lista más “ADT completo” (sort, dedup, reverse, contains, etc.) y sirve como refuerzo/puente. No reemplaza a Morin porque Morin cubre la estructura base y sus invariantes.

#### Bloque 2


| Archivo | Salida u observable importante | Idea estructural | Argumento de costo, espacio o diseño |
|---|---|---|---|
| `demo_sllist.cpp` | `add(10), add(20), push(5)` luego `peek/pop/remove` | Misma estructura soporta patrón pila y cola | Operaciones en cabeza/cola O(1) |
| `demo_dllist.cpp` | Queda `10 20 30` tras insertar en posición 1 | Inserción posicional con lista doble y centinela | Ubicación O(min(i,n-i)), enlace local O(1) |
| `demo_selist.cpp` | Imprime `0 10 20 ... 90` con bloques de 3 | Orden lógico global con almacenamiento por bloques | Trade-off acceso/actualización vía tamaño de bloque |
| `demo_deng_list.cpp` | `front`, `back`, luego `sort()` y vector ordenado | Lista enriquecida tipo ADT | Reutiliza algoritmos sobre interfaz de lista |
| `demo_morin_deng_bridge.cpp` | `stable_sort_with_deng` y `dedup_with_deng` sobre `DLList` | Puente de conversión Morin↔Deng | Conversión O(n) + algoritmo Deng |
| `demo_min_structures.cpp` | `min()` en stack/queue/deque | Metadatos de mínimo acumulado | Consultas `min()` en O(1) |
| `demo_linked_adapters.cpp` | Stack/Queue/Deque funcionando | Adaptadores sobre estructuras base | Reutilización sin duplicar estructura |
| `demo_contiguous_vs_linked.cpp` | Comparación FIFO, extremos y `get(4)` | Contraste contiguo vs enlazado | Localidad vs flexibilidad de enlaces |
| `demo_xor_list.cpp` | Recorrido y extremos en `XorList` | Un solo campo enlace por XOR | Menos punteros, más complejidad práctica |
| `demo_capitulo3_panorama.cpp` | Todas las estructuras “cargadas correctamente” | Visión integrada del capítulo | Coherencia global de diseño |



1. La secuencia `add(10), add(20), push(5)` + `pop()` + `remove()` muestra claro que `SLList` combina comportamiento tipo pila (cabeza) y cola (encolar al final, desencolar por cabeza).
2. En `demo_dllist.cpp`, `d.add(1, 20)` sobre `10 30` evidencia mejor la inserción intermedia (resultado `10 20 30`).
3. En `demo_selist.cpp`, el recorrido por índice imprime en orden lógico creciente pese a estar almacenado por bloques internos.
4. En `demo_deng_list.cpp`, la evidencia fuerte es que además de push/front/back también tiene `sort()` y conversión a vector.
5. En `demo_morin_deng_bridge.cpp`, la parte clave es usar `stable_sort_with_deng` y `dedup_with_deng` directamente sobre `DLList`.
6. En `demo_min_structures.cpp`, no solo se guardan valores: se guarda información adicional (mínimos acumulados) para responder `min()` al instante.
7. En `demo_linked_adapters.cpp`, `LinkedDeque` representa mejor la idea de adaptar una estructura existente (`DLList`) para exponer nueva interfaz.
8. En `demo_contiguous_vs_linked.cpp`, se observa que contiguo favorece localidad/acceso por índice, y enlazado favorece inserción/eliminación local por enlaces.

#### Bloque 3

1. `test_public_week3.cpp` valida en `SLList`: `add`, `push`, `peek`, `pop`, `remove`, `size`.
2. Para `DLList` valida: inserción posicional (`add(i,x)`), `get`, `remove(i)` y tamaño.
3. Para `SEList` valida: `add(i,x)`, `get`, `set`, `remove(i)` y `size`.
4. `test_public_extras.cpp` cubre extras: `secondLast`, `reverse`, `checkSize` (SLList), `rotate` e `isPalindrome` (DLList), además de `MinStack`, `MinQueue`, `MinDeque` y `XorList`.
5. `test_public_linked_adapters.cpp` valida semántica de `LinkedStack` (LIFO), `LinkedQueue` (FIFO) y `LinkedDeque` (doble extremo).
6. `test_public_deng_bridge.cpp` demuestra integración: `DengList` opera como lista enriquecida y el puente aplica sort/dedup/reverse a `DLList`/`SEList` mediante conversión.
7. `stress_selist_week3.cpp` estresa crecimiento (500 inserciones), borrado repetido al frente (250) y reinserción (100), verificando mantenimiento de tamaño lógico final.
8. Una prueba pública sí demuestra correctitud funcional en escenarios representativos y compatibilidad de interfaz.
9. Una prueba pública no demuestra por sí sola complejidad asintótica, ausencia total de fugas ni explicación de invariantes internos.
10. Pasar pruebas no reemplaza explicar invariantes/punteros/complejidad porque la sustentación pide justificar por qué funciona y cuánto cuesta, no solo que “pasó casos”.

#### Bloque 4

1. En `SLList`, `head` apunta al primero, `tail` al último y `n` al número de elementos.
2. `push`: cambia `head` (y `tail` si estaba vacía). `pop/remove`: mueve `head` y puede limpiar `tail` si queda vacía. `add`: usa `tail->next` y actualiza `tail`. `add(i,x)`: ajusta `next` del nodo previo y del nuevo nodo.
3. `secondLast()` recorre desde `head` hasta el nodo cuyo `next` es `tail`; no basta mirar `tail` porque en lista simple no hay puntero al anterior.
4. `reverse()` recorre una vez con tres punteros (`prev`, `curr`, `next`) invirtiendo enlaces; no necesita estructura auxiliar porque reutiliza los nodos existentes.
5. `checkSize()` recorre nodos reales y compara con `n`; además verifica consistencia de `head`/`tail`.
6. En `DLList`, `getNode(i)` decide ruta corta: desde `dummy.next` o desde `dummy.prev`.
7. En `addBefore`, se actualizan cuatro enlaces (`u->prev->next`, `u->next->prev`, y enlaces de `u`). El centinela evita casos borde especiales.
8. `rotate(r)` no mueve datos elemento por elemento: reubica enlaces para cambiar qué nodo queda como primero/luego del `dummy`.
9. `isPalindrome()` compara simultáneamente desde extremos (`left` y `right`) gracias al doble enlace.
10. En `SEList`, `Location` representa (nodo de bloque, índice dentro del bloque).
11. `spread()` redistribuye cuando hay saturación de bloques cercanos; `gather()` compacta cuando hay subocupación.
12. El tamaño `b` controla trade-off: bloques más grandes mejoran salto entre bloques pero encarecen ajustes internos; bloques pequeños hacen lo contrario.

#### Bloque 5

1. `LinkedStack` reutiliza `SLList` mapeando `push/pop/top` a `push/pop/peek`.
2. `LinkedQueue` reutiliza `SLList` mapeando `add/remove/front` a `add/remove/peek`.
3. `LinkedDeque` se apoya naturalmente en `DLList` porque necesita operaciones eficientes en ambos extremos.
4. En `MinStack`, cada entrada guarda valor y mínimo acumulado para responder `min()` en O(1).
5. `MinQueue` usa dos pilas (`in_`, `out_`) para conservar FIFO y aun así consultar mínimo combinando mínimos de ambas.
6. En `MinDeque`, el rebalanceo evita que un lado quede vacío ante operaciones por extremos; reconstruye distribución entre `front_` y `back_`.
7. Implementar estructura = diseñar nodos/enlaces/invariantes desde cero. Adaptar estructura = reutilizar una ya correcta para exponer otra interfaz (ej. LinkedQueue sobre SLList).
8. Constantes defendibles: operaciones básicas de `MinStack` y extremos directos de adaptadores. Amortizadas: transferencias/rebalanceos de `MinQueue` y `MinDeque`.

#### Bloque 6

1. En `DengList` se refuerzan operaciones como `contains`, `find_index`, `sort`, `dedup`, `uniquify`, `reverse` además de operaciones base de lista.
2. Encapsular una lista más rica permite añadir algoritmos sin tocar implementación base de cada estructura de Semana 3.
3. `to_deng` convierte `DLList`/`SEList` a `DengList`; `assign_from_deng` hace la conversión inversa limpiando y recargando destino.
4. `stable_sort_with_deng` evita reimplementar sort en `DLList`/`SEList`: convierte, ordena en Deng, y reasigna.
5. `dedup_with_deng` elimina duplicados vía Deng y devuelve cuántos se removieron; conceptualmente corresponde a deduplicar.
6. `reverse_with_deng` muestra reutilización de algoritmo de reversa sobre una interfaz común y luego reconversión.
7. El costo extra es de conversión O(n) de ida y vuelta. Vale la pena cuando el algoritmo reutilizado compensa (mantenibilidad y menos código duplicado).

#### Bloque 7

1. `ArrayDeque` usa arreglo circular (contiguo); `LinkedDeque` usa nodos enlazados dobles. Cambian localidad de memoria y costo de acceso aleatorio.
2. Mejor localidad contigua significa mejor aprovechamiento de caché: elementos cercanos se cargan juntos.
3. La representación enlazada favorece inserciones/eliminaciones locales y operaciones en extremos sin desplazamiento masivo.
4. En benchmark, `random_get_arraydeque` vs `random_get_dllist` sirve para acceso aleatorio; las pruebas de queue/deque sirven para extremos.
5. Benchmark no es prueba absoluta: depende de tamaño, patrón de acceso, hardware, compilador y detalles de implementación.
6. `XorList` muestra ahorro de punteros al codificar prev/next en un solo campo XOR.
7. Desventaja práctica de `XorList`: mayor complejidad de implementación/debug y menor mantenibilidad.

#### Bloque 8

Al pasar de usar arreglos dinámicos a diseñar estructuras enlazadas y adaptadores sobre nodos, cambia primero la **representación**: dejamos continuidad física y pasamos a enlaces explícitos entre nodos. Eso altera el modelo de acceso: en contiguo domina el **acceso por rango** (índice directo), mientras en enlazado domina el **acceso por posición/enlace** (recorrido).

También cambia el perfil operativo: las **inserciones y eliminaciones locales** son más naturales en enlazado (ajuste de punteros), pero el acceso por índice suele empeorar frente a estructuras contiguas. En complejidad, `SLList` destaca en operaciones de cabeza/cola específicas; `DLList` mejora acceso posicional con doble sentido y centinela; `SEList` introduce bloques para balancear costo de acceso y actualización.

Además, aparece una ventaja de diseño: la **reutilización por adaptadores y puentes**. Ejemplos claros son `LinkedStack`/`LinkedQueue`/`LinkedDeque` y el puente `MorinDengBridge`, que permite aplicar algoritmos de `DengList` sin reescribir toda la estructura base.

En síntesis, la comparación contigua vs enlazada no es “una gana siempre”: contiguo suele ganar en localidad y acceso aleatorio; enlazado suele ganar en flexibilidad estructural y modificaciones locales. Elegir bien depende del patrón real de operaciones.

#### Autoevaluación breve

- Qué puedo defender con seguridad: invariantes básicos de `SLList`, `DLList`, `SEList`; costos de operaciones principales; funcionamiento de adaptadores y puente Deng.
- Qué todavía confundo: detalle fino de cuándo conviene cierto tamaño de bloque `b` en escenarios reales y no solo teóricos.
- Qué evidencia usaría en una sustentación: trazas de demos (`demo_sllist`, `demo_dllist`, `demo_selist`), asserts de pruebas públicas y resultados del benchmark de Semana 3.
