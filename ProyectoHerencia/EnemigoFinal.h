#pragma once
#include "Header1.h"

// Directiva pragma once para evitar la inclusión múltiple del archivo de encabezado "Header1.h".

// Declaración de la clase EnemigoFinal que hereda de la clase Personaje.
class EnemigoFinal : public Personaje {
public:
    int superAtaque1; // Atributo que representa el primer superataque del enemigo final.
    int superAtaque2; // Atributo que representa el segundo superataque del enemigo final.

    // Constructor de la clase EnemigoFinal.
    EnemigoFinal(std::string nom, int vid, int atq, int posX, int posY, int sAtq1, int sAtq2);

    // Método para que el enemigo final ataque a un objetivo, sobrescrito de la clase Personaje.
    void atacar(Personaje& objetivo) override;
};
