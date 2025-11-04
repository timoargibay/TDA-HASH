#include "hash.h"

typedef struct nodo {
        char *clave;
        char *valor;
        struct nodo *siguiente;
} nodo_t;

struct hash {
        nodo_t **tabla;
        size_t capacidad;
        size_t cantidad_elementos;
};

/**
 * Crea una tabla de hash con la capacidad especificada (o 3 si es menor a 3).
 *
 * Devuelve el hash creado o NULL en caso de error.
 *
 */
hash_t *hash_crear(size_t capacidad_inicial)
{
        size_t capacidad_a_usar = 3;
        if(capacidad_inicial > 3)
                capacidad_a_usar = capacidad_inicial;

        hash_t *nuevo_hash = malloc(sizeof(hash_t));
        if(nuevo_hash == NULL)
                return NULL;

        nuevo_hash->tabla = malloc(sizeof(nodo_t)*capacidad_a_usar);
        if(nuevo_hash->tabla == NULL)
                return NULL;
        
        nuevo_hash->cantidad_elementos = capacidad_a_usar;
        nuevo_hash->cantidad_elementos = 0;        

        return nuevo_hash;
}

/**
 * Devuelve la cantidad de elementos en la tabla.
 *
 */
size_t hash_cantidad(hash_t *hash)
{
        if(hash == NULL)
                return 0;

        return hash->cantidad_elementos;
}

/**
 *
 * Inserta un elemento asociado a la clave en la tabla de hash.
 *
 * Si la clave ya existe en la tabla, modificamos el valor y ponemos el nuevo.
 * Si encontrado no es NULL, se almacena el elemento reemplazado en el mismo.
 *
 * Esta funcion almacena una copia de la clave.
 *
 * No se admiten claves nulas.
 *
 * Devuelve true si se pudo almacenar el valor.
 **/
bool hash_insertar(hash_t *hash, char *clave, void *valor, void **encontrado)
{
        if(hash == NULL || clave == NULL)
                return false;
}

/**
 * Busca el elemento asociado a la clave en la tabla.
 **/
void *hash_buscar(hash_t *hash, char *clave)
{
        if(hash == NULL)
                return NULL;
}

/**
 *Devuelve si la clave existe en la tabla o no
 */
bool hash_contiene(hash_t *hash, char *clave)
{
        if(hash == NULL)
                return false;
}

/**
 * Quita el elemento asociado a la clave de la tabla y lo devuelve.
 */
void *hash_quitar(hash_t *hash, char *clave)
{
        if(hash == NULL)
                return NULL;
}

/**
 * Itera cada elemento del hash y aplica la función f.
 *
 * La iteración se corta al completar el total de elementos o cuando la función devuelve false.
 *
 * Devuelve la cantidad de veces que se aplica la función.
 */
size_t hash_iterar(hash_t *hash, bool (*f)(char *, void *, void *), void *ctx);

/**
 * Destruye la tabla
 */
void hash_destruir(hash_t *hash)
{
        if(hash == NULL)
                return;

        hash_destruir_todo(hash, NULL);
}
/**
 * Destruye la tabla y aplica el destructor a los elementos
 */
void hash_destruir_todo(hash_t *hash, void (*destructor)(void *))
{
        if(hash == NULL)
                return;

        
}