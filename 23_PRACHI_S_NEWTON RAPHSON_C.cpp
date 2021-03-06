#include <iostream>
#include<math.h>
#include<iomanip>
#include<stdlib.h>

using namespace std;
float f(float x) //the main function on which we will perform the Newton-Raphson method
{
    float a = x*sin(x)+cos(x);
    return a;
}

float g(float x) //derivative of the function f
{
    float a = x*cos(x);
    return a;
}

int main()
{
    float x0,x1,E,f0,f1,g0,x2;
    int i =1;
    cout<<"Enter the value of initial guess:\t";
    cin>>x0;
    E = 0.00001;
    cout<<"E = 0.00001 \n";
    do
	 {
        g0 = g(x0);
        f0 = f(x0);
        if(g0 == 0.0)
		  {
			   cout<<"Mathematical Error.";
			   exit(0);
		  }
        x1 = x0 - f0/g0;
        x2 = (fabs(x1-x0)/x1);


		  cout<<"Iteration-"<< i<<":\t x = "<<"\t"<< x1<<" and f(x) = "<<"\t"<< f(x1)<< endl;
		  x0 = x1;
		  i++;
		  if (x2>E)
          {
              cout<<"Convergent"<<endl;
          }

		  f1 = f(x1);

	 }while(fabs(f1)>E);

	 cout<< endl<<"The root of the function f is: "<< x1;
	 return 0;
}
