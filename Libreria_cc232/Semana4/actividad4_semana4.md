## Actividad 4-CC232

### Estudiante
- Pantoja Limache Fabio alberto

#### Bloque 1 
1.  - LIFO ( Last in, first out), el ultimo elemento agregado es el primero que se aaextrae.
    - FIFO ( First in, first out), el primer elemento agregado es el primero que se extrae, se accesde por el frente y se agregan por el dorso 
2. Una pila captura el concepto de tareas pendientes en orden inverso. Si se tiene que deshacer acciones, atender lo mas urgente que acaba de llegar, o procesar algo que depende del contexto anterior, la pila preserva esa dependencia.
3. Una cola modela justicia y orden, quien llega primero espera menos y es atendido primero. En BankSimulation, cada ventanilla mantiene una cola de clientes. Los clientes nuevos se encolan en la ventanilla mas corta y se atienden en orden FIFO. Si fuera pila, el ultimo que llega seria atendido primero. Las colas preservan el orden de llegada, que es lo que espera un cliente real.
4. Recursion implicita usa el call stack, cada invocacion deja un registro automatico que incluye variables locales, punto de retorno, parametros. **Reemplazar por estructura explicita** significa usar una pila dentro del prigrama, guardar manuelmente el estado parcial y gestionar el retroceso sin recursion. Esto implica tener las ventajas de control total ( saber que se guarda y cuando), evita el limite del stack y claridad del algoritmo ( se ve explicitamente y no oculto en llamadas anidadas).
5. El estado suficiente para saber donde estabamos y que intentar despues. 
    - En N-Reinas: las reinas ya colocadas (pila Queen con x,y). al retroceder recuperas la ultima, y al avanzar su columna.
    - En laberinto: las celdas visitadas en el camino actual. El algoritmo recupera la ultima y marca como retrocedida.
6. Ambas dividen por la base repetidamente, extraen el residuo como digito y producen los mismos digitos.
    - recursiva: el call stack apila **automaticamente**. Cada nivel guarda (n, base). los digitos se apilan implicitamente en el camino de descenso, y se desapilan automaticamente al retornar.
    - iterativa: apila **manualmente** cada residuo en un Stack<char>. **Controlas** cuando parar ( while: x>0). Los digitos se desapilan al final.
7. Un parentesis de cierre `)` solo es valido si hay una apertura `(` sin cerrar antes. La version iteratida en `Parentheses.h` hace:
    - ve`(`: apila. Es "pendiente" hasta que veas vea un `)`.
    - ve `)`: hay un `(` en el tope? Si no, error. Si si, desapila.
    - al final: pila vacia? Si, entonces valido. hay aperturas sin cerrar? No, valido.</li>
8. 

#### Bloque 2 (tabla y respuestas)
#### Bloque 3 (respuestas)
#### Bloque 4 (respuestas y experimentos 1-2)
#### Bloque 5 (respuestas y experimento 3)
#### Bloque 6 (respuestas y experimentos 4-5)
#### Bloque 7 (respuestas y experimento 6)
#### Bloque 8 (respuesta final)

#### Autoevaluación breve
- Qué puedo defender con seguridad:
- Qué todavía confundo:
- Qué experimento me dio mejor evidencia:
- Qué evidencia usaría en una sustentación: