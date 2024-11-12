

# Proyecto: Fiber Best Route Sheet

  
  

**A D V E R T E N C I A :** Si no puede visualizar de forma correcta las fórmulas matemáticas puede copiar y pegar el archivo README en el siguiente editor [StackEdit](https://stackedit.io/app#)

  

Este programa es capaz de calcular una ruta de despliegue de fibra óptica optimizada para obtener el mejor beneficio según los parámetros de cada lugar a partir de una lista de lugares a ordenar. Tiene dos configuraciones diferentes en el cálculo dependiendo las necesidades del usuario.

## Descripción del avance 1

  

Esta primer iteración, el proyecto contiene las clases necesarias para poder llevar a cabo los cálculos descritos anteriormente.

  

### Clases implementadas :

- Menu: contiene todas las opciones y métodos auxiliares para funcionar.

- Place: es el objeto para crear todos los lugares que desean ser ordenados.

- Calculations: contiene todas las funciones para llevar a cabo los cálculos necesarios.

  

#### Class Diagrams

  

Para más información:

[FBR Class Diagrams](https://drive.google.com/drive/folders/1pHeLUafpOwZdtY40d7tl2Ynv-B-WTv9D?usp=sharing)

  
  

### Capacidades:

El programa es capaz de crear un vector personalizado por el usuario o usar un ejemplo incorporado en el programa.

Para lograr el ordenamiento, se creó una clase llamada *Calculations* para guardar todos los métodos necesarios. Se hizo uso se la librería *algorithm* y tres iteraciones para lograr el resultado deseado.

#### Métodos usados :

  

• **calcNPD()**: Calcula la distancia más cercana entre cada lugar y cualquier otro lugar de la lista.

  

-  **calculateDistance()**: Método auxiliar para calcular la distancia entre dos lugares usando la fórmula de distancia euclidiana:

  

$$  \text{NPD} = \min_{\forall , \text{otros lugares}} \sqrt{(\text{X} - \text{X}{\text{otro}})^2 + (\text{Y} - \text{Y}{\text{otro}})^2}$$

  

**Complejidad**: $O(n^2)$ -> Debe calcular la distancia entre cada par de lugares.

  

<br>

<br>

  

• **calcPI()**: Calcula el Índice de Rentabilidad (PI) de un lugar en función de la opción alpha seleccionada (1 o 2) y el costo por kilómetro (CPK). Este método no devuelve el valor de PI directamente; en su lugar, lo asigna al atributo _Profit_Index_ del objeto Place.

  

$$ PI = (\frac{1}{1+C}) \frac{NH (1 + \alpha  \frac{1}{NPD + \beta})}{CPK} $$

  

**Fórmula detallada**

  

  

• **Término** $\frac{1}{1+C}$ = Reduce el PI en lugares con más competidores.

  

• **Término** $NH$ = La cantidad de casas en ese lugar. *No es proporcionado por el usuario, se calcula con el método _getNum_houses_: $$ NH = \frac{ P }{ PPH }$$

  

• **Término** $1 + \alpha\frac{1}{NPD + \beta}$ = Incrementa el PI para los lugares que están cerca de otros, ponderado por $\alpha$. Esto favorece la eficiencia de despliegue cuando se considera la proximidad geográfica.

  

• **Denominador** $CPK$ = El costo de despliegue de fibra por kilómetro (dólares por kilómetro).

  

  

**Variables y constantes**

  

  

Las variables necesarias para realizar los cálculos son las siguientes:

  

  

• **Near_Place_Dist ( NPD )** = La distancia al lugar más cercano (en kilómetros). Se calcula con _calcNPD()_ en la clase _Calculations_.

  

• **Num_houses ( NH )** = Explicado anteriormente.

  

• **Competitors ( C )** = Explicado anteriormente.

  

• **Cost_Per_Km ( CPK )** = El costo de desplegar fibra por kilómetro (dólares por kilómetro).

  

  

Las constantes necesarias para realizar los cálculos son las siguientes:

  

  

• **Alpha** $\alpha$ = Constante que determina cuánto influye la proximidad a otros lugares en el _Índice de Rentabilidad (PI)_. Ajusta el peso de la proximidad geográfica en la fórmula del PI. Un valor más alto de $\alpha$ aumenta la prioridad de los lugares que están cerca de otros, optimizando el despliegue al considerar beneficios como la reducción de costos al conectar lugares cercanos.

  

$\alpha_1$ = 0.7 = La distancia al lugar más cercano se vuelve más importante.

  

$\alpha_2$ = 0.3 = Se vuelve más relevante el número de casas y los competidores.

  

• **Beta** $\beta$ = Es una pequeña constante positiva que se añade al denominador $(\text{NPD} + \beta)$ para evitar divisiones por cero cuando la distancia al lugar más cercano es cero. Asegura la estabilidad numérica en el cálculo del PI.

  

**Complejidad**: $O(n)$ -> Se ejecuta $n$ veces para conocer el PI de cada lugar.

  

<br>

<br>

  

• **sortPlaces()** ordena un vector de objetos _Place_ basándose en tres criterios diferentes.

  

• **Criterios de ordenamiento**:

  

1.  **Índice de Rentabilidad (Profit_Index)**: En primer lugar, los lugares se ordenan en función de su _Profit_Index_ en orden descendente (es decir, los lugares con mayor _Profit_Index_ aparecerán primero en la lista).

  

2.  **Distancia al Nodo (Node_distance)**: Si dos o más lugares tienen el mismo _Profit_Index_, entonces se ordenarán por su distancia al nodo en orden ascendente (los lugares más cercanos al nodo aparecerán primero).

  

3.  **Distancia al Lugar Más Cercano (Near_Place_Dist)**: En caso de que dos o más lugares tengan el mismo _Profit_Index_ y la misma _Node_distance_, se ordenarán por la distancia al lugar más cercano (_Near_Place_Dist_) en orden ascendente (los lugares más cercanos a otros aparecerán primero).

  

• **Complejidad**: $O(n \log n)$ -> Utiliza un algoritmo de ordenamiento proporcionado por la biblioteca _algorithm_ para llevar a cabo la tarea.

<br>

<br>

## Descripción del avance 2

Este avance contiene una optimización en la manera en que se obtiene el atributo de _near place distance_ para cada objeto de tipo _Place_.

Se hizo implementó una estructura de datos de tipo _DK Tree_ que permite el ordenamiento de los datos en forma de un árbol de búsqueda binaría pero usando valores bidimensionales por el atributo de las coordenadas de cada lugar.

**¿Cómo funciona en el proyecto?**

•  **Construcción del KD-Tree**:

•  Se construye el KD-Tree a partir de la lista de lugares, organizándolos recursivamente. En cada nivel del árbol, se alterna entre dividir los puntos según la coordenada X y la Y.

•  Esto crea una estructura equilibrada que divide el espacio en regiones más pequeñas, facilitando las búsquedas.

•  **Cálculo del NPD (Near Place Distance)**:

•  Para cada lugar, en lugar de comparar con todos los demás (lo cual sería ineficiente para grandes conjuntos de datos), se utiliza el KD-Tree para encontrar su vecino más cercano de forma eficiente.

•  La búsqueda en el KD-Tree permite descartar rápidamente ramas del árbol que no pueden contener al vecino más cercano, reduciendo el número de comparaciones necesarias.

•  **Búsqueda del Vecino Más Cercano**:

•  Se realiza una búsqueda recursiva que en cada paso decide qué rama del árbol explorar en función de la distancia potencial al vecino más cercano.

•  Si una rama no puede contener un punto más cercano que el mejor encontrado hasta el momento, se deja de explorar.

### Cambios sobre el primer avance

1. **calcNPD()** : Anteriormente se tenía una función que usaba la fuerza bruta para poder obtener la distancia más corta al vecino más cercano de cada lugar que se hacía la comparación. La complejidad computacional de esta operación era de $O(n^2)$ en todos los casos porque tenía que comparar cada par de lugares en el vector para obtener la distancia más corta entre ellos. Con la implementación del DK Tree y su método de _nearest Neighbour_ se tiene una complejidad siguiente: 
		- Mejor: $O(n \log n)$ porque la comparación entre las ramas descarta las que definitivamente están lejos del valor deseado.
		- Peor: $O(n^2)$ en esta implementación el árbol puede degenerarse si los valores difieren mucho entre si (no es un árbol AVL), por lo que tendría que hacer la comparación con cada uno de los nodos. 
		- Promedio: $O(n \log n)$ con coordenadas aleatorias y un ligero balance en el árbol, el cálculo del NPD con el árbol es similar al mejor caso. 
<br>

2. **Recibir documentos** : Ahora se pueden cargar archivos de texto para agregar la lista personalizada de los lugares. Se hizo uso de la librería _fstream_. 

3. **Misceláneo** : Los demás cambios son en el menú para adaptarlo a la nueva opción _"4.- Cargar lugares desde un archivo"_ y la forma en que se procesa el constructor del DK Tree al momento de elegir la opción _"2.- Crear mejor ruta de despliegue"_.
<br>

<br>

## Descripción del avance 3

Este avance incluye la reestructuración del menú y la capacidad de exportar archivos de texto con la mejor ruta de despliegue recomendada. 
### Cambios sobre el segundo avance
1. Las opciones del menú fueron reordenadas para tener más coherencia. Cargar una lista de lugares desde un archivo es ahora una extensión del caso de uso de "Crear una lista de lugares". 
2. La opción de exportar el archivo con la sugerencia de la ruta de despliegue fue agregada como una extensión al caso de uso de "Crear mejor ruta de despliegue" al final de dicho caso.



## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:
  
**Windows**
`g++ -std=c++17 src\main.cpp src\Menu.cpp src\Place.cpp src\Calculations.cpp src\KDTree -Iinclude -o program.exe` 

**MacOS**
`clang++ -std=c++17 src/main.cpp src/Menu.cpp src/Place.cpp src/Calculations.cpp src/KDTree.cpp -Iinclude -o program` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

**Windows**
`start program.exe` 
**MacOS**
`./program` 

## Descripción de las entradas del avance de proyecto
El programa puede recibir entradas de dos maneras:

  

1. **Ingreso Manual de Lugares**:

•  A través del menú, el usuario puede crear una lista personalizada ingresando los datos de cada lugar manualmente.

•  Los datos solicitados para cada lugar son:

•  **Nombre del lugar**: Texto.

•  **Distancia al nodo**: Número decimal (kilómetros).

•  **Población**: Número entero.

•  **Personas por casa**: Número entero.

•  **Competidores**: Número entero.

•  **Coordenada X**: Número decimal.

•  **Coordenada Y**: Número decimal.

2. **Carga de Lugares desde un Archivo**:

•  El usuario puede cargar una lista de lugares desde un archivo de texto siguiendo el formato especificado.

•  Cada línea representa un lugar y debe tener los datos separados por comas, en el siguiente orden:

- NombreDelLugar,DistanciaAlNodo,Población,PersonasPorCasa,Competidores,CoordenadaX,CoordenadaY
<br>

Ejemplo:

Ciudad A,10.0,5000,4,2,100.0,200.0
Ciudad B,15.0,3000,5,1,150.0,250.0
Ciudad C,20.0,8000,3,0,200.0,300.0

**I M P O R T A N TE**

•  El archivo debe estar en el mismo directorio desde el cual se ejecuta el programa o se debe proporcionar la ruta completa al archivo.

Si deseas probar con el archivo de prueba solo debes escribir: _example.txt_ en la opción 1 y escoger "2.- Cargar lugares desde un archivo".

## Descripción de las salidas del avance de proyecto
El programa proporciona los siguientes resultados:

**Lista Ordenada de Lugares**:

•  Después de procesar los datos y calcular el Índice de Rentabilidad (PI) para cada lugar, el programa muestra una lista ordenada de los lugares según su PI, de mayor a menor.

•  La información presentada para cada lugar incluye:

- **Nombre del lugar**.

-  **Índice de Rentabilidad (PI)**.

-  **Distancia al nodo**.

-   **Near Place Distance (NPD)**.

-  **Detalle de Cálculos**:

•  El programa puede mostrar el valor de NPD como depuración. 
Finalmente se ordenan de acuerdo sortPlaces().

| PN | PI |ND | NPD |
|--|--|--|--|
| Ciudad C | 5.59407 | 20.0 | 14.1421 |
| Ciudad A | 0.859305 | 10.0| 14.1421 |
| Ciudad B | 0.62949 | 15.0 | 14.1421 |

Dado el siguiente resultado tiene sentido basado en las reglas que se usaron en sortPlaces()

Conviene conectar primero la Ciudad C porque no existe ningún competidor y en la zona más competitiva hay 5, por lo que conviene dejarla hasta el final de la conexión.

**Archivos exportados**:
Ahora es posible guardar la lista en un archivo de tipo texto que guardará en cada linea un resultado como la tabla anterior. 

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Decidí explicar la complejidad computacional en las capacidades del programa para acompañarlo de las fórmulas matemáticas que se requieren para llevar a cabo la lógica del programa. De forma resumida puedo listar las funciones y la complejidad:

1.  **calcNPD()**

Este método cambió, la complejidad se describe arriba en el primer cambio.

2.  **calcPI()**:

**Complejidad**: $O(n)$

Este no es propiamente un algoritmo de ordenamiento, pero su complejidad es más sencilla ya que sólo calcula el valor de PI aunque la fórmula se vea complicada.

3.  **sortPlaces()**:

**Complejidad**: $O(n \log n)$

El algoritmo de ordenamiento que se utiliza es una función sort() de la biblioteca _algorithm_, la cual emplea *introsort* como su implementación por defecto (Wikipedia). Este algoritmo combina *quicksort*, *heapsort* y *insertion sort*, por lo que mantiene una complejidad promedio de $O(n \log n)$.
#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

Escogí el KD Tree porque la manera en que se organiza la información en el es por varias dimensiones, su nombre dice KD por que puede ser de K dimensiones. En mi caso solo necesitaba 2 por las posiciones geográficas en 2D. Su complejidad es muy similar a la de un árbol de búsqueda binaria. 

El árbol se construye recursivamente cada vez que se agrega un nodo, por lo que esta parte tiene un $O(n \log n)$.

Una estructura que no cambie fue el uso de vectores. El KD Tree me ayudó a mejorar la operación de _calcNPD()_ pero no era óptimo para realizar el en el cálculo del PI y en el ordenamiento de la salida, necesitaba un recorrido iterativo y era más sencillo de implementar y entender con un vector.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

Las funciones más importantes del programa ya han sido analizadas con anterioridad, sin embargo existen otro métodos que son más sencillos y están presentes en partes como el menú, en la carga y exportación de datos. 

**Métodos adicionales**: 
En el menú: 

1. **Display**: $O(1)$
	Solo despliega el menú que se ha escrito.
2. **ProcessInput**: $O(1)$
	Procesa la opción del usuario.
3. **CreatePlaces**: $O(n)$
	Este combina el constructor de los lugares para agregarlos al vector designado para guardar los lugares, por lo que se repite las veces que el usuario necesite. 
4. **BestDeployment**: $O(n \log n)$
	Debido a que hace uso de la estructura de datos KD Tree su complejidad es de $O(n \log n)$ porque descarta las ramas que definitivamente no prometen un resultado cercano al deseado. Sin embargo, como el árbol no es AVL se puede degenerar si las coordenadas difieren mucho entre si dando como resultado una complejidad en el peor caso de $O(n^2)$. Sin embargo, para ese punto tendría que ser muy obvio que lo lugares están tan separados que perdería el sentido usar el programa para una ruta ya que el gasto de recursos sería igual a conectar cada lugar uno por uno. 
	
	Para este caso, sería más recomendable usar grafos con una matriz de adyacencia para buscar la ruta más corta en el orden en que los puntos desean conectarse, sin embargo debido al tiempo de desarrollo de este proyecto, el KD Tree era la estructura de datos óptima para esta tarea. 

5. **ModifyCustomPlaces**: $O(n)$
	El usuario modifica, elimina o añade lugares las veces que quiera.

6. **LoadPlacesFromFile**: $O(n)$
	Debido a que es una función iterativa, se ejecutará n veces según cuantos registros tenga el archivo que se desea agregar 

7. **exportBestRoute**:  $O(n)$
	Similar a cargar datos, este método se ejecuta n veces según sea el número de lugares que se han ordenado en el vector de lugares. 

8. **initializeExamplePlaces**: $O(1)$
	Este método inicializa el vector de ejemplo cada vez que se inicia el programa por lo que solo se realiza una sola vez. 

#### COMPLEJIDAD FINAL DEL PROGRAMA: 

El método más complejo del programa es la comparación entre lugares para conocer su distancia más corta entre sí, por lo que podríamos tomar ambos escenarios; peor $O(n^2)$ y promedio $O(n \log n)$,  como la complejidad final. 
¿Por qué? Porque en un escenario real sería muy complicado que se diera el peor ya que deben estar muy separados los lugares para que se diera el peor escenario y en ese caso, la diferencia de distancia sería tanta que podría ser vista la inneficiencia lógica de usar el programa para tratar de encontrar la mejor ruta en lugares tan separados. Por lo que la mayor parte del tiempo, el programa tendrá una complejidad de $O(n \log n)$.


	


### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
En base a las instrucciones dadas, el algoritmo de ordenamiento ha sido implementado correctamente en el método **sortPlaces()**

porque automatiza tres ordenamientos por criterios diferentes (descritos anteriormente) por medio de la función sort() de la biblioteca estándar de C++.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Aunque el algoritmo de ordenamiento se mantiene igual, el KD Tree y el método del vecino más cercano permite que el programa sea más escalable con grandes volúmenes de información porque su caso promedio es de una complejidad de $O(n \log n)$. Nota: La complejidad del método está detallada en el cambio 1 de este avance.

Iba a ser muy complicado hacer una implementación con un árbol de búsqueda binaria si la formula para el PI seguía considerando el NPD. Podría haber modificado la fórmula y quedarme con el ordenamiento del árbol sólo por el PI y podía usar sin problemas un árbol de búsqueda binaría. Pero usar un árbol bidimensional para mejorar un método de cálculo de distancias parecía más interesante. 


### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.

El programa usa dos métodos para consultar información. Cada vez que el usuario agrega un nuevo lugar, primero se carga al vector _customPlaces_ y posteriormente se hace la consulta de la mejor ruta de despliegue en dónde se construye el árbol para realizar la operación de los vecinos más cercanos. 

Si bien no contempla un método para traer un nodo en específico, la naturaleza del programa no necesita de dicha función. Esto es porque la estructura de datos del KD Tree más que servir como almacén, sirve como un comparador y esto hace que dentro de la navegación del método del vecino más cercano solo se necesite consultar las hojas de cada nodo por medio se sus punteros. 

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

Para esta competencia solo fue necesario entender cómo funcionaba la librería estándar de fstream para la lectura de datos. Posteriormente, era cuestión de usar un ciclo While para leer las líneas del archivo y asignar cada valor separado por comas a un atributo del constructor de los objetos de tipo Place y agregarlos al vector de _customPlaces_. 

Como se mencionó anteriormente, el vector se transforma en un árbol cuando el usuario haya terminado de personalizar la lista de los lugares que desea comparar, por lo que los valores de los archivos se implementan a un vector para facilitar las cosas.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta

Para esta competencia fue necesario aprender a usar la otra parte de la librería de fstream para la escritura de archivos. Para esto solo es necesario abrir el archivo; en caso de que no exista lo crea desde cero, después iterar sobre el vector de lugares en donde se ha guardado la lista ordenada y extraer los atributos de cada lugar con los getters para ser escritos en el archivo. 

Cómo área de mejora se podría implementar que cada archivo tenga un número al final para no sobre escribir el mismo archivo (algo así como las descargas en internet que agregan un número al final aunque sea el mismo archivo), sin embargo no supe como lograr eso aún. 