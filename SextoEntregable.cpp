
// Ejercicio 6 Practica 7
void dividirPorPromedio(vector<float> &s){
	int i=0;
	vector<float> s0=s;
	int p=promedio(s0);
	while( i<s.size()/2){
		s[i]=s0[i]/p;
		s[s.size()-i-1]=s0[s0.size()-i-1]/p;
		i++;
	}
	return;
}

float promedio(vector<float> &s){
	float res=0;
	for(int i=0;i<s.size();i++){
		res+=s[i];	
	}
	res/=s.size();
	return res;
}

// Ejercicio 13 Practica 8
int minimoCosto(vector<vector<int>> m){
    vector<vector<int>> copia = m;
    int f = 0;
    int c = 0;
    while(f < m.size() - 1){
        f++;
        copia[f][c] = copia[f][c] + copia[f-1][c];
    }
    f = 0;
    while(c < m.size() - 1){
        c++;
        copia[f][c] = copia[f][c] + copia[f][c-1];
    }
    for(int i = 1; i < m.size(); i++){
        for(int j = 1; j < m.size(); j++){
            if(copia[i-1][j] < copia[i][j-1]){
                copia[i][j] = copia[i][j] + copia[i-1][j];
            } else {
                copia[i][j] = copia[i][j] + copia[i][j-1];
            }
        }
    }
    return copia[m.size() - 1][m.size() - 1];
}

int main()
{
    vector<vector<int>> m = {{1,2,1},{1,10,1},{10,10,1}};
    cout << minimoCosto(m);

    return 0;
}


// Ejercicio 3 Practica 9

//Pre n>=0
int raizA(int n){
	int i=0; 		//O(1)
	while(i*i<n){ 	// O(1) y sqrt(n) iteraciones
		i++; 			//O(1)
	}				// t(n) = O(1) + 2*O(1)sqrt(n) => O(sqrt(n))
	if(i*i==n)		//O(1)
		return i;	//O(1)

	return i-1; 	//O(1)
}					// t(n) = 4*O(1) + O(sqrt(n)) 

//Complejidad: O(sqrt(n))

int raizB(int n){
	int low=0;  			//O(1)
	int high=n; 			//O(1)

	while(low+1<high && low*low<n){ //O(1) y log(n) iteraciones
		int mid=(low+high)/2; 			//O(1)
		if(mid*mid<=n){ 				//O(1)
			low=mid; 					//O(1)
		}else{
			high=mid; 					//O(1)
		}
	}						// t(n) = O(1) + 4*O(1)*log(n) => O(log(n))

	return low; 			//O(1)
}							// t(n) = 4*O(1) + O(log(n))

//Complejidad: O(log(n))
