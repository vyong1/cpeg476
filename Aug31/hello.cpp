#include <iostream>
//Note that there is a different input/output library iostream
//Also a slightly different notation for including <libraryname> instead of "libraryname.h"

//Again there is a "main" function with a return type "int"
int main() {
  //Now printf is replaced by a "stream" concept, where "cout" is the output stream 
  //and we pipe values into that output stream by the "<<" operator.
  //Also the "\n" has a more abstract version "endl" for a platform independent newline character
  std::cout << "Hello World!" << std::endl;
  //Finally you'll note that there is a "std::" namespace in front of the cout and endl keywords.
  //We can do away with that by having a "using namespace std;" line higher in the code
  //Or even a "using std::cout;" and "using std::endl;" lines higher in the code.
  //In those cases just 'cout << "hello" << endl;' would work
}