#include "pa2m.h"
#include <stdbool.h>
#include "src/hash.h"

//void prueba_funcion_hash_deterministica()
//{
//	char clave[] = "Zangoose hermoso pokemon";
//	size_t posicion = funcion_hash(clave, 100);
//	size_t old_pos;
//	bool todo_ok = true;
//
//	for(unsigned int i = 0; i < 10; i++) {
//		old_pos = posicion;
//		posicion = funcion_hash(clave, 100);
//		if(old_pos != posicion)
//			todo_ok = false;
//	}
//
//	pa2m_afirmar(todo_ok, "La funcion de hash siempre es deterministica");
//}
//
//void prueba_crear_nodo()
//{
//	int primer_microprocesador = 8008;
//	nodo_t *mi_nodo = crear_nodo("Jolteon mi pokemon favorito", &primer_microprocesador);
//	bool todo_ok = false;
//
//	if(mi_nodo != NULL && *mi_nodo->clave == primer_microprocesador && mi_nodo->siguiente == NULL && strcmp(mi_nodo->clave, "Jolteon mi pokemon favorito") == 0)
//		todo_ok = true;
//
//	free(mi_nodo);
//	pa2m_afirmar(todo_ok, "Se crean los nodos correctamente");
//}

void prueba_crear_hash()
{
	hash_t *mi_hash = hash_crear(200);
	bool todo_ok = true;

	if(mi_hash == NULL) 
		todo_ok = false;

	if(todo_ok == true)
		hash_destruir(mi_hash);

	pa2m_afirmar(todo_ok, "Se crea un hash correctamente");
}

void prueba_cantidad_hash()
{
	hash_t *mi_hash = hash_crear(200);
	bool todo_ok = true;
	bool inserciones_ok = true;
	bool cantidades_ok = true;

	int numero1 = 1;
	int numero2 = 2;
	int numero3 = 3;
	int numero4 = 4;
	int numero5 = 5;
	int numero6 = 6;
	int numero7 = 7;
	int numero8 = 8;
	int numero9 = 9;
	int numero0 = 0; 

	if(mi_hash == NULL) {
		todo_ok = false;
	}

	size_t cant0 = 0;
	size_t cant1 = 0;
	size_t cant2 = 0;
	size_t cant3 = 0;
	size_t cant4 = 0;
	size_t cant5 = 0;
	size_t cant6 = 0;
	size_t cant7 = 0;
	size_t cant8 = 0;
	size_t cant9 = 0;

	bool num1 = false;
	bool num2 = false;
	bool num3 = false;
	bool num4 = false;
	bool num5 = false;
	bool num6 = false;
	bool num7 = false;
	bool num8 = false;
	bool num9 = false;
	bool num0 = false;	

	bool cant1_ok = false;
	bool cant2_ok = false;
	bool cant3_ok = false;
	bool cant4_ok = false;
	bool cant5_ok = false;
	bool cant6_ok = false;
	bool cant7_ok = false;
	bool cant8_ok = false;
	bool cant9_ok = false;
	bool cant0_ok = false; 

	if(todo_ok == true) {
		num0 = hash_insertar(mi_hash, "0", &numero0, NULL);
		cant0 = hash_cantidad(mi_hash);
		num1 = hash_insertar(mi_hash, "1", &numero1, NULL);
		cant1 = hash_cantidad(mi_hash);
		num2 = hash_insertar(mi_hash, "2", &numero2, NULL);
		cant2 = hash_cantidad(mi_hash);
		num3 = hash_insertar(mi_hash, "3", &numero3, NULL);
		cant3 = hash_cantidad(mi_hash);
		num4 = hash_insertar(mi_hash, "4", &numero4, NULL);
		cant4 = hash_cantidad(mi_hash);
		num5 = hash_insertar(mi_hash, "5", &numero5, NULL);
		cant5 = hash_cantidad(mi_hash);
		num6 = hash_insertar(mi_hash, "6", &numero6, NULL);
		cant6 = hash_cantidad(mi_hash);
		num7 = hash_insertar(mi_hash, "7", &numero7, NULL);
		cant7 = hash_cantidad(mi_hash);
		num8 = hash_insertar(mi_hash, "8", &numero8, NULL);
		cant8 = hash_cantidad(mi_hash);
		num9 = hash_insertar(mi_hash, "9", &numero9, NULL);
		cant9 = hash_cantidad(mi_hash);
		hash_destruir(mi_hash);
	}

	cant0_ok = (cant0 == 1);
	cant1_ok = (cant1 == 2);
	cant2_ok = (cant2 == 3);
	cant3_ok = (cant3 == 4);
	cant4_ok = (cant4 == 5);
	cant5_ok = (cant5 == 6);
	cant6_ok = (cant6 == 7);
	cant7_ok = (cant7 == 8);
	cant8_ok = (cant8 == 9);
	cant9_ok = (cant9 == 10);

	if(!cant0_ok || !cant1_ok || !cant2_ok || !cant3_ok || !cant4_ok || !cant5_ok || !cant6_ok || !cant7_ok || !cant8_ok || !cant9_ok)
		cantidades_ok = false;

	if(!num0 || !num1 || !num2 || !num3 || !num4 || !num5 || !num6 || !num7 || !num8 || !num9)
		inserciones_ok = false;

	if(!inserciones_ok || !cantidades_ok)
		todo_ok = false;

	pa2m_afirmar(todo_ok, "Se muestran bien las cantidades en el hash");

}

void prueba_insercion_hash()
{
	{
	hash_t *mi_hash = hash_crear(200);
	bool todo_ok = true;

	int numero1 = 1;
	int numero2 = 2;
	int numero3 = 3;
	int numero4 = 4;
	int numero5 = 5;
	int numero6 = 6;
	int numero7 = 7;
	int numero8 = 8;
	int numero9 = 9;
	int numero0 = 0; 

	if(mi_hash == NULL) {
		todo_ok = false;
	}

	bool num1 = false;	
	bool num2 = false;
	bool num3 = false;
	bool num4 = false;
	bool num5 = false;
	bool num6 = false;
	bool num7 = false;
	bool num8 = false;
	bool num9 = false;
	bool num0 = false;	

	if(todo_ok == true) {
		num0 = hash_insertar(mi_hash, "0", &numero0, NULL);
		num1 = hash_insertar(mi_hash, "1", &numero1, NULL);
		num2 = hash_insertar(mi_hash, "2", &numero2, NULL);
		num3 = hash_insertar(mi_hash, "3", &numero3, NULL);
		num4 = hash_insertar(mi_hash, "4", &numero4, NULL);
		num5 = hash_insertar(mi_hash, "5", &numero5, NULL);
		num6 = hash_insertar(mi_hash, "6", &numero6, NULL);
		num7 = hash_insertar(mi_hash, "7", &numero7, NULL);
		num8 = hash_insertar(mi_hash, "8", &numero8, NULL);
		num9 = hash_insertar(mi_hash, "9", &numero9, NULL);
		hash_destruir(mi_hash);
	}

	if(num0 && num1 && num2 && num3 && num4 && num5 && num6 && num7 && num8 && num9)
		todo_ok = true;
	else
		todo_ok = false;

	pa2m_afirmar(todo_ok, "Se insertaron bien los elementos en el hash");

}
}

//void prueba_buscar_hash()
//{
//
//}
//
//void prueba_hash_contiene()
//{
//
//}
//
//void prueba_quitar_de_hash()
//{
//
//}
//
//void prueba_iterador()
//{
//
//}


int main()
{
	//pa2m_nuevo_grupo("============== Funciones propias ===============");
	//prueba_funcion_hash_deterministica();
	//prueba_crear_nodo();

	pa2m_nuevo_grupo("============== Primitivas HASH ==============");
	prueba_crear_hash();
	prueba_cantidad_hash();
	prueba_insercion_hash();
	//prueba_buscar_hash();
	//prueba_hash_contiene();
	//prueba_quitar_de_hash();
	//prueba_iterador();

	return pa2m_mostrar_reporte();
}
