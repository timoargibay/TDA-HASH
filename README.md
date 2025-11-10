<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

# TDA HASH

## Repositorio de (Nombre Apellido) - (Padrón) - (Mail)

- Para compilar:

```bash
make compilar-todo
```

- Para ejecutar:

```bash
./main {comandos}
```

- Para ejecutar con valgrind:
```bash
make valgrind-main
make valgrind-pruebas
```
---
##  Funcionamiento

Para este TDA se trabajó sobre un hash de tipo abierto, es decir que los datos se guardaban de forma externa fuera del hash, personalmente elegí usar nodos simplemente enlazados
como los encontrados en el tda lista, esto resulto especialmente util para manejar los escenarios en los que hubieran colisiones ya que simplemente se podia agregar el nodo atras de el que ya existia en ese lugar.

estructura de hash:
<div align="center">
<img src="hash_t.jpeg">
</div>

estructura del nodo de hash:

<div align="center">
<img src="nodo_t_nodohash.jpeg">
</div>

## Respuestas a las preguntas teóricas
1) Un diccionario es un TDA que usamos para almacenar datos, se basa fundamentalmente en tener un dato como clave que nosotros conocemos y otro dato que puede ser cualquier cosa como valor. Entonces tenemos, por ej, que para la clave "Perro" puedo tener de valor, el nombre de mi perro.

   - Formas de implementar un diccionario hay muchas, empezando por la implementada acá que es mediante una tabla de hash, que nos proveé la masiva ventaja frente a lista o ABB de que podemos encontrar lo que buscamos en tiempo O(1). ¿Como? Usando una funcion de hash que, provista una semilla (para nosotros la clave) nos da un numero, ese numero nosotros lo usamos para saber en que lugar de la tabla de hash se encuentra lo que buscamos, esto es especialmente util a la hora de guardar muchos datos ya que no tengo que recorrer otros elementos para llegar a lo que busco. Por supuesto esto no es perfecto, pueden haber casos en los que dos claves nos den el mismo resultado y tengamos una "Colision", en cuyo caso, por ej para esta implementacion, se forma una lista de nodos simplemente enlazados.
  - Otras formas pueden ser mediante dos listas normales, una con las claves y otra con los valores, teniendo la correspondencia de que la clave (por ej) 4 se corresponde si o si al valor 4 de la lista de valores.
  - Una forma más de implementacion puede ser haciendo una lista ordenada segun las claves y usando busqueda binaria en vez de hash.

2) Una funcion de hash es una funcion que recibe algo (nos referimos como semilla) y a traves de distintas operaciones, genera un valor y nos lo devuelve. Para nuestro caso especifico necesitamos que sea deterministico, osea, que siempre que demos la misma semilla nos devuelva el mismo resultado, si no, no vamos a poder encontrar lo que guardemos y que genere la menor cantidad de colisiones posibles para mantener la eficiencia del programa.

- Para el manejo de colisiones hay muchos metodos pero el que utilice yo para este hash abierto fue que en caso de colision, se enlaze el nuevo nodo al que ya estaba y se cree una lista de nodos simplemente enlazados (encadenamiento). Si se tratara de un hash cerrado lo que se tendria que hacer seria mover a la siguiente posicion hasta encontrar una posicion vacia e insertarlo ahi, esto es a lo que se llama "Probing" y al buscar, si vemos que hay una colision, hacemos lo mismo, sabiendo que si encontramos un lugar vacio que nunca se uso y que no contiene lo que buscamos, significa que entonces lo que buscamos no existe.

Caso de un hash cerrado:


- El tamaño de la tabla es muy importante para el manejo de colisiones, por lo general se trata de mantener el factor de carga (es decir, cuantos elementos hay en la tabla sobre su capacidad total) en un valor menor a 0,7 ya que despues se pierde mucha eficiencia debido a que hay colisiones, cuando se pasa este nivel lo que se sugiere hacer es un "rehashing", donde basicamente realocamos la tabla y volvemos a cargar todo con una capacidad mas grande (normalmente *2 de lo que ya habia), asi nos liberamos de muchas coliciones y mantenemos la eficiencia lo mas cerca a O(1) posible. Esto si bien puede parecer innecesario pq en caso de haber colisiones se degenera en una lista de nodos, conviene evitarlo pq puede rapidamente degradar la eficiencia de la tabla.

   

