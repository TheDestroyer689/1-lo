

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int main()
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( hOut, BACKGROUND_RED );
    int a,b,v1, v2;
    int tab[10][10];
    int traf[10][10];

    srand(time(NULL));
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tab[i][j]=0;
        }    
    }                    //zerowanie
    for (int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            traf[i][j]=0;
        }    
    }
    for (int i = 0; i < 2; i++)
    {
        v1=rand() % 10;
        v2=rand() % 8;
        while(tab[v1][v2]==1 || tab[v1][v2+1]==1 || tab[v1][v2+2]==1)
        {
            v1=rand() % 10;
            v2=rand() % 8;
        }
        tab[v1][v2] = 1;
        tab[v1][v2+1] = 1;
        tab[v1][v2+2] = 1;
    }        
    
    for (int i = 0; i < 1; i++)
    {
        v1=rand() % 10;
        v2=rand() % 7;
        while(tab[v1][v2]==1 || tab[v1][v2+1]==1 || tab[v1][v2+2]==1 || tab[v1][v2+3]==1)
        {
            v1=rand() % 10;
            v2=rand() % 7;
        }
        tab[v1][v2] = 1;
        tab[v1][v2+1] = 1;
        tab[v1][v2+2] = 1;
        tab[v1][v2+3] = 1;
    }      
    for (int i = 0; i < 2; i++)
    {
        v1=rand() % 8;
        v2=rand() % 10;
        while(tab[v1][v2]==1 || tab[v1+1][v2]==1 || tab[v1+2][v2]==1)
        {
            v1=rand() % 8;
            v2=rand() % 10;
        }
        tab[v1][v2] = 1;
        tab[v1+1][v2] = 1;
        tab[v1+2][v2] = 1;
    }      
    for (int i = 0; i < 1; i++)
    {
        
       v1=rand() % 10;
       v2=rand() % 10;
       while(tab[v1][v2] == 1)
       {
           v1=rand() % 10;
           v2=rand() % 10;
       }
       tab[v1][v2] = 1;    
        
    }                    //losowanie statkow
    for(int i =0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            cout << tab[i][j] << " ";
        }    
        cout << endl;
    }        
    int trafienia = 0;
    for (int i = 0; i < 20; i++)
    {
        cin >> a >> b;
        a = a - 1;
        b = b - 1;
        if(tab[a][b] == 1)
        {
            cout << "Trafiony! \n";
            trafienia = trafienia + 1;
            tab[a][b] = 0;
            traf[a][b] = 2;
        } else {
            cout << "Pudlo\n";
            traf[a][b] = 1;
        }    
        if(trafienia == 10)
        {
            cout << "Wygrales \n";
            return 0;
        }
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j <10; j++)
            {
                cout << traf[i][j]<< " ";
            }
            cout << endl;    
        }        
    }
    return 0;
}