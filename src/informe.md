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