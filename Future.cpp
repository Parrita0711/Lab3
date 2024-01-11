#include <iostream>
#include <future>
#include <chrono>

using namespace std;

int main() {
    future<int> f = async([](){
        this_thread::sleep_for(chrono::seconds(1));
        return 90;
    });

    cout << "Esperando el resultado..." << endl;
    int result = f.get();
    cout << "Resultdo: " << result << endl;

    return 0;
}
