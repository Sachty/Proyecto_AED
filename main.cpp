//
// Created by allxs on 20/02/2024.
//

#include "treap.h"
#include <iostream>
using namespace std;

int main() {
    std::cout << "\n--------------------------------------------------------" << std::endl;
    std::cout <<    "--------------------- EJEMPLO 1 ------------------------" << std::endl;

    // Se crea el treap
    Treap<int> treap;

    // Se inserta algunos valores
    treap.insertar(10, 8);
    treap.insertar(20, 2);
    treap.insertar(30, 1);
    treap.insertar(40, 6);
    treap.insertar(50, 5);
    treap.insertar(60, 4);

    // Se muestra el Treap
    std::cout << "Treap despues de insertar los numeros base:" << std::endl;
    treap.display();

    std::cout << "\t\tDatos del treap" << std::endl;

    // Se busca dos valores
    std::cout << "Esta el 40 en el Treap? " << (treap.buscar(40) ? "Si" : "No") << std::endl;
    std::cout << "Esta el 70 en el Treap? " << (treap.buscar(70) ? "Si" : "No") << std::endl;

    // Obtener el minimo y el maximo
    std::cout << "Minimo: " << treap.minimo() << std::endl;
    std::cout << "Maximo: " << treap.maximo() << std::endl;

    // Se obtiene la altura y el tamaño
    std::cout << "Altura: " << treap.altura() << std::endl;
    std::cout << "Tamano: " << treap.tamano() << std::endl;

    // Se hacen los recorridos
    std::cout << "Preorden: ";
    treap.preorden();
    std::cout << "Inorden: ";
    treap.inorden();
    std::cout << "Postorden: ";
    treap.postorden();


    std::cout << "\n\n\t\tNuevas Inserciones (paso a paso)" << std::endl;

    // Insertar un nuevo elemento
    treap.insertar(15, 3); // aqui se debe realizar rotacion como bst
    // Mostramos el Treap
    std::cout << "Treap despues de insertar (15,3):" << std::endl;
    treap.display();

    // Insertar un nuevo elemento
    treap.insertar(7, 7); // aqui se debe realizar rotacion como bst

    // Mostramos el Treap
    std::cout << "Treap despues de insertar (7,7):" << std::endl;
    treap.display();

    // Insertar un nuevo elemento
    treap.insertar(70,12); // aqui se debe realizar rotacion como bst

    // Mostramos el Treap
    std::cout << "Treap despues de insertar (70,12):" << std::endl;
    treap.display();


    // ******************************************************************************************
    std::cout << "\n--------------------------------------------------------" << std::endl;
    std::cout <<    "--------------------- EJEMPLO 2 ------------------------" << std::endl;

    // Creamos un nuevo treap
    Treap<int> treap2;

    // Insertamos algunos valores
    treap2.insertar(10, 8);
    treap2.insertar(7, 7);
    treap2.insertar(40, 6);
    treap2.insertar(20, 2);
    treap2.insertar(50, 5);
    treap2.insertar(30, 1);
    treap2.insertar(60, 4);

    // Mostramos el Treap
    std::cout << "Treap despues de insertar  a los numeros base:" << std::endl;
    treap2.display();

    std::cout << "\t\tNuevas Eliminaciones (paso a paso)" << std::endl;

    // Se borra el 60
    treap2.borrar(60);
    // Mostramos el Treap
    std::cout << "Treap despues de borrar (60,4):" << std::endl;
    treap2.display();

    // Se borra el 20
    treap2.borrar(20);
    // Mostramos el Treap
    std::cout << "Treap despues de borrar (20,2):" << std::endl;
    treap2.display();

    // Se borra el 40
    treap2.borrar(40);
    // Mostramos el Treap
    std::cout << "Treap despues de borrar (40,6):" << std::endl;
    treap2.display();



    return 0;
}
