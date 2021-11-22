
#include <iostream>
#include<conio.h>
using namespace std;

int generaTamanio() {
	return rand() % 26 + 25;
}
void generaImprimeSecuencia(int* (&arreglo), int tamanio) {
	if (arreglo != nullptr)delete[] arreglo;
	arreglo = new int[tamanio];
	for (int i = 0; i < tamanio; i++) {
		arreglo[i] = rand() % 9 + 1;
	}
	cout << "MENSAJE GENERADO" << endl;
	for (int i = 0; i < tamanio; i++) {
		cout << arreglo[i] << " ";
	}
	cout << endl;
}
void alternosAscendentes(int arreglo[], int tamanio,int &cantidadAlternos) {
	cout << "Digitos alternos en secuencia ascendente:" << endl;
	for (int i = 0; i < tamanio - 4; i++) {
		if (arreglo[i + 4] > arreglo[i + 2] && arreglo[i + 2] > arreglo[i]) {
			cout << arreglo[i] << " " << arreglo[i + 2] << " " << arreglo[i + 4] << endl;
		}
	}
	for (int i = 0; i < tamanio - 4; i++) {
		if (arreglo[i + 4] > arreglo[i + 2] && arreglo[i + 2] > arreglo[i]) {
			cantidadAlternos++;
			break;
		}
	}
	
}
void imparRepetido(int arreglo[], int tamanio,int &cantidadImpares) {
	cout << "Impar repetido:" << endl;
	for (int i = 0; i < tamanio - 2; i++) {
		if (i % 2 == 0)break;
		if (arreglo[i] == arreglo[i + 1] && arreglo[i + 1] == arreglo[i + 2]) {
			cout << arreglo[i]<<endl;
			cantidadImpares++;
			continue;
		}

	}
}
void numeroMayor(int arreglo[], int tamanio) {
	int aux=0;
	for (int i = 0; i < tamanio; i++) {
		for (int j = 0;j < tamanio; j++) {
			if (arreglo[j] < arreglo[i]) {
				aux = arreglo[j];
				arreglo[j] = arreglo[i];
				arreglo[i] = aux;
			}
		}
	}
	cout << "Numero mayor que se puede formar:" << endl;
	for (int i = 0; i < tamanio; i++) {
		cout << arreglo[i] << " ";
	}
	cout << endl;
}
int main()
{
	srand(time(NULL));
	int tamanio;
	int* arreglo = nullptr;
	char letra;
	int cantidadMensajes = 0;
	int cantidadAlternos = 0;
	int cantidadImpares = 0;
	while (true) {
		cantidadMensajes++;
		tamanio = generaTamanio();
		generaImprimeSecuencia(arreglo, tamanio);
		alternosAscendentes(arreglo, tamanio,cantidadAlternos);
		imparRepetido(arreglo, tamanio,cantidadImpares);
		numeroMayor(arreglo, tamanio);
		cout << " \n";
		cout << "Para salir presione la tecla F, para continuar presione cualquier otra!" << endl;
		letra=_getch();
		letra = toupper(letra);
		if (letra == 'F')break;
	}
	cout << "\n";
	cout << "La cantidad de numeros que se procesaron: " << cantidadMensajes << endl;
	cout << "Cantidad de numeros en los cuales tres digitos de posicion alterna se encuentran en secuencia ascendente:" << cantidadAlternos << endl;
	cout << "Cantidad de impares consecutivos:" << cantidadImpares << endl;
	system("pause>nul");
	return 0;
}

