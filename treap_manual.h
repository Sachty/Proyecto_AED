//
// Created by allxs on 19/02/2024.
//

#ifndef PROYECTO_AED_TREAP_MANUAL_H
#define PROYECTO_AED_TREAP_MANUAL_H


#include "nodo.h"
#include <iostream>
#include <memory>

template <typename T>
class Treap {
private:
    std::shared_ptr<Nodo<T>> raiz; // Raíz del Treap

    // Funciones privadas
    std::shared_ptr<Nodo<T>> rotarIzquierda(std::shared_ptr<Nodo<T>> nodo) {
        // Rotamos el nodo a la izquierda
        auto temp = nodo->derecha;
        nodo->derecha = temp->izquierda;
        temp->izquierda = nodo;
        return temp;
    }

    std::shared_ptr<Nodo<T>> rotarDerecha(std::shared_ptr<Nodo<T>> nodo) {
        // Rotamos el nodo a la derecha
        auto temp = nodo->izquierda;
        nodo->izquierda = temp->derecha;
        temp->derecha = nodo;
        return temp;
    }

    std::shared_ptr<Nodo<T>> insertar(std::shared_ptr<Nodo<T>> nodo, T valor, int prioridad) {
        // Si el nodo es nulo, creamos un nuevo nodo
        if (!nodo) return std::make_shared<Nodo<T>>(valor, prioridad);

        // Si el valor es menor que el valor del nodo, lo insertamos en la izquierda
        if (valor < nodo->valor) {
            nodo->izquierda = insertar(nodo->izquierda, valor, prioridad);
            if (nodo->izquierda->prioridad > nodo->prioridad) nodo = rotarDerecha(nodo);
        }
            // Si el valor es mayor o igual, lo insertamos en la derecha
        else {
            nodo->derecha = insertar(nodo->derecha, valor, prioridad);
            if (nodo->derecha->prioridad > nodo->prioridad) nodo = rotarIzquierda(nodo);
        }

        return nodo;
    }

    std::shared_ptr<Nodo<T>> borrar(std::shared_ptr<Nodo<T>> nodo, T valor) {
        // Si el nodo es nulo, no hacemos nada
        if (!nodo) return nodo;

        // Si el valor es menor que el valor del nodo, borramos en la izquierda
        if (valor < nodo->valor) nodo->izquierda = borrar(nodo->izquierda, valor);
            // Si el valor es mayor que el valor del nodo, borramos en la derecha
        else if (valor > nodo->valor) nodo->derecha = borrar(nodo->derecha, valor);
            // Si el valor es igual al valor del nodo, borramos este nodo
        else {
            // Si el nodo es una hoja, simplemente lo borramos
            if (!nodo->izquierda && !nodo->derecha) nodo.reset();
                // Si el nodo solo tiene un hijo, lo reemplazamos por ese hijo
            else if (!nodo->izquierda) nodo = nodo->derecha;
            else if (!nodo->derecha) nodo = nodo->izquierda;
                // Si el nodo tiene dos hijos, lo reemplazamos por el hijo con mayor prioridad
            else if (nodo->izquierda->prioridad < nodo->derecha->prioridad) {
                nodo = rotarIzquierda(nodo);
                nodo->izquierda = borrar(nodo->izquierda, valor);
            } else {
                nodo = rotarDerecha(nodo);
                nodo->derecha = borrar(nodo->derecha, valor);
            }
        }

        return nodo;
    }

    void display(std::shared_ptr<Nodo<T>> nodo, std::string indent = "", std::string dir = "") {
        // Si el nodo es nulo, no hacemos nada
        if (nodo) {
            // Mostramos el nodo de la derecha primero (en la parte inferior)
            display(nodo->derecha, indent + "     ", "/");
            // Mostramos el nodo actual
            std::cout << indent << dir << "(" << nodo->valor << "," << nodo->prioridad << ") h:" << altura(nodo) << std::endl;
            // Mostramos el nodo de la izquierda después (en la parte superior)
            display(nodo->izquierda, indent + "     ", "\\");
        }
    }



    bool buscar(std::shared_ptr<Nodo<T>> nodo, T valor) {
        // Si el nodo es nulo, el valor no está en el Treap
        if (!nodo) return false;

        // Si el valor es igual al valor del nodo, lo encontramos
        if (valor == nodo->valor) return true;

        // Si el valor es menor que el valor del nodo, buscamos en la izquierda
        if (valor < nodo->valor) return buscar(nodo->izquierda, valor);

        // Si el valor es mayor que el valor del nodo, buscamos en la derecha
        return buscar(nodo->derecha, valor);
    }

    T minimo(std::shared_ptr<Nodo<T>> nodo) {
        // Si el nodo es nulo, no hay mínimo
        if (!nodo) throw std::runtime_error("El Treap está vacío");

        // Si el nodo no tiene hijo izquierdo, este nodo es el mínimo
        if (!nodo->izquierda) return nodo->valor;

        // Si el nodo tiene hijo izquierdo, el mínimo está en la izquierda
        return minimo(nodo->izquierda);
    }

    T maximo(std::shared_ptr<Nodo<T>> nodo) {
        // Si el nodo es nulo, no hay máximo
        if (!nodo) throw std::runtime_error("El Treap está vacío");

        // Si el nodo no tiene hijo derecho, este nodo es el máximo
        if (!nodo->derecha) return nodo->valor;

        // Si el nodo tiene hijo derecho, el máximo está en la derecha
        return maximo(nodo->derecha);
    }

    int altura(std::shared_ptr<Nodo<T>> nodo) {
        // Si el nodo es nulo, la altura es -1
        if (!nodo) return -1;

        // La altura es el máximo entre la altura de la izquierda y la derecha, más 1
        return std::max(altura(nodo->izquierda), altura(nodo->derecha)) + 1;
    }

    void preorden(std::shared_ptr<Nodo<T>> nodo) {
        // Si el nodo es nulo, no hacemos nada
        if (!nodo) return;

        // Visitamos el nodo actual, luego la izquierda y la derecha
        std::cout << nodo->valor << " ";
        preorden(nodo->izquierda);
        preorden(nodo->derecha);
    }

    void inorden(std::shared_ptr<Nodo<T>> nodo) {
        // Si el nodo es nulo, no hacemos nada
        if (!nodo) return;

        // Visitamos la izquierda, luego el nodo actual y la derecha
        inorden(nodo->izquierda);
        std::cout << nodo->valor << " ";
        inorden(nodo->derecha);
    }

    void postorden(std::shared_ptr<Nodo<T>> nodo) {
        // Si el nodo es nulo, no hacemos nada
        if (!nodo) return;

        // Visitamos la izquierda, luego la derecha y el nodo actual
        postorden(nodo->izquierda);
        postorden(nodo->derecha);
        std::cout << nodo->valor << " ";
    }

    int tamano(std::shared_ptr<Nodo<T>> nodo) {
        // Si el nodo es nulo, el tamaño es 0
        if (!nodo) return 0;

        // El tamaño es el tamaño de la izquierda más el tamaño de la derecha, más 1
        return tamano(nodo->izquierda) + tamano(nodo->derecha) + 1;
    }

public:
    // Constructor
    Treap() : raiz(nullptr) {}

    // Destructor
    ~Treap() = default;

    // Funciones públicas
    void insertar(T valor, int prioridad) { raiz = insertar(raiz, valor, prioridad); }
    void borrar(T valor) { raiz = borrar(raiz, valor); }
    void display() {
        display(raiz, "", "");
        std::cout << std::endl;
    }
    bool buscar(T valor) { return buscar(raiz, valor); }
    T minimo() { return minimo(raiz); }
    T maximo() { return maximo(raiz); }
    int altura() { return altura(raiz); }
    void preorden() { preorden(raiz); std::cout << std::endl; }
    void inorden() { inorden(raiz); std::cout << std::endl; }
    void postorden() { postorden(raiz); std::cout << std::endl; }
    int tamano() { return tamano(raiz); }
};






#endif //PROYECTO_AED_TREAP_MANUAL_H
