// Practica: Juego del gato (tres en raya) con matrices en C++
// Objetivo: programar el juego del gato para dos jugadores usando una matriz de 3x3.
// Link del repositorio de GitHub: https://github.com/JesusAntonioSolisGomez/Gato-con-matrices-de-3x3

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

const int N = 3;

// Llena el tablero con espacios vacios
void inicializarTablero(char tablero[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tablero[i][j] = ' ';
        }
    }
}

// Muestra el tablero en pantalla
void mostrarTablero(char tablero[N][N]) {
   cout << "\n     A   B   C\n";
    cout << "   +---+---+---+\n";
    for (int i = 0; i < N; i++) {
        cout << " " << i + 1 << " |";
        for (int j = 0; j < N; j++) {
            cout << " " << tablero[i][j] << " |";
        }
        cout << "\n   +---+---+---+\n";
    }
    cout << endl;
}

// Verifica si el jugador con la ficha 'ficha' ha ganado
bool hayGanador(char tablero[N][N], char ficha) {
    // Revisar filas y columnas
    for (int i = 0; i < N; i++) {
        if (tablero[i][0] == ficha && tablero[i][1] == ficha && tablero[i][2] == ficha)
            return true;
        if (tablero[0][i] == ficha && tablero[1][i] == ficha && tablero[2][i] == ficha)
            return true;
    }
   // Revisar diagonales
    if (tablero[0][0] == ficha && tablero[1][1] == ficha && tablero[2][2] == ficha)
        return true;
    if (tablero[0][2] == ficha && tablero[1][1] == ficha && tablero[2][0] == ficha)
        return true;
 
    return false;
}

// Verifica si el tablero esta lleno (empate)
bool tableroLleno(char tablero[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tablero[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Pide al jugador una jugada valida y la coloca en el tablero
void pedirJugada(char tablero[N][N], char ficha, const string& nombre) {
    int fila;
    char letra;
    while (true) {
        cout << nombre << " (" << ficha << "), ingresa fila (1-3) y columna (A-C), ej. 1 C: ";
        if (!(cin >> fila >> letra)) {
            // Entrada invalida (la fila no es numero): limpiar y volver a pedir
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida. Escribe un numero de fila y una letra de columna, ej. 1 C.\n";
            continue;
        }
        // Convertir la letra a indice de columna: A=0, B=1, C=2 (acepta minusculas)
        int columna = toupper(letra) - 'A' + 1;
 
        if (fila < 1 || fila > N || columna < 1 || columna > N) {
            cout << "Posicion fuera del tablero. Intenta de nuevo.\n";
        } else if (tablero[fila - 1][columna - 1] != ' ') {
            cout << "Esa casilla ya esta ocupada. Elige otra.\n";
        } else {
            tablero[fila - 1][columna - 1] = ficha;
            break;

        }
    }
}

int main() {
    char tablero[N][N];
    string jugador1, jugador2;
    char opcion;
 
    cout << "=== JUEGO DEL GATO ===\n";
    cout << "Nombre del jugador 1 (X): ";
    getline(cin, jugador1);
    cout << "Nombre del jugador 2 (O): ";
    getline(cin, jugador2);
 
    do {
        inicializarTablero(tablero);
        char fichaActual = 'X';
        string nombreActual = jugador1;
        bool terminado = false;
 
        while (!terminado) {
            mostrarTablero(tablero);
            pedirJugada(tablero, fichaActual, nombreActual);
 
            if (hayGanador(tablero, fichaActual)) {
                mostrarTablero(tablero);
                cout << "Felicidades " << nombreActual << ", ganaste!\n";
                terminado = true;
            } else if (tableroLleno(tablero)) {
                mostrarTablero(tablero);
                cout << "Empate!\n";
                terminado = true;
            } else {
                // Cambiar de turno
                if (fichaActual == 'X') {
                    fichaActual = 'O';
                    nombreActual = jugador2;
                } else {
                    fichaActual = 'X';
                    nombreActual = jugador1;
                }
            }
        }

       cout << "\nJugar otra vez? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');
 
    cout << "Gracias por jugar!\n";
    return 0;
}
