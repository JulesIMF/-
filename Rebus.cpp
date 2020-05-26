//JulesIMF template

#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <cstring>
#include <Windows.h>

#define vsegda_prav72 ios_base::sync_with_stdio(0); cin.tie(0);
#define forn(__i,__n) for(int __i = 0; __i < __n; __i++)
#define mp make_pair
#define pb push_back
#define outn(___s) cout << ___s << "\n"
#define outs(___s) cout << ___s << " "
#define acnt cout << "\t"

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

inline long long powll(int n) {
	ll ret = 1;
	forn(i, 10) {
		ret *= (i+1);
	}
	return ret;
}

inline void nextp(map<char, int>& m, vector<int>& v, ll& j, ll& maxn) {	
	//bool changed = false;
	
jj:
	if (j >= maxn) return;
	auto it = m.begin();
	next_permutation(v.begin(), v.end());
	;
	
	for (int i = 0; i < m.size(); i++) {
		//if (v[i] == (it++)->second) continue;
		//changed = true;
		m[(it++)->first] = v[i];
	}
	/*if (!changed) {
		j++; goto jj;
	}*/
}

inline ll stoll(map<char, int>& m, string& s) {
	ll ans = 0;
	if (m[s[0]] == 0) return -1;
	for (auto a : s) {
		ans *= 10;
		ans += m[a];
	}
	return ans;
}

set<vll> simple_solve(vector<string> add, string sum) {
	vector<int> perm = { 0,1,2,3,4,5,6,7,8,9 };
	set<vll> ans;
	int addsize = add.size();
	ll* ch = new ll[add.size()];
	ll summ, acc;
	map<char, int> m;
	for (auto s : add) {
		for (auto c : s) {
			m[c] = 0;
		}
	}
	for (auto c : sum) {
		m[c] = 0;
	}
	if (m.size() > 10) return set<vll>();
	auto n = powll(m.size());
	for (ll j = 0; j < n; j++) {
		for (int i = 0; i < addsize; i++) {
			ch[i] = stoll(m, add[i]);
			if (ch[i] == -1) goto k;
		}
		summ = stoll(m, sum);
		if (summ == -1) goto k;
		acc = 0;
		forn(i, addsize) {
			acc += ch[i];
		}
		if (acc == summ) {
			vll vt;
			forn(i, addsize) {
				vt.pb(ch[i]);
			}
			vt.pb(summ);
			ans.insert(vt);
		}

	k:
		nextp(m,perm,j,n);
	}
	return ans;
}

inline string symbol_c(int i, int size) {
	if (i + 1 == size) return "";
	if (i + 2 == size) return " = ";
	return " + ";
}

int main() { 
	vsegda_prav72;
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitle("Ребус");
	
	cout << "Решатель ребусов для Доса\nРешение конкретного ребуса с заданными слагаемыми и суммой\n\n";
	
	string request;
	bool b=false, wr = true;
	while (wr) {
		request = "";
		
		if (b&&wr) {
			cout << "Этот режим ещё не готов\n";
		}
		if (!b && wr) {
			int nOfAdd;
			lessthantwo:
			cout << "Введите количество слагаемых: ";
			cin >> nOfAdd;
			if (nOfAdd < 2) {
				cout << "Cлагаемых должно быть не меньше двух!\n\n";
				goto lessthantwo;
			}
			vector<string> adds;
			forn(i, nOfAdd) {
				cout << "Введите " << i + 1 << " слагаемое: ";
				cin >> request;
				adds.pb(request);
			}
			cout << "Введите сумму: ";
			cin >> request;
			cout << "\nПоиск решений для ребуса:\n\n\t";
			forn(i, adds.size()) {
				cout << adds[i] << symbol_c(i, adds.size() + 1);
			}
			cout << request << endl << endl;
			auto v = simple_solve(adds, request);

			if (v.size() == 0) {
				cout << "\nНет подходящих решений\n\n";
				continue;
			}
			cout << "\nПодходят следующие решения:\n";
			for (auto _v : v) {
				acnt;
				forn(i, _v.size()) {
					cout << _v[i] << symbol_c(i, _v.size());
				}
				cout << endl;
			}
			cout << "\n";
		}
	}
}
