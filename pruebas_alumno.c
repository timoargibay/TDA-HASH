#include "pa2m.h"
#include <stdbool.h>
#include "src/hash.h"
#include "src/tp1.h"

void prueba_crear_hash()
{
	hash_t *mi_hash = hash_crear(200);
	bool todo_ok = true;

	if (mi_hash == NULL)
		todo_ok = false;

	if (todo_ok == true)
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

	if (mi_hash == NULL) {
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

	if (todo_ok == true) {
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

	if (!cant0_ok || !cant1_ok || !cant2_ok || !cant3_ok || !cant4_ok ||
	    !cant5_ok || !cant6_ok || !cant7_ok || !cant8_ok || !cant9_ok)
		cantidades_ok = false;

	if (!num0 || !num1 || !num2 || !num3 || !num4 || !num5 || !num6 ||
	    !num7 || !num8 || !num9)
		inserciones_ok = false;

	if (!inserciones_ok || !cantidades_ok)
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

		if (mi_hash == NULL) {
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

		if (todo_ok == true) {
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

		if (num0 && num1 && num2 && num3 && num4 && num5 && num6 &&
		    num7 && num8 && num9)
			todo_ok = true;
		else
			todo_ok = false;

		pa2m_afirmar(todo_ok,
			     "Se insertaron bien los elementos en el hash");
	}
}

void prueba_crear_hash_mgrande()
{
	hash_t *mi_hash = hash_crear(999999);
	pa2m_afirmar(mi_hash != NULL, "Se creo un hash muy grande");
	hash_destruir(mi_hash);
}

void prueba_hash_vacio()
{
	hash_t *mi_hash = hash_crear(0);
	pa2m_afirmar(mi_hash != NULL, "Se creo un hash minimo");
	hash_destruir(mi_hash);
}

void prueba_destruir_con_elementos()
{
	hash_t *mi_hash = hash_crear(8008);
	char claves[] = "Jolteon";
	bool fallo = false;

	for (int i = 0; i < 5000; i++) {
		if (hash_insertar(mi_hash, claves + 1, NULL, NULL) == false)
			fallo = true;
	}

	hash_destruir(mi_hash);
	pa2m_afirmar(fallo == false,
		     "Se destruye bien el hash (revisar valgrind)");
}

void prueba_inserto_un_elem()
{
	hash_t *mi_hash = hash_crear(0);
	struct pokemon Zangoose;
	Zangoose.ataque = 99;
	Zangoose.defensa = 99;
	Zangoose.id = 84;
	Zangoose.nombre = "Zangoose";
	Zangoose.velocidad = 99;

	pa2m_afirmar(hash_insertar(mi_hash, Zangoose.nombre, &Zangoose, NULL),
		     "Se inserto a Zangoose en hash");
	hash_destruir(mi_hash);
}

void prueba_inserto_dos_elem()
{
	hash_t *mi_hash = hash_crear(0);
	struct pokemon Zangoose;
	Zangoose.ataque = 99;
	Zangoose.defensa = 99;
	Zangoose.id = 84;
	Zangoose.nombre = "Zangoose";
	Zangoose.velocidad = 99;
	Zangoose.tipo = TIPO_NORM;

	struct pokemon Pikachu;
	Pikachu.ataque = 55;
	Pikachu.defensa = 40;
	Pikachu.velocidad = 90;
	Pikachu.id = 1;
	Pikachu.tipo = TIPO_ELEC;
	Pikachu.nombre = "Pikachu";

	pa2m_afirmar(hash_insertar(mi_hash, Zangoose.nombre, &Zangoose, NULL) &&
			     hash_insertar(mi_hash, Pikachu.nombre, &Pikachu,
					   NULL),
		     "Se insertaron bien dos elementos");

	hash_destruir(mi_hash);
}
void prueba_inserto_misma_clave()
{
	hash_t *mi_hash = hash_crear(0);
	struct pokemon Zangoose;
	Zangoose.ataque = 99;
	Zangoose.defensa = 99;
	Zangoose.id = 84;
	Zangoose.nombre = "Zangoose";
	Zangoose.velocidad = 99;
	Zangoose.tipo = TIPO_NORM;

	struct pokemon Pikachu;
	Pikachu.ataque = 55;
	Pikachu.defensa = 40;
	Pikachu.velocidad = 90;
	Pikachu.id = 1;
	Pikachu.tipo = TIPO_ELEC;
	Pikachu.nombre = "Pikachu";

	pa2m_afirmar(hash_insertar(mi_hash, Zangoose.nombre, &Zangoose, NULL) &&
			     hash_insertar(mi_hash, Zangoose.nombre, &Pikachu,
					   NULL),
		     "Se inserta bien un elemento con la misma clave");

	hash_destruir(mi_hash);
}

void prueba_encontrado_me_da_valor_viejo()
{
	hash_t *mi_hash = hash_crear(0);
	struct pokemon Zangoose;
	Zangoose.ataque = 99;
	Zangoose.defensa = 99;
	Zangoose.id = 84;
	Zangoose.nombre = "Zangoose";
	Zangoose.velocidad = 99;
	Zangoose.tipo = TIPO_NORM;

	struct pokemon Pikachu;
	Pikachu.ataque = 55;
	Pikachu.defensa = 40;
	Pikachu.velocidad = 90;
	Pikachu.id = 1;
	Pikachu.tipo = TIPO_ELEC;
	Pikachu.nombre = "Pikachu";

	void *Zangoose_ptr = &Zangoose;
	void *ver1;
	hash_insertar(mi_hash, Zangoose.nombre, &Zangoose, NULL);
	hash_insertar(mi_hash, Zangoose.nombre, &Pikachu, &ver1);

	pa2m_afirmar(
		ver1 == Zangoose_ptr,
		"Se inserta bien un elemento con la misma clave y se devuelve el elemento viejo");

	hash_destruir(mi_hash);
}

void prueba_insertar_clave_null()
{
	hash_t *mi_hash = hash_crear(0);

	pa2m_afirmar(hash_insertar(mi_hash, NULL, NULL, NULL) == false,
		     "Al insertar clave NULL da error");

	hash_destruir(mi_hash);
}

void prueba_rehasheos()
{
	hash_t *mi_hash = hash_crear(0);

	char claves[32];
	bool fallo = false;
	size_t cantidad = 5000;

	for (size_t i = 0; i < cantidad; i++) {
		sprintf(claves, "claves_%li", i);

		if (hash_insertar(mi_hash, claves, NULL, NULL) == false)
			fallo = true;
	}

	size_t cantidad_segun_hash = hash_cantidad(mi_hash);

	if (cantidad_segun_hash != cantidad) {
		printf("Hay %ld elems.\n", cantidad_segun_hash);
		fallo = true;
	}

	pa2m_afirmar(
		fallo == false,
		"Se insertaron %ld elementos en un hash de tamaño minimo sin problemas",
		cantidad);

	hash_destruir(mi_hash);
}

void prueba_eliminar()
{
	hash_t *mi_hash = hash_crear(0);

	char claves[32];
	bool fallo = false;
	size_t cantidad = 5000;

	for (size_t i = 0; i < cantidad; i++) {
		sprintf(claves, "claves_%li", i);

		if (hash_insertar(mi_hash, claves, NULL, NULL) == false)
			fallo = true;
	}

	size_t cantidad_segun_hash = hash_cantidad(mi_hash);

	if (cantidad_segun_hash != cantidad) {
		printf("Hay %ld elems.\n", cantidad_segun_hash);
		fallo = true;
	}

	for (size_t i = 0; i < cantidad; i++) {
		sprintf(claves, "claves_%li", i);

		hash_quitar(mi_hash, claves);
	}

	if (hash_cantidad(mi_hash) != 0)
		fallo = true;

	pa2m_afirmar(
		fallo == false,
		"Se insertaron %ld elementos y se eliminaron bien uno a uno",
		cantidad);

	hash_destruir(mi_hash);
}

int main()
{
	pa2m_nuevo_grupo("============== Primitivas HASH ==============");
	prueba_cantidad_hash();
	prueba_insercion_hash();

	pa2m_nuevo_grupo("============== Creacion y borrado ==============");
	prueba_crear_hash();
	prueba_crear_hash_mgrande();
	prueba_hash_vacio();
	prueba_destruir_con_elementos();

	pa2m_nuevo_grupo("============== Insercion y rehash ==============");
	prueba_inserto_un_elem();
	prueba_inserto_dos_elem();
	prueba_inserto_misma_clave();
	prueba_encontrado_me_da_valor_viejo();
	prueba_insertar_clave_null();
	prueba_rehasheos();
	prueba_eliminar();

	return pa2m_mostrar_reporte();
}
