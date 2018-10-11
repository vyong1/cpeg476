#include <iostream>
using std::cout;
using std::endl;

int main() {
//To understand * and & we first have to realize that
//there are FOUR ways to use these symbols:
//"int *varname" vs "*varname" (in the wild)
//"int &varname" vs "&varname" (in the wild)
    
//the four meanings are just different, so always be aware
//of using this symbol in a declaration vs not in a declaration
    
//* in the declaration:
//    int *varname 
//declares varname as a "pointer to an int"
    
//* in the wild:
//    *varname 
// means "contents at location varname"
    
//& in the declaration: 
//     int &varname 
//declares varname as a "reference to an int"
    
//& in the wild:
//     &varname
//means "address of varname"

//Let's practice:

    int i;         //declares an int 
                   //it is left uninitialized
                   
    int *p2i = &i; //declares p2i as a pointer to an int
                   //also sets the value to the "address of" i
    
    int &r2i = i;  //declared r2i as a reference to i
                   //initializes the reference to i
    
    int copy_i = i;//declares another int copy_i
                   //initializes to the value of i
    
    //display the value of each variable:
    cout << "i: " << i << endl;                 // Some random memory value
    cout << "p2i: " << p2i << endl;             //
    cout << "r2i: " << r2i << endl;
    cout << "copy_i: " << copy_i << endl;
    
    //"address of" operator (&) applied to each variable:
    cout << "&i: " << &i << endl;
    cout << "&r2i: " << &r2i << endl;
    cout << "&p2i: " << &p2i << endl;
    cout << "&copy_i: " << &copy_i << endl;
    
    //"contents at" operator (*) only makes sense for pointers
    
    //cout << "*i: " << *i << endl; //gives ERROR
               //invalid type argument of unary '*' (have 'int')
    cout << "*p2i: " << *p2i << endl;
    //cout << "*r2i: " << *r2i << endl; //gives ERROR
               //invalid type argument of unary '*' (have 'int')
    //cout << "*copy_i: " << *copy_i << endl; //gives ERROR
               //invalid type argument of unary '*' (have 'int')
    
    i = 10;
    cout << "\n\nSet i to 10.  Here are the changes:\n\n" << endl;

    //display plain old values o to the value of i
    
    //display the value of each variable:
    cout << "i: " << i << endl;                 // Some random memory value
    cout << "p2i: " << p2i << endl;             //
    cout << "r2i: " << r2i << endl;
    cout << "copy_i: " << copy_i << endl;
    
    //"address of" operator (&) applied to each variable:
    cout << "&i: " << &i << endl;
    cout << "&r2i: " << &r2i << endl;
    cout << "&p2i: " << &p2i << endl;
    cout << "&copy_i: " << &copy_i << endl;
    
    //"contents at" operator (*) only makes sense for pointers
    
    //cout << "*i: " << *i << endl; //gives ERROR
               //invalid type argument of unary '*' (have 'int')
    cout << "*p2i: " << *p2i << endl;
    //cout << "*r2i: " << *r2i < to the value of i
    
    //display the value of each variable:
    cout << "i: " << i << endl;                 // Some random memory value
    cout << "p2i: " << p2i << endl;             //
    cout << "r2i: " << r2i << endl;
    cout << "copy_i: " << copy_i << endl;
    
    //"address of" operator (&) applied to each variable:
    cout << "&i: " << &i << endl;
    cout << "&r2i: " << &r2i << endl;
    cout << "&p2i: " << &p2i << endl;
    cout << "&copy_i: " << &copy_i << endl;
    
    //"contents at" operator (*) only makes sense for pointers
    
    //cout << "*i: " << *i << endl; //gives ERROR
               //invalid type argument of unary '*' (have 'int')
    cout << "*p2i: " << *p2i << endl;
    //cout << "*r2i: " << *r2i << endl; //gives ERROR
               //invalid type argument of unary '*' (have 'int')
    //cout << "*copy_i: " << *co< endl; //gives ERROR
               //invalid type argument of unary '*' (have 'int')
    //cout << "*copy_i: " << *cof each variable:
    cout << "i: " << i << endl;
    cout << "p2i: " << p2i << endl;
    cout << "r2i: " << r2i << endl;
    cout << "copy_i: " << copy_i << endl;
    
    //"address of" operator applied to each variable:
    cout << "&i: " << &i << endl;
    cout << "&r2i: " << &r2i << endl;
    cout << "&p2i: " << &p2i << endl;
    cout << "&copy_i: " << &copy_i << endl;
    
    //"contents at" operator only makes sense for pointers
    cout << "*p2i: " << *p2i << endl;
}