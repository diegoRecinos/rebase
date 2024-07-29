#include <iostream>
using namespace std;

void imprimirPersonaje();
void imprimirEnemigo1();
void imprimirEnemigo2();
void imprimirEnemigo3();
void imprimirEnemigo4();
void imprimirEnemigo5();
void imprimirEnemigo6();
void imprimirEnemigo7();
void imprimirEnemigo8();
void imprimirEnemigo9();
void imprimirJefeFinal();


//Personaje principal
void imprimirPersonaje(){
    printf("  / %c \n",92);
    cout << "  | |" << endl;
    cout << "  | |" << endl;
    cout << "  | |" << endl;
    cout << "  |:|      __" << endl;
    cout << ",_|:|_,   /  )" << endl;
    cout << "  (Oo    / _I_" << endl;
    printf("   +%c %c  || __| \n",92,92);
    printf("      %c %c||___|\n",92,92);
    printf("        %c /.:.%c-%c \n",92,92,92);
    printf("         |.:. /-----%c \n",92);
    cout << "         |___|::oOo::|" << endl;
    cout << "         /   |:<_T_>:|" << endl;
    printf("        |_____%c ::: /\n",92);
    printf("         | |  %c %c:/\n",92,92);
    cout << "         | |   | |" << endl;
    printf("         %c /   | %c___\n",92,92);
    printf("         / |   %c_____%c \n",92,92);
    cout << "         `-'" << endl;
}

//Hormiga
void imprimirEnemigo1(){
    printf("                                                         %c / \n",92);
    cout << "                                                         >v<"<<endl;
    cout << "                                                         >O<"<<endl;
    cout << "                                                         >O<"<<endl;
}

//Hada
void imprimirEnemigo2(){
cout << "                                           .'.         .'." << endl;
printf("                                           |  %c       /  |\n",92);
printf("                                           '.  %c  |  /  .'\n",92);
printf("                                             '. %c%c|// .'\n",92,92);
cout << "                                               '-- --'" << endl;
printf("                                               .'/|%c'.\n",92);
cout << "                                              '..'|'..'" << endl;
}

//Diablito
void imprimirEnemigo3(){
printf("                                               |%c     ____\n",92);
printf("                                               | %c.-./ .-'\n",92);
printf("                                                %c _  _(\n",92);
cout << "                                                | .)(./" << endl;
printf("                                                |   %c(\n",92);
printf("                                                |     %c   |\n",92);
printf("                                                |  %cvvv   |\n",92);
cout << "                                                |  |__    |" << endl;
cout << "                                               /      `-. |" << endl;
}

//Buho
void imprimirEnemigo4(){
printf("                                             /%c /%c \n",92,92);
cout << "                                            ((ovo))" << endl;
cout << "                                            ():::()" << endl;
cout << "                                              VVV" << endl;
}

//Fantasma
void imprimirEnemigo5(){
cout << "                                                 .-." << endl;
cout << "                                                (o o) boo!" << endl;
printf("                                                | O %c\n",92);
printf("                                                 %c   %c\n",92,92);
cout << "                                                  `~~~'" << endl;

}

//Oruga
void imprimirEnemigo6(){
cout << "                                                   .    .                      " << endl;
cout << "                                                    )  (                      " << endl;
cout << "                                                   (.--.)_ _ _ _ _ _ _ _ _ _ _  " << endl;
cout << "                                                   ('_' ) } } } } } } } } } } }} " << endl;
cout << "                                                   <'--`<<<<<<<<<<<<<<<<<<<<<   " << endl;
}

//Yoda
void imprimirEnemigo7(){
cout << "                                                      __.-._" << endl;
cout << "                                                      '-._''7'" << endl;
cout << "                                                       /'.-c" << endl;
cout << "                                                       |  /T" << endl;
cout << "                                                      _)_/LI" << endl;
}

//Cabeza de alien
void imprimirEnemigo8(){
cout << "                                                             _________" << endl;
printf("                                                            /___   ___%c\n",92);
printf("                                                           //@@@%c /@@@%c%c\n",92,92,92);
printf("                                                           %c%c@@@/ %c@@@//\n",92,92,92);
printf("                                                            %c___ %c ___/\n",92,34);
cout << "                                                               | - |" << endl;
printf("                                                                %c_/\n",92);
}

//Esqueleto
void imprimirEnemigo9(){
cout << "                                                                .-." << endl;
cout << "                                                               (o.o)" << endl;
cout << "                                                                |=|" << endl;
cout << "                                                               __|__" << endl;
printf("                                                             //.=|=.%c%c\n",92,92);
printf("                                                            // .=|=. %c%c\n",92,92);
printf("                                                            %c%c .=|=. //\n",92,92);
printf("                                                             %c%c(_=_)//\n",92,92);
cout << "                                                              (:| |:)" << endl;
cout << "                                                               || ||" << endl;
cout << "                                                               () ()" << endl;
cout << "                                                               || ||" << endl;
cout << "                                                               || ||" << endl;
cout << "                                                              ==' '==" << endl;
}

//Godzilla?
void imprimirJefeFinal(){
cout << "                            _,-}}-._" << endl;
printf("                           /%c   }  /%c\n",92,92);
printf("                          _|(O%c_ _/O)\n",92);
cout << "                        _|/  (__''__)" << endl;
printf("                      _|%c/    WVVVVW\n",92);
printf("                     %c _%c     %cMMMM/_\n",92,92,92);
printf("                   _|%c_%c     _ '---; %c_\n",92,92,92);
printf("              /%c   %c _%c/      %c_   /   %c\n",92,92,92,92,92);
printf("             / (    _%c/     %c   %c  |'VVV\n",92,92,92);
printf("            (  '-,._%c_.(      'VVV /\n",92);
printf("             %c         /   _) /   _)\n",92);
printf("              '....--''%c__vvv)%c__vvv)\n",92,92);
}

