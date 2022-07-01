#include <iostream>
#include <regex>
#include <string>
using namespace std;
void fnc(){
    string st;
    cin>>st;
	regex r(".*[A-Z]+.*");
	regex s(".*[a-z]+.*");
	regex t(".*[0-9]+.*");
	bool ok=1;
    if(!regex_match(st,r)){
        ok=0;
    }
    if(!regex_match(st,s)){
        ok=0;
    }
    if(!regex_match(st,t)){
        ok=0;
    }
    cout<<(ok?"YES":"NO")<<"\n";
}
int main() {
	//code
	int n;
	cin>>n;
	while(n>0){
	    fnc();
	    n--;
	}
	return 0;
}