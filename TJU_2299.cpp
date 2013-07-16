#include <stdio.h>
#include <string.h>
#define N 10001
#define M 20001
struct e{
    int v;
    e* next;
};
e *link[N], edge[M * 2];
int m, n, son[N], rootdegree, el, b[N], bb[N], time;
bool judge[N];
int min(int a, int b){
    return a > b ? b : a;
}
void dfs(int u, int root){
    e *l = link[u];int i, v;bool c = false;
    b[u] = bb[u] = time++;judge[u] = true;
    while(l){
        v = l->v;
        if(!judge[v]){
            dfs(v, root);
            if(u == root){
                rootdegree++;
                if(rootdegree >= 2) son[u]++;
            }
            else{
                bb[u] = min(bb[u], bb[v]);
                if(bb[v] >= b[u])son[u]++;
            }
        }
        else bb[u] = min(bb[u], b[v]);
        l = l->next;
    }
}
int main(){
    int i, j, u, v, fl, ans;
    while(scanf("%d%d", &n, &m), n || m){
        for(i = 0; i < n; i++){
            b[i] = bb[i] = judge[i] = 0;son[i] = 1;link[i] = NULL;
        }el = rootdegree = fl = 0;
        for(i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            edge[el].v = v;edge[el].next = link[u];link[u] = &edge[el++];
            edge[el].v = u;edge[el].next = link[v];link[v] = &edge[el++];
        }
        if(n == 1){
            puts("0");continue;
        }
        if(m == 0){
            printf("%d\n", n - 1);continue;
        }
        for(i = 0; i < n; i++){
            if(!judge[i]){
                rootdegree = time = 0;dfs(i, i);fl++;
            }
        }ans = 1;
        for(i = 0; i < n; i++){
            if(son[i] > ans)ans = son[i];
        }printf("%d\n", ans + fl - 1);
    }
    return 0;
}
