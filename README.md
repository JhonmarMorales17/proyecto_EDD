# proyecto_EDD
En el reino del oriente, una familia ha protegido al Shogun por generaciones. Con el avance tecnológico, el clan quiere digitalizar sus registros genealógicos y automatizar la selección de sucesores para mantener el liderazgo de manera eficiente.

Este programa permite:
- Cargar datos familiares desde un archivo CSV.
- Gestionar la línea de sucesión según las reglas del clan.
- Asignar automáticamente un nuevo líder si el actual muere o supera los 70 años.
- Registrar contribuidores (colaboradores del líder) y ordenarlos por importancia.
- Modificar datos de los miembros (excepto ID y padre).

* Funcionalidades del Programa

1. Mostrar línea de sucesión	Lista el orden de herederos al liderazgo (solo vivos).
2. Asignar nuevo líder	Si el líder actual murió, busca automáticamente un sucesor.
3. Verificar edad del líder	Si tiene más de 70 años, transfiere el liderazgo.
4. Mostrar líder actual	Muestra datos del líder y sus contribuidores.
5. Actualizar datos de un miembro	Permite modificar nombre, edad, estado, etc.
0. Salir	Cierra el programa.

❓ Cómo Ejecutar el Código:

Clona el repositorio: " git clone https://github.com/JhonmarMorales17/proyecto_EDD.git "

Compilar el código: " g++ -o .\bin\main.exe .\src\si.cpp "

Ejecutar el programa: " .\bin\main.exe "
