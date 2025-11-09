#include "src/hash.h"
#include "src/tp1.h"
#include "src/extras_tp1.h"
#include <stdio.h>
#include <string.h>

typedef struct pokemon pokemon_t;

//Usada para pasarle datos y ajustes a copiar_agregar_pokemons, usando el ptr comodin
struct caja_datos {
	hash_t *hash;
	bool por_nombre;
};

void destruir_pokemon(void *pokemon)
{
	if (pokemon == NULL)
		return;

	pokemon_t *pokemon_a_liberar = pokemon;
	free(pokemon_a_liberar->nombre);
	free(pokemon_a_liberar);
}

bool mostrar_pokemon(pokemon_t *pokemon_seleccionado)
{
	char *tipo_pokemon = malloc(16 * sizeof(char));
	if (tipo_pokemon == NULL)
		return false;

	switch (pokemon_seleccionado->tipo) {
	case TIPO_AGUA:
		strcpy(tipo_pokemon, "Agua");
		break;
	case TIPO_ELEC:
		strcpy(tipo_pokemon, "Electrico");
		break;
	case TIPO_FANT:
		strcpy(tipo_pokemon, "Fantasma");
		break;
	case TIPO_FUEG:
		strcpy(tipo_pokemon, "Fuego");
		break;
	case TIPO_LUCH:
		strcpy(tipo_pokemon, "Lucha");
		break;
	case TIPO_NORM:
		strcpy(tipo_pokemon, "Normal");
		break;
	case TIPO_PLAN:
		strcpy(tipo_pokemon, "Planta");
		break;
	case TIPO_PSI:
		strcpy(tipo_pokemon, "Psiquico");
		break;

	default:
		strcpy(tipo_pokemon, "INVALIDO");
		break;
	}

	printf("------------------------------\n");
	printf("ID: %i\nNombre: %s\nTipo: %s\nAtaque: %i\nDefensa: %i\nVelocidad: %i",
	       pokemon_seleccionado->id, pokemon_seleccionado->nombre,
	       tipo_pokemon, pokemon_seleccionado->ataque,
	       pokemon_seleccionado->defensa, pokemon_seleccionado->velocidad);
	printf("\n------------------------------\n");

	free(tipo_pokemon);
	return true;
}

char *copiar_string(char *string)
{
	if (string == NULL)
		return NULL;

	char *copia = malloc((strlen(string) + 1) * sizeof(char));
	if (copia == NULL)
		return NULL;

	strcpy(copia, string);
	return copia;
}

/* Hace una copia real de el pokemon usando memoria dinamica. Funcion sacada de Tp-Lista para usar con Tp1
*/
bool copia_agrega_pokemon(pokemon_t *el_pokemon, void *contexto)
{
	pokemon_t *pokemon_dinamico = malloc(sizeof(pokemon_t));
	if (pokemon_dinamico == NULL || contexto == NULL)
		return false;

	struct caja_datos *config = contexto;
	*pokemon_dinamico = *el_pokemon;
	pokemon_dinamico->nombre = copiar_string(el_pokemon->nombre);
	char id_string[16];
	sprintf(id_string, "%i", pokemon_dinamico->id);

	if (pokemon_dinamico->nombre == NULL) {
		free(pokemon_dinamico);
		return false;
	}

	if (config->por_nombre)
		return hash_insertar(config->hash, pokemon_dinamico->nombre,
				     pokemon_dinamico, NULL);
	else
		return hash_insertar(config->hash, id_string, pokemon_dinamico,
				     NULL);
}

int main(int argc, char *argumento[])
{
	if (argc < 5) {
		printf("Error: Faltan argumentos!\n");
		return 1;
	}

	tp1_t *pokemons_1 = tp1_leer_archivo(argumento[1]);
	if (pokemons_1 == NULL)
		return 1;

	hash_t *hash_pokemons = hash_crear(tp1_cantidad(pokemons_1) * 2);
	if (hash_pokemons == NULL)
		return 1;

	struct caja_datos config_copias;
	config_copias.hash = hash_pokemons;
	if (strcmp(argumento[3], "nombre") == 0)
		config_copias.por_nombre = true;
	else
		config_copias.por_nombre = false;

	if (tp1_con_cada_pokemon(pokemons_1, copia_agrega_pokemon,
				 &config_copias) != tp1_cantidad(pokemons_1))
		return 1;

	tp1_destruir(pokemons_1);

	pokemon_t *pokemon_actual = NULL;
	int argumento_4_id;

	/*---------Manejo de posibilidades---------*/
	if (strcmp(argumento[3], "id") == 0) {
		argumento_4_id = strtnum(argumento[4]);
		pokemon_actual = hash_buscar(hash_pokemons, argumento[4]);
		if (pokemon_actual != NULL &&
		    argumento_4_id == pokemon_actual->id) {
			mostrar_pokemon(pokemon_actual);
		} else {
			printf("Error: No se encontro ese pokemon :(\n");
		}
	} else if (strcmp(argumento[3], "nombre") == 0) {
		pokemon_actual = hash_buscar(hash_pokemons, argumento[4]);

		if (pokemon_actual != NULL &&
		    strcmp(argumento[4], pokemon_actual->nombre) == 0) {
			mostrar_pokemon(pokemon_actual);
		} else {
			printf("Error: No se encontro ese pokemon :(\n");
		}
	}

	hash_destruir_todo(hash_pokemons, destruir_pokemon);
	return 0;
}