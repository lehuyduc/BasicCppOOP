int main () {
  int a=10;
  int b=20;
  int c;
  c = g(a,b);
  printf ("value of g(%d,%d)=%d\n", a, b, c);
  return 0;
}

g (int x, int y) {
  return x*x + 2*y*y + y*y ;
}
