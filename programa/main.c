#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "Mapa.h"

int main(int argc, char const *argv[]) {
    ///Entrada
    int numLinhas, numColunas;
    int validScan = scanf("%d%d", &numLinhas, &numColunas);
    if (validScan == 2){
		Mapa* mapa = criaMapa(numLinhas, numColunas);

		int melhorSoma;
		int numCores = atoi(argv[1]);

		if (argc == 1) {
		    melhorSoma = melhorSomaTotal(mapa, 1);
		} else if (argc == 2) {
		    melhorSoma = melhorSomaTotal(mapa, numCores);
		}

		printf("%d\n", melhorSoma);

		///Liberação de memória
		liberaMapa(mapa);
	}
    return 0;
}
