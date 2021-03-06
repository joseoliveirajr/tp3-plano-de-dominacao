#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "Mapa.h"

int main(int argc, char const *argv[]) {
	int numCores;
	///Validação dos argumentos na função principal
	int validArgument = (
		(argc == 2) &&
		(sscanf(argv[1], "%d", &numCores) == 1)
	);
	int numLinhas, numColunas;

    ///Entrada padrão
    int validScan = (scanf("%d%d", &numLinhas, &numColunas) == 2);
	if (validArgument && validScan){
		Mapa* mapa = criaMapa(numLinhas, numColunas);
		for (int i = 0; i < numLinhas; i++) {
		    for (int j = 0; j < numColunas; j++) {
		        validScan = scanf("%d", getEnderecoPosicao(mapa, i, j));
		        if (validScan != 1) {
		        	return 0;
                }
		    }
		}
		int melhorSoma = melhorSomaTotal(mapa, numCores);
		printf("%d\n", melhorSoma);

		liberaMapa(mapa);
	}
    return 0;
}
