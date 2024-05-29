#pragma once
#include <string>

// Directiva pragma once para evitar la inclusi�n m�ltiple del archivo de encabezado.

class Personaje {
public:
    int vida; // Atributo que representa la vida del personaje.
    int ataque; // Atributo que representa el poder de ataque del personaje.
    std::string nombre; // Atributo que representa el nombre del personaje.
    int posicionX; // Atributo que representa la posici�n X del personaje en el mapa.
    int posicionY; // Atributo que representa la posici�n Y del personaje en el mapa.

    // Constructor de la clase Personaje.
    Personaje(std::string nom, int vid, int atq, int posX, int posY);

    // M�todo virtual para que los objetos de la clase Personaje puedan atacar.
    virtual void atacar(Personaje& objetivo);

    // M�todos getter para obtener los valores de los atributos.
    int getVida() const;
    int getAtaque() const;
    std::string getNombre() const;
    int getPosicionX() const;
    int getPosicionY() const;

    // M�todos setter para establecer los valores de los atributos.
    void setVida(int vid);
    void setAtaque(int atq);
    void setNombre(std::string nom);
    void setPosicionX(int posX);
    void setPosicionY(int posY);
};
