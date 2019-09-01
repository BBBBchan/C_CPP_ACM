#ifndef __SOLVER_H__
#define __SOLVER_H__

#include <bits/stdc++.h>
using namespace std;

struct Operation {
  char t;
  string s;
  int l;
};
class Solver {
 public: string solve(const string &s, int p, const vector<Operation> &ops) {
    /**********  Begin  **********/
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
    /**********  End  **********/
  }

};

#endif
