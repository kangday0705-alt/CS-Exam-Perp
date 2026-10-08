#include <iostream>
#include<string>
#include<list>
#include <iomanip>
using namespace std;

class Bigint {
	list<int> dList;
public:
	Bigint() {}
	Bigint(string s) {
		for (char c : s) {
			dList.push_back(c-'0');
		}
	}
	string tostring() {
		string str;
		for (int n : dList) {
			str += char(n + '0');
		}
		return str;
	}
	friend Bigint operator+(Bigint, Bigint);
};

Bigint operator+(Bigint a, Bigint b) {
	Bigint res;
	int num1, num2, carry = 0;

	auto it1 = a.dList.rbegin();
	auto it2 = b.dList.rbegin();

	while (it1 != a.dList.rend() || it2 != b.dList.rend() || carry) {
		num1 = (it1 != a.dList.rend() ? *it1++ : 0);
		num2 = (it2 != b.dList.rend() ? *it2++ : 0);
		int sum = (num1 + num2 + carry) % 10;
		res.dList.push_front(sum);
		carry= (num1 + num2 + carry) / 10;
	}
	return res;
}

int main() {
	string s1, s2, s3;
	cout << "1: "; cin >> s1;
	cout << "2: "; cin >> s2;
	Bigint a(s1);
	Bigint b(s2);

	Bigint c = a + b;

	s1 = a.tostring();
	s2 = b.tostring();
	s3 = c.tostring();

	cout << setw(s3.length() + 1) << right<< s1 << endl;
	cout << "+";
	cout<< setw(s3.length() + 1) << right << s2 << endl;

	cout << setw(s3.length()+3)<<setfill('-') << "" << endl;
	cout << "= ";
	cout<<setw(s3.length()) << right << s3 << endl;
}