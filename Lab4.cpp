#include <iostream>

class Error{
		std::string inf;
	public: 
		Error(std::string str){
	 		inf = str;
		}
		void what(){
			std::cout << inf << '\n';
		} 
		~Error(){
		}
};

void Asya(const int* Tree, int n){
	size_t k = 0;
	for (int i = 0; i < n; i++){
		if(Tree[i] == -1) k++;
	}
	if (k != 1) throw Error("Smt wrong witn the root");
}


void direct(const int* Tree, int n, int root){		
	for(int i = 0; i < n; i++){	
		if(Tree[i] == root){
			std::cout << i << ' ';
			direct(Tree, n, i);
		}  	
	}
}

void reverse(const int* Tree, int n, int root){
	for(int i = 0; i < n; i++){	
		if(Tree[i] == root){
			reverse(Tree, n, i);
			std::cout << i << ' ';
		}  	
	}
}

int Oly(const int* Tree, int n, int root){	
	for (int i = 0; i < n; i++){
		if (Tree[i] == root){
			return i;
		}
	}
	return root;
}


int OlyBro(const int* Tree, int n, int id){
		for (int i = id + 1; i < n; i++){
		if (Tree[i] == Tree[id])
			return i;
		}
}

size_t End(const int* Tree, int n, int root){
	size_t k = 0;
	for (int i = 0; i < n; i++)
		if (Tree[i] == root) k++;
	return k;	
}

void symmetric(const int* Tree, int n, int root){

int id;

if (End(Tree, n, root) == 0){
	std::cout << root << ' ';
	return;
}

id = Oly(Tree, n, root);
symmetric(Tree, n, id);
if(root != -1) std::cout << root << ' ';

for (int i = 0; i < End(Tree, n, root) - 1; i++){
	symmetric(Tree, n, OlyBro(Tree, n, id));
	id = OlyBro(Tree, n, id);
}	
} 

int main() {
	int N;
	std::cin >> N;
	int* Tree = new int[N];
	
	for (int i = 0; i < N; i++){
		std::cin >> Tree[i];
	}
	try{
		Asya(Tree, N);
		
		direct(Tree, N, -1);
		std::cout << std::endl;
		
		reverse(Tree, N, -1);
		std::cout << std::endl;
		
		symmetric(Tree, N, -1);
		std::cout << std::endl;
	}catch (Error& e){
		e.what();
	}

	delete[] Tree;
	return 0;
}
