#include<iostream>
using namespace std;


void GenerayLista_Paralelos(char* Vgripe, char* Vtos, int* Vpesos, int n) {
	char siono[] = { 'S','N' };
	for (int i = 0; i < n; i++) {
		Vgripe[i] = siono[rand() % 2];
		Vtos[i] = siono[rand() % 2];
		Vpesos[i] = rand() % 31 + 30;
	}
	cout << "Datos aleatoriamente generados : \n\n";
	for (int i = 0; i < n; i++) {
		cout << "Alumno " << i + 1 << endl;
		cout << "Gripe: " << Vgripe[i] << endl;
		cout << "Tos: " << Vtos[i] << endl;
		cout << "Peso: " << Vpesos[i] << "\n\n";
	}
}

float Porcentaje_gripe_tos(char* Vgripe, char* Vtos, int* Vpesos, int n) {
	if (n == 0)return 0;
	int cant = 0;
	for (int i = 0; i < n; i++) {
		if (Vgripe[i] == 'S' && Vtos[i] == 'S') {
			cant++;
		}
	}

	float porcentaje = (float)cant * 100 / (float)n;
	return porcentaje;
}

float Promedio_pesos(char* Vgripe, char* Vtos, int* Vpesos, int n) {
	float suma = 0, cant = 0;
	for (int i = 0; i < n; i++) {
		if (Vgripe[i] == 'S' || Vtos[i] == 'S') {
			cant++;
			suma += Vpesos[i];
		}
	}
	if (cant == 0)return 0;
	return suma / cant;

}
void Listado_ordenado(char* Vgripe, char* Vtos, int* Vpesos, int n) {
	char aux1;
	int aux2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (Vpesos[j] < Vpesos[i]) {
				aux1 = Vgripe[i];
				Vgripe[i] = Vgripe[j];
				Vgripe[j] = aux1;
				aux1 = Vtos[i];
				Vtos[i] = Vtos[j];
				Vtos[j] = aux1;
				aux2 = Vpesos[i];
				Vpesos[i] = Vpesos[j];
				Vpesos[j] = aux2;
			}
		}
	}
	cout << "Peso  Gripe  Tos" << endl;
	for (int i = 0; i < n; i++) {
		cout << " " << Vpesos[i] << "     " << Vgripe[i] << "     " << Vtos[i] << endl;
	}
}
int main4587() {
	srand(time(NULL));
	int n = 0;
	do {
		cout << "Ingrese numero de alumnos: "; cin >> n;
	} while (n < 0 || n>20);
	char* Vgripe = new char[n];
	char* Vtos = new char[n];
	int* Vpesos = new int[n];
	GenerayLista_Paralelos(Vgripe, Vtos, Vpesos, n);
	cout << "Resultados :" << endl;
	cout << "Porcentaje de alumnos(as) que tienen gripe y tos: " << Porcentaje_gripe_tos(Vgripe, Vtos, Vpesos, n) << " %" << endl;
	cout << "Promedio de  pesos de los alumnos con alguna enfermedad: " << Promedio_pesos(Vgripe, Vtos, Vpesos, n) << " kg" << endl;
	cout << "Listado ordenado :" << endl;
	Listado_ordenado(Vgripe, Vtos, Vpesos, n);
	delete[] Vgripe;
	delete[] Vtos;
	delete[] Vpesos;
	system("pause>nul");
	return 0;
}



int main342345() {
	srand(time(NULL));
	setlocale(LC_ALL, "spanish");
	int n, patron;
	int** matriz = nullptr;
	do {
		cout << "Ingrese el tamaño de la matriz :"; cin >> n;
	} while (n < 1 || n>30);
	matriz = new  int* [n];
	for (int i = 0; i < n; i++) {
		matriz[i] = new int[n];
	}
	//generando datos
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matriz[i][j] = rand() % 10;
		}
	}
	//IMPRIMIR MATRIZ
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	do {
		cout << "Ingrese patron numerico :"; cin >> patron;
	} while (patron < 100 || patron>999);


	//el patron siempre tiene 3 cifras
	cout << "\n";

	int veces = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j <= n - 3) {
				if (matriz[i][j] == patron / 100 && matriz[i][j + 1] == (patron % 100) / 10 && matriz[i][j + 2] == patron % 10) {
					veces++;
				}
			}
		}
	}
	cout << "El número de veces que se repite el patrón es: " << veces << endl;



	for (int i = 0; i < n; i++) {
		delete[] matriz[i];
	}
	delete[] matriz;
	return 0;
}


int main() {
	srand(time(NULL));

	int n = 30;
	int* codVendedores = new int[n];
	int** matriz = new int* [n];
	for (int i = 0; i < n; i++) {
		codVendedores[i] = 201 + i;
	}
	for (int i = 0; i < n; i++) {
		matriz[i] = new int[3];
	}
	for (int i = 0; i < n; i++) {
		matriz[i][0] = rand() % 40 + 10;
		matriz[i][1] = rand() % 90 + 10;
		matriz[i][2] = rand() % 40 + 10;
	}
	cout << "Matriz :\n\n";
	cout << "  Codigo vendedor\tMin. a fijo\tMin. a celular\tMen. de texto" << endl;
	for (int i = 0; i < n; i++) {
		cout << "      " << codVendedores[i];
		cout << "\t\t   " << matriz[i][0] << "\t\t    " << matriz[i][1] << "\t\t    " << matriz[i][2];
		cout << "\n";
	}

	cout << "\n";
	int maxMinCelulares = matriz[0][1];
	int pos = 0;
	for (int i = 1; i < n; i++) {
		if (matriz[i][1] > maxMinCelulares)
		{
			maxMinCelulares = matriz[i][1];
			pos = i;
		}
	}
	cout << "Resultados :\n";
	cout << "Mayor minutos a celulares : " << maxMinCelulares << endl;
	cout << "Codigo(s) de los vendedores con mayor minutos a celulares: \n";
	for (int i = 1; i < n; i++) {
		if (matriz[i][1] == maxMinCelulares)
			cout << codVendedores[i]<<endl;
	}
	float aPagar;
	cout << "Exceso a pagar por cada vendedor :" << endl;
	for (int i = 0; i < n; i++) {
		aPagar = 0;
		if (matriz[i][0] > 20) {
			aPagar += (matriz[i][0] - 20) * 0.35;
		}
		if (matriz[i][1] > 40) {
			aPagar += (matriz[i][1] - 40) * 0.45;
		}
		if (matriz[i][2] > 20) {
			aPagar += (matriz[i][2] - 20) * 0.20;
		}
		cout << "Vendedor " << i + 1 << " debe pagar " << aPagar << endl;
	}
	cout << "Promedios :" << endl;
	int suma1=0, suma2=0, suma3 = 0;
	for (int i = 0; i < n; i++) {
		suma1 += matriz[i][0];
		suma2 += matriz[i][1];
		suma3 += matriz[i][2];
	}
	cout << "Promedio de min a fijos :" << (float)suma1 / (float)n<<endl;
	cout << "Promedio de min a celulares :" << (float)suma2 / (float)n<<endl;
	cout << "Promedio de men de texto :" << (float)suma3 / (float)n<<endl;

	for (int i = 0; i < n; i++) {
		delete[] matriz[i];
	}
	delete[] matriz;
	delete[] codVendedores;



	return 0;
}