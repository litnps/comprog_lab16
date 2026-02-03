#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));

	double a[3][2] = {1,2,3,4,5,6};
	double b[2];
	findColSum(a[0],b,3,2);
	showData(b,1,2);
	
	// const int N = 6, M = 8;
	// double data[N][M] = {};
	// double sum1[N] = {};
	// double sum2[M] = {};
	// double *dPtr = data[0];
	// randData(dPtr,N,M);
	// showData(dPtr,N,M);
	
	// cout << "---------------------------------------------\n";
	
	// findRowSum(dPtr,sum1,N,M);
	// showData(sum1,N,1);
	
	// cout << "---------------------------------------------\n";
	
	// findColSum(dPtr,sum2,N,M); 
	// showData(sum2,1,M);
}


void showData(double *data,int N, int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout <<  *(data + i);
        if((i+1)%M == 0) cout << endl;
        else cout << " ";
    }
}

void randData(double *data, int N, int M){
    for(int i = 0; i < N*M; i++){
        *(data+i) = (rand()%100+1)*0.01;
    }
}

// void findRowSum(const double *data ,double *sum,int n,int m){
//     int j = 0;
//     for(int i = 0 ; i < n * m ; ++i){
//         *(sum + j) += *(data + i);
// 		if((i+1)%m == 0) ++j;
//     }
// }

void findRowSum(const double *data ,double *sum,int n,int m){
    for(int i = 0 ; i < n ; ++i){
		double s = 0;
		for(int j = 0 ; j < m ; ++j){
			s += data[i*m + j];
		}
		sum[i] = s;
	}
}

// void findColSum(const double *data,double *sum,int n,int m){
// 	for(int i = 0 ; i < n * m ; ++i) 
// 		*(sum + i%m) += *(data + i);
// }

void findColSum(const double *data,double *sum,int n,int m){
	for(int j = 0 ; j < m ; ++j){
		double s = 0;
		for(int i = 0 ; i < n ; ++i){
			s += data[i*m + j];
		}
		sum[j] = s;
	}
}
