// Diego Rodríguez Dávila A01283005
#include <bits/stdc++.h> 
using namespace std; 

struct Punto { 
    int x, y; 
}; 


int orientacion(Punto p, Punto q, Punto r) { 
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 

  if (val == 0) return 0;  
  return (val > 0)? 1: 2; 
} 

// Imprime convex hull de un conjunto de n puntos.
void convexHull(Punto puntos[], int n) { 
    if (n < 3) return; 

    vector<Punto> hull; 

    int l = 0; 
    for (int i = 1; i < n; i++) 
        if (puntos[i].x < puntos[l].x) 
            l = i; 

    int p = l, q; 
    do { 

        hull.push_back(puntos[p]); 

        q = (p+1)%n; 
        for (int i = 0; i < n; i++) { 
           if (orientacion(puntos[p], puntos[i], puntos[q]) == 2) 
               q = i; 
        } 

        p = q; 

    } while (p != l);  

    // Imprime resultado
    for (int i = 0; i < hull.size(); i++) 
        cout << "(" << hull[i].x << ", " << hull[i].y << ")\n"; 
} 

int main() { 
  int n;
  cout << "Ingresa la cantidad de puntos: \n";
  cin >> n;
  
  Punto puntos[n]; 
  
  for (int i = 0; i < n; i++) {
    cout << "Ingrese las coordenadas (x, y) del punto " << i + 1 << ": ";
    //Ejemplo: Ingrese las coordenadas (x, y) del punto 1: 3 3
    cin >> puntos[i].x >> puntos[i].y;
  }
  
  convexHull(puntos, n); 
  return 0; 
} 