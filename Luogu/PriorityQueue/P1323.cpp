#include<iostream>
#include<string>
#include<queue>

using namespace std;

priority_queue<int,vector<int>,greater<int> > q;
int k,m;
string num;
string got;

int main() {
	cin>>k>>m;
	q.push(1);
	while(k--) {
		int head=q.top();
		q.pop();
		q.push(head*2+1);
		q.push(head*4+5);
		num+=to_string(head);
	}
	cout << num << endl;

	while(m) {
		for(int i = 0; i < num.size(); ++i){
			if(num[i] < num[min(i+1, int(num.size()-1))]){
				num.erase(i,1);
				m--;
				break;
			}
		}
	}

	cout << num;
    return 0;
}