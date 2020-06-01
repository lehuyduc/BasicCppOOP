#include <iostream>

using namespace std;

const int nb = 10;
const int excluded = 5;

int main () 
{
  cout<<"enter "<<nb<<" values:"<<endl;
  int values[nb];
  for (int i=0; i<nb; i++)
    cin >> values[i];

  int nbval = 0;
  for (int i=0; i<nb; i++)
    switch (values[i]) {
    case excluded-1:
    case excluded  :
    case excluded+1:
      ++nbval;
    }

  cout<<nbval<<" forbidden values"<<endl;

  return 0;
}
