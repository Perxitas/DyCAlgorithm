1.- Asegurarse que todos los archivos esten en una carpeta
2.-Abrir shell de linux en dicha ubicacion
3.-Generar los datos: 
    g++ -g generadordedatasets.cpp -o generador 
    ./generador

4.-Generar ejecutables del sorting a probar
    g++ -g insertion.cpp -o insertion
    g++ -g mergesort.cpp -o merge 
    g++ -g quicksort.cpp -o quick
    g++ -g csorting.cpp -o sorting

5.- Ejecutar algoritmo de sorteo con dataset deseado, ejemplo:
    ./quick random_dataset.txt
    