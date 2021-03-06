//
//  main.cpp
//  HPC Question 3
//
//  Created by Ernest on 23/3/2016.
//  Copyright © 2016 Kan Tsz Hang. All rights reserved.
//

#include <iostream>
#include <vector>
#include "TriMatrix.h"

using namespace std;

int main(){
    double L, T, alpha, dt;
    int Nx;
    
    
    // get user input
    {using namespace std;
        cout << "L: ";
        cin >> L;
        
        cout << "T: ";
        cin >> T;
        
        cout << "alpha: ";
        cin >> alpha;
        
        cout << "Nx: ";
        cin >> Nx;
        
        cout << "dt: ";
        cin >> dt;
    }
    
    double dx = L/Nx;
    double nu = alpha*dt/dx/dx;
    double gamma0 = 0;
    double gamma1 = 0;
    
    
    //Defining all BASIC vectors used in the programme
    
    vector<double> x((Nx+1));
    vector<double> u0((Nx+1));
    vector<double> u1(Nx+1);
    vector<double> u2(Nx+1);
   
    
    //Defining x-vector
    for (int i=0;i<Nx+1;i++) {
        x[i]=dx*i; //equallly spaced elements in x-vector
    }
    
    //Defining a vector, which uses the initial condition u0, to hold the solution
    for (int i=0; i<Nx+1; i++) {
        u0[i]=x[i]*(1-x[i]);
    }
    
    //Transfer entries from u0 vector to the u1 vector created earlier

    
    for (int i=0; i<Nx+1; i++) {
        
        (u1)[i] = u0[i];
    }
    
    u1[0]=gamma0;
    u1[Nx]=gamma1;
    
    //create tridiagonal matrix using TriMatrix class constructor
    
    TriMatrix myTri(Nx, nu);
    myTri.displayM();
    
  
    
    for (double i=0; i<(T-dt); i=i+dt) {

        u2=myTri/u1;
        u1=u2;
     
    }
    
    
    
    
    return 0;
    
}
