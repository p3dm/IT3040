// bài 1
#include <iostream> 
using namespace std;
struct Node { 
    int data; 
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};


Node* prepend(Node* head, int data) {
    Node* new_node = new Node(data);
    new_node->next = head;
    head = new_node;
    return head;
    
    
}

// print the list content on a line
void print(Node* head) {
    Node *tmp = head;
    while(tmp != NULL){
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    cout << endl;
}

// return the new head of the reversed list
Node* reverse(Node* head) {
     Node* current = head->next;
    Node* prev = head; prev->next = NULL;
    Node* next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    head = prev;

    return head;
}
  
int main() {
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    } 
    
    cout << "Original list: ";
    print(head);

    head = reverse(head);
    
    cout << "Reversed list: ";
    print(head);

    return 0; 
}
//---------------------------------------------------------------------------------
//bài 2
double area(Point a, Point b, Point c){
    double xa = get<0>(a), ya = get<1>(a);
    double xb = get<0>(b), yb = get<1>(b);
    double xc = get<0>(c), yc = get<1>(c);
    double xab = xa - xb;
    double yab = ya-yb;
    double xac = xa-xc;
    double yac = ya-yc;
    return abs((xab*yac - xac*yab)/2);

}
//---------------------------------------------------------------------------------
//bài 3
Vector cross_product(Vector a, Vector b){
    double xa = get<0>(a), ya = get<1>(a), za = get<2>(a);
    double xb = get<0>(b), yb = get<1>(b), zb = get<2>(b);
    double x = ya * zb - za * yb;
    double y = za * xb - xa * zb;
    double z = xa * yb - ya * xb;
    return {x, y, z};
}
//---------------------------------------------------------------------------------
//bài 4
#include<iostream> 
#include<vector>
#include<algorithm>

using namespace std;

vector<int> evenRemove(vector<int> &a){
    for(auto num = a.begin(); num != a.end();){
        if(*num % 2 == 0){
            num = a.erase(num);
        } else {
            ++num;
        }
    }
    return a;
}

vector<int> sortDecrease(vector<int> &a){
    sort(a.begin(), a.end(), greater<int>());
    return a;
}

vector<int> mergeVector(vector<int> &a, vector<int> &b){
    a.insert(a.end(), b.begin(), b.end());
    return a;
}



int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), b(m+1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    evenRemove(a);
    
    cout << "Odd elements of a: ";
    for(int num : a){
        cout << num << " ";
    }
    cout << endl;
    
    evenRemove(b);
    cout << "Odd elements of b: ";
    for(int num : b){
        cout << num << " ";
    }
    cout << endl;
    cout << "Decreasingly sorted a: ";
    sortDecrease(a);
    for(int num : a){
        cout << num << " ";
    }
    cout << endl;
    cout << "Decreasingly sorted b: ";
    sortDecrease(b);
    for(int num : b){
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> c = mergeVector(a, b);
    cout << "Decreasingly sorted c: ";
    sortDecrease(c);
    for(int num: c){
        cout << num << " ";
    }
}
//---------------------------------------------------------------------------------
//bài 5
void dfs(const vector<list<int>>& adj) {
    int n = adj.size() - 1;
    vector<bool> visited(n + 1, false); 
    stack<int> s;                      

    
    s.push(1);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        
        if (!visited[current]) {
            visited[current] = true;  
            cout << current << " " << endl; 
            for (auto it = adj[current].rbegin(); it != adj[current].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);
                }
            }
        }
    }
  
}
//---------------------------------------------------------------------------------
//bài 6
void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size(),false);
    Q.push(1); // Bắt đầu từ đỉnh số 1
    while(!Q.empty()){
        int current = Q.front();
        Q.pop();

        if(!visited[current]){
            visited[current] = true;
            cout << current << endl;
            for(auto i = adj[current].begin(); i != adj[current].end(); ++i ){
                if(!visited[*i]){
                    Q.push(*i);
                }
            }
        }
    }
}
//---------------------------------------------------------------------------------
//bài 7
template<class T>

set<T> set_union(const set<T> &a, const set<T> &b) {
    set<T> c;
    for(T v : a){
        c.insert(v);
    }

    for(T v  : b){
        c.insert(v);
    }
    return c;

}

template<class T>

set<T> set_intersection(const set<T> &a, const set<T> &b) {
    set<T> c;
    for(T u: a){
        for(T v : b){
            if(u == v){
                c.insert(v);
            }
        }
    }
    return c;

}
//---------------------------------------------------------------------------------
//bài 8
template <class T>
std::map<T, double> fuzzy_set_union(const std::map<T, double>& a, const std::map<T, double>& b)
{
    std::map<T, double> c = a;
    for (const auto& e : b) {
        if (c.count(e.first)) {
            c[e.first] = std::max(c[e.first], e.second);
        } else {
            c.insert(e);
        }
    }
    return c;
}

template <class T>
std::map<T, double> fuzzy_set_intersection(const std::map<T, double>& a, const std::map<T, double>& b)
{
    std::map<T, double> c;
    for (const auto& x : a) {
        const auto it = b.find(x.first);
        if (it != b.end()) {
            c[x.first] = std::min(x.second, it->second);
        }
    }
    return c;
}
//---------------------------------------------------------------------------------
//bài 9
std::vector<int> dijkstra(const std::vector<std::vector<std::pair<int, int>>>& adj)
{
    std::priority_queue<std::pair<int, int>> Q;
    std::vector<int> d(adj.size(), INT_MAX);
    d[0] = 0;
    Q.push({ 0, 0 });
    while (!Q.empty()) {
        int du = -Q.top().first;
        int u = Q.top().second;
        Q.pop();
        if (du != d[u])
            continue;
        for (auto e : adj[u]) {
            int v = e.first;
            int c = e.second;
            if (d[v] > d[u] + c) {
                d[v] = d[u] + c;
                Q.push({ -d[v], v });
            }
        }
    }
    return d;
}
