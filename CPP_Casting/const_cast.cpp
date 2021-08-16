#include <iostream>
using namespace std;

int change(int *p2)
{
   return (*p2 * 10);
}

int main()
{
   // # Example 1
   const int a = 20;
   const int *b = &a;
   cout << "Example 1 | old value is " << *b << "\n";
   int *c = const_cast<int *>(b);
   *c = 40;
   cout << "Example 1 | new value is " << *b << endl;

   // # Example 2
   const int num = 100;
   const int *p = &num;
   int *p1 = const_cast<int *>(p);
   cout << "Example #2 | Output is " << change(p1);

   return 0;
}