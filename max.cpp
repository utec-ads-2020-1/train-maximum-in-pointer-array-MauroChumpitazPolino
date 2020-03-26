
#include <iostream>
using namespace std;
 
int max(int *iptr[], int n);

int main() {
    int n, i;
    int array[100] = {0};
    int *iptr[100];

    // Step 1: Get the number of array values by the user.
    cout << "Ingresar el tamaño del vector:" << endl;
    cin >> n;

    // Step 2: Limit the array length.
    if (n > 100)
    {
        n = 100;
    }
    else if(n < 1)
    {
        n = 1;
    }

    // Step 3: Get the array values by the user.
    for (i = 0; i < n; i++) {
        cout << "Ingresar variable #" << (i+1) << endl;
        cin >> array[(i + 3) % n];
        iptr[i] = &(array[(i + 3) % n]);
    }

    // Step 4: Show the highest number in the array.
    cout << "El número mayor es: \n" << max(iptr, n) << "\n" << endl;

    cin.ignore();
    cout << "Presione ENTER para salir ...";
    cin.get();
}       

int max(int *iptr[], int n){
    int v_max = **iptr;           
    
    for (int i = 1; i < n; i++)
    {
        iptr++;
        if (v_max < **iptr)
        {
            v_max = **iptr;
        }
    }

    return v_max;
}