#include <iostream>
#include <iomanip>
using namespace std;

float proterm(int i, float value, float x[])
{
	float pro = 1;
	for (int j = 0; j < i; j++) {
		pro = pro * (value - x[j]);
	}
	return pro;
}

void dividedDiffTable(float x[], float y[][10], int n)
{
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
		}
	}
}

float applyFormula(float value, float x[],
				float y[][10], int n)
{
	float sum = y[0][0];

	for (int i = 1; i < n; i++) {
	sum = sum + (proterm(i, value, x) * y[0][i]);
	}
	return sum;
}

void printDiffTable(float y[][10],int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			cout << setprecision(4) <<y[i][j] << "\t ";
		}
		cout << "\n";
	}
}

int main()
{
		float value, sum, y[10][10];
    float x[4];
    int n= sizeof(x)/sizeof(int);

    cout<<"Enter the value for x:"<<endl;
    for(int i=0; i<n; i++){
        int k=i;
        cout<<++k<<":";
        cin>>x[i];
    };

    cout<<"Enter the vales for y: "<<endl;
    for(int i=0; i<n; i++){
        int k=i;
        cout<<++k<<":";
        cin>>y[i][0];
    }

    cout<<endl<<"Divided Difference Table"<<endl;

	dividedDiffTable(x, y, n);

	printDiffTable(y,n);

	value = 7;

	cout << "\nValue at " << value << " is "
			<< applyFormula(value, x, y, n) << endl;
	return 0;
}
