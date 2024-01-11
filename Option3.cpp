#include <thread>
#include <vector>
#include <iostream>

using namespace std;

//Funcion para calcular el productor entre dos vectores
double puntoProducto(const vector<double>& vec1, const vector<double>& vec2, size_t start, size_t end)
{
    double resultado = 0.0;
    for (size_t i = start; i < end; ++i)
    {
        resultado += vec1[i] * vec2[i];
    }
    return resultado;
}

int main()
{
    //Dos vectores del mismo tamaño
    vector<double> vec1 = {30.0, 29.0, 28.0};
    vector<double> vec2 = {28.0, 29.0, 30.0};

    // Definimos los hilos
    size_t numThreads = 3;

    //Se calcula el rango de indices para cada hilo
    size_t tamaño = vec1.size();
    size_t tamañoBloque = tamaño / numThreads;

    //Matriz para almacenar el resultado de cada hilo
    double resultados[numThreads];

    //Se crean y se inician los hilos
    thread threads[numThreads];
    for (size_t i = 0; i < numThreads; ++i)
    {
        size_t start = i * tamañoBloque;
        size_t end = (i == numThreads - 1) ? tamaño : start + tamañoBloque;
        threads[i] = thread(puntoProducto, ref(vec1), ref(vec2), start, end);
    }

    //Se espera a que terminen todos los hilos y arroje los resultado
    for (size_t i = 0; i < numThreads; ++i)
    {
        threads[i].join();
        resultados[i] = puntoProducto(vec1, vec2, i * tamañoBloque, (i == numThreads - 1) ? tamaño : (i + 1) * tamañoBloque);
    }

    //Se calcula el punto producto final sumando todos los hilos
    double puntoProductoResultado = 0.0;
    for (size_t i = 0; i < numThreads; ++i)
    {
        puntoProductoResultado += resultados[i];
    }

    //Se imprime el resultado
    cout << "El producto de los dos vectores es: " << puntoProductoResultado << endl;
}