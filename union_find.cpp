#include <bits/stdc++.h>

using namespace std;

int parent[1000001];
int ran[1000001];

int find(int u){
    if(parent[u] == u) return u;
    else return parent[u] = find(parent[u]);
}

void union1(int x, int y){
    int u = find(x);
    int v = find(y);

    if(ran[u] > ran[v]) swap(u, v);

    parent[u] = v;

    if(ran[u] == ran[v]) ++ran[v];
}

int union2(int x, int y){
   x = find(x);
   y = find(y);

   // 두 값의 root가 같지 않으면
   if(x != y) {
       root[y] = x; // y의 root를 x로 변경
       nodeCount[x] += nodeCount[y]; // x의 node 수에 y의 node 수를 더한다.
       nodeCount[y] = 1; // x에 붙은 y의 node 수는 1로 초기화
   }
   return nodeCount[x]; // 가장 root의 node 수 반환
}
//최소 신장 트리

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M; cin >> N >> M;


	for(int i=1; i<=N; i++)
        parent[i] = i;

    for(int i=0; i<M; i++){
        int w,a,b;
        cin >>w >> a >> b;

        if(w== 0)
            merge(a,b);
        else{
            if(find(a) == find(b)) cout <<"YES\n";
            else cout <<"NO\n";
        }
    }
	return 0;
}
