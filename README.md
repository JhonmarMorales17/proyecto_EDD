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

Detalle del problema:

-Registros obsoletos: La información está en archivos CSV sin estructura jerárquica, dificultando la visualización de relaciones familiares.

-Sucesión lenta y subjetiva: Sin reglas automatizadas, la elección de un nuevo líder depende de interpretaciones humanas, pudiendo causar disputas.

-Falta de preparación para emergencias: Si el líder muere repentinamente, no hay un mecanismo rápido para asignar un reemplazo válido.

-Pérdida de reconocimiento a contribuidores: No hay un sistema organizado para priorizar aliados clave del clan según su importancia.

*Cómo el Programa Soluciona el Problema
-Eficiencia en Búsqueda:
El árbol binario permite recorridos rápidos para encontrar sucesores según las reglas establecidas.

-Automatización de Sucesión:
Elimina la necesidad de intervención manual, reduciendo conflictos por herencia del liderazgo.

-Reglas Claras y Priorizadas:
El algoritmo sigue estrictamente la jerarquía definida por el clan, asegurando legitimidad.

-Gestión de Contribuidores:
Mantiene un registro ordenado de quienes apoyan al líder, facilitando la toma de decisiones.

Objetivo:
El objetivo principal del código es automatizar el sistema de sucesión del clan según sus reglas tradicionales, garantizando una transición de liderazgo rápida, justa y sin conflictos cuando el líder muera o cumpla 70 años, mientras digitaliza y organiza los registros genealógicos y de contribuidores en una estructura eficiente (árbol binario).

❓ Cómo Ejecutar el Código:

Clona el repositorio: " git clone https://github.com/JhonmarMorales17/proyecto_EDD.git "

Compilar el código: " g++ -o .\bin\main.exe .\src\si.cpp "

Ejecutar el programa: " .\bin\main.exe "
