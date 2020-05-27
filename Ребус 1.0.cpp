//JulesIMF template

#include <cmath>
#include <ccomplex>
#include <functional>
#include <fstream>
#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>
#include <Windows.h>

#define vsegda_prav72 ios_base::sync_with_stdio(0); cin.tie(0);
#define fort() int ___t; cin >> ___t; for(int sdcsdsd = 0; sdcsdsd < ___t; sdcsdsd++)
#define forn(__i,__n) for(int __i = 0; __i < __n; __i++)
#define mp make_pair
#define pb push_back
#define bgn begin()
#define ed end()
#define fst first
#define snd second
#define itall(__v) __v.begin(), __v.end()
#define outn(___s) cout << ___s << "\n"
#define outs(___s) cout << ___s << " "
#define acnt cout << "\t"
#define nl cout << "\n"
#define adel(___a) delete[] ___a

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;


const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek = 998244353;
const ll mod7 = 1e9 + 7;
const ll mod9 = 1e9 + 9;
const ld PI = 3.14159265358;
//------------------SOLUTION STARTS--------------------



int parsefs(string& s) {
	int ans = 0;
	if (s[0] == '-') throw 0;
	for (auto a : s) {
		if (!isdigit(a)) throw -1;
		ans *= 10;
		ans += (int(a) - int('0'));
	}
	return ans;

}

inline bool NextSet(int* a, int n, int m)
{
	int k = m;
	for (int i = k - 1; i >= 0; --i)
		if (a[i] < n - k + i + 1)
		{
			++a[i];
			for (int j = i + 1; j < k; ++j)
				a[j] = a[j - 1] + 1;
			return true;
		}
	return false;
}

vector<int> vfroma(int* a, int m) {
	vector<int> v;
	forn(i, m) {
		v.pb(a[i]);
	}
	return v;
}

long long powll(int n) {
	ll ret = 1;
	forn(i, n) {
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
/*	if (v == vi({ 3,8,0,1,5,2,9,4,6,7 }))
		cout << "IM HERE\n\n";*/
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
	
	;
	
	if (m.size() > 10) return set<vll>();
	
	int* _d = new int[m.size()];
	auto msize = m.size();
	ll n = powll(10);
	ll ___n = powll(10 - m.size());
	ll __n = powll(m.size());
	n /= __n;
	n /= ___n;
	forn(i, msize) {
		_d[i] = i + 1;
	}
	for (ll j = 0; j < n; j++) {
		vi _v;
		for (int i = 0; i < m.size(); i++) {
			_v.pb(_d[i]);
		}
		for (ll gg = 0; gg < __n; gg++) {
			auto it = m.begin();
			for (int i = 0; i < msize; i++) {
				(it++)->second = _v[i]-1;
			}
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
			next_permutation(_v.begin(), _v.end());
		}
		NextSet(_d, 10, msize);
	}
	return ans;
}

inline string symbol_c(int i, int size) {
	if (i + 1 == size) return "";
	if (i + 2 == size) return " = ";
	return " + ";
}

void retstring(int l, int& n, set<char>& s, vector<string>& adds, string cur, bool& out) {
	if (l == n) {
		auto _v = simple_solve(adds, cur);
		if (_v.size() > 0) {
			cout << cur << endl;
			if (out) {
				for (auto v : _v) {
					acnt;
					forn(i, v.size()) {
						cout << v[i] << symbol_c(i, v.size());
					}
					cout << endl;
				}
			}
		}
	}
	else {
		for (auto c : s) {
			retstring(l + 1, n, s, adds, cur+c, out);
		}
	}
}


int main() { 
	vsegda_prav72;
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitle("Ребус");
	
	cout << "Решатель ребусов для Доса\n\nЕсть два режима:\n\n\t1) Решение конкретного ребуса с заданными слагаемыми и суммой\n\t2) Нахождение подходящей суммы для заданных слагаемых\n\n";
	
	string request;
	bool b=false, wr = true;
	//cout << "Выберите режим 1 или 2: ";
	while (wr) {
		badrequest:
		request = "";
		if(request == "") cout << "Выберите режим 1/2 или 0 для выхода: ";
		getline(cin, request);
		if (request == "0") {
			wr = false;
			goto norm;
		}
		if (request == "Джулс" || request == "джулс") {
			cout << "Подлива\n\n";
			goto badrequest;
		}
		if (request == "1") {
			b = false;
			goto norm;
		}
		if (request == "2") {
			b = true;
			goto norm;
		}
		if(request != "") cout << "Некорректный запрос!\n\n";
		goto badrequest;

		norm:
		if (b&&wr) {
			vector<string> adds;
			int maxlength = 0;
			forn(i, 2) {
				cout << "Введите " << i + 1 << " слагаемое: ";
				cin >> request;
				maxlength = max(maxlength, request.size());
				adds.pb(request);
			}
			cout << "Решений для каждой возможной суммы может быть слишком много. Выводить решения для каждой возможной суммы?\nДА - введите 0, НЕТ - любое другое значение: ";
			cin >> request;
			bool out = false;
			if (request == "0") out = true;
			cout << "\nПоиск возможных сумм для заданных слагаемых...\n\n";
			set<char> st;
			for (auto ss : adds) {
				for (auto c : ss) st.insert(c);
			}
			retstring(0, maxlength,st,adds,"",out);
			maxlength++;
			retstring(0, maxlength, st, adds, "", out);
			cout << "\nПоиск завершён\n\n";
		}
		if (!b && wr) {
			int nOfAdd;
			lessthantwo:
			cout << "Введите количество слагаемых: ";
			cin >> request;
			try {
				nOfAdd = parsefs(request);
			}
			catch (int error) {
				switch (error) {
				case -1:
					cout << "Введенное значение не является числом!\n\n";
					break;
				case 0:
					cout << "Число не должно быть отрицательным!\n\n";
					break;
				default:
					cout << "Неизвестная ошибка!\n\n";
				}
				goto lessthantwo;
			}
			if (nOfAdd < 2) {
				if (nOfAdd == 2) return 0;
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
