#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[N] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,result,N,M);
	showData(result,N,1);
}

//Write definition of randData(), showData() and findRowSum()
void randData(double *dPtr,int N,int M){
 for(int i=0;i<(M*N);i++){
    *dPtr=(rand()%101)/100.0;
     dPtr+=1;
 }
}

void findRowSum(const double *dPtr,double *result,int N,int M){
	int j=0;
 for(int i=0;i<(M*N);i++){
    result[j]=result[j]+*dPtr;
    dPtr+=1;
	if((i-(N-1))%7==0)
	j+=1;
  }
}

void showData(double *result,int N,int M){
for(int i=0;i<N;i++){
	for(int j=0;j<M;j++){
      	cout<<setw(9)<<*result;
		result+=1;  
	}
cout<<"\n";
}

}