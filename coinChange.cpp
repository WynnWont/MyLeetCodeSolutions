#include <vector>
#include <unordered_map>
//#include <ext/hash_map>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int coinChange(vector<int>& coins, int amount){
	if(coins.empty() || 0==amount) return -1;
	int i,j,m;
	//unordered_map<int,int> changedCoins;
	int* changedCoins = new int[amount+1];//if a hash would be quickly.
	for(i=0;i<=amount;++i)
		changedCoins[i]=amount+1;
	sort(coins.begin(), coins.end());
	for(i=0;i<coins.size();++i)
		changedCoins[coins[i]]=1;
	for(i=0;i<=amount;++i){
		for(j=0;j<coins.size();++j){
		    if((i-coins[j])<0) continue;
			if(changedCoins[i-coins[j]]!=amount+1){
				m=changedCoins[i-coins[j]]+1;
				if(changedCoins[i]==amount+1){
					changedCoins[i]=m;
				}else{
					if(m < changedCoins[i])
						changedCoins[i]=m;
				}
			}
		}
	}
	if(changedCoins[amount]==amount+1)
		m=-1;
	else
		m=changedCoins[amount];
	delete[] changedCoins;
	return m;
}
int main(){
	int arr[]={206,280,362,59,486,27,177,437,329};
	vector<int> coins(arr, arr+sizeof(arr)/sizeof(int));
	cout<<coinChange(coins, 7621)<<endl;
	return 0;
}
