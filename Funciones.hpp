#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

struct Heroe
{
    int salud = 400;
    int ataque = 50;   
    float acc = 9; //si la suma de los dos dados es <= personaje.acc 
    int heal = 10; //porcentaje que se puede curar el enemigo despues de un ataque
    int ataqueX2;
    float aciertoX2; // auxiliares  para el danio x2

}personaje;

struct Enemigo
{
    int salud;
    int ataque;
    float acc; //si la suma de los dos dados es <= enemigo.acc
    int heal = 50; //porcentaje que se puede curar el enemigo despues de un ataque

}enemigo1,enemigo2,enemigo3,enemigo4,enemigo5,
enemigo6,enemigo7,enemigo8,enemigo9,jefefinal;

//VARIABLES GLOBALES 

bool muerto = false;




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
            cout << *Salud << endl;
        }
        else
        {
            cout << endl
                 << "\tTu ataque fallo" << endl;
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
            
            cout << *Salud << endl;
        }
        else
        {
            cout << endl
                 << "\tEl enemigo fallo su ataque" << endl;
        }
    }
}

void curarse(int *Salud, int *heal , bool turno) // a las funciones se deben de evaluar en direcciones de memoria de variable: &var
                                                    //en la definicion de la funcion se ocupan punteros: *ptr
{
   if (turno == true) //turno del jugador
    {
        int randInt = rand()%15+1; //funcion genera un numero aletorio de 1 a 10;
        if ((randInt == 1)|| (randInt == 2)) // prob 2/15 de curarse
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
        *Salud = *Salud + *heal; //el enemigo se cura el porcentaje de (salud * heal) 
        cout << "\tEl enemigo se ha curado: " << *heal << " pts" <<endl;
        }

    }
}

void combate(Heroe &personaje, Enemigo &enemigo)
{

    int accion;
    bool turno = true;

    // El combate durara hasta que los puntos de salud del Heroe o del enemigo sean 0

    while ((enemigo.salud > 0) && (personaje.salud > 0) )
    {

        // Si turno = true, es el turno del jugador, de lo contrario es el turno del enemigo
        if (turno == true)
        {   
            cout << endl;
            cout << "SALUD: " << personaje.salud << endl << "SALUD ENEMIGO: " << enemigo.salud << endl << "ATAQUE ENEMIGO: " << enemigo.ataque <<endl;

            cout << endl;
            cout<<endl;
            cout<< "Es tu turno!" << endl;
            cout << "Elige una accion: " << endl;
            cout << "1. Ataque normal: " << personaje.ataque << " pts" << endl;
            cout << "2. Ataque pesado (doble de danio, -20% Probabilidad de acertar)" << endl;
            cout<<"opcion: ";

            cin >> accion;
            cout<<endl;

            bool continuar = true;
            do{
                switch (accion)
                {
                case 1:
                    Ataque(&enemigo.salud , &personaje.ataque, &personaje.acc, turno); // a las funciones se deben de evaluar en direcciones de memoria de variable: &var
                                                                                        //en la definicion de la funcion se ocupan punteros: *ptr
                    curarse(&personaje.salud , &personaje.heal, turno);
                    // Cambio al turno del enemigo
                    turno = false; 
                    continuar = false; // booleano que interrumpe el do while 
                    break;
                case 2:
                    // auxiliares para no modificar el original
                    personaje.ataqueX2 = personaje.ataque * 2; // danio de ataque x 2
                    personaje.aciertoX2 = personaje.acc - 2.4; // % de acierto disminuye en un 20%

                    Ataque(&enemigo.salud , &personaje.ataqueX2 , &personaje.aciertoX2, turno);
                    curarse(&personaje.salud , &personaje.heal, turno);
                    // Cambio al turno del enemigo
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
                Ataque(&personaje.salud , &enemigo.ataque ,&enemigo.acc, turno); //enemigo ataca
                curarse(&enemigo.salud , &enemigo.heal, turno); //el enemigo tiene cierta probabilida de curarse despues de un ataque
                turno = true;// Cambio al turno del jugador
            }
        
        }
    }

    if (personaje.salud <= 0)   //personaje muere
    {
        muerto = true; 
    }
    

}

