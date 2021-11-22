
#include <iostream>
using namespace std;
void genera_y_muestra_matriz(int matriz[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j ++) {
			matriz[i][j] = rand() % 9 + 1;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}
int genera_numero_capicua() {
	int digitos[3];
	digitos[0] = rand() %9+1;
	digitos[1] = rand() % 9 + 1;
	digitos[2] = digitos[0];
	int numero = digitos[2] + 10 * digitos[1] + 100 * digitos[0];
	return numero;
}
void frecuencia_cantidad_veces(int matriz[10][10],int capicua) {
	int digitoUno = capicua / 100;
	int digitoDos = (capicua % 100)/10;
	int cantidadUno = 0;
	int cantidadDos = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (matriz[i][j] == digitoUno)cantidadUno++;
			if (matriz[i][j] == digitoDos)cantidadDos++;
		}
	}
	cout << "Digito " << digitoUno << " aparece " << cantidadUno << " veces" << endl;
	cout << "Digito " << digitoDos << " aparece " << cantidadDos << " veces" << endl;
}
void numero_capicua_en_matriz(int matriz[10][10], int capicua) {
	int digitoUno = capicua / 100;
	int digitoDos = (capicua % 100) / 10;
	int apariciones = 0;
	cout << "Los puntos donde aparece el numero capicua en forma horizontal son:" << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (matriz[i][j] == digitoUno && matriz[i][j + 1] == digitoDos && matriz[i][j + 2] == digitoUno) {
				cout << "Fila: " << i << ", Columna: " << j << endl;
				apariciones++;
			}
		}
	}
	cout << "\nTotal de apariciones: " << apariciones << endl;
}
int main() {
	srand(time(NULL));
	int matriz[10][10];
	int capicua;
	genera_y_muestra_matriz(matriz);
	capicua = genera_numero_capicua();
	cout << "\nNumero capicua generado: " << capicua << endl;
	cout << "\nResultados:" << endl;
	frecuencia_cantidad_veces(matriz, capicua);
	cout << "\n";
	numero_capicua_en_matriz(matriz, capicua);
	
	system("pause>nul");
	return 0;
}