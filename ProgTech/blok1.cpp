#include <iostream>

using namespace std;


namespace math{
  int add(int a,int b){ return a+b; }

  int multiply(int a,int b){ return a*b; }

  int power(int base, int exp){
    int result = 1;
    for(int i = 1; i < exp; i++){
      result *= base;
    }
    return result;
  }
}

void swapValues(int& a, int& b) {
  int c = a; a =b; b = c;
}

template<typename T>
void identify(T&& value) {
  cout << value << endl;
}

namespace util {

  template<typename D>
  void swap(D& a, D& b) {
    D c = a; a = b; b = c;
  }
}



int main(){

// ------ Uloha 1 ------

  cout << math::add(2,3) << endl;
  cout << math::multiply(2,3) << endl;
  cout << math::power(2,3) << endl;

// ------ Uloha 2 ------
  int x = 2, y = 3;
  swapValues(x, y);
  cout << x << " " << y << endl;

// ------ Uloha 3 ------
  identify(x);
  identify(10);

// ------ Uloha 4 ------
  int n = 3, m = 9;
  //double m = 5.789; nemoxeme daj v funkciu swap parametre
  //rozneho typu, lebo typename funguje iba s jednym
  util::swap(n,m);
  cout << n << " " << m << endl;
  return 0;
}
