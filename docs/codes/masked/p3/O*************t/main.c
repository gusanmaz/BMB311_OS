#include <bits/stdc++.h>
using namespace std;


int groupsOfOnes(string S, int N)
{
	int count = 0;


	stack<int> st;


	for (int i = 0; i < N; i++) {


		if (S[i] == '1')
			st.push(1);
	
		else {
		
			if (!st.empty()) {
				count++;
				while (!st.empty()) {
					st.pop();
				}
			}
		}
	}

	if (!st.empty())
		count++;


	return count;
}

int main()
{

	string S = "100110111";
	int N = S.length();


	cout << groupsOfOnes(S, N) << endl;
	return 0;
}
