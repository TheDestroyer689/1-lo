#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>


using namespace std;

std::ostream& bold_on(std::ostream& os)
{
    return os << "\e[1m";
}

std::ostream& bold_off(std::ostream& os)
{
    return os << "\e[0m";
}


void load_city(int tab[40][40]){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i = 0; i < 40; i ++){
        for(int j = 0; j < 40; j++){
            switch(tab[i][j]){
                case 0:

                    SetConsoleTextAttribute(hConsole,  BACKGROUND_GREEN);
                    cout << bold_on << "   ";
                    break;
                case 1:

                    SetConsoleTextAttribute(hConsole,  BACKGROUND_BLUE);
                    cout << bold_on << "   ";
                    break;
                case 2:

                    SetConsoleTextAttribute(hConsole,  38);
                    for(int i = 0; i < 3; i++){
                        int random = rand() % 3;
                        if(random == 0){
                            cout << "T";
                        } else if(random == 1) {
                            cout << "t";
                        } else {
                            cout << "i";
                        }
                    }
                    
                    
                    
                    
                    break;
                case 3:

                    SetConsoleTextAttribute(hConsole,  BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY|FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
                    cout << bold_on << "   ";
                    break;
                case 4:

                    SetConsoleTextAttribute(hConsole,  BACKGROUND_BLUE | BACKGROUND_INTENSITY|FOREGROUND_BLUE |FOREGROUND_INTENSITY);
                    cout << bold_on << "   ";
                    break;
                case 5:

                    SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                    cout << bold_on << "   ";
                    break;
                case 6:

                    SetConsoleTextAttribute(hConsole, 70);
                    cout << bold_on << "[";
                    switch (rand() % 4)
                    {
                    case 0:
                        cout << bold_on << "H";
                        break;
                    case 1:
                        cout << bold_on << "U";
                        break;
                    case 2:
                        cout << bold_on << "O";
                        break;
                    
                    default:
                        cout << bold_on << "I";
                        break;
                    }
                    cout << bold_on << "]";
                    break;
                case 7:

                    SetConsoleTextAttribute(hConsole, 15);
                    cout << bold_on << " = ";
                    break;
                default:
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << bold_off <<"!!!";
                break;
                    
            }
        }
        SetConsoleTextAttribute(hConsole, 7);
        cout << endl;
    }
}

int main(){

    srand(time(NULL));

    int city[40][40];
    for(int i = 0; i < 40; i ++){
        for(int j = 0; j < 40; j++){
            city[i][j] = 0;
        }
    }
    for(int i = 0; i < 6; i++){
        int v1 = rand() % 40;
        int v2 = rand() % 40;
        
        for(int ii = -2; ii < 3; ii++){
            for(int jj = -2; jj < 3; jj++){
                city[v1 + ii][v2 + jj] = 1;
            }

        }
        for(int ii = -3; ii < 4; ii++){
            for(int jj = -3; jj < 4; jj++){
                if(city[v1 + ii][v2 + jj] == 0){
                    if(rand() % 10 == 0){
                        city[v1 + ii][v2 + jj] = 0;
                    } else {
                        city[v1 + ii][v2 + jj] = 1;
                    }

                    

                }else{
                    city[v1 + ii][v2 + jj] = 1;
                }
                
            }

        }
        for(int ii = -4; ii < 5; ii++){
            for(int jj = -4; jj < 5; jj++){
                if(city[v1 + ii][v2 + jj] == 0){
                    int random = rand() % 10;
                    if(random == 0 || random == 1 || random == 2 || random == 3){
                        city[v1 + ii][v2 + jj] = 0;
                    } else {
                        city[v1 + ii][v2 + jj] = 1;
                    }

                    

                }else{
                    city[v1 + ii][v2 + jj] = 1;
                }
                
            }

        }
        for(int ii = -5; ii < 6; ii++){
            for(int jj = -5; jj < 6; jj++){
                if(city[v1 + ii][v2 + jj] == 0){
                    int random = rand() % 10;
                    if(random == 0 || random == 1 || random == 2 || random == 3 || random == 4 || random == 5 || random == 6){
                        city[v1 + ii][v2 + jj] = 0;
                    } else {
                        city[v1 + ii][v2 + jj] = 1;
                    }

                    

                }else{
                    city[v1 + ii][v2 + jj] = 1;
                }
                
            }

        }

        
    }
    for(int i = 0; i < 40; i++){
        for(int j = 0; j<40 ; j++){
            if(city[i][j] == 0){
                if( city[i+1][j] == 1 ||city[i][j+1] == 1 ||city[i-1][j] == 1 ||city[i][j-1] == 1){
                    city[i][j] = 3;
                }
            }
        }
    }
    for(int i = 0; i < 40; i++){
        for(int j = 0; j<40 ; j++){
            if(city[i][j] == 1){
                if( city[i+1][j] == 3 ||city[i][j+1] == 3 ||city[i-1][j] == 3 ||city[i][j-1] == 3){
                    city[i][j] = 4;
                }
            }
        }
    }
    
    for(int jjj = 0; jjj<20 ; jjj++){
        int i, j;
        i = rand() % 40;
        j = rand() % 40;
        if(city[i][j] == 0){
            if( city[i+1][j] == 0 &&city[i][j+1] == 0 &&city[i-1][j] == 0 &&city[i][j-1] == 0){
                city[i][j] = 2;
                for(int ii = -1; ii <2; ii++){
                    for(int jj = -1; jj <2; jj++){
                        int random = rand() % 4;
                        if(random != 0){
                            if(city[i + ii][j + jj] == 0){
                                city[i + ii][j + jj] = 2;
                            }
                
                        }
                        
                    }
                }
                for(int ii = -2; ii <3; ii++){
                    for(int jj = -2; jj <3; jj++){
                        int random = rand() % 4;
                        if(random != 0 && random !=1 && random != 2){
                            if(city[i + ii][j + jj] == 0){
                                city[i + ii][j + jj] = 2;
                            }
                
                        }
                        
                    }
                }
                
        
                
            }
        }
    }
    for(int i = 0; i<50; i++){
        int v1, v2;
        v1 = rand() % 40;
        v2 = rand() % 40;
        if(city[v1][v2] == 0){
            city[v1][v2]=5;
        }
    }
    int river = 0;
    int riv = rand() % 40;
    city[river][riv] = 1;
    while (river != 39)
    {
        switch (rand() % 4)
        {
            
        case 0:
            riv = riv+1;
            city[river][riv] = 4;
            break;
        case 1:
            riv = riv-1;
            city[river][riv] = 4;
            break;
        default:
            river = river+1;
            city[river][riv] = 4;
            break;
            
        }
    }
    int road_i, road_j;
    road_i = rand() % 30 + 5;
    road_j = rand() % 30 + 5;
    while(city[road_i][road_j] != 0){

    
        road_i = rand() % 30 + 5;
        road_j = rand() % 30 + 5;
    }
    city[road_i][road_j] = 7;
    int los;
    los = rand() % 15 +1;
    for(int i = 0; i < los; i++){
        if(city[road_i + i][road_j] != 4){
            city[road_i + i][road_j] = 7;
        }
    }
    los = rand() % 15 + 1;
    for(int i = 0; i < los; i++){
        if(city[road_i][road_j-i] != 4){
            city[road_i][road_j-i] = 7;
        }
    }
    los = rand() % 15 + 1;
    for(int i = 0; i < los; i++){
        if(city[road_i][road_j+i] != 4){
            city[road_i][road_j+i] = 7;
        }
    }
    los = rand() % 15 + 1;
    for(int i = 0; i < los; i++){
        if(city[road_i - i][road_j] != 4){
            city[road_i - i][road_j] = 7;
        }
    }
    road_i = rand() % 30 + 5;
    road_j = rand() % 30 + 5;
    while(city[road_i][road_j] != 0){

    
        road_i = rand() % 30 + 5;
        road_j = rand() % 30 + 5;
    }
    city[road_i][road_j] = 7;
    los = rand() % 15 +1;
    for(int i = 0; i < los; i++){
        if(city[road_i + i][road_j] != 4){
            city[road_i + i][road_j] = 7;
        }
    }
    los = rand() % 15 + 1;
    for(int i = 0; i < los; i++){
        if(city[road_i][road_j-i] != 4){
            city[road_i][road_j-i] = 7;
        }
    }
    los = rand() % 15 + 1;
    for(int i = 0; i < los; i++){
        if(city[road_i][road_j+i] != 4){
            city[road_i][road_j+i] = 7;
        }
    }
    los = rand() % 15 + 1;
    for(int i = 0; i < los; i++){
        if(city[road_i - i][road_j] != 4){
            city[road_i - i][road_j] = 7;
        }
    }
    for(int i = 0; i < 40; i++){
        for(int j = 0; j<40 ; j++){
            if(city[i][j] == 0){
                if( city[i+1][j] == 7 ||city[i][j+1] == 7 ||city[i-1][j] == 7 ||city[i][j-1] == 7){
                    if(rand() % 10 != 0)
                        city[i][j] = 6;
                }
            }
        }
    }

    
    
    load_city(city);
    

    return 0;
}
