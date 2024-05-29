#include "EnemigoFinal.h"
#include <iostream>
#include <cstdlib> // Para rand()

// Constructor de EnemigoFinal
EnemigoFinal::EnemigoFinal(std::string nom, int vid, int atq, int posX, int posY, int sAtq1, int sAtq2)
    : Personaje(nom, vid, atq, posX, posY), superAtaque1(sAtq1), superAtaque2(sAtq2) {}

// Método para atacar sobrescrito
void EnemigoFinal::atacar(Personaje& objetivo) {
    int ataqueUsado = ataque;
    if (rand() % 2 == 0) { // 50% de probabilidad de usar un super ataque
        ataqueUsado = (rand() % 2 == 0) ? superAtaque1 : superAtaque2;
        std::cout << nombre << " usa un super ataque causando " << ataqueUsado << " puntos de daño a " << objetivo.nombre << "." << std::endl;
    }
    else {
        std::cout << nombre << " ataca a " << objetivo.nombre << " causando " << ataqueUsado << " puntos de daño." << std::endl;
    }
    objetivo.vida -= ataqueUsado;
}
