# Gato-con-matrices-de-3x3
Juego del gato, para dos jugadores en consola, hecho en C++ con una matriz de 3x3.

# Juego del Gato en C++

Práctica de programación: juego del gato (tres en raya) para dos jugadores en la consola, implementado con una matriz de 3x3.

## Características

- Tablero representado con una matriz `char tablero[3][3]`
- Dos jugadores con nombre personalizado (X y O)
- Columnas con letras (A, B, C) y filas con números (1, 2, 3)
- Detección de ganador (filas, columnas y diagonales) y de empate
- Validación de jugadas: casillas ocupadas, posiciones fuera del tablero y entradas inválidas
- Opción de jugar otra partida al terminar

## Cómo jugar

En cada turno escribe la fila y la columna separadas por un espacio. Por ejemplo, `1 C` coloca tu ficha en la fila 1, columna C (acepta mayúsculas y minúsculas).

Gana quien complete una línea de tres fichas iguales, ya sea horizontal, vertical o diagonal.

## Conceptos utilizados

Matrices (arreglos bidimensionales), ciclos `for`, `while` y `do...while`, funciones con parámetros, condicionales y entrada/salida con `cin` y `cout`.

## Autor

Jesus Antonio Solis Gomez
3ss
Estructura de datos
