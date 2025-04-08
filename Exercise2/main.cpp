#include <iostream>
#include <iomanip> //precisione 16
#include "Eigen/Eigen" //libreria eigen

using namespace std;
using namespace Eigen;

//funzione per risolvere
void solve(Matrix2d A, Vector2d b)
{
	Vector2d x_es; //inizializzo il vettore soluzione esatta
	x_es<<-1.0, -1.0; 
	Vector2d x_PALU = A.fullPivLu().solve(b); //vettore x risultante dalla fattorizzazione PALU
	Vector2d x_QR = A.householderQr().solve(b); //vettore x risultante dalla fattorizzazione QR
	double err_PALU = (x_PALU-x_es).norm()/x_es.norm();
	double err_QR = (x_QR-x_es).norm()/x_es.norm();
	
	cout << "La soluzione del sistema tramite decomposizione PALU è " << scientific << setprecision(16) << x_PALU << endl;
	cout << "L'errore del sistema tramite decomposizione PALU è " << scientific << setprecision(16) << err_PALU << endl;
	cout << "La soluzione del sistema tramite decomposizione QR è " << scientific << setprecision(16) << x_QR << endl;
	cout << "L'errore del sistema tramite decomposizione QR è " << scientific << setprecision(16) << err_QR << endl;
} 



int main()
{	
	//sistema 1
	cout << "Sistema 1" << endl;	
	Matrix2d A1;
	A1 <<5.547001962252291e-01, -3.770900990025203e-02, 
		8.320502943378437e-01,	-9.992887623566787e-01;
	Vector2d b1;
	b1<<-5.169911863249772e-01, 1.672384680188350e-01;
	
	solve(A1, b1);
	
	
	
	//sistema 2
	cout << "Sistema 2" << endl;	
	Matrix2d A2;
	A2 <<5.547001962252291e-01, -5.540607316466765e-01,
	8.320502943378437e-01, -8.324762492991313e-01;
	Vector2d b2;
	b2<<-6.394645785530173e-04, 4.259549612877223e-04;
	
	solve(A2, b2);
	
	
	//sistema 3
	cout << "Sistema 3" << endl;	
	Matrix2d A3;
	A3 <<5.547001962252291e-01, -5.547001955851905e-01,
	8.320502943378437e-01, -8.320502947645361e-01;
	Vector2d b3;
	b3<<-6.400391328043042e-10,	4.266924591433963e-10;
	
	solve(A3, b3);
	
    return 0;
}