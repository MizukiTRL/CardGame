#include <stdio.h>
#include "../gameLogic/setUp.c"

int main(int n) {
    
	int menuChoice;

    do {
        printf("\n------------ BIENVENIDOS AL JUEGO ------------\n");
        printf("\n1. Nuevo juego\n");
        printf("2. Continuar\n");
        printf("3. Salir\n");
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1:
                printf("1. Nuevo juego CHECK\n");
                menuInicial(n);
                break;
            case 2:
                printf("2. Continuar CHECK\n");
                menuInicial(n);
                break;
            case 3:
                printf("3. Saliendo del programa...\n");
                break;
            default:
                printf("\nOpcion invalida, intenta de nuevo\n");
                break;
        }
    } while (menuChoice != 3);

    return 0;
}

int menuInicial(int n ) {

	int menuChoice = 0; 

    do {

    printf("\n");
    printf("\n");
    printf("\n------------ BIENVENIDOS AL JUEGO ------------\n");
	printf("\n");
	printf("1. Explorar\n");
	printf("2. Deck\n");
	printf("3. Bestiario\n");
	printf("4 . Salir\n");
	scanf("\n%d", &menuChoice);
	printf("\n");
	printf("\n");


	switch (menuChoice) {
        case 1:
            printf("1. explorar");
            break;
        case 2:
		printf("2. deck");
			break;
		case 3:
		printf("3. bestiario");
		
		// ZONA DE COMBATE
		// - INICIAR COMBATE
		// - CAMBIAR ENEMIGO
		
		// ZONA DE DESCANSO
		//- RECUPERAR
		//- TIENDA
		//- GUARDAR
		// - - PROGRESO EN ARCHIVO BINARIO O ARCHIVO TEXTO, VOLVER A ZONA DESCANSO
		//- SEGUIR
		
			break;
		case 4:
		printf("4. Regresando al menu principal\n");
            printf("\nSeguro de que deseas ir al menu principal?...\n");
            printf("1. Si\n");
            printf("2. No\n");

            int confirmation = 0;
            printf("\nSelecciona una opcion: ");
            scanf("%d", &confirmation);

            switch(confirmation) {
                case 1:
                    printf("Continuando en el menu principal...\n");
                    main(n);
                    break;
                case 2:
                	menuInicial(2);
                	break;
                default:
                    printf("OPCION INVALIDA, INTENTE DE NUEVO\n");
                    break;
            }
            break;
        default:
            printf("\nOPCION INVALIDA, INTENTE DE NUEVO\n");
            break;
        }
    
	}	while (menuChoice =!23);
	
	
    return 0;
}
