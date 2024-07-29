#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

struct Heroe
{
    int salud = 600;
    int ataque = 80;   
    float acc = 9; //si la suma de los dos dados es <= personaje.acc 
    int heal = 40; //puntos que se puede curar el enemigo despues de un ataque
    int ataqueX2;
    float aciertoX2; // auxiliares  para el danio x2

}personaje;

struct Enemigo
{
    int salud;
    int ataque;
    float acc; //si la suma de los dos dados es <= enemigo.acc
    int heal = 50; //puntos que se puede curar el enemigo despues de un ataque

}enemigo1,enemigo2,enemigo3,enemigo4,enemigo5,
enemigo6,enemigo7,enemigo8,enemigo9,jefefinal;

//VARIABLES GLOBALES 
int pos = 0; //posicion del jugador en el tablero

bool muerto = false;

//Representacion del tablero antes de comenzar la partida
int tablero[15] = {0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 2, 3};
/*
0 1 1 1 0 1 1 1 0 1 1  1  0  2  3   
"0" casillas sin nada, 
"1" casillas de combate, 
"2" casilla que te regresa a la primera posicion, 
"3" casilla del jefe final )
Posiciones: |0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|

Tu posicion actual 0 
*/



//Funcion para obtener num del 1-6
int Tirar_Dado()
{
    int ran;
    ran = rand() % 6 + 1;
    return ran;
}

bool comprobar_Acierto(float acc, int dado1, int dado2)
{
    if (dado1 + dado2 <= acc)
    {
        return true;
    }
    else
    {
        return false;
    }
}

float Calculo_Probabilidad(float acc)
{

    float sum = 0;
    int casoFavorable = 1;
    int Casofavorable = 5;
    for (int i = 0; i < acc - 1; i++)
    {
        if (i >= 6)
        {
            sum = sum + Casofavorable;
            Casofavorable--;
        }
        else
        {
            sum = sum + casoFavorable;
            casoFavorable++;
        }
    }
    return (sum / 36) * 100;
}

void Ataque(int *Salud, int *ataque, float *acc, bool turno) // a las funciones se deben de evaluar en direcciones de memoria de variable: &var
                                                               //en la definicion de la funcion se ocupan punteros: *ptr
{

    //Se muestra la probabilidad de acertar el ataque 
    cout << "\n\tProbabilidad de acierto: " << Calculo_Probabilidad(*acc) << "%" << endl;
    int dado1, dado2;
    bool acierto = false;
    dado1 = Tirar_Dado();
    dado2 = Tirar_Dado();

    cout << endl
         << "\tSe lanzan los dados y cae un " << dado1 << " y un " << dado2 << " (Suma debe de ser <= " << *acc << ")";


    // Se evalua si la suma de los dados cumple la condicion de acierto del enemigo correspondiente
    acierto = comprobar_Acierto(*acc, dado1, dado2);

    // Se verifica si es el turno del jugador o si es el del enemigo

    if (turno == true)
    {

        if (acierto == true)
        {
            cout << endl
                 << "\tGolpeas al enemigo y su salud disminuye a: ";
            *Salud = *Salud - *ataque;
            if (*Salud <= 0)
            {
                *Salud = 0;
            }
            cout << *Salud << endl <<endl;
            //system("pause");
        }
        else
        {
            cout << endl
                 << "\tTu ataque fallo" << endl <<endl;
                 //system("pause");
        }
    }
    else
    {

        if (acierto == true)
        {
            cout << endl
                 << "\tEl enemigo te golpea y tu salud disminuye a: ";
            *Salud = *Salud - *ataque;
            if (*Salud <= 0)
            {
                *Salud = 0;
            }
            
            cout << *Salud << endl <<endl;
            //system("pause");
        }
        else
        {
            cout << endl
                 << "\tEl enemigo fallo su ataque" << endl <<endl;
                 //system("pause");
        }
    }
}

void curarse(int *Salud, int *heal , bool turno) // a las funciones se deben de evaluar en direcciones de memoria de variable: &var
                                                    //en la definicion de la funcion se ocupan punteros: *ptr
{
   if (turno == true) //turno del jugador
    {
        int randInt = rand()%15+1; //funcion genera un numero aletorio de 1 a 15;
        if ((randInt == 1)|| (randInt == 2) || (randInt == 3)) // prob 3/15 de curarse
        {
        *Salud = *Salud +  *heal; //el personaje se cura el porcentaje de (salud * heal) 
        cout << "\tEl personaje se ha curado: " << *heal << " pts" <<endl;
        }
    }
    else //turno del enemigo
    {
        int randInt = rand()%20+1; //funcion genera un numero aletorio de 1 a 20;
        if((randInt == 1)|| (randInt == 2) || (randInt == 3)) // prob 3/20 de curarse
        {
        *Salud = *Salud + *heal; //el enemigo se cura heal pts de salud) 
        cout << "\tEl enemigo se ha curado: " << *heal << " pts" <<endl;
        }

    }
}

void combate(Heroe &personaje, Enemigo &enemigo)
{

    int accion;
    bool turno = true;
    int enclavado = pos;
    // El combate durara hasta que los puntos de salud del Heroe o del enemigo sean 0

    while ((enemigo.salud > 0) && (personaje.salud > 0) )
    {
        if ((enclavado == pos) || (tablero[pos] == 3)) // se evalua que enemigo va se va a enfrentar dependiendo de la posicion del jugador en el tablero
        {                                               //se imprime en loop los personajes cada turno
            if (tablero[pos] == 3)
            {
                enclavado = 12; //jefe
            }
            
            switch (enclavado)
            {
            case 1:
                    imprimirPersonaje();
                    imprimirEnemigo1();
                break;
            case 2:
                    imprimirPersonaje();
                    imprimirEnemigo2();
                break;
            case 3:
                    imprimirPersonaje();
                    imprimirEnemigo3();
                break;
            case 5:
                    imprimirPersonaje();
                    imprimirEnemigo4();
                break;
            case 6:
                    imprimirPersonaje();
                    imprimirEnemigo5();
                break;
            case 7:
                    imprimirPersonaje();
                    imprimirEnemigo6();
                break;
            case 9:
                    imprimirPersonaje();
                    imprimirEnemigo7();
                break;
            case 10:
                    imprimirPersonaje();
                    imprimirEnemigo8();
                break;
            case 11:
                    imprimirPersonaje();
                    imprimirEnemigo9();
                break;
            case 12:
                    imprimirPersonaje();
                    imprimirJefeFinal();
                break;           
                        
            default:
                break;
            }
        }
        
        
        // Si turno = true, es el turno del jugador, de lo contrario es el turno del enemigo
        if (turno == true)
        {   
            cout << "-------------TU TURNO------------" << endl;
            cout << endl;
            cout << "SALUD: " << personaje.salud << endl << "SALUD ENEMIGO: " << enemigo.salud << endl << "ATAQUE ENEMIGO: " << enemigo.ataque <<endl;
            bool continuar = true;
            do{
                cout<<endl;
                cout << "Elige una accion: " << endl;
                cout << "1. Ataque normal: " << personaje.ataque << " pts" << endl;
                cout << "2. Ataque pesado (doble de danio, -" << Calculo_Probabilidad(personaje.acc-3) <<"% " << "de acertar)" << endl;
                cout<<"Opcion: ";

                cin >> accion;
                //cout<<endl;
 
                switch (accion)
                {
                case 1:
                    Ataque(&enemigo.salud , &personaje.ataque, &personaje.acc, turno); // a las funciones se deben de evaluar en direcciones de memoria de variable: &var
                                                                                        //en la definicion de la funcion se ocupan punteros: *ptr
                    curarse(&personaje.salud , &personaje.heal, turno);
                    system("pause");
                    // Cambio al turno del enemigo
                    turno = false; 
                    continuar = false; // booleano que interrumpe el do while 
                    break;
                case 2:
                    // auxiliares para no modificar el original
                    personaje.ataqueX2 = personaje.ataque * 2; // danio de ataque x 2
                    personaje.aciertoX2 = personaje.acc - 3; // % de acierto disminuye en un 20%

                    Ataque(&enemigo.salud , &personaje.ataqueX2 , &personaje.aciertoX2, turno);
                    curarse(&personaje.salud , &personaje.heal, turno);
                    // Cambio al turno del enemigo
                    system("pause");
                    turno = false;
                    continuar = false;
                    break;
                default:

                    break;
                }
            }while(continuar);

        }
        else
        {
            if (enemigo.salud > 0)  //si el enemigo sigue en pie 
            {
                cout << "-------------TURNO ENEMIGO-------------" << endl;
                Ataque(&personaje.salud , &enemigo.ataque ,&enemigo.acc, turno); //enemigo ataca
                curarse(&enemigo.salud , &enemigo.heal, turno); //el enemigo tiene cierta probabilida de curarse despues de un ataque
                system("pause");
                turno = true;// Cambio al turno del jugador
            }
        
        }
    }

    if (personaje.salud <= 0)   //personaje muere
    {
        muerto = true; 
    }
    

}

