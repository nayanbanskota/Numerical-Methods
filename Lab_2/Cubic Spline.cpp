#include <iostream>
#include <math.h>
using namespace std;

class cubic
{
public:
    void askAll();
    void askI();
    void askX();
    void askFi();
    void askXi();

    void findA();
    void findH();
    void findS();
    void findU();

    void solve();


private:
    double xi[20],f[20],h[19],s[19],a[20],u[20];
    int Inumber;
    double XX;

};
void cubic::askX()
{
    cout << "Enter X: ";
    cin >> XX;
}
void cubic::askI()
{
    cout << "Enter number of Items: ";
    cin >> Inumber;
}

void cubic::askXi()
{
    for(int i = 0; i < Inumber; i++)
    {
        cout << "Enter X" << i << ": ";
        cin >> xi[i];
    }
}


void cubic::askFi()
{
    for(int i = 0; i < Inumber; i++)
    {
        cout << "Enter F" << i << ": ";
        cin >> f[i];
    }
}

void cubic::findU()
{
    for(int i = 0; i < Inumber; i++)
    {
        u[i] = XX - xi[i];
    }
}

void cubic::findH()
{
    for(int i = 1; i < Inumber; i++)
    {
        h[i] = xi[i] - xi[i-1];
    }
}
void cubic::findA()
{
    for(int i = 1; i < Inumber-1; i++)
    {
        a[i] = ( 6*( (f[i+1]-f[i])/h[i+1] -  (f[i]-f[i-1])/h[i]  )  -  h[i]*a[i-1]  -  
               h[i+1]*a[i+1]  ) / (2*( h[i] + h[i+1] ));
    }
}

void cubic::findS()
{
    int k;
    for(int i = 1; i < Inumber; i++)
    {
        if(XX>=xi[i-1]&& XX<=xi[i]){
        s[i] =  a[i-1]/(6*h[i]) * ( pow(h[i],2)*u[i] - pow(u[i],2) )  +  a[i]/(6*h[i]) * 
                ( pow(u[i-1],3)  - pow(h[i],2)*u[i-1]  )   +  1/h[i] * (f[i]*u[i-1]  -  
                f[i-1]*u[i]);
        k = i;
    }
    }
    cout << "s "<< s[k];

}

void cubic::askAll()
{
    askI();
    askXi();
    askFi();
    askX();
    a[0] = 0;
    a[Inumber-1] = 0;
}

void cubic::solve()
{
    findH();
    findU();
    findA();
    findS();
}

int main()
{

    cubic c1;
    c1.askAll();
    c1.solve();
    return 0;
}
