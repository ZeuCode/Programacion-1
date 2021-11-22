
#include <iostream>
#include<conio.h>
using namespace std;
struct Encuestado {
	int edad;
	char respuesta;
	char genero;
	char nivelSocial;
};
void genera_y_muestra_arreglo(Encuestado arreglo[], int tamanio) {
	char generos[] = { 'F','M' };
	char respuestas[] = { 'A','D' };
	char niveles[] = { 'A','B','C' };
	for (int i = 0; i < tamanio; i++) {
		arreglo[i].edad = rand() % 58 + 18;
		arreglo[i].genero = generos[rand() % 2];
		arreglo[i].nivelSocial = niveles[rand() % 3];
		arreglo[i].respuesta = respuestas[rand() % 2];
	}

	cout << "\t   ";
	for (int i = 0; i < tamanio; i++) {
		cout.width(4);
		cout << "[" << i << "]";
	}
	cout << endl;
	cout << "Edad\t    ";
	for (int i = 0; i < tamanio; i++) {
		cout.width(4);
		cout << arreglo[i].edad << "  ";
	}
	cout << endl;
	cout << "Respuesta  ";
	for (int i = 0; i < tamanio; i++) {
		cout.width(4);
		cout << arreglo[i].respuesta << "  ";
	}
	cout << endl;
	cout << "Genero\t   ";
	for (int i = 0; i < tamanio; i++) {
		cout.width(4);
		cout << arreglo[i].genero << "  ";
	}
	cout << endl;
	cout << "Nivel\t   ";
	for (int i = 0; i < tamanio; i++) {
		cout.width(4);
		cout << arreglo[i].nivelSocial << "  ";
	}
	cout << endl;
}
void hallar_menor_y_cuantos(Encuestado arreglo[], int tamanio) {
	int menor = arreglo[0].edad;
	int cantidad = 0;
	for (int i = 1; i < tamanio; i++) {
		if (arreglo[i].edad < menor)menor = arreglo[i].edad;
	}
	for (int i = 0; i < tamanio; i++) {
		if (arreglo[i].edad == menor)cantidad++;
	}
	cout << "\n";
	cout << "La menor edad entre los encuestados es: " << menor << endl;
	cout << "Y la tienen " << cantidad << " persona(s)" << endl;

}
void porcentaje_aprobacion_y_desaprobacion(Encuestado arreglo[], int tamanio) {
	int hombresAprobando = 0;
	int mujeresDesaprobando = 0;
	int hombres = 0, mujeres = 0;
	for (int i = 0; i < tamanio; i++) {
		if (arreglo[i].genero == 'F')
		{
			mujeres++;
			if (arreglo[i].respuesta == 'D')mujeresDesaprobando++;
		}
		else {
			hombres++;
			if (arreglo[i].respuesta == 'A')hombresAprobando++;
		}
	}
	cout << "\n";
	if (hombres != 0)
		cout << "El porcentaje de hombres que aprueban al ministro:" << hombresAprobando*100 / (float)hombres<<"%"<<endl;
	else cout << "No encuesto ningun hombre" << endl;
	if (mujeres != 0)
		cout << "El porcentaje de mujeres que desaprueban al ministro:" << mujeresDesaprobando*100 / (float)mujeres<<"%"<<endl;
	else cout << "No encuesto ningun hombre" << endl;
}
void promedio_edad_por_genero(Encuestado arreglo[], int tamanio) {
	int edadHombres = 0,hombres=0;
	int edadMujeres = 0,mujeres=0;
	for (int i = 0; i < tamanio; i++) {
		if (arreglo[i].genero == 'F') {
			mujeres++;
			edadMujeres += arreglo[i].edad;
		}
		else {
			hombres++;
			edadHombres += arreglo[i].edad;
		}
	}
	cout << " \n";
	if (hombres != 0)
		cout << "Promedio de edad de los hombres encuestados: " << edadHombres / (float)hombres << endl;
	else cout << "No se encuestaron hombres" << endl;
	if (mujeres != 0)
		cout << "Promedio de edad de las mujeres encuestadas: " << edadMujeres / (float)mujeres << endl;
	else cout << "No se encuestaron mujeres" << endl;
}
void ordenar_y_mostrar(Encuestado arreglo[], int tamanio) {
	char aux1;
	int aux2;
	for (int i = 0; i < tamanio; i++) {
		for (int j = 0; j < tamanio; j++) {
			if (arreglo[i].nivelSocial < arreglo[j].nivelSocial) {
				aux2 = arreglo[i].edad;
				arreglo[i].edad = arreglo[j].edad;
				arreglo[j].edad = aux2;

				aux1 = arreglo[i].genero;
				arreglo[i].genero = arreglo[j].genero;
				arreglo[j].genero = aux1;

				aux1 = arreglo[i].nivelSocial;
				arreglo[i].nivelSocial = arreglo[j].nivelSocial;
				arreglo[j].nivelSocial = aux1;

				aux1 = arreglo[i].respuesta;
				arreglo[i].respuesta = arreglo[j].respuesta;
				arreglo[j].respuesta = aux1;

			}
		}
	}
	cout << " \n";
	cout << "\t   ";
	for (int i = 0; i < tamanio; i++) {
		cout.width(4);
		cout << "[" << i << "]";
	}
	cout << endl;
	cout << "Edad\t    ";
	for (int i = 0; i < tamanio; i++) {
		cout.width(4);
		cout << arreglo[i].edad << "  ";
	}
	cout << endl;
	cout << "Respuesta  ";
	for (int i = 0; i < tamanio; i++) {
		cout.width(4);
		cout << arreglo[i].respuesta << "  ";
	}
	cout << endl;
	cout << "Genero\t   ";
	for (int i = 0; i < tamanio; i++) {
		cout.width(4);
		cout << arreglo[i].genero << "  ";
	}
	cout << endl;
	cout << "Nivel\t   ";
	for (int i = 0; i < tamanio; i++) {
		cout.width(4);
		cout << arreglo[i].nivelSocial << "  ";
	}
	cout << endl;

}
int main() {
	srand(time(NULL));
	int tamanio;
	Encuestado* arreglo;
	do {
		cout << "Ingrese el numero de personas encuestadas: "; cin >> tamanio;
	} while (tamanio < 1 || tamanio>100);
	arreglo = new Encuestado[tamanio];
	genera_y_muestra_arreglo(arreglo, tamanio);
	hallar_menor_y_cuantos(arreglo, tamanio);
	porcentaje_aprobacion_y_desaprobacion(arreglo, tamanio);
	promedio_edad_por_genero(arreglo, tamanio);
	ordenar_y_mostrar(arreglo, tamanio);

	delete[] arreglo;

	system("pause>nul");
	return 0;

}