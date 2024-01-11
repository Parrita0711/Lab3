#include <thread>
#include <iostream>

using namespace std;

void threadProc()
{
    cout << "Inside thread = " << this_thread::get_id() << endl;
}

int main()
{
    thread t(threadProc);
    t.join();
}