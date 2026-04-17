## Actividad 2-CC232

### Integrantes
- Espinoza Sandoval, Adriel Alejandro
- Pantoja Limache, Fabio Alberto

#### Bloque 1
1. Es un arreglo cuyos elementos están guardados con posiciones seguidas en la memoria física de la computadora.
2. Porque la memoria de la computadora es limitada, acceder a esa memoria tiene un costo acotado.
3. En un vector, size es el tamaño de los elementos usados, y capacity el tamaño de memoria reservada para guardar los elementos.
4. Porque las demás direcciones de memoria cercana podrían estar siendo usadas para otros procesos.
5. Tanto ArrayStack como DengVector son implementaciones de un arreglo dinámico que puede cambiar su tamaño. Difieren en su interfaz, ya que uno 
6. En el 
7. Mejora en la implementación de funciones nativas de C++, haciendo las copias más rápidas. Esto no cambia su costo asintótico.
8. RootishArrayStack "divide" un ArrayStack en bloques separados en la memoria.
9. 
10. 

#### Bloque 2
| Archivo | Salida u observable importante | Idea estructural | Argumento de costo o espacio |
| --- | --- | --- | --- |
|`Semana2/demos/demo_array_basico.cpp`|Despues de `b=a`, el arreglo `b` pasa a tener los datos de `a` y su tamaño|Diseñada como un contenedor minimo con dos campos: puntero a memoria dinamica `a` y tamaño logico `length`.La decision estructural central es **ownership unico** del buffer interno: la asignacion mueve ese ownership al destino, en vez de clonar contenido.|Complejidad temporal $O(1)$|
|`Semana2/demos/demo_arraystack.cpp`|Despues de `add(1,15)`, el elemento  seinserta en posicion1 y 20 se desplaza a la derecha. El `remove(1)` extrae ese 15 y los restantes se desplazan :`10 20`| Mantiene un array dinamico `a` con un contador logico `n` de elementos activos. Las inserciones/eliminaciones **desplazan elementos** en el array para mantener continuidad|Insercion/eliminacion en posicion `i`: $O(n)$. Acceso get(i) :$O(1)$. Redimension amortizada: $O(1)$. Espacio $O(n)$ con overhead pro capacidad de reserva|
|`Semana2/demos/demo_arraystack_explicado.cpp`||||
|`Semana2/demos/demo_fastarraystack.cpp`||||
|`Semana2/demos/demo_rootisharraystack.cpp`||||
|`Semana2/demos/demo_rootisharraystack_explicado.cpp`||||
|`Semana2/demos/demo_deng_vector.cpp`||||
|`Semana2/demos/demo_stl_vector_contraste.cpp`||||



#### Bloque 3
1. Prueba el funcionamiento de `add` (inserción), `size`, `get` y `remove`.
2. Prueba el funcionamiento de `add`, `size`, `get` y `remove`.
3. Prueba el funcionamiento de `add`, `size`, `get` y `remove`.
4. Demuestra un comportamiento válido mínimo esperado.
5. No demuestra comportamientos más internos, como invariantes, costos, casos bordes, etc.
6. Se intenta estresar su estabilidad, ya que en las pruebas los arreglos dinámicos se hacen crecer y decrecer, requiriendo de una reserva de un bloque nuevo y copiar todos sus elementos hacia allá.
7. Porque el comportamiento de un algoritmo su análisis se centra más en la implementación de código.

#### Bloque 4
(respuestas)

#### Bloque 5
1. Los elementos se guardan en bloques de tamaño creciente respecto al anterior. Siendo el primer bloque de tamaño 1, el segundo 2, etc.
2. Ya que cada bloque i tiene tamaño i, la capacidad sería 1 + 2 + ... + r = r*(r+1)/2
3. Halla el bloque en el que está guardada la posición i del RootishArrayStack.
4. Además de hallar el bloque en el que está guardada, también hallar la posición de ese elemento respecto al bloque.
5. Al fragmentar el espacio, no es necesario a 
6. Los métodos de insertar elementos, eliminar, escribir y acceder a elementos.
7.

#### Bloque 6
(respuestas)

#### Bloque 7
(respuesta final)

#### Autoevaluación breve
- Qué podemos defender con seguridad:
- Qué todavía confundimos:
- Qué evidencia usaríamos en una sustentación: