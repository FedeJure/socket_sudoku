# Aproximacion del modelado

## Estructura:
    Esta implementacion del sudoku remoto consta de dos partes principales, el cliente y el servidor. El usuario que quiera jugar, tendra que conectarse a travez del cliente, el cual conoce al servidor y el mismo estara corriendo no necesariamente en el mismo directorio y mucho menos en la misma computadora.

    El servidor y el cliente van a estar conectados a travez de un socket, el cual transmitira directivas dadas por el usuario hasta el servidor y este ejecutara la logica y responderá al cliente un resultado.

* El servidor

    El servidor es un programa que estará continuamente corriendo y escuchando lo que un cliente envía. Para ello hace uso del TDA socket, lo cual le permitira mantener una conexion de ambos lados con el cliente.
    
    Para ejecutar la logica propia del juego sudoku, el servidor delega esa responsabilidad al TDA sudoku.

* El cliente

    El cliente estara continuamente escuchando la entrada ingresada por el usuario mediante el archivo stdin. en caso que el usuario ingrese un comando reconocido por el programa, este realizara una accion, la cual depende del comando ingresado. En la mayoría de los casos, se comunica a travez del socket con el servidor e imprimie la respuesta del mismo por terminal (escribe en el archivo stdout).

* El sudoku

    El sudoku es un TDA que usa el servidor para resolver la logica del juego sudoku. 


# Implementación

Esta sección presenta detalles de implementacion de funciones que vale la pena prestar mas atención

* sudoku:verify 
>   Esta función verifica que el estado actual del tablero del sudoku respete las reglas del juego. Realiza un unico doble loop for, en el cual en cada iteracion del loop de mayor nivel inicializan tres array de enteros seteados en **0** (uno para las filas, uno para las columnas, y otro para las zonas); cada posicion de ese array corresponde a un **valor** de un casillero en su fila, columna o zona correspondiente. Este se setea en **1** en la posicion del valor encontrado en el loop de menor nivel siempre y cuando no se encuentre ya en 1, en cuyo caso termina la ejecucion devolviendo el valor de error y significa que no se respeta las reglas del sudoku.
Se puede pensar esta idea parecido a una mascara de bits, ya que en cada posicion del array se debería pasar una unica vez o ninguna; si no pasa esto significa que el valor se está repitiendo.

* sudoku:draw
> Esta funcion 'dibuja' el tablero en un ```char*``` pasado por parametro. Se podría resolver con algunas iteraciones por fila y dibujando cada fila como corresponde, pero a mi parecer se iba a hacer un problema mas complejo del que en realidad es asique decidi implementar 3 funciones que dibujen separaciones,lineas y filas con los numeros (igualmente el tamaño del sudoku no debería cambiar, y si se quiere cambiar algun estilo del tablero unicamente hay q tocar la funcion que modifica la linea correspondiente sin tener que preocuparse por un complejo algoritmo que resuelva **éste** caso de tablero).

