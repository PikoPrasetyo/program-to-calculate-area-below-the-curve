#include <iostream> //1. deklarasi library yang akan digunakan.
#include <iomanip>
#include <cmath>
#include <conio.h>

using namespace std;

class variable { //2. deklarasi class.
	float batas_bawah, batas_atas; //3. deklarasi variable.
	float i, n;
	float delta_X;
	float jumlah = 0;
	float fungsi(float x)
	{
		return (x*x + 2*x - 3); //4. deklarasi kurva yang ingin dihitung luasannya. 
	}

public :
	void input() //5. program penginputan batas atas dan batas bawah.
	{
		cout << "Masukkan batas atas	= "; cin >> batas_atas;
		cout << "Masukkan batas bawah	= "; cin >> batas_bawah;
	}
	int luas() //6. interpretasi rumus yang digunakan dengan ketelitian 20-bit.
	{
		n = pow(2.00, 20);
		delta_X = (batas_atas - batas_bawah) / n;
		float Xi;
		for (i = 1; i < n; i++) 
		{
			Xi = batas_bawah + i * delta_X;
			jumlah += fungsi(Xi)*delta_X;
		}
		cout << fixed << setprecision(2) << "Luas	= " << jumlah << endl;
		return 0;
	}
};

int main() //7. driver utama.
{
	variable var;
	var.input();
	var.luas();
	_getch();
}
