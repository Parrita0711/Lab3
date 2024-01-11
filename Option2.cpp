#include <thread>
#include <iostream>

using namespace std;

void threadProc(int x, float y, double *z)
{
    cout << "Dentro de thread " << this_thread::get_id() << endl;
    cout << "Valor de los parametros: int=" << x << ", float=" << y << ", double=" << *z << endl;
}

int main()
{
    thread t1(threadProc, 1, 2.0f, new double(3.0));
    thread t2(threadProc, 4, 5.0f, new double(6.0));
    thread t3(threadProc, 7, 8.0f, new double(9.0));

    t1.join();
    t2.join();
    t3.join();
}