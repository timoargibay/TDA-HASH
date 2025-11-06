#include "hash.h"

typedef struct nodo {
        const char *clave;
        void *valor;
        struct nodo *siguiente;
} nodo_t;

struct hash {
        nodo_t **tabla;
        size_t capacidad;
        size_t cantidad_elementos;
};

size_t funcion_hash(const char *clave, size_t tamaño_tabla)
{
        if(clave == NULL || tamaño_tabla == 0)
                return 0;
        
        size_t hash = 5381;
        int c;

        while((c = *clave++))
                hash = ((hash << 5) + hash) + c;
        
        return hash%tamaño_tabla;
}

nodo_t *crear_nodo(const char *clave, void *valor)
{
        nodo_t *nuevo_nodo = calloc(1, sizeof(nodo_t));
        if(nuevo_nodo == NULL)
                return NULL;

        nuevo_nodo->clave = clave;
        nuevo_nodo->valor = valor;
        return nuevo_nodo;
}

//---------------Primitivas del TDA---------------//
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

        hash_t *nuevo_hash = calloc(1, sizeof(hash_t));
        if(nuevo_hash == NULL)
                return NULL;

        nuevo_hash->tabla = calloc(capacidad_a_usar, sizeof(nodo_t*)*capacidad_a_usar);
        if(nuevo_hash->tabla == NULL) {
                free(nuevo_hash);
                return NULL;
        }

        nuevo_hash->capacidad = capacidad_a_usar;

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

        size_t posicion = funcion_hash(clave, hash->capacidad);

        *encontrado = hash_buscar(hash, clave);
}

/**
 * Busca el elemento asociado a la clave en la tabla.
 **/
void *hash_buscar(hash_t *hash, char *clave)
{
        if(hash == NULL || hash->capacidad == 0 || clave == NULL)
                return NULL;

        size_t valor = funcion_hash(clave, hash->capacidad);
        nodo_t *nodo_actual = hash->tabla[valor];

        while(nodo_actual != NULL) {
                if(strcmp(nodo_actual->clave, clave) == 0)
                        return nodo_actual->valor;
                
                nodo_actual = nodo_actual->siguiente;
        }

        return NULL;
}

/**
 *Devuelve si la clave existe en la tabla o no
 */
bool hash_contiene(hash_t *hash, char *clave)
{
        if(hash == NULL || clave == NULL)
                return false;

        if(hash_buscar(hash, clave) != NULL)
                return true;

        return false;
}

/**
 * Quita el elemento asociado a la clave de la tabla y lo devuelve.
 */
void *hash_quitar(hash_t *hash, char *clave)
{
        if(hash == NULL)
                return NULL;

        size_t posicion = funcion_hash(clave, hash->capacidad);
}

/**
 * Itera cada elemento del hash y aplica la función f.
 *
 * La iteración se corta al completar el total de elementos o cuando la función devuelve false.
 *
 * Devuelve la cantidad de veces que se aplica la función.
 */
size_t hash_iterar(hash_t *hash, bool (*f)(char *, void *, void *), void *ctx)
{
        if(hash == NULL || hash->capacidad == 0 || f == NULL)
                return 0;

        size_t posicion_tabla;
        size_t elementos_afectados = 0;
        nodo_t *nodo_actual;
        bool estado = true;

        for(posicion_tabla = 0;posicion_tabla < hash->capacidad; posicion_tabla++) {
                nodo_actual = hash->tabla[posicion_tabla];

                if(estado == false)
                        break;

                while(estado == true && nodo_actual != NULL) {
                        estado = f(nodo_actual->clave, nodo_actual->valor, ctx);
                        elementos_afectados++;
                        nodo_actual = nodo_actual->siguiente;
                }
        }

        return elementos_afectados;
}

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

        size_t i;
        nodo_t *nodo_actual;
        nodo_t *siguiente;
        for(i = 0; i < hash->capacidad; i++) {
                nodo_actual = hash->tabla[i];

                while(nodo_actual != NULL) {
                        if(destructor != NULL)
                                destructor(nodo_actual->valor);

                        siguiente = nodo_actual->siguiente;
                        free(nodo_actual);
                        nodo_actual = siguiente;
                }
        }
        free(hash->tabla);
        free(hash);
}