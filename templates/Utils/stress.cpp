#include "bits/stdc++.h"

using namespace std;
#define ll long long
#define int long long

random_device rd;
mt19937_64 mt(rd());

ll rnd(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(mt); }

const int LIMIT = 1e6;

void generate() {
  ofstream cout("test.txt");

  int n = rnd(1, 10);
  cout << n << '\n';
  for (int i = 0; i < n; ++i) {
    cout << rnd(1, 1e5) << ' ';
  }

  cout.close();
}

int32_t main() {
  system("g++ -lm -O3 -std=c++17 -DLOCAL -pipe -o main.exe ../main.cpp");
  system("g++ -lm -O3 -std=c++17 -pipe -o brute.exe ../brute.cpp");
//  system("g++ -lm -O3 -std=c++17 -pipe -o gen.exe ../gen.cpp"); // run gen file ?

  for (int tc = 1; tc <= LIMIT; ++tc) {
    cerr << "Case " << tc << '\n';

//    system("gen.exe >test.txt"); /// file
//    generate(); /// function

    system("main.exe <test.txt >wa.txt");
    if (system("brute.exe <test.txt >ac.txt"))break;
    ifstream acs("ac.txt");
    ifstream was("wa.txt");
    string ac, wa;
    getline(was, wa, (char) EOF);
    getline(acs, ac, (char) EOF);
    was.close();
    acs.close();
    if (ac != wa) break;
  }
}
