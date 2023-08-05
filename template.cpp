#ifdef ONLINE_JUDGE
#define _CRT_SECURE_NO_WARNINGS
#endif
//#define XOX
// HEADERS BEGIN
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
// HEADERS END
using namespace std;
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#endif
typedef long long int ll;
typedef vector<int> v32;
typedef vector<ll> v64;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> pi;
#define cont continue;
#define stoi stoll
#define em emplace_back
#define pb push_back
#define mp make_pair
#define e cout<<endl;
#define r return;
#define er cout<<endl; return;
#define re cout<<endl; return;
#define ff first
#define ss second
#define hi cout<<"HI";
#define max(a, b) (a < b ? b : a)
#define min(a, b) (a > b ? b : a)
#define ci cin>>
#define c >>
#define cou cout<<
#define co <<
#define des greater<int>()
#define sorted(v) sort(v.begin(),v.end())
#define sz size()
#define ma(v) max_element(v.begin(), v.end())
#define mi(v) min_element(v.begin(), v.end())
#define rev(s) reverse(s.begin(), s.end())
#define f(a, cz) for (int a = 0; a < cz; a++)
#define fi(i,dat) for (auto i = dat.begin();i!=dat.end();++i)
#define endl "\n"
#define nl NULL
//####DEBUGGING
vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while(!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
//####DEBUGGING END
ll jlt(ll a,ll n){
//find the a**x <= n, return a**x
    ll ans=1;
    while(ans<=n){
        ans*=a;
    }
    return ans/a;
}
vector<string> split(const string &s, char delimiter)
{
    vector<string> tokens;
    istringstream iss(s);
    string token;

    while (getline(iss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

//USER DEFINED CONSTS
ll MOD=1e9+7;

ll gcd(ll a, ll b)
{
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if (a == 0) {
        return b;
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}
struct node {
    int data;
    node* left;
    node* right;

    node(int value) {
        data = value;
        left = right = NULL;
    }
};

bool isBST(node* root, node* &prev) {
    if (root) {
        if (!isBST(root->left, prev))
            return false;

        // Allows only distinct valued nodes
        if (prev != NULL && root->data <= prev->data)
            return false;

        prev = root;

        return isBST(root->right, prev);
    }

    return true;
}
bool sortbyCond(const pair<int, int>& a,const pair<int, int>& b) //first element by ascending and second by descending
{
if (a.first != b.first)
return (a.first < b.first); 
else
return (a.second > b.second);
}
string get_str()
{
   fflush(stdin);
    string s;
    getline(cin,s);
    return s;
}
int binarysearch(v64 & arr,ll n,ll k)
    {
    ll ct = -1;
    for (ll b = n;b>=1;b/=2)
    {
        while(ct + b <n && arr[ct+b]<=k) ct+=b;
    }
    return ct;
}
template<typename T>
void inp_vec(vector<T> &vec,ll n)
{
    T tmp;
    f(i,n)
    {
        cin>>tmp;
        vec.pb(tmp);
    }
}
template<typename T>
ll summer(vector<T> &vec)
{
    ll sum=0;
    f(i,vec.size())
    {
        sum+=vec[i];
    }
    return sum;
}
v64 stov(string &s)
{
    v64 res;
    fi(i,s)
    {
        res.pb((ll)(*i-'0'));
    }
    return res;
}
vector<bool> seive_eratosthenes(int n)
{
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= n; i++) {
        if (sieve[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                sieve[j] = false;
        }
 
    }
    return sieve;
}
ll power(ll a,ll b){
   if(b==0) return 1;
   if(b==1) return a%MOD;
   ll res = power(a,b/2);
   if(b%2==0){
       ll ans = (res%MOD) * (res%MOD);
       return ans%MOD;
   }
   ll ans = (res%MOD)*(res%MOD);
   ans%=MOD;
   ans = (ans*(a%MOD))%MOD;
   return ans%MOD;
}
// Number of integers from 1 to n that are co-prime to n.
vector<ll> euler_totient_1_to_n(ll n) {
    std::vector<ll> v(n + 1);
    for (ll i = 0; i <= n; i++) {
        v[i] = i;
    }
    for (ll i = 2; i <= n; i++) {
        if (v[i] == i) {
            v[i] = i - 1;
            for (ll j = i * 2; j <= n; j += i) {
                v[j] -= v[j] / i;
            }
        }
    }
    return v;
}

bool isPrime(ll n) {
    if (n == 1) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

ll modInverse(ll A, ll M) {
    ll m0 = M;
    ll y = 0, x = 1;
    if (M == 1) {
        return 0;
    }
    while (A > 1) {
        ll q = A / M;
        ll t = M;
        M = A % M, A = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) return x += m0;
    return x;
}

bool isPalindrome(const std::string& a) {
    for (int i = 0; 2 * i < a.size(); i++) {
        if (a[i] != a[a.size() - i - 1]) return false;
    }
    return true;
}

template<typename T>
void printer(const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << endl;
}
ll phi(ll n){
    // phi(n) = n*(1 - 1/p1)*(1 - 1/p2)....*(1 - 1/pk), p1,p2.. are prime factors of n
    ll cnt=n;
    for(ll i=2;i*i<=n;i++){
        if(n%i == 0){
            cnt -= cnt/i;
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>=2) cnt -= cnt/n;
    return cnt;
}

void bfs(vector<int> v[], int start_node, int visited[]){
    queue<int> q;
    q.push(start_node);
    visited[start_node] = 1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto i : v[front]){
            if(visited[i] == 0){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

void dfs(vector<int> v[], int node, int visited[]){
    if(visited[node] == 1){
        return;
    }
    visited[node] = 1;
    for(auto i : v[node]){
        dfs(v, i, visited);
    }
}
double log_a_to_base_b(int a, int b)
{
    return (double)log2(a) / log2(b);
}
//########################SEGMENT TREE#############################
struct my_node {
    ll mn = 0;
    void merge(const my_node& l, const my_node& rq) {
        mn = l.mn + rq.mn;
    }
};

template<typename node>
struct segtree {
    int len;
    vector<node> t;

    segtree(int l) {
        len = l;
        t.resize(4 * len);
    }

    void build(const vector<ll>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            t[v].mn = arr[tl];
            return;
        }
        int tm = (tl + tr) >> 1;
        build(arr, v << 1, tl, tm);
        build(arr, v << 1 | 1, tm + 1, tr);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

node query(int v, int tl, int tr, int l, int rq) {
        if (l > rq) {
            return node();
        }
        if (tl == l && tr == rq) {
            return t[v];
        }
        int tm = (tl + tr) >> 1;
        node left = query(v << 1, tl, tm, l, min(rq, tm));
        node right = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), rq);
        node result;
        result.merge(left, right);
        return result;
    }

void update(int v, int tl, int tr, int pos, ll new_val) {
        if (tl == tr) {
            t[v].mn = new_val;
            return;
        }
        int tm = (tl + tr) >> 1;
        if (pos <= tm) {
            update(v << 1, tl, tm, pos, new_val);
        } else {
            update(v << 1 | 1, tm + 1, tr, pos, new_val);
        }
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }
};
//########################SEGMENT TREE#############################

//##############################TRIE#################################
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
 
// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)
 
// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
 
// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
 
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;
 
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
 
    if (pNode)
    {
        int i;
 
        pNode->isEndOfWord = false;
 
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
 
    return pNode;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
 
    struct TrieNode *pCrawl = root;
 
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}
 
// Returns true if key presents in trie, else false
bool search(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
 
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
 
        if (!pCrawl->children[index])
            return false;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl->isEndOfWord);
}
//##############################TRIE#################################
//##############SETS#################
// Function to compute the intersection of two sets
std::set<int> setIntersection(const std::set<int>& set1, const std::set<int>& set2) {
    std::set<int> intersection;
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                          std::inserter(intersection, intersection.begin()));
    return intersection;
}

// Function to compute the union of two sets
std::set<int> setUnion(const std::set<int>& set1, const std::set<int>& set2) {
    std::set<int> uni;
    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
                   std::inserter(uni, uni.begin()));
    return uni;
}

// Function to print the elements of a set
void printSet(const std::set<int>& s) {
    for (const auto& elem : s) {
        std::cout << elem << " ";
    }
    std::cout << endl;
}
//##############SETS#################




void solve()
{
    


}


int main()
{
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0), cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("output.txt","w",stderr);
#endif
// std::cout << std::fixed;
// std::cout << std::setprecision(10);
    int t = 1;
    // cin >> t;                                                     //INPUT TEST CASES
    while (t--)
        solve();
    return 0;
}

