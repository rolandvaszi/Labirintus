#include <iostream>
#include <fstream>

using namespace std;

bool bejaras(int **&labirintus, int x, int y, int **&megold,int &N,int &szamlalo);
bool bejaras2(int **&labirintus, int x, int y, int **&megold,int &N,int &szamlalo);

void kiiras(int **&megold, int &N, int &szamlalo) {
    cout<<endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << megold[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Hivasok szama: "<<szamlalo<<endl;
}

bool benneVan(int **&labirintus, int x, int y, int &N) {
    if(x >= 0 && x < N && y >= 0 && y < N && labirintus[x][y] == 1) {
        return true;
    }
    return false;
}

bool megoldas(int **&labirintus, int **&megold, int &N,int &szamlalo) {
    /*int megold[N][N] = { { 0, 0, 0, 0},
                     { 0, 0, 0, 0},
                     { 0, 0, 0, 0},
                     { 0, 0, 0, 0} };*/
    if(bejaras(labirintus, 0, 0, megold,N,szamlalo) == false) {
        cout << "Nincs megoldas!" << endl;
        cout << "Hivasok szama: "<<szamlalo<<endl;
        return false;
    }
    kiiras(megold,N,szamlalo);
    return true;
}

bool megoldas2(int **&labirintus, int **&megold, int &N,int &szamlalo) {
    if(bejaras2(labirintus, 0, 0, megold,N,szamlalo) == false) {
        cout << "Nincs megoldas!" << endl;
        cout << "Hivasok szama: "<<szamlalo<<endl;
        return false;
    }
    kiiras(labirintus,N,szamlalo);
    return true;
}

bool bejaras(int **&labirintus, int x, int y, int **&megold,int &N,int &szamlalo) {
    szamlalo++;
    //cout<<szamlalo<<" ";
    if(x == N - 1 && y == N - 1) {
        megold[x][y] = 1;
        return true;
    }
    if(benneVan(labirintus, x, y, N) == true) {
        megold[x][y] = 1;
        if(x<N-1){
            if(megold[x+1][y]==0 && x<N-1){
                if(megold[x+1][y]==0 && bejaras(labirintus, x+1, y, megold,N,szamlalo) == true) {
                    return true;
                }
            }
        }
        if(y<N-1){
            if(megold[x][y+1]==0){
                if(bejaras(labirintus, x, y+1, megold,N,szamlalo) == true) {
                    return true;
                }
            }
        }
        if(x>0){
            if(megold[x-1][y]==0){
                if(bejaras(labirintus, x-1, y, megold,N,szamlalo) == true) {
                    return true;
                }
            }
        }
        if(y-1){
            if(megold[x][y-1]==0){
                if(bejaras(labirintus, x, y-1, megold,N,szamlalo) == true) {
                    return true;
                }
            }
        }
        megold[x][y] = 0;
        return false;
    }
    return false;
}

bool bejaras2(int **&labirintus, int x, int y, int **&megold,int &N,int &szamlalo) {
    szamlalo++;
    //cout<<szamlalo<<" ";
    if(x == N - 1 && y == N - 1) {
        //megold[x][y] = 1;
        return true;
    }
    if(benneVan(labirintus, x, y, N) == true) {
        //megold[x][y] = 1;
        if(x<N-1){
            if(labirintus[x+1][y]==1){
                if(bejaras(labirintus, x+1, y, megold,N,szamlalo) == true) {
                    return true;
                }
            }
            else
                return false;
        }
        if(y<N-1){
            if(labirintus[x][y+1]==1){
                if(bejaras(labirintus, x, y+1, megold,N,szamlalo) == true) {
                    return true;
                }
            }
        }
        if(x>0){
            if(labirintus[x-1][y]==1){
                if(bejaras(labirintus, x-1, y, megold,N,szamlalo) == true) {
                    return true;
                }
            }
        }
        if(y-1){
            if(labirintus[x][y-1]==1){
                if(bejaras(labirintus, x, y-1, megold,N,szamlalo) == true) {
                    return true;
                }
            }
        }

        //megold[x][y] = 0;
        labirintus[x][y]=0;
        return false;

    }
    labirintus[x][y]=0;
    return false;
}

void beolvas(int **&labirintus,int **&megold,const char * be, int &N){
    int n;
    ifstream f (be);
    f >> n;
    N=n;
    labirintus = new int*[n];
    for(int i=0; i<n; ++i)
    {
        labirintus[i]=new int[n];
    }
    megold = new int*[n];
    for(int i=0; i<n; ++i)
    {
        megold[i]=new int[n];
    }
    for(int i=0; i<n; ++i)
    {
        for(int j=0;j<n;++j)
        {
            f>>labirintus[i][j];
            megold[i][j]=0;
        }
    }
    for(int i=0; i<n; ++i)
    {
        for(int j=0;j<n;++j)
        {
            cout << labirintus[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int **labirintus, **megold;
int N, szamlalo=0;

int main(int argc, char* argv[]) {
    if(argc != 3) {
        cout << "Tul keves argumentum!" << endl;
        return 0;
    }
    beolvas(labirintus, megold, argv[1], N);
    switch(argv[2][0]){
        case '1':  megoldas(labirintus, megold, N, szamlalo);
            break;
        case '2':  megoldas2(labirintus, megold, N, szamlalo);
            break;
        default: cout << "Nincs ilyen opcio!" << endl;
    }
    return 0;
}