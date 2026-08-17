    #include<iostream>

    using namespace std;

    int main() { 

        // Take the number as a string
        string s;
        cout << "Enter the number (n) : ";
        cin >> s;

        // convert the number to a digit array
        int l = s.size();
        int n[l];
        for(int i=0; i<l; i++)
            n[i] = s[i]-'0';


        // Take the modulo 
        int m; 
        cout << "Enter the value of Modulo (m) : ";
        cin >> m;
        
        // Find the periodic sequence and only find its length
        int p=2;
        int a = 0;
        int b = 1;
        int c;

        while(true) {
            c = (a+b)%m;
            a = b;
            b = c;
            if (a==0 && b==1)
                break;
            p++;
        }    

        p = p-1;
        cout << "Value of P : " << p << endl;

        // Perform N % P. Remember to start from the MSB
        int r = 0;
        for(int i=0;i<l;i++) 
            r = ((r*10)+n[i])%p;
        cout << "Value of R : " << r << endl;

        // Find F(R) using bottom up approach
        a = 0;
        b = 1;
        c = r;
        int ans = c;
        for (int i=2;i<=r; i++) {
            c = (a+b)%m;
            a = b; 
            b = c;
        }
        ans = c;

        cout << "F(N) : " << ans << endl;
    }
