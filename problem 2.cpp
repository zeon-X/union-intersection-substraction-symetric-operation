#include <bits/stdc++.h>
#include <string.h>
#include <string>
#define pb   push_back
using namespace std;


vector<int> unique_array(vector <int> &x){
    vector <int> y;

    int len = x.size();
    // x.pb(x[x.size()-1]+1); // making the extra last elem unique

    sort(x.begin(), x.end());

    for(int i=0; i<len; ++i){
        if(x[i]!=x[i+1]){
            y.pb(x[i]);
        }
    }
    return y;
}


void CartesianProduct (vector <int> &x,vector <int> &y,vector <int> &z){
    int n,m,l;
    n=x.size();
    m=y.size();
    l=z.size();

    for(int i=0; i< n; ++i){
        for(int j=0; j< m; ++j){
            for(int k=0; k< l; ++k){
                cout << "(" << x[i] << "," << y[j] << "," << z[k] << ") , ";
            }
        }
    }

    cout << "\n\n";

}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    #endif


    int n,m,k,x;
    cin >> n >> m >> k;

    vector <int> A,B,C;

    for(int i=0;i<n;++i){
        cin >> x; A.pb(x);
    }

    for(int i=0;i<m;++i){
        cin >> x; B.pb(x);
    }

    for(int i=0;i<k;++i){
        cin >> x; C.pb(x);
    }

    //UNIQUE ARRAYS
    A = unique_array(A);
    B = unique_array(B);
    C = unique_array(C);

    n=A.size();
    m=B.size();
    k=C.size();

    cout << "\nArray A: ";
    for(int i=0;i<n;++i)cout << A[i] << " "; cout << "\n";
    cout << "Array B: ";
    for(int i=0;i<m;++i)cout << B[i] << " "; cout << "\n";
    cout << "Array C: ";
    for(int i=0;i<k;++i)cout << C[i] << " "; cout << "\n\n";



    //CARTESIAN PRODUCT PRINT

    CartesianProduct(A,B,C);
    

}






