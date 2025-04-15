#include <bits/stdc++.h>
using namespace std;

class Page
{
    string userName, Email, password;
    string userSearch, passSearch, emailSearch;
    fstream file;

public:
    void login();
    void signup();
    void forget();
};
