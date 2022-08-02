#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char tString[30];

typedef struct
{
	int nroLibreta;
	tString nombre;
}tDatos;

typedef struct nodo
{
	tDatos alumnos;
	struct nodo *siguiente;
}tLista;

tLista *lista;

void InicializarLista();
bool ListaVacia();
void InsertarPrimero(tDatos);
void InsertarAdelante(tDatos);
void InsertarElemento(tDatos);
void EliminarPrimero();
void InsertarK(int, tDatos);
void EliminarK(int);
void Visualizar();
int CantidadAlumnos();
void Menu();

int main()
{
	InicializarLista();
	Menu();
	return 0 ;
}

void InicializarLista()
{
	lista = NULL;
}

bool ListaVacia()
{
	return (lista == NULL);
}

void InsertarPrimero(tDatos pDatos)
{
	lista = (tLista *) malloc(sizeof(tLista));
	lista->alumnos.nroLibreta = pDatos.nroLibreta;
	strcpy(lista->alumnos.nombre, pDatos.nombre);
	lista->siguiente = NULL;
	printf("Primer elemento insertado!\n");
}

void InsertarAdelante(tDatos pDatos)
{
	tLista *nuevoNodo;
	nuevoNodo = (tLista *) malloc(sizeof(tLista));
	nuevoNodo->alumnos.nroLibreta = pDatos.nroLibreta;
	strcpy(nuevoNodo->alumnos.nombre, pDatos.nombre);
	nuevoNodo->siguiente = lista;
	lista = nuevoNodo;
	printf("Elemento insertado!\n");
}

void InsertarElemento(tDatos pDatos)
{
	if(ListaVacia())
		InsertarPrimero(pDatos);
	else
		InsertarAdelante(pDatos);
}

void EliminarPrimero()
{
	if(!ListaVacia())
	{
		tLista *nodoSuprimir;
		nodoSuprimir = lista;
		lista = lista->siguiente;
		free(nodoSuprimir);
		printf("Primer elemento eliminado!\n");
	}
	else
		printf("No se puede eliminar!n");
}

void Visualizar()
{
	tLista *aux;
	aux = lista;
	if(!ListaVacia())
	{
		while(aux != NULL)
		{
		printf("Numero de libreta universitaria: %d\n", aux->alumnos.nroLibreta);
		printf("Nombre del Alumno: %s\n\n", aux->alumnos.nombre);
		aux = aux->siguiente;
		}
	}
	else
		printf("La lista esta vacia!!!\n");
}

int CantidadAlumnos()
{
	tLista *aux;
	aux = lista;
	int cantidad = 0;
	if(!ListaVacia())
	{
		while(aux != NULL)
		{
			cantidad++;
			aux = aux->siguiente;
		}
	}
	return cantidad;
}

void InsertarK(int k, tDatos pDatoNuevo)
{
	tLista *nuevoNodo, *aux;
	aux = lista;
	int i;
	for (i=0; i<k-1; i++)
	{
		aux = aux->siguiente;
	}
	nuevoNodo = (tLista *) malloc(sizeof(tLista));
	nuevoNodo->alumnos.nroLibreta = pDatoNuevo.nroLibreta;
	strcpy(nuevoNodo->alumnos.nombre, pDatoNuevo.nombre);
	nuevoNodo->siguiente = aux->siguiente;
	aux->siguiente = nuevoNodo;
	printf("Elemento insertado en la posicion: %d\n", k);
}

void EliminarK(int k)
{
	tLista *nodoSuprimir, *aux;
	aux = lista;
	int i;
	if( k < CantidadAlumnos() && k > 1)
	{
		for(i=0; i<k-1; i++)
		{
			aux = aux->siguiente;
		}
		nodoSuprimir = aux->siguiente;
		aux->siguiente = nodoSuprimir->siguiente;
		free(nodoSuprimir);
		
		printf("Elemento de la posicion %d eliminado\n", k);
	}
	else
		printf("No se puede eliminar elemento de la posicion %d\n", k);
}

void Menu()
{
	int opcion;
	
	printf("Menu de opciones:\n");
	printf("1-Agregar alumno\n");
	printf("2-Eliminar alumno\n");
	printf("3-Agregar alumno en posicion K\n");
	printf("4-Eliminar alumno de la posicion K\n");
	printf("5-Visualizar lista de alumnos\n");
	printf("6-Cantidad de alumnos en la lista\n");
	printf("Seleccione una opcion: ");
	scanf("%d", &opcion); fflush(stdin);
	system("cls");
	
	while(opcion != 0)
	{
		switch(opcion)
		{
			case 1:
				{
					char respuesta;
					tDatos dato;
					do
					{
						printf("Ingrese numero de libreta universitaria: \n");
						scanf("%d", &dato.nroLibreta); fflush(stdin);
						printf("Ingrese nombre del alumno: \n");
						gets(dato.nombre); fflush(stdin);
						
						InsertarElemento(dato);
						printf("Desea seguir ingresando datos? s/n\n");
						scanf("%s", &respuesta); fflush(stdin);
					}
					while(respuesta != 'n');
					system("pause"); system("cls");
					Menu();
				}break;
				
			case 2:
				{
					EliminarPrimero();
					system("pause"); system("cls");
					Menu();
				}break;
				
			case 3:
				{
					int k;
					tDatos datoK;
					printf("Ingrese la posicion para agregar alumno: \n");
					scanf("%d", &k);
					
					printf("Ingrese numero de libreta universitaria: \n");
					scanf("%d", &datoK.nroLibreta); fflush(stdin);
					printf("Ingrese nombre del alumno: \n");
					gets(datoK.nombre); fflush(stdin);
					
					InsertarK(k, datoK);
					system("pause"); system("cls");
					Menu();
				}break;
				
			case 4:
				{
					int k;
					printf("Ingrese la posicion del alumno a eliminar: \n");
					scanf("%d", &k);
					
					EliminarK(k);
					system("pause"); system("cls");
					Menu();
				}break;
				
			case 5:
				{
					Visualizar();
					system("pause"); system("cls");
					Menu();
				}break;
				
			case 6:
				{
					printf("La cantidad de alumnos en la lista es %d\n", CantidadAlumnos());
					system("pause"); system("cls");
					Menu();
				}break;
		}
	printf("Menu de opciones:\n");
	printf("1-Agregar alumno\n");
	printf("2-Eliminar alumno\n");
	printf("3-Agregar alumno en posicionK\n");
	printf("4-Eliminar alumno de la posicion K\n");
	printf("5-Visualizar lista de alumnos\n");
	printf("6-Cantidad de alumnos en la lista\n");
	printf("Seleccione una opcion: ");
	scanf("%d", &opcion); fflush(stdin);
	system("cls");
	}
}





















