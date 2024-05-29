#pragma once
#include "Header1.h"

// Directiva pragma once para evitar la inclusi�n m�ltiple del archivo de encabezado "Header1.h".

// Declaraci�n de la clase EnemigoFinal que hereda de la clase Personaje.
class EnemigoFinal : public Personaje {
public:
    int superAtaque1; // Atributo que representa el primer superataque del enemigo final.
    int superAtaque2; // Atributo que representa el segundo superataque del enemigo final.

    // Constructor de la clase EnemigoFinal.
    EnemigoFinal(std::string nom, int vid, int atq, int posX, int posY, int sAtq1, int sAtq2);

    // M�todo para que el enemigo final ataque a un objetivo, sobrescrito de la clase Personaje.
    void atacar(Personaje& objetivo) override;
};
