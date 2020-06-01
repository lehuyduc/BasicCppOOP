#include <iostream>

// TODO: add the swap function ...
void swap(const int* &p1, const int* &p2)
{
    const int* i = p1;
    p1 = p2;
    p2 = i;
}


int main() {
  const int arrays[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  const int *p1 = arrays+1;
  const int *p2 = arrays+8;
  std::cout << *p1 << " and "<< *p2 << std::endl;

    std::cout << p1 << " " << p2 << "\n";
  swap( --p1, ++p2 );
    std::cout << p1 << " " << p2 << "\n";
  std::cout << *p1 << " and "<< *p2 << std::endl;

  return 0;
}
