#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  cout << "##  Program C++ Matriks 2x2  ##" << endl;
  cout << "===============================" << endl;
  cout << endl;

  int matriks[2][2], i, j;

  // proses input elemen matriks
  for(i = 0; i < 2 ; i++){
    for(j = 0; j < 2; j++){
      cout << "Baris " <<i+1<<", kolom "<<j+1<< " = ";
      cin >> matriks[i][j];
    }
    cout << endl;
  }

  cout << "Hasil matriks: " << endl;

  // menampilkan elemen matriks
  for(i = 0; i < 2 ; i++){
    for(j = 0; j < 2; j++){
      cout << setw(3) << matriks[i][j] << " ";
    }
    cout << endl;
  }
 
  return 0;
}
