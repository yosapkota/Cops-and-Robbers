#include <iostream>
#include "point.h"

using namespace std;

void findHull(Point[], int k, Point hull[], int&);
void bubbleSort(Point[] , int);
bool isInsideHull(Point, Point[] , int&);
bool turnsRight(Point, Point, Point);


int main() {

int c,r,o;
int nCopHull = 0;
int nRobberHull = 0;
Point copHull[100], robberHull[100];
cin >> c >> r >> o;

if ((c < 3 or c > 100) or (r < 3 or r > 100) or (o < 3 or o > 100)) {
  cout << "Enter the numbers in the range 3-100" << endl;
  return 1;
}


Point cop[c], robber[r] , people[o];

for (int i=0; i < c; i++) {
  cin >> cop[i];
}

for (int i=0; i < r; i++) {
  cin >> robber[i];
}

for (int i=0; i < o; i++) {
  cin >> people[i];
}

//cout << "Before : " << endl;
//cout << nCopHull << endl;

//changing order here
//findHull(cop,c, copHull, nCopHull);
findHull(robber,r, robberHull, nRobberHull);
findHull(cop,c, copHull, nCopHull);

//cout << "After : " << endl;
//cout << nCopHull << endl;


//for (int i = 0; i < c; i++) {
// cout << cop[i] << endl;
//}

//for (int i = 0; i < nCopHull; i++) {
//  cout << copHull[i] << endl;
//}

//for (int i = 0; i < nRobberHull; i++) {
// cout << robberHull[i] << endl;
//} 

int safe = 0;
int robbed = 0;
int inDanger = 0;

for (int i=0; i < o; i++) {
 bool insideCopHull = isInsideHull(people[i],copHull,nCopHull);
 if (insideCopHull == true) {
  safe++;
 }
 //else {
 //  inDanger++;
 //}
}

for (int i=0; i < o; i++) {
 bool insideRobberHull = isInsideHull(people[i],robberHull,nRobberHull);
 if (insideRobberHull == true and !isInsideHull(people[i],copHull,nCopHull)) {
   //cout << people[i] << endl;
   robbed++;
 }
}


//cout << "Break " << endl;

for (int i=0; i < o; i++) {
 if(!isInsideHull(people[i],robberHull,nRobberHull) and    ! isInsideHull(people[i],copHull,nCopHull)) {
    //cout << people[i] << endl;
    inDanger++;
 }
}

cout << "Safe : " << safe << endl;
cout << "Robbed : " << robbed << endl;
cout << "In Danger : " << inDanger << endl;

return 0;

}


void bubbleSort(Point p[], int n) {
 Point tmp1, tmp2;
 for(int i = 0; i < n; i++) {
   for( int j = 0; j < n-1; j++) {
  
    if( p[j].getX() == p[j+1].getX() ) {  
        if(p[j].getY() > p[j+1].getY()) {
          tmp1 = p[j+1];
          p[j+1] = p[j];
          p[j] = tmp1;    
        }
     }
   
    if( p[j].getX() > p[j+1].getX()) {
      tmp2 = p[j+1];
      p[j+1] = p[j];
      p[j] = tmp2;
    } 
   }
  }
}


 void findHull(Point p[], int k, Point hull[], int &nHull){
 bubbleSort(p,k);
 Point lower[100];
 lower[0] = p[0];
 int t = 0;
 for(int i=1; i < k; i++) {
   //((lower[t] - lower[t-1]) * (p[i] - lower[t])) <= 0/1)
    while (t > 0 and turnsRight(lower[t-1],lower[t],p[i])) {        
         t = t-1;
      }	
    t = t+1;
    lower[t] = p[i];
    }
   
  //cout << t << endl;
  
   
 Point upper[100];

 upper[0] = p[k-1];
 int u = 0;
 for(int i= k-2; i >= 0; i--) {
   //((upper[u] - upper[u-1]) * (p[i] - upper[u]) <= 0/1
    while (u > 0 and turnsRight(upper[u-1],upper[u], p[i])) {
      u = u-1;
      }
    u= u+1;
    upper[u] = p[i];
    }
  
  //cout << u << endl;  
  
  int i =0;
  
  for(int j =0; j < t; j++,i++) {
     hull[i] = lower[j];
  }
  
  for(int j =0; j < u; j++,i++) {
     hull[i] = upper[j];
   }
   
   nHull = u + t;
 }

bool isInsideHull(Point p, Point H[], int &nHull) {

 //Point p;
 int k = nHull;
 for(int i =0; i < k; i++){
  int j =(i+1) % k;
  Fraction turnsRightOnly = (H[i] - p) * (H[j] - H[i]);
  if (turnsRightOnly < 0 / 1) {
    return false;
  }
  //if (turnsRight(p,H[i],H[j])) {
  // return false;
  //}
  }
 
 return true;
}

bool turnsRight(Point p1, Point p2, Point p3) {

 Fraction val;
 val = (p2 - p1) * (p3 - p2);
 if (val <= 0/1) {
  return true;
 }
 else {
  return false;
 }
}



