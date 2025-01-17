#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include "Funciones.hpp"
#include "Personajes.hpp"

using namespace std;

int pos = 0; //posicion del jugador en el tablero


int main()
{
    enemigo1.acc = 11, enemigo2.acc = 8, enemigo3.acc = 6 ; //suerte de los enemigos
    enemigo4.acc = 5, enemigo5.acc = 7, enemigo6.acc = 9; //si la suma de los dos dados es <= enemigoN.acc
    enemigo7.acc = 8, enemigo8.acc = 8, enemigo9.acc = 6;
    jefefinal.acc = 10;

    enemigo1.ataque = 25, enemigo2.ataque = 30, enemigo3.ataque = 40 ; //Puntos de da;o de los enemigos
    enemigo4.ataque = 50, enemigo5.ataque = 60, enemigo6.ataque = 70; 
    enemigo7.ataque = 80, enemigo8.ataque = 90, enemigo9.ataque = 100;
    jefefinal.ataque = 150;

    enemigo1.salud = 60, enemigo2.salud = 75, enemigo3.salud = 100 ; //Salud de enemigos
    enemigo4.salud = 150, enemigo5.salud = 150, enemigo6.salud = 175;
    enemigo7.salud = 175, enemigo8.salud = 175, enemigo9.salud = 175;
    jefefinal.salud = 500;

    int tablero[15] = {0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 2, 3};

    /*Representacion del tablero antes de comenzar la partida
    0 1 1 1 0 1 1 1 0 1 1  1  0  2  3   (0 casillas sin nada, 1 casillas de combate, 2 casilla que te regresa a la primera posicion, 3 casilla del jefe final )
    |0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|
    Tu posicion actual 0 
    */
    
    int x;
    float probabilidadCombate;
    int casosCombate;
    float dado;
    
    //El bucle acabara cuando el jugador llegue a la ultima posicion o cuando el jugador muera
    while (pos < 14 && muerto == false)
    {
        casosCombate = 0;
        srand(time(0)); //Inicializando generador de numero aleatorio
        x = pos;
        //Este for sirve para ver cuantas casillas de combate hay en las 3 posiciones siguientes
        for (int i = 0; i < 3; i++)
        {
            x++; //Incrementa las posiciones del tablero
            if ((tablero[x] == 1) || (tablero[x] == 3))
            {
                casosCombate += 1; //Si el tablero en dicha posicion es 1 o 3 se sumara uno a los casos de combate
            }
            
        }
        //cout << "casosCombate: " << casosCombate <<endl;
        //Para calcular la probabilidad de combate los casos favorables seran los casos de combate (Cuantas casillas de combate hay en las siguientes 3 posiciones)
        //entre los casos posibles que son 3 porque podes caer en tres posibles casillas, multiplicado por 100 para calcular el porcentaje
        probabilidadCombate =  casosCombate / 3 * 100;
        
        cout << endl;
        cout << "-------------------------------------------------------------------------" <<endl;
        cout << "Tu posicion inicial: " << pos << "\t\t Probabilidad de combate: " << probabilidadCombate << "%" << endl;
        dado = pos;
        pos += ((rand() % 3) + 1);//Genera un numero aleatorio entre 1-3 y se le suma a la posicion
        if (pos > 14)//Si la posicion mas el numero aleatorio da un numero mayor a 14, la posicion sera igual a 14 que es la ultima poscion del tablero
        {
            pos = 14;
        }                      //posicion final(pos) - posicion inicial(dado)
        cout << "En tu primer dado ha salido: " << pos - dado << "\t\t Tu posicion actual en el tablero es: " << pos << endl;

        switch (tablero[pos])
        {
        case 0:
            cout << "\nHAS LOGRADO PASAR SIN COMBATIR" << endl; //0 casilla vacia
            break;

        case 1:
            cout << "\nTe ha tocado combatir, buena suerte! " << endl;//1 casilla de combate
             
            cout<<endl;
            
            tablero[pos] = 0; // Se van eliminando mazmorras [enemigos] en el tablero a medida que avanza
                
                // se evalua que enemigo va se va a enfrentar dependiendo de la posicion del jugador en el tablero
                //No se repiten los enemigos
                switch (pos) 
                {
                case 1:
                    imprimirPersonaje();
                    imprimirEnemigo1();
                    combate(personaje, enemigo1);
                    break;
                
                case 2: 
                    imprimirPersonaje();
                    imprimirEnemigo2();
                    combate(personaje, enemigo2);
                    break;
                
                case 3: 
                    imprimirPersonaje();
                    imprimirEnemigo3();
                    combate(personaje, enemigo3);
                    break;

                case 5: 
                    imprimirPersonaje();
                    imprimirEnemigo4();
                    combate(personaje, enemigo4);
                    break;

                case 6: 
                    imprimirPersonaje();
                    imprimirEnemigo5();
                    combate(personaje, enemigo5);
                    break;

                case 7: 
                    imprimirPersonaje();
                    imprimirEnemigo6();
                    combate(personaje, enemigo6);
                    break;

                case 9: 
                    imprimirPersonaje();
                    imprimirEnemigo7();
                    combate(personaje, enemigo7);
                    break;

                case 10: 
                    imprimirPersonaje();    
                    imprimirEnemigo8();
                    combate(personaje, enemigo8);
                    break;

                case 11: 
                    imprimirPersonaje();
                    imprimirEnemigo9();
                    combate(personaje, enemigo9);
                    break;
                

                default:
                    break;
                }
                
            break;
        case 2:
            cout << "\nQue mala suerte! Tienes que empezar todo de nuevo" << endl;//2 casilla de reinicio
            tablero[pos] = 0;
            pos = 0;
            
            break;

        case 3:
            cout << "\nEl jefe final se aproxima, ve a por el!" << endl;// 3 casilla de Jefe final
            tablero[pos] = 0;
            imprimirJefeFinal();
            combate(personaje, jefefinal);
            break;

        default: 
            break;
        }
        
        cout << endl;
        system("pause");
    }

    if(muerto == true){//Si el jugador se murio saldra Game Over, sino saldra felicidades ...
        cout<<" GAME OVER "<<endl;
    }else{
        cout<<" FELICIDADES HAS GANADO EL JUEGO "<<endl;
    }
}