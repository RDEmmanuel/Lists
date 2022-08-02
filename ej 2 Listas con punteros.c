#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char tString[30];

typedef struct 
{
	int codProducto;
	tString descripcion;
	float precioUnitario;
}tDatos;

typedef struct nodo
{
	tDatos producto;
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
int CantidadElementos();
void Menu();

int main()
{
	InicializarLista();
	Menu();
	return 0;
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
	lista->producto.codProducto = pDatos.codProducto;
	strcpy(lista->producto.descripcion, pDatos.descripcion);
	lista->producto.precioUnitario = pDatos.precioUnitario;
	lista->siguiente = NULL;
	printf("Primer elemento insertado!\n");
}

void InsertarAdelante(tDatos pDatos)
{
	tLista *nuevoNodo;
	nuevoNodo = (tLista *) malloc(sizeof(tLista));
	nuevoNodo->producto.codProducto = pDatos.codProducto;
	strcpy(nuevoNodo->producto.descripcion, pDatos.descripcion);
	nuevoNodo->producto.precioUnitario = pDatos.precioUnitario;
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
	printf("Primer elemento de la lista eliminado!\n");
	}
	else
		printf("No se puede eliminar!\n");

}

void VisualizarElementos()
{
	tLista *aux;
	aux = lista;
	if(!ListaVacia())
	{
		while (aux!=NULL)
		{
			printf("Codigo de producto: %d\nDescripcion: %s\nPrecio Unitario: %.2f\n\n", aux->producto.codProducto, aux->producto.descripcion, aux->producto.precioUnitario);
			aux = aux->siguiente;
		}
	}
	else
		printf("La lista esta vacia!!!\n");
}

int CantidadElementos()
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

void InsertarK(int k, tDatos nuevoDato)
{
	tLista * nuevoNodo, *aux;
	int i;
	aux = lista;
	for(i = 1; i < k-1; i++)
	{
		aux = aux->siguiente;
	}
	nuevoNodo = malloc(sizeof(tLista));
	nuevoNodo->producto.codProducto = nuevoDato.codProducto;
	strcpy(nuevoNodo->producto.descripcion, nuevoDato.descripcion);
	nuevoNodo->producto.precioUnitario = nuevoDato.precioUnitario;	
	nuevoNodo->siguiente = aux->siguiente;
	aux->siguiente = nuevoNodo;
	printf("Elemento insertado en la posicion: %d\n",k);
}

void EliminarK(int k)
{
	tLista *nodoSuprimir, *aux;
	int i;
	aux = lista;
	
	if(k <= CantidadElementos() && k > 1)
	{
		for(i=1; i<k-1; i++)
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
	tDatos dato;
	
	printf(">>>Menu de opciones<<<\n");
	printf("1-Insertar producto\n");
	printf("2-Eliminar primer producto\n");
	printf("3-Insertar K\n");
	printf("4-Eliminar K\n");
	printf("5-Visualizar productos de la lista\n");
	printf("Elija una opcion: ");
	
	scanf("%d", &opcion); fflush(stdin);
	system("cls");
	while (opcion != 0)
	{
		switch(opcion)
		{
			case 1:
				{
					char respuesta;
					do
					{
						printf("Ingrese codigo de producto: \n");
						scanf("%d", &dato.codProducto);
						printf("Ingrese descripcion: \n");
						scanf("%s", &dato.descripcion);
						printf("Ingrese precio unitario: \n");
						scanf("%f", &dato.precioUnitario);
						
						InsertarElemento(dato);
						printf("Desea seguir ingresando datos? s/n\n");
						scanf("%s", &respuesta);
					}
					while (respuesta != 'n');
					system("pause"); system("cls");
					Menu();
				}
				break;
				
			case 2:
				{
					EliminarPrimero();
					system("pause"); system("cls");
					Menu();
				}
				break;
				
			case 3:
				{
					int k;
					tDatos datoK;
					printf("Ingrese posicion para insertar: \n");
					scanf("%d", &k);
					
					printf("Ingrese codigo de producto: \n");
					scanf("%d", &datoK.codProducto);
					printf("Ingrese descripcion: \n");
					scanf("%s", &datoK.descripcion);
					printf("Ingrese precio unitario: \n");
					scanf("%f", &datoK.precioUnitario);
					InsertarK(k, datoK);
					system("pause"); system("cls");
					Menu();
				}
				break;
				
			case 4:
				{
					int k;
					printf("Ingrese la posicion del elemento a eliminar: \n");
					scanf("%d", &k);
					EliminarK(k);
					system("pause"); system("cls");
					Menu();
				}
				break;
				
			case 5:
				{
					VisualizarElementos();
					system("pause"); system("cls");
					Menu();
				}
				break;
		}
	printf(">>>Menu de opciones<<<\n");
	printf("1-Insertar producto\n");
	printf("2-Eliminar primer producto\n");
	printf("3-Insertar K\n");
	printf("4-Eliminar K\n");
	printf("5-Visualizar productos de la lista\n");
	printf("Elija una opcion: ");
	
	scanf("%d", &opcion); fflush(stdin);
	system("cls");	
	}
}


























