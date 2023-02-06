#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib>


using namespace std;
#define NOMBRE "AXEL AQUINO\n"

/* RECUERDO DE FIGURAS PARA EL TABLERO
    printf("IGUAL O DOS LINEAS  \xCD  \n");
    printf("T DE TROY \xCB   \n");
    printf("T DE TROY PA ABAJO \xCA  \n");
    printf("CRUZ \xCE   \n");
    printf("BARRA VERTICAL   \xBA  \n");
    printf("CODO A LA IZQUEIRDA \xBC    \n");
    printf("CONJUNTO VACIO \x9D   \n");
    printf("CUADRADITO BLANCO \xDC   \n");
 */
    int aciertosJugador2, aciertosJugador1, fallosJugador2, fallosJugador1;
    float porcJugador1,  porcJugador2;
    char c; //almacena una variable char para usarla en la funcion "traducir" y que se devuelva un int.
    char tablero2 [10][11] = {

        //lineas de posicion
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"}

    };
    char tablero [10][11] = {

        //lineas de posicion
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"}

    };
     char tablero3 [10][11] = {

        //lineas de posicion
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"},
        {"__________"}

    };

//traduce los datos char a int para que funcione con las coordenadas correctas.
int traducir(char caract){
    switch(caract){
    case 'a':
    case 'A':
       return 1;
        break;
    case 'b':
    case 'B':
       return 2;
        break;
    case 'c':
    case 'C':
       return 3;
        break;
    case 'd':
    case 'D':
       return 4;
        break;
    case 'e':
    case 'E':
       return  5;
        break;
    case 'f':
    case 'F':
       return 6;
        break;
    case 'g':
    case 'G':
       return 7;
        break;
    case 'h':
    case 'H':
       return 8;
        break;
    case 'i':
    case 'I':
       return 9 ;
        break;
    case 'j':
    case 'J':
       return 10;
        break;
    }
}

//imprime los tableros.
void imprimir ( char (*tablero)[11] ) {
    system("cls");
    for( int c = 0; c < 35; c++  ){
        printf("\xCD");
    }
    printf("\n  \xBA A  B  C  D  E  F  G  H  I  J  \xBA\n");
    printf("\xCD\xCD\xCE");
    for( int c = 0; c < 31; c++  ){
        printf("\xCD");
    }
    printf("\xBA\n");

    for ( int i = 0; i < 10; i++ ) {
        if(i != 9){
            printf("y%i", i+1);
            printf("\xBA ");
        } else {
            printf("10");
            printf("\xBA ");
        }
        for ( int z = 0; z < 10; z++ ) {
            printf("%c",tablero[i][z]);
            printf("  ");//posiciona las ubicaciones
        }
        printf("\xBA\n");
        printf("  \xBA                               \xBA\n");
    }

    //imprime lineas de abajo del tablero y 2 espacios en el final
    printf("\xCD\xCD\xCA");
    for( int c2 = 0; c2 < 31; c2++  ){
        printf("\xCD");
    }
    printf("\xBC\n\n");
}

//coloca barcos en tablero 1
void colocarBarcos(int i){
        int x, y, n = i;

    imprimir(tablero);
    for(int i = 1; i <= 4; i++){
     //leemos dato
        int band = 0;
      while(band == 0){
        printf("----JUGADOR %i----\n", n);
        printf("----PORTA AVIONES = POSICION %i DE 4----\n", i);
        printf("Elija una coordenada de A a J para posicionar el porta aviones\n");
        scanf("%s",&c);
        x = traducir(c);
        printf("Elija una coordenada de Y1 a Y10 para posicionar el porta aviones\n");
        scanf("%i",&y);
        x--;//restamos uno por desface
        y--;
        if ( (x >= 0 && y  >= 0) && tablero[y][x] != 'P'){
                tablero[y][x] = 'P';
                band = 1;
        }else {
            system("cls");
            imprimir(tablero);
            printf("Error, vuelva a ingresar las coordenadas\n");
            }
      }
            imprimir ( tablero );
    }
    Sleep(200);

      for(int i = 1; i <= 2; i++){
     //leemos dato
        int band = 0;
      while(band == 0){
        printf("----JUGADOR %i----\n", n);
        printf("----DESTRUCTOR = POSICION %i DE 2----\n", i);
        printf("Elija una coordenada de A a J para posicionar el destructor\n");
        scanf("%s",&c);
        x = traducir(c);
        printf("Elija una coordenada de Y1 a Y10 para posicionar el destructor\n");
        scanf("%i",&y);

        x--;//restamos uno por desface
        y--;
        if ( x >= 0 && y  >= 0 && tablero[y][x] != 'P' && tablero[y][x] != 'D' ){
                tablero[y][x] = 'D';
                band = 1;
        } else {
            system("cls");
            imprimir(tablero);
            printf("Error, vuelva a ingresar las coordenadas\n");
        }
      }
            imprimir ( tablero );
    }
    Sleep(200);

     for(int i = 1; i <= 3; i++){
     //leemos dato
        int band = 0;
         while(band == 0){
        printf("----JUGADOR %i----\n", n);
        printf("----SUBMARINO = POSICION %i DE 3----\n", i);
        printf("Elija una coordenada de A a J para posicionar el submarino\n");
        scanf("%s",&c);
        x = traducir(c);
        printf("Elija una coordenada de Y1 a Y10 para posicionar el submarino\n");
        scanf("%i",&y);

        x--;//restamos uno por desface
        y--;
        if ( x >= 0 && y  >= 0 && tablero[y][x] != 'P' && tablero[y][x] != 'D' && tablero[y][x] != 'S'){
                tablero[y][x] = 'S';
                band = 1;
            } else {
            system("cls");
            imprimir(tablero);
            printf("Error, vuelva a ingresar las coordenadas\n");
            }
        }
            imprimir ( tablero );
    }
    Sleep(200);

     for(int i = 1; i <= 2; i++){
     //leemos dato
        int band = 0;
        while(band == 0){
        printf("----JUGADOR %i----\n", n);
        printf("----CRUCERO = POSICION %i DE 2----\n", i);
        printf("Elija una coordenada de A a J para posicionar el crucero\n");
        scanf("%s",&c);
        x = traducir(c);
        printf("Elija una coordenada de Y1 a Y10 para posicionar el crucero\n");
        scanf("%i",&y);

        x--;//restamos uno por desface
        y--;
        if ( x >= 0 && y  >= 0 && tablero[y][x] != 'P' && tablero[y][x] != 'D' && tablero[y][x] != 'S' && tablero[y][x] != 'C' ){
                tablero[y][x] = 'C';
                band = 1;
        } else {
            system("cls");
            imprimir(tablero);
            printf("Error, vuelva a ingresar las coordenadas\n");
            }
        }
            imprimir ( tablero );
    }
    Sleep(200);
}

//reinicia tableros 1 y 2 copiando el tablero 3 (no encontre otra forma de hacerlo mas que usando un tablero de mas)
void copiar(){
      for(int i = 0; i < 10; i++){
        for(int j=0; j < 11; j++){
            tablero2[i][j] = tablero3[i][j];
            tablero[i][j] = tablero3[i][j];
            }
        }
    }

//funcion mas importante y extensa . Es la que se encarga de combinar las demas funciones para que se juege correctamente.
void jugar(){

    int aciertosJugador2 = 0, aciertosJugador1 = 0, fallosJugador2 = 0, fallosJugador1 = 0, porta = 0, sub = 0, cruc = 0, dest = 0;
    float porcJugador1 = 0; porcJugador2 = 0;

    for (int i = 1; i <= 2; i ++){
    int y, x, aciertos = 0, fallos = 0, band = 2, total;
    if(i == 2){
        copiar();
        band = 1;
    }
    colocarBarcos(i);
    system("cls");
    imprimir(tablero2);
    while(aciertos < 11){
        //atacamos en tablero 2
        printf("\t--------JUGADOR %i ATACA--------\n\t Aciertos: %i\n\t Fallos: %i\n",band, aciertos, fallos);
        printf("Elija una coordenada de A a J para atacar\n");
        scanf("%s",&c);
        x = traducir(c);
        printf("Elija una coordenada de Y1 a Y10 para atacar\n");
        scanf("%i",&y);
        x--;//restamos uno por desface
        y--;
        if( tablero2[y][x] == 'P' || tablero2[y][x] == 'D' || tablero2[y][x] == 'S' || tablero2[y][x] == 'C' ){
            aciertos -= 1;
             switch(tablero[y][x]){
            case 'P':
                porta -= 1;
                break;
            case 'C':
                cruc -= 1;
                break;
            case 'D':
               dest -= 1;
                break;
            case 'S':
                sub -= 1;
                break;
                }
        }
        switch(tablero[y][x]){
            case 'P':
                tablero2[y][x] = 'P';
                imprimir(tablero2);
                aciertos += 1;
                porta += 1;
                if(porta == 4){
                    printf("EL PORTA AVIONES A SIDO DESTRUIDO\n");
                }
                break;
            case 'C':
                tablero2[y][x] = 'C';
                imprimir(tablero2);
                aciertos += 1;
                cruc += 1;
                if(cruc == 2){
                    printf("EL CRUCERO A SIDO DESTRUIDO\n");
                }
                break;
            case 'D':
                tablero2[y][x] = 'D';
                imprimir(tablero2);
                aciertos += 1;
                dest += 1;
                if(dest == 2){
                    printf("EL DESTRUCTOR A SIDO DESTRUIDO\n");
                }
                break;
            case 'S':
                tablero2[y][x] = 'S';
                imprimir(tablero2);
                aciertos += 1;
                sub += 1;
                if(sub == 3){
                    printf("EL SUBMARINO A SIDO DESTRUIDO\n");
                }
                break;
            default:
                tablero2[y][x] = '\x9D';
                imprimir(tablero2);
                fallos += 1;
            }
        }
            total = aciertos + fallos;
            if(i == 1){
                aciertosJugador2 = aciertos;
                fallosJugador2 = fallos;
                porcJugador2 = aciertos*100/total;
            }else if (i == 2) {
                aciertosJugador1 = aciertos;
                fallosJugador1 = fallos;
                porcJugador1 = aciertos*100/total;
            }
    }
    printf("JUGADOR 1: \n Aciertos: %i\n Fallos: %i\n Porcentaje: %.1f\n", aciertosJugador1, fallosJugador1, porcJugador1);
    printf("JUGADOR 2: \n Aciertos: %i\n Fallos: %i\n Porcentaje: %.1f\n", aciertosJugador2, fallosJugador2, porcJugador2);
    if(porcJugador1 == porcJugador2){
        printf("------EMPATE------\n");
    } else if(porcJugador1 > porcJugador2){
        printf("------GANADOR JUGADOR 1------\n");
    } else if(porcJugador1 < porcJugador2){
        printf("------GANADOR JUGADOR 2------\n");
    }
    printf("Pulse cualquier tecla para volver al menu principal\n");
    getch();
}

//llamamos al score para visualizar las estadisticas de la ultima partida (las cuales fueron almacenadas en la funcion "jugar").
void score(){
    system("cls");
    if(aciertosJugador1 == 0){
        printf("\n---LOS DATOS SE REGISTRARAN CUANDO JUEGUEN AL MENOS UNA PARTIDA---\n\n");
    }
    printf("----ULTIMA PARTIDA----\n");
    printf("JUGADOR 1: \n Aciertos: %i\n Fallos: %i\n Porcentaje: %.1f\n", aciertosJugador1, fallosJugador1, porcJugador1);
    printf("JUGADOR 2: \n Aciertos: %i\n Fallos: %i\n Porcentaje: %.1f\n", aciertosJugador2, fallosJugador2, porcJugador2);
    printf("EL RESULTADO DE LA PARTIDA FUE: \n");
     if(porcJugador1 == porcJugador2){
        printf("------EMPATE------\n");
    } else if(porcJugador1 > porcJugador2){
        printf("------GANADOR JUGADOR 1------\n");
    } else if(porcJugador1 < porcJugador2){
        printf("------GANADOR JUGADOR 2------\n");
    }
    printf("Pulse cualquier tecla para volver al menu principal\n");
    getch();
}

//imprime el menu.
void imprimirMenu() {
    system("cls");
	printf("\n\xCD\xCD BATALLA NAVAL \xCD\xCD\n");
	printf("\n1) Jugar");
	printf("\n2) Score");
	printf("\n3) Creditos");
	printf("\n4) Salir\n");
	printf("\nIngrese una opcion: ");
}

//funcion que anida las anteriores para que la lectura del codigo sea mas sencilla y visualmente llevadera, ordena el codigo entero en un simple switch.
void Hola() {
    int opc;
	imprimirMenu();
	scanf("%i", &opc);
        while(opc != 4 ){
           switch(opc){
            case 1:
                    jugar();
                    copiar();
                    imprimirMenu();
                    scanf("%i", &opc);
                break;
            case 2:
                    score();
                    imprimirMenu();
                    scanf("%i", &opc);
                break;
            case 3:
                    printf("Developer: %s", NOMBRE);
                    printf("\nIngrese una opcion: ");
                    scanf("%i", &opc);
                break;
            default:
                    printf("Ingrese una opcion correcta\n");
                    scanf("%i", &opc);
                break;

           }
        }
}

//si existe una funcion en el main que se llame "hola", no puede faltar el "chau". Creada por simple maña de que se llame a dos funciones en el main.
void Chau(){
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD VUELVA PRONTO \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\n\n\t\t\t\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD GRACIAS POR JUGAR CON NOSOTROS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n\n\n\n\n\n\n\n\n\n");

}


int main() {

    Hola();
    Chau();

    return 0;
}

