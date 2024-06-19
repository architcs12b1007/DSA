#include <iostream>
#include <vector>
#include <map>

#define MOD 1000000007

using namespace std;

int numDistinctPrimeFactors(int n) {
    map<int, int> factors;
    while (n % 2 == 0) {
        factors[2]++;
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1)
        factors[n]++;
    return factors.size();
}

int main() {
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    int K;
    cin >> K;
    
    vector<int> distinctFactors(N, 0);
    for (int i = 0; i < N; i++)
        distinctFactors[i] = numDistinctPrimeFactors(arr[i]);
    
    long long score = 1;
    vector<bool> chosen(N, false);
    
    for (int op = 0; op < K; op++) {
        int maxDistinctFactors = -1;
        int maxIdx = -1;
        
        for (int i = 0; i < N; i++) {
            if (!chosen[i] && distinctFactors[i] > maxDistinctFactors) {
                maxDistinctFactors = distinctFactors[i];
                maxIdx = i;
            }
        }
        
        if (maxIdx == -1)
            break;
        
        chosen[maxIdx] = true;
        score = (score * arr[maxIdx]) % MOD;
    }
    
    cout << score << endl;
    
    return 0;
}


long long solve(int N,vector<int> A){
    long long ans=0;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(A[A[A[i]-1]-1]==A[A[A[j]-1]-1])
            ans++;        
        }
    }

    return ans;

}