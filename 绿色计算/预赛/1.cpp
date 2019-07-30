#include <bits/stdc++.h>
using namespace std;
struct Operation {
  char t;
  string s;
  int l;
}te;
vector<Operation> ops;
string s;
int p;
string solve(const string &s, int p, const vector<Operation> &ops) {
    string S = s;
    for(int i = 0; i < ops.size(); i++){
        if(ops[i].t == 'L'){
            if(p-ops[i].l >= 0){
                p -= ops[i].l;
            }
            else{
                p = 0;
            }
        }
        else if(ops[i].t == 'R'){
            if(p+ops[i].l <= S.size()){
                p+=ops[i].l;
            }
            else{
                p = S.size();
            }
        }
        else if(ops[i].t == 'I'){
            string temp = "";
            // for(int j = 0; j < p; j++){
            //     temp += S[j];
            // }
            temp += S.substr(0,p);
            temp+=ops[i].s;
            // for(int j = p; j < S.size(); j++){
            //     temp += S[j];
            // }
            temp += S.substr(p,S.size()-p);
            S = temp;
            p += ops[i].s.size();
        }
        else if(ops[i].t == 'B'){
            string temp = "";
            if(p-ops[i].l >= 0){
                // for(int j = 0; j < p-ops[i].l; j++){
                //     temp += S[j];
                // }
                temp += S.substr(0,p-ops[i].l);
                // for(int j = p; j < S.size(); j++){
                //     temp += S[j];
                // }
                temp += S.substr(p, S.size()-p);
                S = temp;
                p -= ops[i].l;
            }
            else{
                // for(int j = p; j < S.size(); j++){
                //     temp += S[j];
                // }
                temp += S.substr(p,S.size()-p);
                S = temp;
                p = 0;
            }
        }
        else if(ops[i].t == 'D'){
            string temp = "";
            if(ops[i].l+p < S.size()){
                // for(int j = 0; j < p; j++){
                //     temp += S[j];
                // }
                temp += S.substr(0,p);
                // for(int j = p + ops[i].l; j < S.size(); j++){
                //     temp += S[j];
                // }
                temp += S.substr(p+ops[i].l, S.size()-p-ops[i].l);
            }
            else{
                // for(int j = 0; j < p; j++){
                //     temp += S[i];
                // }
                temp += S.substr(0,p);
            }
            S = temp;
        }

    }

    return S;
  }
int main(int argc, char const *argv[])
{
	cin >> s;
	//cout << s <<endl;
	cin >> p;
	//cout << p << endl;
	for(int i = 0; i < 2; i++){
		cin >> te.t;
		cin >> te.s;
		cin >> te.l;
		ops.push_back(te);
		//cout << ops[i].t << " " << ops[i].s << " " << ops[i].l << endl;
	}
	cout << solve(s,p,ops) <<endl;
	return 0;
}
/*
whatsyourproblem
5
L 1 2
D 1 1
R 1 4
I ABCDEF 0
L 1 3
B 1 2
*/