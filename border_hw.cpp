#include<string>
#include<vector>
#include<iostream>
#include <fstream> 
#include <iomanip> 

using namespace std;


string::size_type width(const vector<string>& v) {
	string::size_type maxlen = 0;

	for (vector<string>::size_type i = 0; i != v.size(); i++) {
		maxlen = max(maxlen, v[i].size());
	}

	return maxlen;
}


vector<string> frame(const vector<string>& v) {
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, ' *');

	
	ret.push_back(border);

	

	for (vector<string>::size_type i = 0;
		i != v.size(); i++) {
		ret.push_back("*" + v[i] +
			string(maxlen - v[i].size(), ' ') + "*");
	}


	ret.push_back(border);
	return ret;
}


vector<string> vcat(const vector<string>& top,
	const vector <string>& bottom) {
	vector <string> ret = top;
	for (vector<string>::const_iterator it = bottom.begin();
		it != bottom.end(); ++it) {
		ret.push_back(*it);
	}

	return ret;
}

vector<string> hcat(const vector<string>& left,
	const vector <string>& right) {
	vector<string> ret;

	string::size_type width1 = width(left) + 1;

	vector<string>::size_type i = 0, j = 0;

	while (i != left.size() || j != right.size()) {
		string s;

		if (i != left.size()) {
			s = left[i++];
		}

		s += string(width1 - s.size(), ' ');

		if (j != right.size()) {
			s += right[j++];
		}

		ret.push_back(s);
	}
	return ret;
}
vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	// invariant: we have processed characters original value of [i, i)
	while (i != s.size())
	{
		// ignore leading blanks
		// invariant: characters in range [original i, current i)
		while (i != s.size() && isspace(s[i]))
			++i;

		// find end of next word
		string_size j = i;

		// invariant: none of the characters in range [original j, current j) is a space
		while (j != s.size() && !isspace(s[j]))
			++j;

		// if we found some non-whitespace characters
		if (i != j)
			// copy from s starting at i and taking j - i chars
			ret.push_back(s.substr(i, j - i));
		i = j;
	}
	return ret;
}
/*
1. ���� split() �������� ����ϱ�
2. vcat() ����ϱ�
3. hcat() ����ϱ�
4. out.txt ���Ͽ��� ��� ��� �������ּ���.
*/
int main() {
	string s;

	while (getline(cin, s)) {
		vector<string> v = split(s);

		for (vector<string>::size_type i = 0; i != s.size(); ++i)
			cout << s[i] << endl;

		vector<string> f = frame(v);
		for (const string& line : f) {
			cout << line << endl;
		}
	}
		ofstream outFile("out.txt");

		while (getline(cin, s)) {
			vector<string> v = split(s);
			for (const string& word : v) {
				cout << word << endl;
				outFile << word << endl;
			}
			vector<string> framed = frame(v);
			for (const string& line : framed) {
				cout << line << endl;
				outFile << line << endl;
			}

			vector<string> v_result = vcat(v, frame(v));
			for (const string& line : v_result) {
				cout << line << endl;
				outFile << line << endl;
			}

			vector<string> h_result = hcat(v, frame(v));
			for (const string& line : h_result) {
				cout << line << endl;
				outFile << line << endl;
			}
		}
		// out.txt �ݱ�
	outFile.close();
	return 0;
}
