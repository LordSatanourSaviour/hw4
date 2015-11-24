
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

double* reading( const int, const string);
void writing(double*, const int, const string);
void filter(double*, const int);

int main(){
    const int N=237;
    const string fname_in = "noisy.txt";
    const string fname_out = "less_noisy.txt";
    double* p = reading(N, fname_in);;
    
    filter(p, N);
    filter(p, N);
    filter(p, N);
    writing(p, N, fname_out);
    
    
    
    delete[] p;
    return 0;
    
}


double* reading( const int N, const string fname_in){
   double* p = new double[N];
    ifstream in(fname_in.c_str()); //create input file stream
    
    for (int i=0; i<N; i++) {
        
        in >> p[i];
    }
    in.close(); //close input file stream
    return p;
}



void writing(double* p, const int N, const string fname_out){
    ofstream out(fname_out.c_str());
    for (int i=0; i<N; i++) {
         out << p[i] << endl;
    }
   
    out.close();
}

void filter(double* p, const int N){
    double ps;
    double p_old;
    p[0] = (p[N-1]+p[0]+p[1])/3.0;
    
    for (int i=1; i<N-1; i++) {
        ps = (p[i-1]+p[i]+p[i+1])/3.0;
        p_old = p[i];
        p[i] = ps;
    }
    p[N-1] = (p[N-2]+p[N-1]+p[0])/3.0;
}