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

int max_bit_size (int n){
    vector <int>bin;
    while (n > 0) {
        bin.pb(n % 2);
        n = n / 2;
    }
    return bin.size();
}


vector<int> decToBin(int n,int size){

    //store binary number
    vector <int>bin;
 
    while (n > 0) {
        bin.pb(n % 2);
        n = n / 2;
    }

    int diff = size - bin.size();

    for(int i=0; i <diff;  ++i) bin.pb(0);


    reverse(bin.begin(), bin.end());
 
    return bin;
}


void SubsetPrint(vector <int> &x,int size){

    int num_of_subset = pow(2,size); 
    vector <int> bin;

    int maxbitsize = max_bit_size(num_of_subset-1);


    cout << "The subset is : ";

    for(int i=1; i<num_of_subset; ++i){

        bin = decToBin(i,maxbitsize);

        cout << "{ ";
        for(int j=0; j<bin.size();++j){
            if(bin[j]==1)cout << x[j] << " ";
        }
        cout << "},";


    
    }

    cout << "{ Q }\n\n";
}



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    #endif

    int n,x;
    cin >> n;

    vector <int> A;

    for(int i=0;i<n;++i){
        cin >> x; A.pb(x);
    }

    //UNIQUE ARRAYS
    A = unique_array(A);

    n=A.size();

    cout << "\nArray A: ";
    for(int i=0;i<n;++i)cout << A[i] << " "; cout << "\n\n";


    SubsetPrint(A,n);

}






