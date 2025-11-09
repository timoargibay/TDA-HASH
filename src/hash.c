#include <stdlib.h>
#include <string.h>
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

static size_t funcion_hash(const char *clave, size_t tamaño_tabla)
{
        if(clave == NULL || tamaño_tabla == 0)
                return 0;
        
        size_t hash = 5381;
        size_t c;

        while((c = (unsigned char)*clave++))
                hash = ((hash << 5) + hash) + c;
        
        return hash%tamaño_tabla;
}

static nodo_t *crear_nodo(const char *clave, void *valor)
{
        if(clave == NULL)
                return NULL;
        
        nodo_t *nuevo_nodo = calloc(1, sizeof(nodo_t));
        if(nuevo_nodo == NULL)
                return NULL;

        nuevo_nodo->clave = clave;
        nuevo_nodo->valor = valor;
        return nuevo_nodo;
}

static nodo_t *buscador(hash_t *hash, const char *clave, nodo_t **padre)
{
        if(hash == NULL || hash->capacidad == 0 || clave == NULL)
                return NULL;

        nodo_t *el_padre = NULL;
        nodo_t *nodo_actual = NULL;
        size_t posicion = funcion_hash(clave, hash->capacidad);
        nodo_actual = hash->tabla[posicion];

        //Si en ese lugar no hay nada, entonces no se encontró
        if(nodo_actual == NULL)
                return NULL;
        
        //Si hay cosas pero la clave no coincide, busco adentro
        while(nodo_actual != NULL) {
                if(strcmp(nodo_actual->clave, clave) == 0) {
                        break;
                }
                else {
                        el_padre = nodo_actual;
                        nodo_actual = nodo_actual->siguiente;
                }
        }

        if(padre != NULL) 
                *padre = el_padre;

        return nodo_actual;
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

        nuevo_hash->tabla = calloc(capacidad_a_usar, sizeof(nodo_t*));
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
        nodo_t *nodo_actual = hash->tabla[posicion];

        if(encontrado != NULL)
                *encontrado = hash_buscar(hash, clave);

        if(*encontrado != NULL) {
                while(nodo_actual != NULL && strcmp(nodo_actual->clave, clave) != 0)
                        nodo_actual = nodo_actual->siguiente;

                nodo_actual->valor = valor;
        } else if(nodo_actual != NULL){
                nodo_t *nuevo_nodo = crear_nodo(clave, valor);
                if(nuevo_nodo == NULL)
                        return false;
                
                nodo_actual->siguiente = nuevo_nodo;
        } else {
                hash->tabla[posicion] = crear_nodo(clave, valor);
                if(hash->tabla[posicion] == NULL)
                        return false;
        }

        hash->cantidad_elementos++;
        return true;
}

/**
 * Busca el elemento asociado a la clave en la tabla.
 **/
void *hash_buscar(hash_t *hash, char *clave)
{
        if(hash == NULL || hash->capacidad == 0 || clave == NULL)
                return NULL;

        nodo_t *nodo = buscador(hash, clave, NULL);

        if(nodo != NULL)
                return nodo->valor;
        
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
        if(hash == NULL || clave == NULL)
                return NULL;

        nodo_t *nodo_padre = NULL;
        nodo_t *nodo_eliminar = buscador(hash, clave, &nodo_padre);
        void *dato_eliminado = NULL;

        if(nodo_padre != NULL && nodo_eliminar != NULL) {
                dato_eliminado = nodo_eliminar->valor;
                nodo_padre->siguiente = nodo_eliminar->siguiente;
                hash->cantidad_elementos--;
                free(nodo_eliminar);
                return dato_eliminado;
        }

        //Si llegué hasta aca, nodo_padre es NULL si o si entonces es el primero en esa posicion
        if(nodo_eliminar != NULL) {
                if(nodo_eliminar->siguiente != NULL)
                        hash->tabla[funcion_hash(clave, hash->capacidad)] = nodo_eliminar->siguiente;

                dato_eliminado = nodo_eliminar->valor;
                free(nodo_eliminar);
                return dato_eliminado;
        } 

        return NULL;
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
                        estado = f((char*)nodo_actual->clave, nodo_actual->valor, ctx);
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