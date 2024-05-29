#include "Header1.h"
#include <iostream>

// Incluye el archivo de encabezado "Header1.h", que contiene la declaración de la clase Personaje y otras declaraciones necesarias.

// Constructor de Personaje
Personaje::Personaje(std::string nom, int vid, int atq, int posX, int posY)
    : nombre(nom), vida(vid), ataque(atq), posicionX(posX), posicionY(posY) {}
// Define el constructor de la clase Personaje. Este constructor inicializa los atributos vida, ataque, nombre, posicionX y posicionY con los valores proporcionados.

// Método para atacar
void Personaje::atacar(Personaje& objetivo) {
    std::cout << nombre << " ataca a " << objetivo.nombre << " causándole " << ataque << " puntos de daño." << std::endl;
    objetivo.vida -= ataque;
}
// Define el método para atacar de la clase Personaje. Este método muestra un mensaje indicando que el personaje está atacando a otro personaje y reduce la vida del objetivo según el valor de ataque del personaje que ataca.

// Getters
int Personaje::getVida() const { return vida; }
int Personaje::getAtaque() const { return ataque; }
std::string Personaje::getNombre() const { return nombre; }
int Personaje::getPosicionX() const { return posicionX; }
int Personaje::getPosicionY() const { return posicionY; }
// Define los métodos getter para obtener los valores de los atributos vida, ataque, nombre, posicionX y posicionY de la clase Personaje.

// Setters
void Personaje::setVida(int vid) { vida = vid; }
void Personaje::setAtaque(int atq) { ataque = atq; }
void Personaje::setNombre(std::string nom) { nombre = nom; }
void Personaje::setPosicionX(int posX) { posicionX = posX; }
void Personaje::setPosicionY(int posY) { posicionY = posY; }
// Define los métodos setter para establecer los valores de los atributos vida, ataque, nombre, posicionX y posicionY de la clase Personaje.
