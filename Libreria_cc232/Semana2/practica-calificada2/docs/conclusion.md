## Comparativa Algoritmos

### Algoritmo No Optimizado (Fuerza bruta - O(n³))

```
Configuración:
- Búsqueda exhaustiva de todas las subcadenas
- Validación repetida de cada subcadena
- Complejidad Teórica: O(n³)

Rendimiento Medido:
- Tiempo Total: 7.32 segundos
- Llamadas: 9
- Tiempo Promedio: 813.33 ms/llamada
- Porcentaje de CPU: 99.73%
```

**Limitaciones:**
- Impracticable para datos en tiempo real
- Requiere >800ms por ejecución
- Escalabilidad pobre con entrada creciente

### Algoritmo Optimizado (Stack - O(n))

```
Configuración:
- Una sola pasada sobre la cadena
- Uso de stack para rastrear índices
- Complejidad Teórica: O(n)

Rendimiento Medido:
- Tiempo Total: < 0.01 segundos
- Llamadas: 9
- Tiempo Promedio: < 0.01 ms/llamada
- Porcentaje de CPU: 0.00%
```

**Ventajas:**
- Prácticamente imperceptible en ejecución
- Escalable a entradas arbitrarias
- Listo para producción

---



## Conclusión

Podemos concluir gracias al analisis de gprof que el **algoritmo optimizado (stack) es superior en todos los aspectos**:

- **Velocidad:** 700x más rápido
- **Escalabilidad:** O(n) vs O(n³)
- **Producción:** Listo para uso inmediato
- **Mediciones gprof:** 99.73% vs 0.00% de CPU

La diferencia observada (813 ms vs <0.01 ms) es concluyente y se recomienda **adoptar siempre el algoritmo optimizado**.

---
