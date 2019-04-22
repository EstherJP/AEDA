
1.- Seleccion
2.- ShakeSort
3.- HeapSort
4.- MergeSort
5.- ShellSort


***MODO DEMOSTRACION***

-> g++ -g -DEMOSTRACION dni.cpp count.cpp main.cpp -o main_des

-> ./main_des N metodo semilla *alfa
*si el metodo es 5 hay que poner la semilla

***MODO ESTADISTICO***

-> g++ -g dni.cpp count.cpp main.cpp -o main_est

-> ./main_est N *metodo semilla alfa npruebas
*el numero del metodo no influye ya que se ejecutan todos los algoritmos