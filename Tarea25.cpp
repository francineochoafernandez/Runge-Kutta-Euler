# Runge-Kutta-Euler
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

typedef struct RungeKuta
{
  float x0,y0,h;
  int n;

  float EcuacionEuler(float x)
  {
    float y;
    y = -2*pow(x,3) + 12*pow(x,2) -20*x + 8.5;
    return y;
  }

  float EcuacionVerdadera(float x)
  {
    float y;
    y = -0.5*pow(x,4) + 4*pow(x,3) - 10*pow(x,2) + 8.5*x+ 1;
    return y;
  }

  void Itera(int op)
  {
    float y=y0;

    if(op==1)
    {
      printf("|    x    |     y     |\t\n");
      for(float i=0;i<n;i=i+0.5)
      {
        y= y +EcuacionEuler(i)*h;
        printf("| %f |  %f  |\t\n",i,y);
      }
    }
    else
    {
      printf("|    x    |     y     |\t\n");
      for(float i=0;i<n;i=i+0.5)
      {
        y= EcuacionVerdadera(i);
        printf("| %f |  %f  |\t\n",i,y);
      }
    }



  }

}RK;

int main (void)
{
  RK ec;
  ec.n=5;//iteraciones
  ec.x0=0;
  ec.y0=1;
  ec.h=0.5;
  cout << "Los valores de Euler son:" << endl;
  ec.Itera(1);
  cout << "Los valores verdaderos son:" << endl;
  ec.Itera(2);

  return 0;
}
