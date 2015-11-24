

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void randnum(const int , double* const);
void maxi(const int, double* const, double&);
void mini(const int, double* const, double&);

int main() {
    int N=10;
    double p[N];
    double minp;
    double maxp;
    
    randnum(N, p);
    
    for (int j=0; j<N; j++) {
        cout << "p[" << j << "]=" << p[j]<< endl;
    }
    
    mini(N, p, minp);
    maxi(N, p, maxp);
    

    
    cout << "min=" << minp << "\t"<< "max=" << maxp << endl;
    
    return 0;
}




void randnum(const int N, double* const p){
    srand(time(NULL));
    for (int i=0; i<N; i++) {
        p[i]=double(rand())/1e8;
    }
    
    
    
}

void maxi(const int N, double* const p, double& maxp){
    maxp = p[0];
    for (int i=1; i<N; i++) {
        if (p[i]>maxp) {
            maxp=p[i];
            
        }
        
    }
}

void mini(const int N, double* const p, double& minp){
    minp=p[0];
    for (int i=1; i<N; i++) {
        if (p[i]<minp) {
            minp=p[i];

        }
        
    }
    
    
}