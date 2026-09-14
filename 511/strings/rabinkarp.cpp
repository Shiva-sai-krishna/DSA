#include<string>
#include<iostream>
#include<vector>

using namespace std;

bool simpleStringMatch(string& T, string& P, int idx) {
    int i,m;

    m = P.size();
    for (i=0; i<m;i++) { 
        if (T[idx+i] != P[i])
            return false;
    }

    return true;
}


vector<int> rabin(string& T, string& P) {
    long long int HT, HP, PR, MSB;
    int n, m, i, j, d=256; 
    vector<int> result;

    n = T.size();
    m = P.size();
    PR = 1000000000 + 7;
    MSB = 1;
    HT = HP = 0;

    if (m > n || m == 0) return result;

    for (i=0;i<m; i++) {
        MSB = (MSB*d)%PR;
        HP = ((HP*d)+P[i])%PR;
        HT = ((HT*d)+T[i])%PR;
    }

    if (HP == HT && simpleStringMatch(T,P,0)) 
        result.push_back(0);

    for (i=0,j=m; j<n; i++, j++) {
        HT = ((HT * d - (MSB * T[i]) % PR + T[j]) % PR + PR) % PR;
        if (HP == HT && simpleStringMatch(T,P,i+1)) 
            result.push_back(i+1);
    }

    return result;
}

int main() {
    string T, P;

    cout << "Enter the Text" << endl;
    cin >> T;

    cout << "Enter the Pattern" << endl;
    cin >> P;

    auto indexes = rabin(T,P);
    if (indexes.size() == 0) cout << "No Matches Found" << endl;
    else {
        cout << "Matches Found at : ";
        for (int index : indexes) cout << index << " ";
    }

    return 0;
}