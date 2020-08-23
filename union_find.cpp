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

   // �� ���� root�� ���� ������
   if(x != y) {
       root[y] = x; // y�� root�� x�� ����
       nodeCount[x] += nodeCount[y]; // x�� node ���� y�� node ���� ���Ѵ�.
       nodeCount[y] = 1; // x�� ���� y�� node ���� 1�� �ʱ�ȭ
   }
   return nodeCount[x]; // ���� root�� node �� ��ȯ
}
//�ּ� ���� Ʈ��

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
