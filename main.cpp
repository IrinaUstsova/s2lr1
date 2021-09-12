#include "Vector.h"

using namespace std;

int main() { //Демонстрация работы функционала
   Vector v;
   v.push_back(62);
   v.push_back(34);
   cout << v;
   cout << v.find(34) << endl;
   int* a = new int[5];

   Vector v1(5, *a);
   cout << v1;
   v1.replace(5, 0);
   cout << v1;
   v = v1;
   cout << v;
}
