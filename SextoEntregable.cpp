
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
int minimoCosto(vector<vector<int>> m){ // |m| = n
    int i = 0; 							//O(1)
    int j = 0; 							//O(1)
    int sum = m[i][j]; 					//O(1)
    while(i< m.size()-1 &&j< m.size()-1){// O(1) y n iteraciones
        if(m[i][j+1] <= m[i+1][j]){ 		//O(1)
            j++; 							//O(1)
        } else {
            i++; 							//O(1)
        }
        sum = sum + m[i][j]; 				//O(1)
    }									// t(n) = O(1) + O(1)3n => O(n)
    if(i < m.size() - 1){ 				//O(1)
        i++; 							//O(1)
        while(i < m.size()){ 			 //O(1) y n iteraciones
            sum = sum + m[i][j]; 			//O(1)
            i++; 							//O(1)
        }									// t(n) = O(1) + O(1)3n => O(n)
    } else {
        if(j < m.size() - 1){ 			//O(1)
            j++;  						//O(1)
            while(j < m.size()){ 		//O(1) y n iteraciones
            sum = sum + m[i][j]; 			//O(1)
            j++; 							//O(1)
            }							// t(n) = O(1) + O(1)3n => O(n)
        } 
    }
    return sum; 						//O(1)
}										//t(n) = 3*O(1) + O(n) + O(n) + O(1)

//Complejidad: 2*O(n) => O(n)


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
