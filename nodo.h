//
// Created by allxs on 20/02/2024.
//

#ifndef PROYECTO_AED_NODO_H
#define PROYECTO_AED_NODO_H

#include <memory>

template <typename T>
class Nodo {
public:
    T valor; // Valor del nodo
    int prioridad; // Prioridad del nodo
    std::shared_ptr<Nodo<T>> izquierda, derecha; // Hijos del nodo

    // Constructor
    Nodo(T valor, int prioridad) : valor(valor), prioridad(prioridad), izquierda(nullptr), derecha(nullptr) {}

    // Destructor
    ~Nodo() = default;
};




#endif //PROYECTO_AED_NODO_H