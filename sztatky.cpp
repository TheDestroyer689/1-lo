

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int main()
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( hOut, FOREGROUND_BLUE );
    int a, b2, v1, v2;
    char b;
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
        switch(b){
            case 'A':
                b = 0;
                break;
            case 'B':
                b = 1;
                break;
            case 'C':
                b = 2;
                break;
            case 'D':
                b = 3;
                break;
            case 'E':
                b = 4;
                break;
            case 'F':
                b = 5;
                break;
            case 'G':
                b = 6;
                break;
            case 'H':
                b = 7;
                break;
            case 'I':
                b = 8;
                break;
            case 'J':
                b = 9;
                break;
            default:
                b = 0;
                break;
                
        }
        if(tab[a][b] == 1)
        {
            SetConsoleTextAttribute( hOut, FOREGROUND_RED );
            cout << "Trafiony! \n";
            trafienia = trafienia + 1;
            tab[a][b] = 0;
            traf[a][b] = 2;
        } else {
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );
            cout << "Pudlo\n";
            traf[a][b] = 1;
        }    
        if(trafienia == 10)
        {
            SetConsoleTextAttribute( hOut, FOREGROUND_RED );
            cout << "Wygrales!!!!!! \n";
            return 0;
        }
        SetConsoleTextAttribute( hOut, FOREGROUND_BLUE );
        cout << "0|A B C D E F G H I J" << endl;
        for(int i = 0; i < 10; i++)
        {
            cout << i+1 << "|";
            for(int j = 0; j <10; j++)
            {
                switch(traf[i][j]){
                    case 0:
                        SetConsoleTextAttribute( hOut, FOREGROUND_BLUE );
                        cout << "~" << " ";
                        break;
                    case 1:
                        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );
                        cout << "+"<< " ";
                        break;
                    default:
                        SetConsoleTextAttribute( hOut, FOREGROUND_RED );
                        cout << "0"<< " ";
                        break;
                    
                }
                
            }
            cout << endl;    
        }        
    }
    return 0;
}