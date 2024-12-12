#include <vector>
#include <string>
#include <iostream>

using namespace std;

string valid(string input) {
    if (input[0]!='(' || input.back()!=')')
        return "Invalid";
    double x=0, y=0;
    int i=1;
    bool decimalSeen=false;
    i+=(input[i]=='-' || input[i]=='+');
    if (input[i]=='.')
        return "Invalid";
    while (i<input.length() && input[i]!=',') {
        if (input[i]=='.') {
            if (decimalSeen)
                return "Invalid";
            decimalSeen=true;
        } else if (input[i]<'0' || input[i]>'9')
            return "Invalid";
        i++;
    }
    if (i>=input.length() || input[i-1]<'0' || input[i-1]>'9')
        return "Invalid";
    x=stod(input.substr(1, i-1));
    i++;
    int j=i;
    decimalSeen=false;
    i+=(input[i]=='-' || input[i]=='+');
    if (input[i]=='.')
        return "Invalid";
    while (i<input.length() && input[i]!=')') {
        if (input[i]=='.') {
            if (decimalSeen)
                return "Invalid";
            decimalSeen=true;
        } else if (input[i]<'0' || input[i]>'9')
            return "Invalid";
        i++;
    }
    if (i>=input.length() || input[i-1]<'0' || input[i-1]>'9')
        return "Invalid";
    y=stod(input.substr(j, i-j));
    if (x<-90 || x>90 || y<-180 || y>180)
        return "Invalid";
    return "Valid";
}

int main() {
    cout << valid("(-1111,1)") << endl;
}