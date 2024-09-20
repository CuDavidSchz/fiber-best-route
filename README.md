
> Written with [StackEdit](https://stackedit.io/).

# Fiber Best Route Sheet

  **W A R N I N G**: if you can not visualize the math formulas, please use [stackedit.io](https://stackedit.io/). Copy and paste the following text.

### Summary

This program receives a list of different places that have to be connected with a fiber optical network and analyzes the best route sheet to perform a project using key data to improve the material use.
  

## How does it work?
  
There is a global data bank that stores different records of places.

**Class Place**

  

The Place class represents each location considered for the deployment of the fiber optic network. It contains all the necessary information to calculate the *Profitability Index (PI)* and determine the optimal deployment route.
| Attribute | Type | Description |
|--|--|--|
| Place_name ( PN ) | string | The name of the place |
| Node_dist ( ND ) | float | The distance between the place and the node that is connecting to ( in kilometers)
| Population ( P ) | int | The quantity of population in that place (non - negative integer).|
|Ppl_p_house ( PPH ) | int | The number of people living in each house (positive integer, ≥ 1). | int | 
|Competitors ( C ) | int | The number of other internet providers in that place. |
| X | float 	| The x coordinate of that place.|
| Y | float |  The y coordinate of that place. |
| Near_Place_Dist ( NPD )| float |The nearest place to another (kilometers) *Not provided by the user. |
|Profit_Index ( PI ) | float | The value that indicates how much relevant is a place to sort the places order connection. *Not provided by the user

#### Class Diagrams

To check more information please go to: 
[FBR Class Diagrams](https://drive.google.com/drive/folders/1pHeLUafpOwZdtY40d7tl2Ynv-B-WTv9D?usp=sharing)
### How calculate the best route?

#### Formula
First, the program needs to calculate the  *Profitability Index ( PI )* of each place. It is calculated as this way:
$$ PI  = (\frac{1}{1+C}) \frac{NH (1 + \alpha \frac{1}{NPD + \beta})}{CPK} $$


There is a class **Calculations** for all the operations needed to perform the **PI** calculation.
#### Formula detailed

- **Term** $\frac{1}{1+C}$ = Reduces PI in places with more competitors
- **Term** $NH$ =- The quantity of houses in that place. * Not provided by the user. It is calculated with getNum_houses: $$ NH = \frac{ P }{ PPH  } $$
- **Term** $1 + \alpha\frac{1}{NPD + \beta}$ = Increases the PI for places that are close to others, weighted by $\alpha$. This favors deployment efficiency when considering geographical proximity.
- **Denominator** $CPK$ = The cost of fiber deployment per kilometer (dollar per kilometer)

#### Variables and constants
The necessary variables to perform the calculations are these:

- **Near_Place_Dist ( NPD )** = The nearest place to another (kilometers)
Calculated with: 
$$ \text{NPD} = \min_{\forall \, \text{other places}} \sqrt{(\text{X} - \text{X}{\text{other}})^2 + (\text{Y} - \text{Y}{\text{other}})^2}$$


- **Num_houses ( NH )** = Explained earlier
- **Competitors ( C )** = Explained earlier
- **Cost_Per_Km ( CPK )** = The cost of deploy fiber per kilometer (dollars per kilometer)

The necessary constants to perform the calculations are these:

- **Alpha** $\alpha$ = Constant that determines how much proximity to other places influences the *Profitability Index (PI)*. Adjusts the weight of geographical proximity in the PI formula. A higher value of $\alpha$ increases the priority of places that are close to others, optimizing deployment by considering benefits such as reduced costs when connecting nearby places.

	$\alpha_1$ = 0.7 = the nearest place distance becomes more important. 
	$\alpha_2$ = 0.3 = it becomes more relevant the number of houses and the competitors. 

- **Beta** $\beta$ = It is a small positive constant that is added to the denominator $(\text{NPD} + \beta)$ to avoid division by zero when the distance to the nearest place is zero. Ensures numerical stability in the calculation of the PI. 


With this value, the program generates a list of a possible way to deploy the fiber and maximize efficiency. 

# Code

## Implementation

#### Calculations
The class *Calculations* has the following methods:

- **calcNPD()** : It uses the formula explained earlier. This is the way it is implemented:

	**Complexity** : 
    enter code here

- **sortNPD()** : It uses a sort included in the *algorithm* library to sort the PI of the different places. It generates a Result object that is going to be displayed by the next class.

	**Complexity** : 
    enter code here

#### Results
The class *Results* has the following methods:
