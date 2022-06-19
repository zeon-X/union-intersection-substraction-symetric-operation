#include <bits/stdc++.h>
#define pb push_back
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



vector<int> union_Function(vector<int>&x, vector<int>&y){
    vector <int> u;

    for(int i=0; i<x.size();++i)u.pb(x[i]);
    for(int i=0; i<y.size();++i)u.pb(y[i]);

    return u;
}


vector<int> intersection_Function(vector<int>&x, vector<int>&y){
    vector <int> u;

    for(int i=0; i<x.size();++i)
        for(int j=0; j<y.size();++j){
            if(x[i]==y[j]) u.pb(x[i]);
        }

    return u;
}

vector<int> AsubB_Function(vector<int>&x, vector<int>&y){
    vector <int> u;

    vector <int> intersect = intersection_Function(x,y);

    for(int i=0; i<x.size();++i){

        bool flag = false;

        for(int j=0; j<intersect.size();++j){
            if(x[i]==intersect[j]) {flag=true; break;}
        }

        if(!flag) u.pb(x[i]);
    }

    return u;
}


vector<int> symetric_Function(vector<int>&x, vector<int>&y){
    vector <int> u;

    vector <int> unionSet = union_Function(x,y);
    vector <int> intersectSet = intersection_Function(x,y);

    u = AsubB_Function(unionSet,intersectSet);

    return u;
}



void printing_Function(vector<int>&x,string arrayName){
    int len = x.size();

    cout << arrayName << ":\n";

    for(int i=0;i<len;++i) cout << x[i] << " "; 
    cout << "\n\n";
}



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    #endif

    int n,m,x;
    cin >> n >> m;

    vector <int> A,B;

    for(int i=0;i<n;++i){
        cin >> x; A.pb(x);
    }

    for(int i=0;i<m;++i){
        cin >> x; B.pb(x);
    }

    //UNIQUE ARRAYS
    A = unique_array(A);
    B = unique_array(B);

    n=A.size();
    m=B.size();

    cout << "\nArray A: ";
    for(int i=0;i<n;++i)cout << A[i] << " "; cout << "\n";
    cout << "Array B: ";
    for(int i=0;i<m;++i)cout << B[i] << " "; cout << "\n\n";



    //RESULT ARRAY----------------------------
    vector <int> res;
    
    //union
    res = union_Function(A,B);
    printing_Function(res,"union");

    //intersection
    res = intersection_Function(A,B);
    printing_Function(res,"intersection");

    //subs
    res = AsubB_Function(A,B);
    printing_Function(res,"A sub B");

    //symetric
    res = symetric_Function(A,B);
    printing_Function(res,"symetric");




}






