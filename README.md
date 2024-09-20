
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

•  **calcNPD()**: Calcula la distancia más cercana entre cada lugar y cualquier otro lugar de la lista.

- **calculateDistance()**: Método auxiliar para calcular la distancia entre dos lugares usando la fórmula de distancia euclidiana:

$$ \text{NPD} = \min_{\forall , \text{otros lugares}} \sqrt{(\text{X} - \text{X}{\text{otro}})^2 + (\text{Y} - \text{Y}{\text{otro}})^2}$$

**Complejidad**: $O(n^2)$ -> Debe calcular la distancia entre cada par de lugares.

<br>
<br>

•  **calcPI()**: Calcula el Índice de Rentabilidad (PI) de un lugar en función de la opción alpha seleccionada (1 o 2) y el costo por kilómetro (CPK). Este método no devuelve el valor de PI directamente; en su lugar, lo asigna al atributo _Profit_Index_ del objeto Place.

$$ PI  = (\frac{1}{1+C}) \frac{NH (1 + \alpha \frac{1}{NPD + \beta})}{CPK} $$

**Fórmula detallada**

  

•  **Término** $\frac{1}{1+C}$ = Reduce el PI en lugares con más competidores.

•  **Término** $NH$ = La cantidad de casas en ese lugar. *No es proporcionado por el usuario, se calcula con el método _getNum_houses_: $$ NH = \frac{ P }{ PPH  }$$

•  **Término** $1 + \alpha\frac{1}{NPD + \beta}$ = Incrementa el PI para los lugares que están cerca de otros, ponderado por $\alpha$. Esto favorece la eficiencia de despliegue cuando se considera la proximidad geográfica.

•  **Denominador** $CPK$ = El costo de despliegue de fibra por kilómetro (dólares por kilómetro).

  

**Variables y constantes**

  

Las variables necesarias para realizar los cálculos son las siguientes:

  

•  **Near_Place_Dist ( NPD )** = La distancia al lugar más cercano (en kilómetros). Se calcula con _calcNPD()_ en la clase _Calculations_.

•  **Num_houses ( NH )** = Explicado anteriormente.

•  **Competitors ( C )** = Explicado anteriormente.

•  **Cost_Per_Km ( CPK )** = El costo de desplegar fibra por kilómetro (dólares por kilómetro).

  

Las constantes necesarias para realizar los cálculos son las siguientes:

  

•  **Alpha** $\alpha$ = Constante que determina cuánto influye la proximidad a otros lugares en el _Índice de Rentabilidad (PI)_. Ajusta el peso de la proximidad geográfica en la fórmula del PI. Un valor más alto de $\alpha$ aumenta la prioridad de los lugares que están cerca de otros, optimizando el despliegue al considerar beneficios como la reducción de costos al conectar lugares cercanos.

$\alpha_1$ = 0.7 = La distancia al lugar más cercano se vuelve más importante.

$\alpha_2$ = 0.3 = Se vuelve más relevante el número de casas y los competidores.

•  **Beta** $\beta$ = Es una pequeña constante positiva que se añade al denominador $(\text{NPD} + \beta)$ para evitar divisiones por cero cuando la distancia al lugar más cercano es cero. Asegura la estabilidad numérica en el cálculo del PI.

**Complejidad**: $O(n)$ -> Se ejecuta $n$ veces para conocer el PI de cada lugar.

<br>
<br>

• **sortPlaces()** ordena un vector de objetos _Place_ basándose en tres criterios diferentes. 

•  **Criterios de ordenamiento**:

1. **Índice de Rentabilidad (Profit_Index)**: En primer lugar, los lugares se ordenan en función de su _Profit_Index_ en orden descendente (es decir, los lugares con mayor _Profit_Index_ aparecerán primero en la lista).

2. **Distancia al Nodo (Node_distance)**: Si dos o más lugares tienen el mismo _Profit_Index_, entonces se ordenarán por su distancia al nodo en orden ascendente (los lugares más cercanos al nodo aparecerán primero).

3. **Distancia al Lugar Más Cercano (Near_Place_Dist)**: En caso de que dos o más lugares tengan el mismo _Profit_Index_ y la misma _Node_distance_, se ordenarán por la distancia al lugar más cercano (_Near_Place_Dist_) en orden ascendente (los lugares más cercanos a otros aparecerán primero).

•  **Complejidad**: $O(n \log n)$ -> Utiliza un algoritmo de ordenamiento proporcionado por la biblioteca _algorithm_ para llevar a cabo la tarea.
<br>
<br>  

## Instrucciones para compilar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

**Windows**

     g++ -std=c++17 src\main.cpp src\Menu.cpp src\Place.cpp src\Calculations.cpp -Iinclude -o program.exe

**MacOS**

    clang++ -std=c++17 src/main.cpp src/Menu.cpp src/Place.cpp src/Calculations.cpp -Iinclude -o program

  

## Instrucciones para ejecutar el avance de proyecto

Ejecuta el siguiente comando en la terminal:
**Windows**

     start program.exe

**MacOS**

    ./program

  

## Descripción de las entradas del avance de proyecto

El programa no requiere de ningún archivo externo, ya que las entradas necesarias son provistas directamente a través del menú interactivo o por vectores predeterminados.

Las entradas principales del programa consisten en un vector de objetos Place, donde cada objeto representa un lugar que debe ser conectado a una red de fibra óptica. Cada lugar tiene las siguientes características:

| Atributo | Tipo | Descripción |
|--|--|--|
| Place_name ( PN ) | string | Nombre del lugar |
| Node_dist ( ND ) | float | Distancia entre el lugar y el nodo más cercano (en kilómetros).
| Population ( P ) | int | Cantidad de población en el lugar (entero no negativo).|
|Ppl_p_house ( PPH ) | int | Número de personas viviendo en cada casa (entero positivo, ≥ 1).| int | 
|Competitors ( C ) | int | Número de otros proveedores de internet en el lugar. |
| X | float 	| Coordenada X del lugar.|
| Y | float |  Coordenada Y del lugar. |
| Near_Place_Dist ( NPD )| float |Distancia al lugar más cercano (en kilómetros). *No proporcionado por el usuario. |
|Profit_Index ( PI ) | float | Valor que indica la relevancia del lugar para ordenar el orden de conexión de los lugares. *No proporcionado por el usuario.

  #### Vector de ejemplo:

| PN | ND |P | PPH | C | X 	| Y | 
|--|--|--|--|--|--|--|
| Ciudad A | 10.0 | 5000 | 4 | 2 | 100.0 | 200.0	|
| Ciudad B | 15.0 | 3000| 5 | 1 | 150.0 | 250.0 |
| Ciudad C | 20.0 | 8000 | 3 | 0 | 200.0 | 250.0 |


  

## Descripción de las salidas del avance de proyecto

Finalmente se ordenan de acuerdo sortPlaces().

| PN | PI |ND | NPD | 
|--|--|--|--|
| Ciudad C | 5.59407 | 20.0 | 14.1421 |
| Ciudad A | 0.859305 | 10.0| 14.1421 | 
| Ciudad B | 0.62949 | 15.0 | 14.1421 |


Dado el siguiente resultado tiene sentido basado en las reglas que se usaron en sortPlaces()

Conviene conectar primero la Ciudad C porque no existe ningún competidor y en la zona más competitiva hay 5, por lo que conviene dejarla hasta el final de la conexión.

  

## Desarrollo de competencias

  

### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

Decidí explicar la complejidad computacional en las capacidades del programa para acompañarlo de las fórmulas matemáticas que se requieren para llevar a cabo la lógica del programa. De forma resumida puedo 
listar las funciones y la complejidad: 

1. **calcNPD()**
		  **Complejidad**: $O(n^2)$ 
		A medida que crece el vector, se deben realizar todas las posibles combinaciones de los lugares más cercanos y por eso es tan complejo.
	
2. **calcPI()**:
		**Complejidad**: $O(n)$
		Este no es propiamente un algoritmo de ordenamiento, pero su complejidad es más sencilla ya que sólo calcula el valor de PI aunque la fórmula se vea complicada.

3. **sortPlaces()**:
		**Complejidad**: $O(n \log n)$
			El algoritmo de ordenamiento que se utiliza es una función sort() de la biblioteca _algorithm_, la cual emplea *introsort* como su implementación por defecto (Wikipedia). Este algoritmo combina *quicksort*, *heapsort* y *insertion sort*, por lo que mantiene una complejidad promedio de $O(n \log n)$.

### SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

En base a las instrucciones dadas, el algoritmo de ordenamiento ha sido implementado correctamente en el método **sortPlaces()**
porque automatiza tres ordenamientos por criterios diferentes (descritos anteriormente) por medio de la función sort() de la biblioteca estándar de C++.

Cómo mejora considero que podría implementarse un algoritmo de árboles vecinos porque podría reducir dos métodos que son el propio **sortPlaces()** y **calcNPD()** porque podría buscar y ordenar directamente los vecinos más cercanos sin elevar la complejidad a $O(n^2)$. 

La escalabilidad del programa es limitada debido a la función **calcNPD()**.

Para esta primer iteración decidí usar sorts debido a que fueron los conocimientos que tenía a la mano. 