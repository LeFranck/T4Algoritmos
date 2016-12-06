# T4Algoritmos
Input: Lista de enteros sin repetición
Output: mediana de la lista
Tiempo: O(n)
Enfoque: Aleatorizado

P1: El n0 escogido fue 145, y la probabilidad asociada a no tener resultado esta acotada por n^(-0.3606).
Estos valores vienen de escoger la lista R de largo n^(0.6394), este exponente se escoge debido a que a menor exponente menor probabilidad de
no tener resultado. El analisis fue buscar el menor n0 donde el analizis de la probabilidad siguiera 
teniendo sentido y a la vez el d y u no se salieran de R. 

PD: hay un bug con el generador de numeros aleatorios

