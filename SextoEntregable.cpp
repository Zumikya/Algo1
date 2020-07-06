
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
    int i = 0; //O(1)
    int j = 0; //O(1)
    int sum = m[i][j]; //O(1)
    while(i < m.size() - 1 && j < m.size() - 1){ //O(n)
        if(m[i][j+1] <= m[i+1][j]){ //O(1)
            j++; //O(1)
        } else {
            i++; //O(1)
        }
        sum = sum + m[i][j]; //O(1)
    }
    if(i < m.size() - 1){ //O(1)
        i++; //O(1)
        while(i < m.size()){ //O(n)
            sum = sum + m[i][j]; //O(1)
            i++; //O(1)
        }
    } else {
        if(j < m.size() - 1){ //O(1)
            j++;  //O(1)
            while(j < m.size()){ //O(n)
            sum = sum + m[i][j]; //O(1)
            j++; //O(1)
            }
        } 
    }
    return sum; //O(1)
}

//Complejidad: 2*O(n) => O(n)


// Ejercicio 3 Practica 9

//Pre n>=0
int raizA(int n){
	int i=0; //O(1)
	while(i*i<n){ //O(sqrt(n))
		i++; //O(1)
	}
	return i-1; //O(1)
}

//Complejidad: O(sqrt(n))

int raizB(int n){
	int low=0; //O(1)
	int high=n; //O(1)

	while(low+1<high && low*low<n){ //O(log(n))
		int mid=(low+high)/2; //O(1)
		if(mid*mid<=n){ //O(1)
			low=mid; //O(1)
		}else{
			high=mid; //O(1)
		}
	}

	return low; //O(1)
}

//Complejidad: O(log(n))
