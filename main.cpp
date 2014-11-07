#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

void division()
{
    cout<<"--------------------------------------------------" <<endl;
}

void PrintBoard(char arreglo[][6])
{
    for(int x = 0; x<6; x++)
    {
        for(int y = 0; y<6; y++)
        {
            char tmp = arreglo[x][y];
            if(y==5)
                cout<<tmp<<endl;
            else
                cout << tmp;
        }
    }
};

int randomizer()
{
    return 1+rand()%(8-1);
}

bool validar(int x, int y)
{
    if(x>=1 && x<=5 && y>=1 && y<=5)
        return true;
    cout<<"Datos fuera de rango, por favor ingrese posiciones dentro del rango (1-5)" <<endl;
    return false;
}

bool Logic(int ganarX, int ganarY, int x, int y, char arreglo[][6])
{
    if(x==ganarX && y==ganarY)
    {
        arreglo[x][y]='X';
        PrintBoard(arreglo);
        cout<<"Has acertado el disparo y ganaste!" <<endl;
        return true;
    }else
    {
        arreglo[x][y]='O';
        PrintBoard(arreglo);
        cout<<"Has fallado el disparo!" <<endl;
        return false;
    }
}

void Juego()
{
    srand(time(NULL));

    char arreglo[6][6] = {{' ','1','2','3','4','5'},{'1','_','_','_','_','_'},{'2','_','_','_','_','_'},{'3','_','_','_','_','_'},{'4','_','_','_','_','_'},{'5','_','_','_','_','_'}};
    int posX=-1;
    int posY=-1;

    int ganarX = randomizer();
    int ganarY = randomizer();

    PrintBoard(arreglo);

    for(int x = 0; x<10; x++)
    {
        division();
        do{
        cout<<"Ingrese la posicion x" <<endl;
        cin>>posX;
        cout<<"Ingrese la posicion y" <<endl;
        cin>>posY;
        }while(!validar(posX,posY));
        division();
        if(Logic(ganarX,ganarY,posX,posY,arreglo))
            x=10;
        else if(x==8)
            cout<<"Ultimo disparo!" <<endl;
        else if(x==9)
            cout<<"Has perdido!" <<endl;
    }
}

void menu()
{
    int num = 0;

   do{
        division();
   cout<< "1. Jugar!" <<endl;
   cout<< "2. Salir :(" <<endl;
    cout<<"Ingrese una opcion" <<endl;
        cin>>num;
        switch(num)
        {
            case 1:division();
                 Juego();
                    break;
            case 2:division();
                cout<<"Muchas gracias por jugar, vuelve pronto!" <<endl;
                    break;
            default: cout<<"Opcion invalida, porfavor escoja una opcion valida (1-2)" <<endl;
        }
    }while(num!=2);
}

int main()
{
    menu();

    return 0;
}
