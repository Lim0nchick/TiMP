#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
vector<int> tree;

void add() {
	int elem, i;
	cin >> elem;
	if (tree.size() == 0)
		tree.insert(tree.begin(), elem);
	else {
		for (i = 0; i < tree.size(); i++) 
			if (elem <= tree[i])
			{
				tree.insert(tree.begin() + i, elem);
				break;
			}
		if (i == tree.size())
			tree.push_back(elem);
		
	}
}



int main()
{
	char command[4];
	int N;
	cin >> N;

	cout << "add get dell" << endl;
	for (int i = 0; i <= N; i++) {
		scanf("%s", &command);
		switch (command[0]) {
		case 'a':
			add();
			break;
		case 'g':
			cout << tree[0] << endl;
			break;
		case 'd':
			tree.erase(tree.begin());
			break;
		default:
			break;
		}
	}

	system("pause");
    return 0;
}