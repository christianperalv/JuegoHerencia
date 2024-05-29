#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "EnemigoFinal.h"
#include "Header1.h"





using namespace std;

void mostrarNivel(int nivel[9][9], Personaje& heroe) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (i == heroe.getPosicionX() && j == heroe.getPosicionY())
                cout << "H ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

void moverHeroe(Personaje& heroe, char movimiento, int nivel[9][9]) {
    int nuevaX = heroe.getPosicionX();
    int nuevaY = heroe.getPosicionY();

    switch (movimiento) {
    case 'w': nuevaX = max(0, heroe.getPosicionX() - 1); break;
    case 's': nuevaX = min(8, heroe.getPosicionX() + 1); break;
    case 'a': nuevaY = max(0, heroe.getPosicionY() - 1); break;
    case 'd': nuevaY = min(8, heroe.getPosicionY() + 1); break;
    }

    nivel[heroe.getPosicionX()][heroe.getPosicionY()] = 0;
    heroe.setPosicionX(nuevaX);
    heroe.setPosicionY(nuevaY);
    nivel[heroe.getPosicionX()][heroe.getPosicionY()] = 1;
}

bool batalla(Personaje& heroe, Personaje& enemigo) {
    cout << "¡Batalla entre " << heroe.getNombre() << " y " << enemigo.getNombre() << "!" << endl;

    while (heroe.getVida() > 0 && enemigo.getVida() > 0) {
        heroe.atacar(enemigo);
        if (enemigo.getVida() > 0) {
            enemigo.atacar(heroe);
        }
    }

    if (heroe.getVida() > 0) {
        cout << heroe.getNombre() << " ha derrotado a " << enemigo.getNombre() << "." << endl;
        return true;
    }
    else {
        cout << enemigo.getNombre() << " ha derrotado a " << heroe.getNombre() << "." << endl;
        return false;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Inicializar la semilla para números aleatorios

    // Crear héroe
    Personaje heroe("Héroe", 100, 10, 0, 0);

    // Crear enemigos
    vector<Personaje> enemigos = {
        Personaje("Enemigo 1", 30, 5, rand() % 9, rand() % 9),
        Personaje("Enemigo 2", 40, 6, rand() % 9, rand() % 9),
        Personaje("Enemigo 3", 50, 7, rand() % 9, rand() % 9)
    };

    // Crear enemigo final
    EnemigoFinal enemigoFinal("Enemigo Final", 100, 15, 8, rand() % 9, 20, 25);

    // Matriz del juego
    int nivel[9][9] = { 0 };

    // Colocar héroe
    nivel[heroe.getPosicionX()][heroe.getPosicionY()] = 1;

    // Juego principal
    bool juegoTerminado = false;
    while (!juegoTerminado) {
        // Mostrar nivel
        mostrarNivel(nivel, heroe);

        // Movimiento del héroe
        cout << "Introduce el movimiento del héroe (WASD): ";
        char movimiento;
        cin >> movimiento;

        moverHeroe(heroe, movimiento, nivel);

        // Verificar encuentro con enemigos
        for (size_t i = 0; i < enemigos.size(); ++i) {
            if (heroe.getPosicionX() == enemigos[i].getPosicionX() && heroe.getPosicionY() == enemigos[i].getPosicionY()) {
                if (batalla(heroe, enemigos[i])) {
                    enemigos.erase(enemigos.begin() + i);
                    break;
                }
                else {
                    juegoTerminado = true;
                    cout << "¡Game Over!" << endl;
                    return 0;
                }
            }
        }

        // Verificar llegada a la salida
        if (heroe.getPosicionX() == enemigoFinal.getPosicionX() && heroe.getPosicionY() == enemigoFinal.getPosicionY()) {
            if (batalla(heroe, enemigoFinal)) {
                juegoTerminado = true;
                cout << "¡Has ganado el juego!" << endl;
            }
            else {
                juegoTerminado = true;
                cout << "¡Game Over!" << endl;
            }
        }
    }

    return 0;
}
